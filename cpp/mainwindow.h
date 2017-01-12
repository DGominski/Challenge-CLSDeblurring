#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool fileLoaded;
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QString FileToLoad;
    std::string FileToLoadstring;
};

#endif // MAINWINDOW_H
