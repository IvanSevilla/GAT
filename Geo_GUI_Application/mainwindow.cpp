#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(showMaximized()));
    ui->horizontalLayout_7->addWidget(ui->graphicsView);
    ui->Btn_Do->setHidden(1);
    ui->Btn_Undo->setHidden(1);
    ui->Btn_Color->setHidden(1);
    ui->Btn_Add_Point->setHidden(1);
    ui->Btn_Del_Point->setHidden(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_Project_triggered()
{
    QString project_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    QMessageBox::information(this,"..",project_name);
}

void MainWindow::on_actionAdd_Image_triggered()
{
    QString image_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    QMessageBox::information(this,"..",image_name);
    //QImage img;
    //int gw = ui->graphicsView->width();
    //int gh = ui->graphicsView->height();
    QPixmap pix(image_name);
    QGraphicsScene *scene;
    //img.load(image_name);
    scene = new QGraphicsScene(this);
    //pix = pix.scaledToHeight(gh);
    //pix = pix.scaledToWidth(gw);
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());//QRectF(0,0,gw-1,gh-1));

    //int w = pix.rect().x();
    //int h = pix.rect().y();
    //ui->imagelabel->setPixmap(pix.scaled(h,w,Qt::KeepAspectRatio));
    //ui->imagelabel->show();
    ui->graphicsView->setScene(scene);
}




void MainWindow::on_Btn_Edit_clicked(bool checked)
{
    ui->label->setNum(checked);
    if(checked){
        ui->Btn_Do->setHidden(!checked);
        ui->Btn_Undo->setHidden(!checked);
        ui->Btn_Color->setHidden(!checked);
        ui->Btn_Add_Point->setHidden(!checked);
        ui->Btn_Del_Point->setHidden(!checked);
    }else{
        ui->Btn_Do->setHidden(!checked);
        ui->Btn_Undo->setHidden(!checked);
        ui->Btn_Color->setHidden(!checked);
        ui->Btn_Add_Point->setHidden(!checked);
        ui->Btn_Del_Point->setHidden(!checked);
    }
}

void MainWindow::on_Btn_Zoom_In_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}

void MainWindow::on_Btn_Zoom_Out_clicked()
{
    ui->graphicsView->scale(1/1.2,1/1.2);
}
