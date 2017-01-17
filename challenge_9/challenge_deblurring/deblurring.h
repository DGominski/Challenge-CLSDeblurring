#ifndef DEBLURRING_H
#define DEBLURRING_H


#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;

class deblurring
{
public:
    deblurring();

    struct deblurringParamStruct
    {
        double gamma;
        double sigma;
        double angleDeg;
        int ksize;
        int flagGauss;
        int flagMotion;
    };
    typedef struct deblurringParamStruct deblurringParamStruct;


    static Mat Psf2otfPerso(Mat psf , Size size);
    static Mat LapKernel(Size imgSize);
    static Mat GaussKernel(double sigma,int ksize,Size imgSize);
    static Mat deconvolution(Mat img,deblurringParamStruct deblurringParam);

//signals:

//public slots:
};

#endif // DEBLURRING_H
