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
    typedef enum {ADD,DELETE,JOIN,SPLIT,NONE} ACTION;
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
                }

                break;
            case ADD:
                scene->removeItem(redoItems.top().point->getFinalLine());
                scene->removeItem(redoItems.top().point);
                break;
            case JOIN:
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                qDebug()<<redoItems.top().point->getCenter();
                redoItems.top().point->getFinalLine()->setFinal(redoItems.top().point);
                redoItems.top().point->getFinalLine()->updatel();
                scene->addItem(redoItems.top().point->getInitLine());
                redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                redoItems.pop();

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
                //scene->addItem(redoItems.top().point);
                //redoItems.top().g->addToGroup(redoItems.top().point);
                break;
            case ADD:
                //scene->removeItem(redoItems.top().point->getFinalLine());
                //scene->removeItem(redoItems.top().point);
                //qDebug()<<d.point->hasInitLine();
                scene->addItem(redoItems.top().point->getFinalLine());
                scene->addItem(redoItems.top().point);
                //qDebug()<<scene->items().first();
                redoItems.top().g->addToGroup(redoItems.top().point->getFinalLine());
                redoItems.top().g->addToGroup(redoItems.top().point);
                lastItems.push(redoItems.top());
                redoItems.pop();
                break;
            case JOIN:
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
//GROUP actualGroup;
QStack <DoneAction>lastItems;
QStack <DoneAction>redoItems;
QSharedPointer<QGraphicsItemGroup> group;
CustomElipse * lastPoint;
bool setG0 = false;
bool setG1 = false;
bool setG2 = false;
bool setG3 = false;
bool setG4 = false;
bool setG5 = false;
bool setG6 = false;
bool setG7 = false;
};


#endif // GAGRAPHICSVIEW_H
