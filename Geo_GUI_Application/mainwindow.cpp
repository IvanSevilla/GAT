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

    //ui->verticalLayout_5->addWidget(ui->graphicsView);
    ui->Btn_Do->setDisabled(1);
    ui->Btn_Undo->setDisabled(1);
    ui->Btn_Move->setDisabled(1);
    ui->Btn_Add_Point->setDisabled(1);
    ui->Btn_Del_Point->setDisabled(1);
    ui->Btn_Zoom_In->setToolTip("Zoom In");
    ui->Btn_Edit->setToolTip("Edit");
    ui->Btn_Zoom_Out->setToolTip("Zoom Out");
    this->ui->polilines->setHidden(1);
    this->ui->labelPolilines->setHidden(1);

    scene = new QGraphicsScene(this);
    editscene = new QGraphicsScene(this);
    PointCloud = new pcl::PointCloud<pcl::PointXYZ>();



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
    _pm.saveProject(filename,project);
    saveSubproject();
}
void MainWindow::openProject(){

    filename = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(filename != ""){
        if(!project.empty()){
            project.clear();
            subproject.clear();
            this->currentSubproject = 0;
        }
        project = _pm.loadProject(filename);
        subproject = _pm.loadProject(QString(project.at("0").get<std::string>().c_str()));
        if(subproject.at("pointcloud") != ""){
            _pm.readPointCloud(PointCloud,subproject.at("pointcloud").get<std::string>().c_str());
            std::vector<pcl::PointXYZ> _testing;
            pcl::PointXYZ first(401134.00f,4606022.00f,954.93f);
            _testing.push_back(first);
            pcl::PointXYZ second(401238.00f, 4606022.00f, 944.29f);
            _testing.push_back(second);
            pcl::PointXYZ third(401252.00f,4606022.00f, 937.47f);
            _testing.push_back(third);
            pcl::PointXYZ first_2(401354.00f, 4606022.00f, 907.37f);
            _testing.push_back(first_2);
            pcl::PointXYZ second_2(401262.00f, 4606018.00f, 930.44f);
            _testing.push_back(second_2);
            pcl::PointXYZ third_2(401194.00f, 4606008.00f, 949.06f);
            _testing.push_back(third_2);
            FittingPlane _f;
            _f.planeCalc(_testing);
        }
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
        //qDebug()<<_list->size();

        if(!_list->empty()){
            for (int i = 0; i<_list->length();i++){
                //qDebug()<<i;
                CustomElipse* _last = _list->at(i);
                QList<std::array<qreal,2>> _savedpoints;
                //qDebug()<<_last->hasFinalLine();
                while(_last->hasFinalLine()){
                    //qDebug()<<_last->hasFinalLine();
                    //qDebug()<<_last->getCenter().x()<<" "<<_last->getCenter().y();
                    std::array<qreal,2> _a = {_last->getCenter().x(),_last->getCenter().y()};
                    _savedpoints.push_back(_a);
                    _last= _last->getFinalLine()->getInit();
                }
                std::array<qreal,2> _a = {_last->getCenter().x(),_last->getCenter().y()};
                _last = nullptr;
                _savedpoints.push_back(_a);
                if(!subproject["polylines"]["group"+std::to_string(j)]["line"+std::to_string(i)].empty()){
                    subproject.at("polylines").at("group"+std::to_string(j)).clear();
                }
                subproject["polylines"]["group"+std::to_string(j)]["line"+std::to_string(i)] = _savedpoints.toStdList();

            }
        }else{
            subproject["polylines"]["group"+std::to_string(j)] ={};
        }
    }
    std::string _filename;
    if(filename!= ""){
        QDir _dir(".");
        QFileInfo _f(filename);
        _filename = _dir.relativeFilePath(_f.dir().path()).toStdString()+"/subproject"+std::to_string(this->currentSubproject)+".json";
    }else{
        _filename += "/subproject"+std::to_string(this->currentSubproject)+".json";
    }
    qDebug()<<subproject.dump().c_str();
    qDebug()<<_filename.c_str();
    _pm.saveProject(QString(_filename.c_str()),subproject);


}



void MainWindow::on_actionAdd_Image_triggered()
{
    QString image_name = QFileDialog::getOpenFileName(this,"Open File",QDir::homePath());
    if(image_name != ""){
        if(project.empty()){
        std::string _filename;
#if defined(_WIN32) || defined(_WIN64)
        _filename = "../GATProjects";
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
        QDir _dir(".");
        QFileInfo _f(filename);
        project["0"]=_dir.relativeFilePath(_f.dir().path()).toStdString()+"/subproject0.json";
        qDebug()<<project.dump().c_str();
        filename+="project.json";
        currentSubproject = 0;
        }

        if(subproject.empty()){
            createSubproject(image_name);
            currentSubproject = 0;
        }else{
            saveSubproject();
            QDir _dir(".");
            QFileInfo _directory(filename);
            project[std::to_string(currentSubproject)] =_dir.relativeFilePath(_directory.absolutePath()).toStdString()+"/subproject"+std::to_string(currentSubproject)+".json";
            if(filename != "")saveFile();
            qDebug()<<currentSubproject;


            createSubproject(image_name);
            currentSubproject = static_cast<int>(project.size());
            qDebug()<<currentSubproject;
            project[std::to_string(currentSubproject)] = _dir.relativeFilePath(_directory.absolutePath()).toStdString()+"/subproject"+std::to_string(currentSubproject)+".json";

        }

        openImage(image_name);
    }

    }

void MainWindow::openImage(QString image_name){
    if(image){
        scene->removeItem(proxyedit);
        edit->clear();
        delete(proxyedit);
        scene->clear();

        this->ui->Btn_Edit->setChecked(false);
        this->ui->Btn_Add_Point->setChecked(false);
        this->ui->Btn_Del_Point->setChecked(false);
        this->ui->Btn_Move->setChecked(false);


    }else{
        image = true;


    }

    pix.load(image_name);
    minipix.load(image_name);
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());
    ui->graphicsView->setScene(scene);
    stereoScene= new QGraphicsScene();
    ui->graphicsView_2->setScene(stereoScene);
    stereoScene->addEllipse(0,0,260,260,QPen(QColor(175,175,175)),QBrush(QColor(175,175,175),Qt::SolidPattern));
    stereoScene->addEllipse(120,130,8,8,QPen(QColor(228,26,28)),QBrush(QColor(228,26,28),Qt::SolidPattern));
    stereoScene->addEllipse(125,125,8,8,QPen(QColor(228,26,28)),QBrush(QColor(228,26,28),Qt::SolidPattern));
    stereoScene->addEllipse(100,230,8,8,QPen(QColor(55,126,184)),QBrush(QColor(55,126,184),Qt::SolidPattern));
    stereoScene->addEllipse(125,225,8,8,QPen(QColor(55,126,184)),QBrush(QColor(55,126,184),Qt::SolidPattern));
    edit = new CustomGraphicsView();
    deledit = true;
    proxyedit = new QGraphicsProxyWidget();

    QVBoxLayout *layoutedit = new QVBoxLayout(edit);
    layoutedit->setAlignment(Qt::AlignRight | Qt::AlignTop);
    //probar anidar
    edit->setGeometry(pix.rect());

    edit->CreateLogFile();
    edit->setStyleSheet("background-color: rgba(255,255,255,0.001)");
    edit->setSceneG(editscene);
    edit->setToggle(false);
    edit->setAttribute(Qt::WA_AcceptTouchEvents);
    edit->setUpdater(ui->showPolilines);
    ui->centralWidget->setMouseTracking(true);
    edit->setToggle(true);
    proxyedit->setAcceptTouchEvents(true);
    proxyedit->setWidget(edit);
    scene->addItem(proxyedit);

    if(!subproject.empty()){
        for(int i = 0; i<MAX_GROUPS;i++){
            std::string g = "group"+std::to_string(i);
            if(!subproject.at("polylines").at(g).empty()){
                u_long size = static_cast<ulong>(subproject.at("polylines").at(g).size());
                for(u_long _i = 0;_i<size; _i++){
                    auto a = subproject.at("polylines").at(g).at("line"+std::to_string(_i));
                    CustomElipse* last;
                    //qDebug()<<i;
                    for(u_long k = 0; k<a.size();k++){
                        CustomElipse* _ce = new CustomElipse();

                        //qDebug()<<a[k][0].get<qreal>()<<" "<<a[k][1].get<qreal>();
                        QPoint _point(a[k][0].get<int>(),a[k][1].get<int>());
                        _ce->setCenter(_point);
                        _ce->setPen(QPen(edit->getGroupColor(i)));
                        _ce->setBrush(QBrush(edit->getGroupColor(i)));
                        _ce->setRect(_point.x()-2,_point.y()-2,4,4);
                        _ce->setGroupNumber(i);
                        _ce->setFlag(QGraphicsItem::ItemIsMovable,true);
                        _ce->setFlag(QGraphicsItem::ItemIsSelectable,true);
                        _ce->setFlag(QGraphicsItem::ItemClipsToShape,true);
                        edit->getScene()->addItem(_ce);
                        edit->getGroup(i)->addToGroup(_ce);
                        if(k == 0){
                            last = _ce;
                            edit->addPolylineGroup(i,_ce);
                        }else{
                            CustomLine* _li = new CustomLine();
                            _li->setFinal(last);
                            _li->setInitial(_ce);
                            _li->setPen(QPen(edit->getGroupColor(i)));
                            _ce->setInitLine(_li);
                            last->setFinalLine(_li);
                            edit->getScene()->addItem(_li);
                            edit->getGroup(i)->addToGroup(_li);
                            if(k == a.size()-1){
                                last = nullptr;
                                delete(last);
                            }else{
                                last = _ce;
                                _ce = nullptr;
                                _li = nullptr;
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
            ui->Btn_Do->setEnabled(true);
            ui->Btn_Undo->setEnabled(true);
            ui->Btn_Move->setEnabled(true);
            ui->Btn_Add_Point->setEnabled(true);
            ui->Btn_Del_Point->setEnabled(true);
            ui->Btn_Do->setToolTip("Redo");
            ui->Btn_Undo->setToolTip("Undo");
            ui->Btn_Move->setToolTip("Move & Split");
            ui->Btn_Add_Point->setToolTip("Add");
            ui->Btn_Del_Point->setToolTip("Delete & Join");
        }else{
            ui->centralWidget->setMouseTracking(false);
            edit->setToggle(false);
            edit->setPaint(0);
            ui->Btn_Do->setDisabled(!checked);
            ui->Btn_Undo->setDisabled(!checked);
            ui->Btn_Move->setDisabled(!checked);
            ui->Btn_Add_Point->setDisabled(!checked);
            ui->Btn_Del_Point->setDisabled(!checked);
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

void MainWindow::createSubproject(QString image){
    QFileInfo _f(filename);
    QDir _dir(".");
    QFileInfo _im(image);
    _img.load(image);
    QDir _d(_f.absolutePath());
    if(!_d.exists("assets"))_d.mkdir("assets");
    subproject["image"] = _dir.relativeFilePath(_f.absolutePath()).toStdString()+"/assets/"+_im.fileName().toStdString();
    _img.save(subproject.at("image").get<std::string>().c_str());
    subproject["matrix"] = "";
    subproject["calibration"] = "";
    if(!_d.exists("matrix"))_d.mkdir("matrix");
    if(!_d.exists("calibration"))_d.mkdir("calibration");
    subproject["pointcloud"] = "";
    if(!_d.exists("pointcloud"))_d.mkdir("pointcloud");
    subproject["polylines"] = {};
    for(int i = 0; i<MAX_GROUPS;i++){
        subproject["polylines"]["group"+std::to_string(i)] = {};
    }
}

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
                //qDebug()<<_p->size();
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
            Dialog _d;
            bool _dp = _d.questionMessage("This action cannot be undone");
            if(_dp){
                    QString _log = "DELETE POLILINE NUM: ";
                    _log = _log + ui->polilines->currentItem()->whatsThis();
                    QByteArray ba = _log.toLocal8Bit();
                    const char* c_str = ba.data();
                    edit->WriteLogFile(c_str);
                    CustomElipse* _poli = edit->getCurrentGroupPolilines()->value(ui->polilines->currentItem()->whatsThis().toInt());
                    CustomElipse* _last;
                    while(_poli->hasFinalLine()){
                        //qDebug()<<_poli->hasFinalLine();
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
        if(save){
            saveFile();
        }
        project.clear();
        scene->removeItem(proxyedit);
        edit->clear();
        delete(proxyedit);
        scene->clear();
    }
    std::string _filename;
#if defined(_WIN32) || defined(_WIN64)
    _filename = "../GATProjects";
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
#if defined(__unix) || defined(__unix__)
#endif
#if defined( __APPLE__ ) || defined(__MACH__)
    _filename = "../../GATProjects";
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
    project["0"]=_filename+"subproject0.json";
    filename += "project.json";
}


void MainWindow::on_actionNext_Image_triggered()
{
    if(image){
        qDebug()<<currentSubproject;
        if((currentSubproject+1) < static_cast<int>(project.size())){
            qDebug()<<"next";
            saveSubproject();
            qDebug()<<"saved";
            currentSubproject++;
            subproject = _pm.loadProject(QString(project.at(std::to_string(currentSubproject)).get<std::string>().c_str()));
            qDebug()<<subproject.dump().c_str();
            openImage(subproject.at("image").get<std::string>().c_str());
            //qDebug()<<editscene->items();
            ui->Group0->click();
        }
    }
}

void MainWindow::on_actionPrevious_Image_triggered()
{
    if(image){
        qDebug()<<currentSubproject;
        if((currentSubproject-1) >= 0){
            qDebug()<<"previous";
            saveSubproject();
            currentSubproject--;
            qDebug()<<currentSubproject;
            subproject = _pm.loadProject(QString(project.at(std::to_string(currentSubproject)).get<std::string>().c_str()));
            openImage(subproject.at("image").get<std::string>().c_str());
            //qDebug()<<editscene->items();
             ui->Group0->click();
        }
    }
}

void MainWindow::on_actionAdd_Matrix_triggered()
{
    if(image){
      if(subproject.at("matrix").get<std::string>()!= ""){
        //glm::mat4 _test = _pm.readMatrix(subproject.at("matrix").get<std::string>().c_str());
      }
    }

}

void MainWindow::on_actionAdd_Calibration_triggered()
{
    if(image){
        if(subproject.at("calibration").get<std::string>()!= ""){
           // glm::mat4 _test = _pm.readCalibrationMatrix(subproject.at("calibration").get<std::string>().c_str(),pix.width(),pix.height());
    }
    }

}


void MainWindow::on_actionAdd_Point_Cloud_triggered()
{
    if(image){
        if(subproject.at("pointcloud").get<std::string>()!=""){
            _pm.readPointCloud(this->PointCloud,subproject.at("pointcloud").get<std::string>().c_str());
        }
    }
}

void MainWindow::on_actionClose_Project_triggered()
{

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
                       "Are you sure to continue?", nullptr, this);
    msgBox.addButton(tr("Not Save"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole)
        return false;
    else
        return true;

}

