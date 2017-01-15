#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>

#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateImg(void);

private:
    Ui::MainWindow *ui;

    std::string fileNameIn;

private slots:
    void openFileClick(void);
    void saveFileClick(void);
    void exitFileClick(void);
    void aboutFileClick(void);

    void okClick(void);

    void MotionSelection(void);
    void GaussSelection(void);
};

#endif // MAINWINDOW_H
