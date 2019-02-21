#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDir>
#include <QtGui>
#include <QLabel>
#include <iostream>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLoad_Project_triggered();

    void on_actionAdd_Image_triggered();

    void on_Btn_Edit_clicked(bool checked);

    void on_Btn_Zoom_In_clicked();

    void on_Btn_Zoom_Out_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
