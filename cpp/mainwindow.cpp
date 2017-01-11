#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    FileToLoad = "";
    FileToLoadstring = "";
    fileLoaded = false;

    QString sPath = "/media/dimitri";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);

    ui->listView->setModel(filemodel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}


void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QString FileToLoad = filemodel->fileInfo(index).absoluteFilePath();
    std::string FileToLoadstring = FileToLoad.toUtf8().constData();
    fileLoaded = true;
}
