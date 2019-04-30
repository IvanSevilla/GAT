#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MESSAGE \
    Dialog::tr("<p>Message boxes have a caption, a text, " \
               "and any number of buttons, each with standard or custom texts." \
               "<p>Click a button to close the message box. Pressing the Esc button " \
               "will activate the detected escape button (if any).")
#define MESSAGE_DETAILS \
    Dialog::tr("If a message box has detailed text, the user can reveal it " \
               "by pressing the Show Details... button.")


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
    this->ui->polilines->setHidden(1);
    this->ui->labelPolilines->setHidden(1);
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
        edit->setUpdater(ui->showPolilines);
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
    if(image){
        if(checked){
            edit->setToggle(true);
            edit->setPaint(0);
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
            ui->centralWidget->setMouseTracking(false);
            edit->setToggle(false);
            edit->setPaint(0);
            //w->setStyleSheet("background-color: rgba(200,0,0,0.1)");
            ui->Btn_Do->setHidden(!checked);
            ui->Btn_Undo->setHidden(!checked);
            ui->Btn_Move->setHidden(!checked);
            ui->Btn_Add_Point->setHidden(!checked);
            ui->Btn_Del_Point->setHidden(!checked);
        }
    }else{
        ui->Btn_Edit->setChecked(false);
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
    if(image){
        this->edit->setPaint(2);
        this->ui->Btn_Move->setChecked(false);
        this->ui->Btn_Add_Point->setChecked(false);
        this->ui->Btn_Del_Point->setChecked(true);
    }else{
        this->ui->Btn_Del_Point->setChecked(false);
    }
}

void MainWindow::on_Btn_Add_Point_clicked()
{
    if(image){
        this->edit->setPaint(1);
        this->ui->Btn_Move->setChecked(false);
        this->ui->Btn_Add_Point->setChecked(true);
        this->ui->Btn_Del_Point->setChecked(false);
    }else{
        this->ui->Btn_Add_Point->setChecked(false);
    }
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
            unSelectPoliline();
            edit->setGroup(0);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }

}

void MainWindow::on_Group1_clicked(bool checked)
{
    if(image){
        if(checked){
            unSelectPoliline();
            edit->setGroup(1);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }
}


void MainWindow::on_Group2_clicked(bool checked)
{
    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(2);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }
}



void MainWindow::on_Group3_clicked(bool checked)
{
    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(3);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }
}


void MainWindow::on_Group4_clicked(bool checked)
{    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(4);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }

}


void MainWindow::on_Group5_clicked(bool checked)
{    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(5);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }

}


void MainWindow::on_Group6_clicked(bool checked)
{    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(6);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }

}


void MainWindow::on_Group7_clicked(bool checked)
{    if(image){
        if(checked ){
            unSelectPoliline();
            edit->setGroup(7);
            ui->polilines->clear();
            ui->showPolilines->clicked(true);
        }

    }

}

void MainWindow::unSelectPoliline(){
    ui->showPolilines->setChecked(false);
    ui->showPolilines->clicked();
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
    if(image){
        this->edit->setPaint(3);
        this->ui->Btn_Move->setChecked(true);
        this->ui->Btn_Add_Point->setChecked(false);
        this->ui->Btn_Del_Point->setChecked(false);
    }else{
        this->ui->Btn_Move->setChecked(false);
    }

}


void MainWindow::on_Visibility0_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(0,checked);
    else {
        this->ui->Visibility0->setChecked(true);
    }
}

void MainWindow::on_Visibility1_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(1,checked);
    else {
        this->ui->Visibility1->setChecked(true);
    }
}

void MainWindow::on_Visibility2_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(2,checked);
    else {
        this->ui->Visibility2->setChecked(true);
    }
}

void MainWindow::on_Visibility3_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(3,checked);
    else {
        this->ui->Visibility3->setChecked(true);
    }
}

void MainWindow::on_Visibility4_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(4,checked);
    else {
        this->ui->Visibility4->setChecked(true);
    }
}

void MainWindow::on_Visibility5_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(5,checked);
    else {
        this->ui->Visibility5->setChecked(true);
    }
}

void MainWindow::on_Visibility6_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(6,checked);
    else {
        this->ui->Visibility6->setChecked(true);
    }
}

void MainWindow::on_Visibility7_clicked(bool checked)
{
    if(image)this->edit->setGroupVisibility(7,checked);
    else {
        this->ui->Visibility7->setChecked(true);
    }
}

void MainWindow::on_showPolilines_clicked(bool checked)
{
    if(image){
        if(checked){
            if(this->ui->showPolilines->isChecked()){
                ui->polilines->clear();
                QList<CustomElipse*>* _p= edit->getCurrentGroupPolilines();
                qDebug()<<_p->size();
                if(!_p->isEmpty() || _p->size()!=0){
                    this->ui->polilines->setHidden(!checked);
                    this->ui->labelPolilines->setHidden(!checked);
                    for(int i = 0;i<_p->length();i++){
                        QString _line = "Line "+QString::number(i+1);
                        ui->polilines->addItem(_line);
                        ui->polilines->item(i)->setWhatsThis(QString::number(i));
                    }
                    this->ui->showPolilines->setChecked(true);
                }else{
                    this->ui->showPolilines->setChecked(false);
                    this->ui->polilines->setHidden(true);
                    this->ui->labelPolilines->setHidden(true);
                }
            }else{
                this->ui->polilines->setHidden(1);
                ui->polilines->clear();
                this->ui->labelPolilines->setHidden(1);
                this->ui->showPolilines->setChecked(false);
            }
        }else{
            this->ui->polilines->setHidden(!checked);
            ui->polilines->clear();
            this->ui->labelPolilines->setHidden(!checked);
            this->ui->showPolilines->setChecked(false);
        }
    }else{
        this->ui->showPolilines->setChecked(false);
    }
}

void MainWindow::on_actionDelete_Poliline_triggered()
{
    if(image){
            Dialog* _d = new Dialog();
            bool _dp = _d->questionMessage("This action cannot be undone");
            if(_dp){
                //qDebug()<<"Borra";
                QString _log = "DELETE POLILINE NUM:";
                _log = _log + ui->polilines->currentItem()->toolTip();
                QByteArray ba = _log.toLocal8Bit();
                const char* c_str = ba.data();
                edit->WriteLogFile(c_str);
            }else{
                //qDebug()<<"no";

    }

    }
}
void MainWindow::on_polilines_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    //qDebug()<<"hey";
    if(current != nullptr){
        CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(current->whatsThis().toInt());
        while (_poli->hasFinalLine()){
            _poli->setPen(QPen(QColor(0,0,0)));
            _poli->setBrush(QBrush(QColor(0,0,0)));
            _poli->getFinalLine()->setPen(QPen(QColor(0,0,0)));
            _poli= _poli->getFinalLine()->getInit();
        }
        _poli->setPen(QPen(QColor(0,0,0)));
        _poli->setBrush(QBrush(QColor(0,0,0)));
    }
    if (previous != nullptr){
        if(previous->whatsThis().toInt()<=7 && previous->whatsThis().toInt()>=0){
            //qDebug()<<"has another";
            CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(previous->whatsThis().toInt());
            while (_poli->hasFinalLine()){
                _poli->setPen(QPen(edit->getCurrentColor()));
                _poli->setBrush(QBrush(edit->getCurrentColor()));
                _poli->getFinalLine()->setPen(QPen(edit->getCurrentColor()));
                _poli= _poli->getFinalLine()->getInit();
            }
            _poli->setPen(QPen(edit->getCurrentColor()));
            _poli->setBrush(QBrush(edit->getCurrentColor()));
        }
    }
}

// DIALOG
Dialog::Dialog(QWidget *parent)
    : QWidget(parent){}
void Dialog::criticalMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("QMessageBox::critical()"),
                                    MESSAGE,
                                    QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    if (reply == QMessageBox::Abort)
        criticalLabel->setText(tr("Abort"));
    else if (reply == QMessageBox::Retry)
        criticalLabel->setText(tr("Retry"));
    else
        criticalLabel->setText(tr("Ignore"));
}

void Dialog::informationMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("QMessageBox::information()"), MESSAGE);
    if (reply == QMessageBox::Ok)
        informationLabel->setText(tr("OK"));
    else
        informationLabel->setText(tr("Escape"));
}

bool Dialog::questionMessage(const char* _message)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                    _message,
                                    QMessageBox::Yes | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        return true;
    else
        return false;
}

void Dialog::warningMessage()
{
    QMessageBox msgBox(QMessageBox::Warning, tr("QMessageBox::warning()"),
                       MESSAGE, 0, this);
    msgBox.setDetailedText(MESSAGE_DETAILS);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole)
        warningLabel->setText(tr("Save Again"));
    else
        warningLabel->setText(tr("Continue"));

}




