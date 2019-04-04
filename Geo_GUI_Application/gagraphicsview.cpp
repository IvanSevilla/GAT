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
                li->setInitial(dynamic_cast<CustomElipse*>(group->childItems().last()));
                qDebug()<<"1: "<<dynamic_cast<CustomElipse*>(group->childItems().last())->getCenter();
                li->setFinal(it);
                dynamic_cast<CustomElipse*>(group->childItems().last())->setInitLine(li);
                it->setFinalLine(li);
                qDebug()<<"2: "<<it->getCenter();
                qDebug()<<"3: "<<li->line();
                li->setFlag(QGraphicsItem::ItemIsSelectable,true);
                li->setFlag(QGraphicsItem::ItemClipsToShape,true);
                scene->addItem(li);
                group->addToGroup(li);
            }

            scene->addItem(it);
            group->addToGroup(it);
            lastItems.push(group->childItems().last());

            }
            //QGraphicsItem* line = scene->addLine(pt.x(),pt.y(),pt.x()+7.0,pt.y()+4.0,pen);
            //line->setFlag(QGraphicsItem::ItemIsMovable,true);
            //line->setFlag(QGraphicsItem::ItemIsSelectable,true);
            //line->setFlag(QGraphicsItem::ItemClipsToShape,true);


        }if(paint == 2){

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
                        redoItems.push(itemToRemove);
                        redoItemsGroup.push(dynamic_cast<QGraphicsItemGroup*>(redoItems.top()->parentItem()));
                        scene->removeItem(redoItems.top());
                    }

                }
                }

            //qDebug()<<scene->items();


        }if(paint == 3){
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
