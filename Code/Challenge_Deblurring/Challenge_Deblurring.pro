#-------------------------------------------------
#
# Project created by QtCreator 2017-01-12T18:17:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = challenge_deblurring
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    deblurring.cpp

HEADERS  += mainwindow.h \
    cvmat2qpixorqimg.h \
    deblurring.h

FORMS    += mainwindow.ui


INCLUDEPATH += H:\OpenCV3.2\opencv\build_qt_mingw\install\include\ \
            += H:\OpenCV3.2\opencv\build_qt_mingw\install\include\opencv \
            += H:\OpenCV3.2\opencv\build_qt_mingw\install\include\opencv2 \

LIBS +=  -LH:/OpenCV3.2/opencv/build_qt_mingw/install/x86/mingw/bin \
    -lopencv_calib3d320 \
    -lopencv_core320 \
    -lopencv_features2d320 \
    -lopencv_flann320 \
    -lopencv_highgui320 \
    -lopencv_imgcodecs320 \
    -lopencv_imgproc320 \
    -lopencv_ml320 \
    -lopencv_objdetect320 \
    -lopencv_photo320 \
    -lopencv_shape320 \
    -lopencv_stitching320 \
    -lopencv_superres320 \
    -lopencv_video320 \
    -lopencv_videoio320 \
    -lopencv_videostab320 \
