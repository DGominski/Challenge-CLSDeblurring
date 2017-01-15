#include "deblurring.h"
#include <iostream>
#include <fstream>

deblurring::deblurring()
{

}



Mat deblurring::Psf2otfPerso(Mat psf , Size size )
{
    Mat OTF = Mat::zeros(size.height,size.width,psf.type());

    // The PSF to outSize / / Pad
    Size dftSize;

    // The size of DFT transform compute
    dftSize.width = getOptimalDFTSize(size.width);
    dftSize.height = getOptimalDFTSize(size.height);

    //Allocate temporary buffers and initialize them / with 0's
    Mat temp(dftSize, psf.type(),Scalar::all(0));

    //PSF to the top-left corners of temp copy
    Mat roipsf(temp,Rect(0,0,psf.cols,psf.rows));
    psf.copyTo(roipsf);

    //Shift OTF so that the / Circularly of "center" the PSF is at the
    // element of the array. (0,0)
    Mat psf2(dftSize, psf.type(),Scalar::all(0));

    int cx = psf.cols/2;
    int cy = psf.rows/2;

    Mat P0(temp, Rect (0,0, cx, cy)); // Top-Left - Create a ROI per quadrant
    Mat P1(temp, Rect (cx,0, psf.cols-cx, cy));// Top-Right
    Mat P2(temp, Rect (0, cy, cx, psf.rows-cy));// Bottom-Left
    Mat P3(temp, Rect (cx, cy, psf.cols-cx, psf.rows-cy));// Bottom-Right


    Mat Q0(psf2, Rect (0,0, psf.cols-cx,psf.rows-cy)); // Top-Left
    Mat Q1(psf2, Rect (psf2.cols-cx,0, cx, psf.rows-cy));//Top-Right
    Mat Q2(psf2, Rect (0,psf2.rows-cy, psf.cols-cx, cy));// Bottom-Left
    Mat Q3(psf2, Rect (psf2.cols-cx,psf2.rows-cy, cx,cy));// Bottom-Right

    // Swap quadrants (Top-Left with / Bottom-Right)
    P0.copyTo(Q3);
    P3.copyTo(Q0);

    // Swap quadrant (Top-Right with / Bottom-Left)
    P1.copyTo(Q2);
    P2.copyTo(Q1);

    // The OTF Computer
    Mat planes[]= {Mat_<float>(psf2), Mat:: zeros(psf2.size (), CV_32F)};
    Mat complexI;
    merge(planes,2,complexI);

    dft(complexI,complexI);


    OTF = complexI;

    return OTF;
}

Mat deblurring::GaussKernel(double sigma,int ksize,Size imgSize)
{
    Mat gaussK = getGaussianKernel(ksize,sigma,CV_32F);

    Mat gaussKfct;
    gaussKfct = deblurring::Psf2otfPerso(gaussK,imgSize);

    return gaussKfct;
}

Mat deblurring::LapKernel(Size imgSize)
{
    Mat Lap = Mat::zeros(Size(3,3), CV_32F);
    Lap.at<double>(0,0) = 0;
    Lap.at<double>(1,0) = -1;
    Lap.at<double>(2,0) = 0;
    Lap.at<double>(0,1) = -1;
    Lap.at<double>(1,1) = 4;
    Lap.at<double>(2,1) = -1;
    Lap.at<double>(0,2) = 0;
    Lap.at<double>(1,2) = -1;
    Lap.at<double>(2,2) = 0;

    Mat lapKfct;
    lapKfct = deblurring::Psf2otfPerso(Lap,imgSize);

    return lapKfct;
}


Mat deblurring::ComptueDFTandIDFT(Mat img,deblurringParamStruct deblurringParam)
{
    /* Passage d'une image en complex */
    Mat planes[] = {Mat_<float>(img), Mat::zeros(img.size(), CV_32F)};
    Mat imgComplex,imgComplexDFT;    //Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}
    merge(planes, 2, imgComplex);

    /* DFT */
    dft(imgComplex, imgComplexDFT);  // Applying DFT



    Mat lapKfct = LapKernel(img.size());

    Mat Hfct;
    if(deblurringParam.flagGauss == 1)
    {
        Hfct = GaussKernel(deblurringParam.sigma,deblurringParam.ksize,img.size());
    }
    if(deblurringParam.flagMotion == 1)
    {
        // generating the kernel
        Mat kernel_motion_blur = Mat::zeros(Size(deblurringParam.ksize,deblurringParam.ksize),CV_32F);
        for(int i = 0;i<deblurringParam.ksize;i++)
        {
            kernel_motion_blur.at<double>(int((deblurringParam.ksize-1)/2),i) = 1;
        }
        kernel_motion_blur = kernel_motion_blur / deblurringParam.ksize;


        Point2f src_center(kernel_motion_blur.cols/2.0F, kernel_motion_blur.rows/2.0F);
        Mat rot_mat = getRotationMatrix2D(src_center, deblurringParam.angleDeg, 1.0);
        Mat kernel_motion_blur_rot;
        warpAffine(kernel_motion_blur, kernel_motion_blur_rot, rot_mat, kernel_motion_blur.size());
        Hfct = Psf2otfPerso(kernel_motion_blur_rot,img.size());

    }

    Mat H1,H2,P,out;

    /* Conjugé de H */
    Mat ones[] = {Mat::ones(Hfct.size(),CV_32F), Mat::ones(Hfct.size(), CV_32F)};
    Mat complexIones;
    merge(ones, 2, complexIones);
    mulSpectrums(complexIones,Hfct,H1,0,true);


    mulSpectrums(Hfct,Hfct,H2,0,true);
    mulSpectrums(lapKfct,lapKfct,P,0,true);
    mulSpectrums(H1/(H2+deblurringParam.gamma*P),imgComplexDFT,out,0,false);

    Mat outDFT;
    dft(out, outDFT, DFT_REAL_OUTPUT | DFT_SCALE | DFT_INVERSE); // Applying IDFT

    return outDFT;
}


