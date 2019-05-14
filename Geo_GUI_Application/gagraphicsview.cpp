#include "gagraphicsview.h"
#include "mainwindow.h"
#include <QPointF>
#include <QDebug>
#include <string.h>

CustomGraphicsView::CustomGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
    {
    _file ="logFile"+current_date()+".txt";
    current = 0;
    this->setSceneRect(50, 50, 350, 350);
    _color.push_back(QColor(228,26,28));
    _color.push_back(QColor(55,126,184));
    _color.push_back(QColor(77,175,74));
    _color.push_back(QColor(152,78,163));
    _color.push_back(QColor(255,127,0));
    _color.push_back(QColor(255,255,51));
    _color.push_back(QColor(166,86,40));
    _color.push_back(QColor(247,129,191));
    pen.setColor(_color.first());
    brush = QBrush(Qt::SolidPattern);
    brush.setColor(_color.first());

    this->setToggle(false);
    this->setPaint(false);
    for(int i = 0; i<MAX_GROUPS;i++){
        groups.push_back(QSharedPointer<QGraphicsItemGroup>(new QGraphicsItemGroup()));
    }
    group = groups.first();
    for(int i = 0; i<MAX_GROUPS;i++){
        lastPoints.push_back(nullptr);
        poliLines.push_back(new QList<CustomElipse*>());
    }
    lastPoint = nullptr;
    }
void CustomGraphicsView::mousePressEvent(QMouseEvent * e)
{
    if(toggle){
        if(paint == 1){

            if(e->button() == Qt::RightButton){

                if(lastPoint != nullptr){
                    poliLines.mid(lastPoint->getGroupNumber(),1).first()->push_back(lastPoint);
                    std::string log = "FINISH LINE: "+
                            std::to_string(poliLines.mid(lastPoint->getGroupNumber(),1).first()->length())+
                            " Point: "+ std::to_string(lastPoint->getCenter().x()) +
                            "," +std::to_string(lastPoint->getCenter().y());
                    WriteLogFile(log.c_str());
                    up_btn->clicked(true);
                    lastPoints.replace(lastPoint->getGroupNumber(),nullptr);
                    lastPoint = nullptr;
                }

            }else{
                QPointF pt = mapToScene(e->pos());
                std::string log = "ADD POINT: " + std::to_string(pt.x()) + "," +std::to_string(pt.y());

                WriteLogFile(log.c_str());
                up_btn->clicked(true);
                CustomElipse* it = new CustomElipse();
                it->setPen(pen);
                it->setBrush(brush);
                it->setRect(pt.x()-2,pt.y()-2,4,4);
                it->setCenter(pt);
                it->setFlag(QGraphicsItem::ItemIsMovable,true);
                it->setFlag(QGraphicsItem::ItemIsSelectable,true);
                it->setFlag(QGraphicsItem::ItemClipsToShape,true);

                if(lastPoint != nullptr){
                    // Si hay ultimo punto generamos una linea
                    CustomLine * li = new CustomLine();
                    // Le añadimos el color
                    li->setPen(pen);
                    // Asociamos el punto inicial de la linea
                    li->setInitial(lastPoint);
                    // Asociamos el punto final de la linea
                    li->setFinal(it);
                    // En el punto inicial, lo asociamos como linea inicial
                    lastPoint->setInitLine(li);
                    // En el punto final, lo asociamos como linea final
                    it->setFinalLine(li);
                    // Añadimos la linea a la escena
                    scene->addItem(li);
                    // Añadimos la linea al grupo del punto
                    group->addToGroup(li);
                }

            scene->addItem(it);
            group->addToGroup(it);
            it->setGroupNumber(getNumber(it));
            lastPoint = it;
            lastPoints.replace(it->getGroupNumber(),it);
            DoneAction d;
            d.a = ADD;
            d.point = it;
            d.g = dynamic_cast<QGraphicsItemGroup*>(it->parentItem());
            lastItems.push(d);
            redoItems.clear();

            }
        }
    }
    if(paint == 2){

        QGraphicsView::mousePressEvent(e);
        if(!e->isAccepted()) {
            //remove item
            if(e->button() == Qt::RightButton) {
                QGraphicsItem * itemToRemove = nullptr;
                QPointF pt = mapToScene(e->pos());
                foreach(auto item, scene->items(pt)) {
                    if(item->type() == QGraphicsItem::UserType+1) {
                        itemToRemove = item;
                        break;
                    }
                }
                if(itemToRemove != nullptr){
                    redoItems.clear();
                    DoneAction d;

                    d.point = dynamic_cast<CustomElipse*>(itemToRemove);
                    d.a = DEL;
                    d.g = dynamic_cast<QGraphicsItemGroup*>(d.point->parentItem());
                    if(poliLines.value(d.point->getGroupNumber())->contains(d.point)){
                        int _position = poliLines.value(d.point->getGroupNumber())->indexOf(d.point);
                        poliLines.value(d.point->getGroupNumber())->replace(_position,d.point->getFinalLine()->getInit());
                    }
                    if(d.point->hasInitLine()){
                        if(d.point->hasFinalLine()){
                            std::string log = "JOIN POINT: " + std::to_string(pt.x()) + "," +std::to_string(pt.y());

                            WriteLogFile(log.c_str());
                            d.a = JOIN;

                            CustomElipse* p1,*p3;
                            p1 = d.point->getFinalLine()->getInit();
                            p3 = d.point->getInitLine()->getFinal();
                            p3->setFinalLine(p1->getInitLine());
                            p3->getFinalLine()->setFinal(p3);
                            p3->getFinalLine()->updatel();
                            scene->removeItem(d.point->getInitLine());
                        }else{
                            std::string log = "DELETE POINT: " + std::to_string(pt.x()) + "," +std::to_string(pt.y());

                            WriteLogFile(log.c_str());
                            scene->removeItem(d.point->getInitLine());
                        }
                    }else{
                        if(d.point->hasFinalLine()){
                            std::string log = "DELETE POINT: " + std::to_string(pt.x()) + "," +std::to_string(pt.y());

                            WriteLogFile(log.c_str());
                            scene->removeItem(d.point->getFinalLine());
                            if(lastPoint != nullptr){
                                lastPoint = d.point->getFinalLine()->getInit();
                                lastPoints.replace(d.point->getGroupNumber(),lastPoint);
                            }

                        }
                    }
                lastItems.push(d);
                scene->removeItem(lastItems.top().point);
            }
        }

        }
    }
    if(paint == 3){
        if(e->button() == Qt::LeftButton){
        QGraphicsView::mousePressEvent(e);
        }else{
            QGraphicsItem * itemToRemove = nullptr;
            QPointF pt = mapToScene(e->pos());
            foreach(auto item, scene->items(pt)) {
                if(item->type() == QGraphicsItem::UserType+2) {
                    itemToRemove = item;
                    break;
                }

            }
            if(itemToRemove != nullptr){
                CustomLine * _l = dynamic_cast<CustomLine*>(itemToRemove);

                if(_l->hasFinal()){
                    qDebug()<<_l->getFinal()->getCenter();
                    CustomElipse* _e = new CustomElipse();
                    _e->setPen(QPen(_color.value(getNumber(_l))));
                    _e->setBrush(QBrush(_color.value(getNumber(_l))));
                    _e->setRect(pt.x()-2,pt.y()-2,4,4);
                    _e->setCenter(pt);
                    _e->setFlag(QGraphicsItem::ItemIsMovable,true);
                    _e->setFlag(QGraphicsItem::ItemIsSelectable,true);
                    _e->setFlag(QGraphicsItem::ItemClipsToShape,true);
                    CustomLine * li = new CustomLine();
                    li->setPen(QPen(_color.value(getNumber(_l))));
                    li->setInitial(_e);
                    li->setFinal(_l->getFinal());
                    _e->setInitLine(li);
                    _e->setFinalLine(_l);
                    _l->getFinal()->setFinalLine(li);
                    _l->setFinal(_e);
                    scene->addItem(li);
                    groups.value(getNumber(_l)).data()->addToGroup(li);
                    scene->addItem(_e);
                    groups.value(getNumber(_l)).data()->addToGroup(_e);
                    _e->setGroupNumber(getNumber(_e));
                    DoneAction d;
                    std::string log = "SPLIT LINE: " + std::to_string(pt.x()) + "," +std::to_string(pt.y());

                    WriteLogFile(log.c_str());
                    d.a = SPLIT;
                    d.point = _e;
                    d.g = dynamic_cast<QGraphicsItemGroup*>(_e->parentItem());
                    lastItems.push(d);
                    }
            }
        }


    }

}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent * e){
    QGraphicsView::mouseMoveEvent(e);
    if(e->isAccepted()) {
        if(paint == 3){
            CustomElipse * itemToUpdate = nullptr;
            QPointF pt = mapToScene(e->pos());
            foreach(auto item, scene->items(pt)) {
                if(item->type() == QGraphicsItem::UserType+1) {
                    itemToUpdate = dynamic_cast<CustomElipse*>(item);
                    if(itemToUpdate->hasInitLine()){
                        itemToUpdate->getInitLine()->updatel();
                    }if(itemToUpdate->hasFinalLine()){
                        itemToUpdate->getFinalLine()->updatel();
                    }

                    break;
                }
            }
        }
    }
}

void CustomGraphicsView::setToggle(bool t){
    this->toggle = t;
}
void CustomGraphicsView::setPaint(int p){
    this->paint = p;
}

void CustomGraphicsView::setGroup(int g){
    current = g;
    switch(g){
    case 0:
        pen.setColor(_color.first());
        brush.setColor(_color.first());
        group = groups.first();
        lastPoint = lastPoints.first();
        break;
    case 1:
        pen.setColor(_color.mid(1,1).first());
        brush.setColor(_color.mid(1,1).first());
        group = groups.mid(1,1).first();
        lastPoint = lastPoints.mid(1,1).first();
        break;
    case 2:
        pen.setColor(_color.mid(2,1).first());
        brush.setColor(_color.mid(2,1).first());
        group = groups.mid(2,1).first();
        lastPoint = lastPoints.mid(2,1).first();
        break;
    case 3:
        pen.setColor(_color.mid(3,1).first());
        brush.setColor(_color.mid(3,1).first());
        group = groups.mid(3,1).first();
        lastPoint = lastPoints.mid(3,1).first();
        break;
    case 4:
        pen.setColor(_color.mid(4,1).first());
        brush.setColor(_color.mid(4,1).first());
        group = groups.mid(4,1).first();
        lastPoint = lastPoints.mid(4,1).first();
        break;
    case 5:
        pen.setColor(_color.mid(5,1).first());
        brush.setColor(_color.mid(5,1).first());
        group = groups.mid(5,1).first();
        lastPoint = lastPoints.mid(5,1).first();
        break;
    case 6:
        pen.setColor(_color.mid(6,1).first());
        brush.setColor(_color.mid(6,1).first());
        group = groups.mid(6,1).first();
        lastPoint = lastPoints.mid(6,1).first();
        break;
    case 7:
        pen.setColor(_color.last());
        brush.setColor(_color.last());
        group = groups.last();
        lastPoint = lastPoints.last();
        break;
    }
}
void CustomGraphicsView::setGroupVisibility(int vis, bool bvis){
    if(!bvis){
        groups.mid(vis,1).first().data()->hide();
    }else{
        groups.mid(vis,1).first().data()->show();
    }

}
std::string CustomGraphicsView::current_time(){
    time_t now = time(nullptr);
    struct tm tstruct;
    char buf[40];
    tstruct = *localtime(&now);
    //format: HH:mm:ss
    strftime(buf, sizeof(buf), "%X", &tstruct);
    return buf;
}
std::string CustomGraphicsView::current_date(){
        time_t now = time(nullptr);
        struct tm tstruct;
        char buf[40];
        tstruct = *localtime(&now);
        //format: day DD-MM-YYYY
        strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
        return buf;
    }
bool CustomGraphicsView::exists_file (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
  }
void CustomGraphicsView::CreateLogFile(){
    FILE* pFile;
    if(exists_file(_file)){
        pFile = fopen(_file.c_str(), "w");
    }else{
        pFile = fopen(_file.c_str(), "a");
    }

    fprintf(pFile, "%s\n",current_time().c_str());
    fclose(pFile);
}
