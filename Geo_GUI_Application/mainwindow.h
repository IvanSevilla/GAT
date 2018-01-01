#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDir>
#include <QtGui>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>
#include <QList>
#include <QSharedPointer>
#include "gagraphicsview.h"


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

    void on_Btn_Del_Point_clicked();

    void on_Btn_Add_Point_clicked();

    void on_actionMiniMap_triggered(bool tiggered);

    void on_Group0_clicked(bool checked);

    void on_Visiblity0_clicked(bool checked);

    void on_Group1_clicked(bool checked);

    void on_Visiblity1_clicked(bool checked);

    void on_Group2_clicked(bool checked);

    void on_Visibility2_clicked(bool checked);

    void on_Group3_clicked(bool checked);

    void on_Visiblity3_clicked(bool checked);

    void on_Group4_clicked(bool checked);

    void on_Visiblity4_clicked(bool checked);

    void on_Group5_clicked(bool checked);

    void on_Visiblity5_clicked(bool checked);

    void on_Group6_clicked(bool checked);

    void on_Visiblity6_clicked(bool checked);

    void on_Group7_clicked(bool checked);

    void on_Visiblity7_clicked(bool checked);


    void on_Btn_Undo_pressed();

    void on_Btn_Do_clicked();

    void on_Btn_Move_clicked();

private:
    Ui::MainWindow *ui;

    void ZoomOut(double h, double w);
    void ZoomIn(double h, double w);
    void setMousePoint (QPointF point);
    GaGraphicsView* edit;
    QGraphicsView* minimap;
    QPixmap pix;
    QPixmap minipix;
    QGraphicsScene *scene;
    QGraphicsScene *miniscene;
    QGraphicsScene *editscene;
    bool deledit;
    bool delmini;
    bool image;
    QGraphicsProxyWidget *proxyedit;
    QGraphicsProxyWidget *proxymini;

};

#endif // MAINWINDOW_H
