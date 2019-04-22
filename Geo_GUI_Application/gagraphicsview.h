#ifndef GAGRAPHICSVIEW_H
#define GAGRAPHICSVIEW_H

#define MAX_GROUPS 8

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <armadillo>
#include <QStack>
#include <QDebug>
#include <QPointF>
#include "customelipse.h"



class GaGraphicsView : public QGraphicsView
{
Q_OBJECT
public:
    explicit GaGraphicsView(QWidget *parent = 0);
    typedef enum {ADD,DELETE,JOIN,SPLIT,MOVE,NONE} ACTION;
    struct DoneAction
    {
        ACTION a = NONE;
        CustomElipse* point;
        QGraphicsItemGroup* g;

    };
    void setToggle(bool t);
    void setPaint(int paint);
    void addElipse(QMouseEvent *e);
    QGraphicsScene* getGraphicsScene(){
        return scene;
    }

    void setSceneG(QGraphicsScene* extsc){
        scene = extsc;
        this->setScene(scene);
        for(QSharedPointer<QGraphicsItemGroup> g: groups){
            scene->addEllipse(0,0,1,1,QPen(Qt::transparent),QBrush(Qt::transparent));
            g.data()->addToGroup(scene->items().first());
            g->setHandlesChildEvents(false);
            scene->addItem(g.data());
        }
    }
    void setGroup(int g);
    void setGroupVisibility(int vis, bool bvis);

    void removeLastPoint(){ //clear si afegeixes coses a la llista
        qDebug()<<groups.first().data()->childItems().last();
        if(scene->items().size() > 16){
            qDebug()<<scene->items();
            if(!redoItems.isEmpty()){
                if(lastItems.top().a != redoItems.top().a){
                    redoItems.clear();
                }
            }

            while(!scene->items().contains(lastItems.top().point)){
                lastItems.pop();
            }
            redoItems.push(lastItems.pop());


            qDebug()<<redoItems.top().a;
            switch (redoItems.top().a) {
            case DELETE:
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                if(redoItems.top().point->hasInitLine()){
                    scene->addItem(redoItems.top().point->getInitLine());
                    redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                }if(redoItems.top().point->hasFinalLine()){
                    scene->addItem(redoItems.top().point->getFinalLine());
                    redoItems.top().g->addToGroup(redoItems.top().point->getFinalLine());
                    lastPoint = redoItems.top().point;

                }

                break;
            case ADD:
                if(redoItems.top().point->hasFinalLine()){
                    scene->removeItem(redoItems.top().point->getFinalLine());
                    scene->removeItem(redoItems.top().point);
                    lastPoint = redoItems.top().point->getFinalLine()->getInit();
                }else {
                    scene->removeItem(redoItems.top().point);
                }
                break;
            case MOVE:
                break;
            case JOIN:
                redoItems.top().point->getFinalLine()->setFinal(redoItems.top().point);
                redoItems.top().point->getFinalLine()->updatel();
                redoItems.top().point->getInitLine()->getFinal()->setFinalLine(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point->getInitLine());
                redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                break;
            case SPLIT:
                break;
            case NONE:
                break;

            }


        }
    }
    void redoLastPoint(){
        if(!redoItems.isEmpty()){
            switch (redoItems.top().a) {
            case DELETE:
                scene->removeItem(redoItems.top().point);
                if(redoItems.top().point->hasInitLine()){
                    scene->removeItem(redoItems.top().point->getInitLine());
                }if(redoItems.top().point->hasFinalLine()){
                    scene->removeItem(redoItems.top().point->getFinalLine());
                    lastPoint = redoItems.top().point->getFinalLine()->getInit();
                    lastPoints.replace(redoItems.top().point->getGroupNumber(),lastPoint);
                }
                lastItems.push(redoItems.pop());
                break;
            case ADD:
                //scene->removeItem(redoItems.top().point->getFinalLine());
                //scene->removeItem(redoItems.top().point);
                //qDebug()<<d.point->hasInitLine();
                scene->addItem(redoItems.top().point);
                scene->addItem(redoItems.top().point->getFinalLine());

                //qDebug()<<scene->items().first();
                redoItems.top().g->addToGroup(redoItems.top().point->getFinalLine());
                redoItems.top().g->addToGroup(redoItems.top().point);
                lastItems.push(redoItems.pop());
                break;

            case MOVE:
                break;
            case JOIN:
                CustomElipse* p1,*p3;
                p1 = redoItems.top().point->getFinalLine()->getInit();
                p3 = redoItems.top().point->getInitLine()->getFinal();
                p3->setFinalLine(p1->getInitLine());
                p3->getFinalLine()->setFinal(p3);
                p3->getFinalLine()->updatel();
                scene->removeItem(redoItems.top().point->getInitLine());
                scene->removeItem(redoItems.top().point);
                break;
            case SPLIT:

                break;
            case NONE:
                break;

            }
        }
    }
    QGraphicsScene* getScene(){
        return scene;
    }
    int getNumber(CustomElipse* it){
        for(int i = 0; i<groups.size();i++){
            if(groups.mid(i,1).first().data() == dynamic_cast<QGraphicsItemGroup*>(it->parentItem())){
                return i;

            }
        }
        return 8;
    }
signals:
void sendMousePoint(QPointF point);

public slots:
void mousePressEvent(QMouseEvent * e);
//void mouseReleaseEvent(QMouseEvent * e);
void mouseMoveEvent(QMouseEvent * e);

private:
QGraphicsScene * scene;
bool toggle;
int paint;
QPen pen;
QPen penerase;
QBrush brush;
QBrush brusherase;
QList<QSharedPointer<QGraphicsItemGroup>> groups;
QList<CustomElipse*> lastPoints;
//GROUP actualGroup;
QStack <DoneAction>lastItems;
QStack <DoneAction>redoItems;
QSharedPointer<QGraphicsItemGroup> group;
CustomElipse * lastPoint;
};


#endif // GAGRAPHICSVIEW_H
