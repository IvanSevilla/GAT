#include "gagraphicsview.h"
#include "mainwindow.h"
#include <QPointF>
#include <QDebug>

GaGraphicsView::GaGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
    {
    this->setSceneRect(50, 50, 350, 350);
    pen.setColor(QColor(255,0,0));
    brush = QBrush(Qt::SolidPattern);
    brush.setColor(QColor(255,0,0));

    this->setToggle(false);
    this->setPaint(false);
    for(int i = 0; i<MAX_GROUPS;i++){
        groups.push_back(QSharedPointer<QGraphicsItemGroup>(new QGraphicsItemGroup()));
    }
    group = groups.first();
    }
void GaGraphicsView::mousePressEvent(QMouseEvent * e)
{
    if(toggle){
        if(paint == 1){
        //double rad = 1;
            QPointF pt = mapToScene(e->pos());
            qDebug()<<pt;
            CustomElipse* it = new CustomElipse();
            it->setPen(pen);
            it->setBrush(brush);
            it->setRect(pt.x()-1.5,pt.y()-1.5,3,3);
            it->setCenter(pt);
            //qDebug()<<it->hasFinalLine();
            //qDebug()<<it->hasInitLine();
            it->setFlag(QGraphicsItem::ItemIsMovable,true);
            it->setFlag(QGraphicsItem::ItemIsSelectable,true);
            it->setFlag(QGraphicsItem::ItemClipsToShape,true);

            if(group->childItems().size()>1){
                CustomLine * li = new CustomLine();
                li->setPen(pen);
                li->setInitial(lastPoint);
                qDebug()<<"1: "<<lastPoint->getCenter();
                li->setFinal(it);
                lastPoint->setInitLine(li);
                it->setFinalLine(li);
                qDebug()<<"2: "<<it->getCenter();
                qDebug()<<"3: "<<li->line();
                //li->setFlag(QGraphicsItem::ItemIsSelectable,true);
                //li->setFlag(QGraphicsItem::ItemClipsToShape,true);
                scene->addItem(li);
                group->addToGroup(li);
            }

        scene->addItem(it);
        group->addToGroup(it);
        lastPoint = it;
        DoneAction d;
        d.a = ADD;
        d.point = it;
        d.g = dynamic_cast<QGraphicsItemGroup*>(it->parentItem());
        lastItems.push(d);

        }
        //QGraphicsItem* line = scene->addLine(pt.x(),pt.y(),pt.x()+7.0,pt.y()+4.0,pen);
        //line->setFlag(QGraphicsItem::ItemIsMovable,true);
        //line->setFlag(QGraphicsItem::ItemIsSelectable,true);
        //line->setFlag(QGraphicsItem::ItemClipsToShape,true);
    }
    if(paint == 2){

        //penerase.setColor(QColor(0,0,0));
        //brusherase= QBrush(Qt::SolidPattern);
        //brusherase.setColor(QColor(0,0,0));
        //double rad = 1;
        //scene->addEllipse(pt.x()-rad, pt.y()-rad, rad+2.0, rad+2.0,
        //penerase, brusherase);
        QGraphicsView::mousePressEvent(e);
        //qDebug()<<e->button();
        if(!e->isAccepted()) {
            //remove item
            if(e->button() == Qt::RightButton) {
                QGraphicsItem * itemToRemove = nullptr;
                QPointF pt = mapToScene(e->pos());
                //qDebug()<<scene->items(pt);
                foreach(auto item, scene->items(pt)) {
                    if(item->type() == QGraphicsItem::UserType+1) {
                        itemToRemove = item;
                        break;
                    }
                }
                //qDebug()<<itemToRemove->pos();
                if(itemToRemove != nullptr){
                    DoneAction d;
                    d.point = dynamic_cast<CustomElipse*>(itemToRemove);
                    d.a = DELETE;
                    d.g = dynamic_cast<QGraphicsItemGroup*>(d.point->parentItem());
                    qDebug()<<d.point->hasInitLine();
                    qDebug()<<d.point->hasFinalLine();
                    if(d.point->hasInitLine()){
                        if(d.point->hasFinalLine()){
                            d.a = JOIN;
                            CustomElipse* p1,*p3;
                            p1 = d.point->getFinalLine()->getInit();
                            p3 = d.point->getInitLine()->getFinal();
                            p3->setFinalLine(p1->getInitLine());
                            p3->getFinalLine()->setFinal(p3);
                            p3->getFinalLine()->updatel();
                            qDebug()<<p1->getCenter();
                            qDebug()<<p3->getFinalLine()->getInit()->getCenter();
                            qDebug()<<d.point->getCenter();
                            qDebug()<<d.point->getFinalLine()->getInit()->getCenter();
                            scene->removeItem(d.point->getInitLine());
                        }else{
                            scene->removeItem(d.point->getInitLine());
                        }
                    }else{
                        if(d.point->hasFinalLine()){
                            scene->removeItem(d.point->getFinalLine());
                            lastPoint = d.point->getFinalLine()->getInit();
                        }
                    }
                lastItems.push(d);
                scene->removeItem(lastItems.top().point);
                qDebug()<<d.a;
            }
        }
    //qDebug()<<scene->items();
    }else{
        QGraphicsItem * itemToRemove = nullptr;
        QPointF pt = mapToScene(e->pos());
        //qDebug()<<scene->items(pt);
        foreach(auto item, scene->items(pt)) {
            if(item->type() == QGraphicsItem::UserType+2) {
                itemToRemove = item;
                qDebug()<<"HEY";
                break;
            }

        }
        if(itemToRemove != nullptr){
            CustomLine * _l = dynamic_cast<CustomLine*>(itemToRemove);

            if(_l->hasFinal()){
                qDebug()<<_l->getFinal()->getCenter();
                CustomElipse* _e = new CustomElipse();
                _e->setPen(pen);
                _e->setBrush(brush);
                _e->setRect(pt.x()-1.5,pt.y()-1.5,3,3);
                _e->setCenter(pt);
                //qDebug()<<it->hasFinalLine();
                //qDebug()<<it->hasInitLine();
                _e->setFlag(QGraphicsItem::ItemIsMovable,true);
                _e->setFlag(QGraphicsItem::ItemIsSelectable,true);
                _e->setFlag(QGraphicsItem::ItemClipsToShape,true);
                CustomLine * li = new CustomLine();
                li->setPen(pen);
                li->setInitial(_e);
                li->setFinal(_l->getFinal());
                _e->setInitLine(li);
                _e->setFinalLine(_l);
                _l->getFinal()->setFinalLine(li);
                _l->setFinal(_e);
                //li->setFlag(QGraphicsItem::ItemIsSelectable,true);
                //li->setFlag(QGraphicsItem::ItemClipsToShape,true);
                scene->addItem(li);
                group->addToGroup(li);
                scene->addItem(_e);
                group->addToGroup(_e);
                DoneAction d;
                d.a = SPLIT;
                d.point = _e;
                d.g = dynamic_cast<QGraphicsItemGroup*>(_e->parentItem());
                lastItems.push(d);
                }
            }

        }
    }
    if(paint == 3){
        QGraphicsView::mousePressEvent(e);

    }

}

void GaGraphicsView::mouseMoveEvent(QMouseEvent * e){
    QGraphicsView::mouseMoveEvent(e);
    //qDebug()<<e->isAccepted();
    if(e->isAccepted()) {
        //qDebug()<<e;
        if(paint == 3){
           // qDebug()<<scene->items();
            CustomElipse * itemToUpdate = nullptr;
            QPointF pt = mapToScene(e->pos());
            //qDebug()<<scene->items(pt);
            foreach(auto item, scene->items(pt)) {
                if(item->type() == QGraphicsItem::UserType+1) {
                    itemToUpdate = dynamic_cast<CustomElipse*>(item);
                    qDebug()<<itemToUpdate->getCenter();
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

void GaGraphicsView::setToggle(bool t){
    this->toggle = t;
}
void GaGraphicsView::setPaint(int p){
    this->paint = p;
}

void GaGraphicsView::setGroup(int g){
    switch(g){
    case 0:
        pen.setColor(QColor(255,0,0));
        brush.setColor(QColor(255,0,0));
        group = groups.first();

        break;
    case 1:
        pen.setColor(QColor(0,0,255));
        brush.setColor(QColor(0,0,255));
        group = groups.mid(1,1).first();
        break;
    case 2:
        pen.setColor(QColor(0,255,0));
        brush.setColor(QColor(0,255,0));
        group = groups.mid(2,1).first();
        break;
    case 3:
        pen.setColor(QColor(255,255,0));
        brush.setColor(QColor(255,255,0));
        group = groups.mid(3,1).first();
        break;
    case 4:
        pen.setColor(QColor(0,255,255));
        brush.setColor(QColor(0,255,255));
        group = groups.mid(4,1).first();
        break;
    case 5:
        pen.setColor(QColor(145,170,255));
        brush.setColor(QColor(145,170,255));
        group = groups.mid(5,1).first();
        break;
    case 6:
        pen.setColor(QColor(150,255,150));
        brush.setColor(QColor(150,255,150));
        group = groups.mid(6,1).first();
        break;
    case 7:
        pen.setColor(QColor(255,100,100));
        brush.setColor(QColor(255,100,100));
        group = groups.mid(7,1).first();
        break;
    }
}
void GaGraphicsView::setGroupVisibility(int vis, bool bvis){
    if(!bvis){
        groups.mid(vis,1).first().data()->hide();
    }else{
        groups.mid(vis,1).first().data()->show();
    }

}
