/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGroupBox *groupBoxMotion;
    QSpinBox *spinBoxSizeMotion;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxAngle;
    QGroupBox *groupBoxGauss;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *spinBoxSizeGauss;
    QDoubleSpinBox *doubleSpinBoxSigma;
    QPushButton *pushButtonOk;
    QGroupBox *groupBox_3;
    QRadioButton *radioButtonGauss;
    QRadioButton *radioButtonMotion;
    QDoubleSpinBox *doubleSpinBoxGamma;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(291, 599);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBoxMotion = new QGroupBox(centralWidget);
        groupBoxMotion->setObjectName(QStringLiteral("groupBoxMotion"));
        groupBoxMotion->setEnabled(true);
        groupBoxMotion->setGeometry(QRect(10, 160, 261, 121));
        groupBoxMotion->setCheckable(false);
        spinBoxSizeMotion = new QSpinBox(groupBoxMotion);
        spinBoxSizeMotion->setObjectName(QStringLiteral("spinBoxSizeMotion"));
        spinBoxSizeMotion->setGeometry(QRect(140, 40, 91, 22));
        spinBoxSizeMotion->setMinimum(1);
        spinBoxSizeMotion->setMaximum(10000);
        label = new QLabel(groupBoxMotion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 101, 16));
        label_2 = new QLabel(groupBoxMotion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 101, 16));
        spinBoxAngle = new QSpinBox(groupBoxMotion);
        spinBoxAngle->setObjectName(QStringLiteral("spinBoxAngle"));
        spinBoxAngle->setGeometry(QRect(140, 80, 91, 22));
        spinBoxAngle->setMaximum(359);
        groupBoxGauss = new QGroupBox(centralWidget);
        groupBoxGauss->setObjectName(QStringLiteral("groupBoxGauss"));
        groupBoxGauss->setGeometry(QRect(10, 300, 261, 131));
        label_4 = new QLabel(groupBoxGauss);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 70, 101, 16));
        label_3 = new QLabel(groupBoxGauss);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 101, 16));
        spinBoxSizeGauss = new QSpinBox(groupBoxGauss);
        spinBoxSizeGauss->setObjectName(QStringLiteral("spinBoxSizeGauss"));
        spinBoxSizeGauss->setGeometry(QRect(140, 30, 91, 22));
        spinBoxSizeGauss->setMinimum(1);
        spinBoxSizeGauss->setMaximum(10000);
        doubleSpinBoxSigma = new QDoubleSpinBox(groupBoxGauss);
        doubleSpinBoxSigma->setObjectName(QStringLiteral("doubleSpinBoxSigma"));
        doubleSpinBoxSigma->setGeometry(QRect(140, 70, 91, 22));
        doubleSpinBoxSigma->setDecimals(4);
        doubleSpinBoxSigma->setMinimum(0);
        doubleSpinBoxSigma->setSingleStep(0.01);
        pushButtonOk = new QPushButton(centralWidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(70, 460, 131, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 261, 131));
        radioButtonGauss = new QRadioButton(groupBox_3);
        radioButtonGauss->setObjectName(QStringLiteral("radioButtonGauss"));
        radioButtonGauss->setGeometry(QRect(20, 30, 161, 20));
        radioButtonGauss->setChecked(true);
        radioButtonMotion = new QRadioButton(groupBox_3);
        radioButtonMotion->setObjectName(QStringLiteral("radioButtonMotion"));
        radioButtonMotion->setGeometry(QRect(20, 60, 181, 20));
        doubleSpinBoxGamma = new QDoubleSpinBox(groupBox_3);
        doubleSpinBoxGamma->setObjectName(QStringLiteral("doubleSpinBoxGamma"));
        doubleSpinBoxGamma->setGeometry(QRect(140, 90, 91, 22));
        doubleSpinBoxGamma->setDecimals(4);
        doubleSpinBoxGamma->setMinimum(0);
        doubleSpinBoxGamma->setSingleStep(0.01);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 111, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 291, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionAbout);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        groupBoxMotion->setTitle(QApplication::translate("MainWindow", "Motion Filter", 0));
        label->setText(QApplication::translate("MainWindow", "Window Size", 0));
        label_2->setText(QApplication::translate("MainWindow", "Angle (degree)", 0));
        groupBoxGauss->setTitle(QApplication::translate("MainWindow", "Gaussian Filter", 0));
        label_4->setText(QApplication::translate("MainWindow", "Sigma", 0));
        label_3->setText(QApplication::translate("MainWindow", "Window Size", 0));
        pushButtonOk->setText(QApplication::translate("MainWindow", "Apply", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Noyau", 0));
        radioButtonGauss->setText(QApplication::translate("MainWindow", "Gaussian filters", 0));
        radioButtonMotion->setText(QApplication::translate("MainWindow", "Motion filters", 0));
        label_5->setText(QApplication::translate("MainWindow", "Gamma (Laplacian)", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
