#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include <QLabel>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QDebug>

#include "cvmat2qpixorqimg.h"

#include "deblurring.h"

using namespace cv;
using namespace ASM;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Information générale */
    this->setWindowTitle("Challenge Deblurring");


    /* Connection Menu */
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFileClick()));
    connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(aboutFileClick()));

    /* Apply */
    connect(ui->pushButtonOk,SIGNAL(clicked(bool)),this,SLOT(okClick()));

    /* Box */
    connect(ui->radioButtonGauss,SIGNAL(clicked(bool)),this,SLOT(GaussSelection()));
    connect(ui->radioButtonMotion,SIGNAL(clicked(bool)),this,SLOT(MotionSelection()));


    /* Init */
    ui->groupBoxGauss->setEnabled(true);
    ui->groupBoxMotion->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************** SLOTS **************************************************/
/*************************************************************************************************************/

void MainWindow::openFileClick(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("JPG (*.jpg);;BMP (*.bmp);;JPEG (*.jpeg)"));
    fileNameIn = fileName.toStdString();
}


void MainWindow::GaussSelection(void)
{
    ui->groupBoxGauss->setEnabled(true);
    ui->groupBoxMotion->setEnabled(false);
}

void MainWindow::MotionSelection(void)
{
    ui->groupBoxGauss->setEnabled(false);
    ui->groupBoxMotion->setEnabled(true);
}


void MainWindow::aboutFileClick(void)
{
    QString txt;

    txt = "Image deconvolution deblurring\n\n";
    txt += "written by :\n";
    txt += "\t- Dimitri GOMINSKI\n";
    txt += "\t- Julien GUICHON\n";
    txt += "\n";
    txt += "INSA GEA 2014-2017";

    QMessageBox::information(this,"Note",txt);
}

void MainWindow::okClick(void)
{
    int flagOk = 0;
    Mat img;
    QString txt;


    if(fileNameIn.empty() == false)
    {
        Mat I = imread(fileNameIn);
        cvtColor( I, img, CV_RGB2GRAY );

        deblurring::deblurringParamStruct delubrringParam;

        std::ostringstream tilte;
        std::ostringstream tilteSave;
        if(ui->radioButtonGauss->isChecked())
        {
            delubrringParam.flagMotion = 0;
            delubrringParam.flagGauss = 1;

            delubrringParam.angleDeg = 0;

            delubrringParam.gamma = ui->doubleSpinBoxGamma->value();
            delubrringParam.ksize = ui->spinBoxSizeGauss->value();
            delubrringParam.sigma = ui->doubleSpinBoxSigma->value();

            tilte << "Output : " << "ga = " << delubrringParam.gamma << "  sig = " << delubrringParam.sigma << "  W.size = " << delubrringParam.ksize;
            tilteSave << "ga=" << delubrringParam.gamma << "_sig=" << delubrringParam.sigma << "_Wsize=" << delubrringParam.ksize<<".bmp";

            if((delubrringParam.gamma == 0) | (delubrringParam.sigma == 0))
            {
                flagOk = 0;

                txt = "Error with Gamma ou Sigma value !!!\n\n";
                txt += "Gamma > 0\n";
                txt += "Sigma > 0\n";

                QMessageBox::information(this,"Error",txt);
            }
            else
            {
                 flagOk = 1;
            }
        }
        if(ui->radioButtonMotion->isChecked())
        {
            delubrringParam.flagMotion = 1;
            delubrringParam.flagGauss = 0;

            delubrringParam.angleDeg = ui->spinBoxAngle->value();
            delubrringParam.gamma = ui->doubleSpinBoxGamma->value();
            delubrringParam.ksize = ui->spinBoxSizeMotion->value();

            delubrringParam.sigma = 0;

            tilte << "Output : " << "ga = " << delubrringParam.gamma << "  angleDeg = " << delubrringParam.angleDeg << "  W.size = " << delubrringParam.ksize;
            tilteSave << "ga=" << delubrringParam.gamma << "_angleDeg=" << delubrringParam.angleDeg << "_Wsize=" << delubrringParam.ksize<<".bmp";

            if(delubrringParam.gamma == 0)
            {
                flagOk = 0;

                txt = "Error with Gamma !!!\n\n";
                txt += "Gamma > 0\n";

                QMessageBox::information(this,"Error",txt);
            }
            else
            {
                 flagOk = 1;
            }
        }


        if(flagOk == 1)
        {

            Mat outCompute;
            outCompute = deblurring::ComptueDFTandIDFT(img,delubrringParam);

            Mat outComputeCvt;
            outCompute.convertTo(outComputeCvt, CV_8U);


            imshow(tilte.str(), outComputeCvt);

            //show the image
            imshow("Original Image", img);

            //imwrite(tilteSave.str(),outComputeCvt);

            // Wait until user press some key
            waitKey(0);
        }
    }
    else
    {

        txt = "Error with image data\n\n";
        txt += "Is it load ?";

        QMessageBox::information(this,"Error",txt);
    }

}


