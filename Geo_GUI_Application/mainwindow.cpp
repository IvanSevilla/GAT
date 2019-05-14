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
    openProject();
}
void MainWindow::saveFile(){
    qDebug()<<project.dump().c_str();
    _pm.saveProject(filename+"project.json",project);
    saveSubproject();
}
void MainWindow::openProject(){

    filename = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(filename != ""){
        if(!project.empty()){
            saveFile();
            project.clear();
            subproject.clear();
        }
        project = _pm.loadProject(filename);
        subproject = _pm.loadProject(QString(project.at("0").get<std::string>().c_str()));
        std::string d = subproject.at("image").get<std::string>();
        QFileInfo _f(filename);
        filename = _f.absolutePath()+"/";
        openImage(d.c_str());
    }
}
void MainWindow::saveSubproject()
{
    for(int j = 0; j<MAX_GROUPS;j++){
        QList<CustomElipse*>* _list = edit->getPolilines(j);
        if(!_list->empty()){
            for (int i = 0; i<_list->length();i++){
                CustomElipse* _last = _list->value(i);
                QList<std::array<qreal,2>> _savedpoints;
                while(_last->hasFinalLine()){
                    std::array<qreal,2> _a = {_last->getCenter().x(),_last->getCenter().y()};
                    _savedpoints.push_back(_a);
                    _last= _last->getFinalLine()->getInit();
                }
                std::array<qreal,2> _a = {_last->getCenter().x(),_last->getCenter().y()};
                _savedpoints.push_back(_a);
                subproject["polylines"]["group"+std::to_string(j)]["line"+std::to_string(i)] = _savedpoints.toStdList();
            }
        }else{
            subproject["polylines"]["group"+std::to_string(j)] ={};
        }
    }
    std::string _filename;
    if(filename!= ""){
        QFileInfo _f(filename);
        _filename = _f.dir().path().toStdString()+"/subproject"+std::to_string(this->currentSubproject)+".json";
    }else{
        _filename += "/subproject"+std::to_string(this->currentSubproject)+".json";
    }
    _pm.saveProject(QString(_filename.c_str()),subproject);

}



void MainWindow::on_actionAdd_Image_triggered()
{
    QString image_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(image_name != ""){
        if(project.empty()){
        std::string _filename;
#if defined(_WIN32) || defined(_WIN64)
_filename = "C:/Documents/GATProjects/Project"
if(QDir(_filename)){

}
#endif
#if defined(__unix) || defined(__unix__)
#endif
#if defined( __APPLE__ ) || defined(__MACH__)
    _filename = "../../../../GATProjects";
    QDir _directory(".");
    if(!_directory.exists(_filename.c_str())){
        _directory.mkdir(_filename.c_str());
    }
    _filename+="/Project";
        if(!_directory.exists(_filename.c_str())){
            _directory.mkdir(_filename.c_str());
            _filename+="/";
            filename = _filename.c_str();
        }else{
            for(int i = 0;;i++){
                std::string _pr = _filename+std::to_string(i);
                if(!_directory.exists(_pr.c_str())){
                    _directory.mkdir(_pr.c_str());
                    _filename=_pr+"/";
                    filename = _filename.c_str();
                    break;
            }
        }
        }
#endif
#ifdef __linux__
qDebug()<<"_filename";
#endif
        QFileInfo _dir(filename);
        project["0"]=_dir.absolutePath().toStdString()+"/subproject0.json";
        }

        if(subproject.empty()){
            createSubproject(image_name);

        }else{
            saveSubproject();
            QFileInfo _directory(filename);
            project[std::to_string(currentSubproject)] =_directory.absolutePath().toStdString()+"/subproject"+std::to_string(currentSubproject)+".json";
            if(filename != "")saveFile();
            currentSubproject++;
            createSubproject(image_name);
            project[std::to_string(currentSubproject)] = _directory.absolutePath().toStdString()+"/subproject"+std::to_string(currentSubproject)+".json";
            scene->clear();
            edit->getScene()->clear();
            edit->getAllPolilines().clear();
        }

        openImage(image_name);
    }

    }

void MainWindow::openImage(QString image_name){
    if(image){
        delete(proxyedit);
        scene->clear();
    }else{
        image = true;
    }

    QMessageBox::information(this,"..",image_name);
    pix.load(image_name);
    minipix.load(image_name);
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());


    ui->graphicsView->setScene(scene);
    edit = new CustomGraphicsView();
    deledit = true;
    proxyedit = new QGraphicsProxyWidget();

    edit->setGeometry(pix.rect());
    edit->CreateLogFile();
    edit->setStyleSheet("background-color: rgba(255,255,255,0.001)");
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
    if(!subproject.empty()){
        for(int i = 0; i<MAX_GROUPS;i++){
            std::string g = "group"+std::to_string(i);
            if(!subproject.at("polylines").at(g).empty()){
                u_long size = subproject.at("polylines").at(g).size();
                for(u_long _i = 0;_i<size; _i++){
                    QMessageBox::information(this,"..",std::to_string(subproject.at("polylines").at(g).at("line"+std::to_string(_i)).size()).c_str());
                    auto a = subproject.at("polylines").at(g).at("line"+std::to_string(_i));
                    CustomElipse* last;
                    for(u_long k = 0; k<a.size();k++){
                        CustomElipse* _ce = new CustomElipse();
                        QPoint _point(a[k][0].get<qreal>(),a[k][1].get<qreal>());
                        _ce->setCenter(_point);
                        _ce->setPen(QPen(edit->getGroupColor(i)));
                        _ce->setBrush(QBrush(edit->getGroupColor(i)));
                        _ce->setRect(_point.x()-2,_point.y()-2,4,4);
                        _ce->setGroupNumber(i);
                        _ce->setFlag(QGraphicsItem::ItemIsMovable,true);
                        _ce->setFlag(QGraphicsItem::ItemIsSelectable,true);
                        _ce->setFlag(QGraphicsItem::ItemClipsToShape,true);
                        edit->getScene()->addItem(_ce);
                        edit->getGroup(i).data()->addToGroup(_ce);
                        if(k == 0){
                            edit->addPolylineGroup(i,_ce);
                            last = _ce;
                        }else{
                            CustomLine* _li = new CustomLine();
                            _li->setFinal(_ce);
                            _li->setInitial(last);
                            _li->setPen(QPen(edit->getGroupColor(i)));
                            last->setInitLine(_li);
                            _ce->setFinalLine(_li);
                            edit->getScene()->addItem(_li);
                            edit->getGroup(i).data()->addToGroup(_li);
                            if(k == a.size()-1){

                                last = nullptr;
                                delete(last);
                            }else{
                                last = _ce;
                            }
                        }


                    }
                }
            }
        }
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
        minipix = minipix.scaled(450,300,Qt::KeepAspectRatio);
        minimap->setGeometry(QRect(900,0,450,300));
        miniscene = new QGraphicsScene(this);
        miniscene->addPixmap(minipix);
        miniscene->setSceneRect(minipix.rect());
        minimap->setScene(miniscene);
        QVBoxLayout *layoutmini = new QVBoxLayout(minimap);
        layoutmini->setAlignment(Qt::AlignRight | Qt::AlignTop);
        minimap->setParent(ui->graphicsView);
        minimap->show();
    }else{
        delmini = false;
        delete minimap;

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
                QList<CustomElipse*>* _curr = edit->getCurrentGroupPolilines();
                QColor _c = edit->getCurrentColor();
                _c.setAlphaF(0.5);
                for (int i = 0; i<_curr->length();i++){
                    CustomElipse* _last = _curr->value(i);
                    while(_last->hasFinalLine()){

                        _last->setPen(QPen(_c));
                        _last->setBrush(QBrush(_c));
                        _last->getFinalLine()->setPen(QPen(_c));
                        _last= _last->getFinalLine()->getInit();
                    }
                    _last->setPen(QPen(_c));
                    _last->setBrush(QBrush(_c));
                }
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
                    QString _log = "DELETE POLILINE NUM: ";
                    _log = _log + ui->polilines->currentItem()->whatsThis();
                    QByteArray ba = _log.toLocal8Bit();
                    const char* c_str = ba.data();
                    edit->WriteLogFile(c_str);
                    CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(ui->polilines->currentItem()->whatsThis().toInt());
                    CustomElipse* _last;
                    while(_poli->hasFinalLine()){
                        qDebug()<<_poli->hasFinalLine();
                        _last = _poli->getFinalLine()->getInit();
                        edit->getScene()->removeItem(_poli);
                        edit->getScene()->removeItem(_poli->getFinalLine());
                        delete(_poli->getFinalLine());
                        delete(_poli);

                        if(_last != nullptr){
                            _poli = _last;
                        }else{
                            break;
                        }
                    }
                    delete(_poli);
                    edit->getCurrentGroupPolilines()->replace(ui->polilines->currentItem()->whatsThis().toInt(),nullptr);

                    ui->showPolilines->clicked();


            }

    }
}
void MainWindow::on_polilines_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current != nullptr){
        CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(current->whatsThis().toInt());
        while (_poli->hasFinalLine()){
            _poli->setPen(QPen(edit->getCurrentColor()));
            _poli->setBrush(QBrush(edit->getCurrentColor()));
            _poli->getFinalLine()->setPen(QPen(edit->getCurrentColor()));
            _poli= _poli->getFinalLine()->getInit();
        }
        _poli->setPen(QPen(edit->getCurrentColor()));
        _poli->setBrush(QBrush(edit->getCurrentColor()));
    }
    if (previous != nullptr){
        if(previous->whatsThis().toInt()<=50000 && previous->whatsThis().toInt()>=0){
            CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(previous->whatsThis().toInt());
            if(_poli != nullptr){
                QColor _c = edit->getCurrentColor();
                _c.setAlphaF(0.5);
                while (_poli->hasFinalLine()){

                    _poli->setPen(QPen(_c));
                    _poli->setBrush(QBrush(_c));
                    _poli->getFinalLine()->setPen(QPen(_c));
                    _poli= _poli->getFinalLine()->getInit();
                }
                _poli->setPen(QPen(_c));
                _poli->setBrush(QBrush(_c));
            }else{
                edit->getCurrentGroupPolilines()->removeAt(previous->whatsThis().toInt());
            }
        }
    }
}


void MainWindow::on_actionSave_Project_triggered()
{   if(image){
        if(filename == ""){
            //QFileInfo f(filename);
            //qDebug()<<f.dir().path();
            filename = QFileDialog::getSaveFileName(this, "Save file");
        }
        saveFile();
    }
}



void MainWindow::on_actionNewProject_triggered()
{

    if(!project.empty()){
        Dialog d;
        bool save = d.warningMessage();
        if(save)saveFile();
    }
    project.clear();
    project["0"]="../../../subproject0.json";

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

bool Dialog::warningMessage()
{
    QMessageBox msgBox(QMessageBox::Warning, tr("QMessageBox::warning()"),
                       MESSAGE, 0, this);
    msgBox.setDetailedText(MESSAGE_DETAILS);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole)
        return false;
    else
        return true;

}

