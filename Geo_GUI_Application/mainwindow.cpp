#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deledit = false;
    delmini = false;
    image = false;
    //w = new GaGraphicsView();
    //ui->centralWidget->setMouseTracking(true);
    //QWidget::connect (this->w, SIGNAL(sendMousePoint(QPointF)),this, SLOT(setMousePoint(QPointF)));

    QTimer::singleShot(0, this, SLOT(showMaximized()));
    ui->horizontalLayout_7->addWidget(ui->graphicsView);
    ui->Btn_Do->setHidden(1);
    ui->Btn_Undo->setHidden(1);
    ui->Btn_Move->setHidden(1);
    ui->Btn_Add_Point->setHidden(1);
    ui->Btn_Del_Point->setHidden(1);
    ui->Btn_Zoom_In->setToolTip("Zoom In");
    ui->Btn_Edit->setToolTip("Edit");
    ui->Btn_Zoom_Out->setToolTip("Zoom Out");
    scene = new QGraphicsScene(this);
    editscene = new QGraphicsScene(this);



}

MainWindow::~MainWindow()
{
    if(deledit){
        delete edit;
    }
    if(delmini){
        delete minimap;
        delete miniscene;
    }
    delete scene;
    delete editscene;
    delete ui;

}


void MainWindow::on_actionLoad_Project_triggered()
{
    QString project_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    QMessageBox::information(this,"..",project_name);
}

void MainWindow::on_actionAdd_Image_triggered()
{
    //delete w;
    //ui->centralWidget->setMouseTracking(true);
    //QWidget::connect (this->w, SIGNAL(sendMousePoint(QPointF)),this, SLOT(setMousePoint(QPointF)));

    QString image_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(image_name != ""){
        image = true;
        QMessageBox::information(this,"..",image_name);
        //QImage img;
        //int gw = ui->graphicsView->width();
        //int gh = ui->graphicsView->height();
        pix.load(image_name);
        minipix.load(image_name);
        //img.load(image_name);
        //pix = pix.scaledToHeight(gh);
        //pix = pix.scaledToWidth(gw);
        scene->addPixmap(pix);
        scene->setSceneRect(pix.rect());//QRectF(0,0,gw-1,gh-1));

        //int w = pix.rect().x();
        //int h = pix.rect().y();
        //ui->imagelabel->setPixmap(pix.scaled(h,w,Qt::KeepAspectRatio));
        //ui->imagelabel->show();
        ui->graphicsView->setScene(scene);
        //QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
        edit = new GaGraphicsView();
        deledit = true;
        proxyedit = new QGraphicsProxyWidget();

        edit->setGeometry(pix.rect());
        //edit->setHidden(true);
        edit->setStyleSheet("background-color: rgba(200,0,0,0.1)");
        edit->setSceneG(editscene);
        edit->setToggle(false);
        edit->setAttribute(Qt::WA_AcceptTouchEvents);
        QVBoxLayout *layoutedit = new QVBoxLayout(edit);
        layoutedit->setAlignment(Qt::AlignRight | Qt::AlignTop);
        //probar anidar
        proxyedit->setAcceptTouchEvents(true);
        proxyedit->setWidget(edit);
        scene->addItem(proxyedit);
        ui->centralWidget->setMouseTracking(true);
        edit->setToggle(true);
    }

}


void MainWindow::ZoomIn(double h, double w){
    ui->graphicsView->scale(h,w);
}
void MainWindow::ZoomOut(double h, double w){
    ui->graphicsView->scale(h,w);
}

void MainWindow::on_Btn_Edit_clicked(bool checked)
{
    if(checked){
        if(image){

            edit->setToggle(true);
            edit->setPaint(0);
        }
        ui->Btn_Do->setHidden(!checked);
        ui->Btn_Undo->setHidden(!checked);
        ui->Btn_Move->setHidden(!checked);
        ui->Btn_Add_Point->setHidden(!checked);
        ui->Btn_Del_Point->setHidden(!checked);
        ui->Btn_Do->setToolTip("Redo");
        ui->Btn_Undo->setToolTip("Undo");
        ui->Btn_Move->setToolTip("Move & Split");
        ui->Btn_Add_Point->setToolTip("Add");
        ui->Btn_Del_Point->setToolTip("Delete & Join");
    }else{
        if(image){

            ui->centralWidget->setMouseTracking(false);
            edit->setToggle(false);
            edit->setPaint(0);
        }
        //w->setStyleSheet("background-color: rgba(200,0,0,0.1)");
        ui->Btn_Do->setHidden(!checked);
        ui->Btn_Undo->setHidden(!checked);
        ui->Btn_Move->setHidden(!checked);
        ui->Btn_Add_Point->setHidden(!checked);
        ui->Btn_Del_Point->setHidden(!checked);
    }
}

void MainWindow::on_Btn_Zoom_In_clicked()
{   if(image)this->ZoomIn(1.2,1.2);
}

void MainWindow::on_Btn_Zoom_Out_clicked()
{
    if(image)this->ZoomOut(1/1.2,1/1.2);
}

void MainWindow::setMousePoint (QPointF point){

};

void MainWindow::on_Btn_Del_Point_clicked()
{
    if(image)this->edit->setPaint(2);
}

void MainWindow::on_Btn_Add_Point_clicked()
{
    if(image)this->edit->setPaint(1);
}

void MainWindow::on_actionMiniMap_triggered(bool tiggered)
{   if(image){
    if(tiggered){
        minimap = new QGraphicsView();
        minimap->setDragMode(QGraphicsView::NoDrag);
        delmini = true;
        //proxymini = new QGraphicsProxyWidget();
        //int aspectratio = pix.width()/pix.height();
        minipix = minipix.scaled(450,300,Qt::KeepAspectRatio);
        minimap->setGeometry(QRect(900,0,450,300));
        miniscene = new QGraphicsScene(this);
        miniscene->addPixmap(minipix);
        miniscene->setSceneRect(minipix.rect());
        minimap->setScene(miniscene);
        //minimap->setStyleSheet("background-color: rgba(200,0,0,255)");
        QVBoxLayout *layoutmini = new QVBoxLayout(minimap);
        layoutmini->setAlignment(Qt::AlignRight | Qt::AlignTop);
        minimap->setParent(ui->graphicsView);
        minimap->show();
        //proxymini->setWidget(minimap);
        //scene->addItem(proxymini);
    }else{
        delmini = false;
        delete minimap;
        //delete miniscene;
        //scene->removeItem(proxymini);

    }}else{
        ui->actionMiniMap->setChecked(false);
    }
}

void MainWindow::on_Group0_clicked(bool checked)
{
    if(image){
        if(checked){
            edit->setGroup(0);
        }

    }

}

void MainWindow::on_Group1_clicked(bool checked)
{
    if(image){
        if(checked){
            edit->setGroup(1);

        }

    }
}


void MainWindow::on_Group2_clicked(bool checked)
{
    if(image){
        if(checked ){
            edit->setGroup(2);

        }

    }
}



void MainWindow::on_Group3_clicked(bool checked)
{
    if(image){
        if(checked ){
            edit->setGroup(3);

        }

    }
}


void MainWindow::on_Group4_clicked(bool checked)
{    if(image){
        if(checked ){
            edit->setGroup(4);

        }

    }

}


void MainWindow::on_Group5_clicked(bool checked)
{    if(image){
        if(checked ){
            edit->setGroup(5);

        }

    }

}


void MainWindow::on_Group6_clicked(bool checked)
{    if(image){
        if(checked ){
            edit->setGroup(6);

        }

    }

}


void MainWindow::on_Group7_clicked(bool checked)
{    if(image){
        if(checked ){
            edit->setGroup(7);

        }

    }

}




void MainWindow::on_Btn_Undo_pressed()
{
    if(image)edit->removeLastPoint();
}

void MainWindow::on_Btn_Do_clicked()
{
    if(image)edit->redoLastPoint();
}

void MainWindow::on_Btn_Move_clicked()
{
    if(image)this->edit->setPaint(3);

}


void MainWindow::on_Visibility0_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(0,checked);
}

void MainWindow::on_Visibility1_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(1,checked);
}

void MainWindow::on_Visibility2_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(2,checked);
}

void MainWindow::on_Visibility3_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(3,checked);
}

void MainWindow::on_Visibility4_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(4,checked);
}

void MainWindow::on_Visibility5_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(5,checked);
}

void MainWindow::on_Visibility6_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(6,checked);
}

void MainWindow::on_Visibility7_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(7,checked);
}
