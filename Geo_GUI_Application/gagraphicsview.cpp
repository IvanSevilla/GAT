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
    actualGroup = G0;
    this->setToggle(false);
    this->setPaint(false);
    for(int i = 0; i<MAX_GROUPS;i++){
        groups.push_back(QSharedPointer<QGraphicsItemGroup>(new QGraphicsItemGroup()));
    }

    }
void GaGraphicsView::mousePressEvent(QMouseEvent * e)
{
    if(toggle){
        if(paint == 1){
            double rad = 1;
            QPointF pt = mapToScene(e->pos());
            CustomElipse* it = new CustomElipse();
            it->setPen(pen);
            it->setBrush(brush);
            it->setRect(pt.x()-1.5,pt.y()-1.5,3,3);
            it->setFlag(QGraphicsItem::ItemIsMovable,true);
            it->setFlag(QGraphicsItem::ItemIsSelectable,true);
            it->setFlag(QGraphicsItem::ItemClipsToShape,true);
            scene->addItem(it);



            switch (actualGroup) {
            case G0:
                groups.first().data()->addToGroup(it);
                lastItems.push(groups.first().data()->childItems().last());
                break;
            case G1:
                groups.mid(1,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(1,1).first().data()->childItems().last());
                break;
            case G2:
                groups.mid(2,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(2,1).first().data()->childItems().last());
                break;
            case G3:
                groups.mid(3,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(3,1).first().data()->childItems().last());
                break;
            case G4:
                groups.mid(4,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(4,1).first().data()->childItems().last());
                break;
            case G5:
                groups.mid(5,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(5,1).first().data()->childItems().last());
                break;
            case G6:
                groups.mid(6,1).first().data()->addToGroup(it);
                lastItems.push(groups.mid(6,1).first().data()->childItems().last());
                break;
            case G7:
                groups.last().data()->addToGroup(it);
                lastItems.push(groups.last().data()->childItems().last());
                break;

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
            qDebug()<<e->button();
            if(!e->isAccepted()) {
                        //remove item
                if(e->button() == Qt::RightButton) {
                    QGraphicsItem * itemToRemove = NULL;
                    QPointF pt = mapToScene(e->pos());
                    qDebug()<<scene->items(pt);
                    foreach(auto item, scene->items(pt)) {
                        if(item->type() == QGraphicsItem::UserType+1) {
                            itemToRemove = item;
                            break;
                        }
                    }
                    qDebug()<<itemToRemove->pos();
                    if(itemToRemove){
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
        actualGroup = G0;
        pen.setColor(QColor(255,0,0));
        brush.setColor(QColor(255,0,0));
        break;
    case 1:
        actualGroup = G1;
        pen.setColor(QColor(0,0,255));
        brush.setColor(QColor(0,0,255));
        break;
    case 2:
        actualGroup = G2;
        pen.setColor(QColor(0,255,0));
        brush.setColor(QColor(0,255,0));
        break;
    case 3:
        actualGroup = G3;
        pen.setColor(QColor(255,255,0));
        brush.setColor(QColor(255,255,0));
        break;
    case 4:
        actualGroup = G4;
        pen.setColor(QColor(0,255,255));
        brush.setColor(QColor(0,255,255));
        break;
    case 5:
        actualGroup = G5;
        pen.setColor(QColor(145,170,255));
        brush.setColor(QColor(145,170,255));
        break;
    case 6:
        actualGroup = G6;
        pen.setColor(QColor(150,255,150));
        brush.setColor(QColor(150,255,150));
        break;
    case 7:
        actualGroup = G7;
        pen.setColor(QColor(255,100,100));
        brush.setColor(QColor(255,100,100));
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
