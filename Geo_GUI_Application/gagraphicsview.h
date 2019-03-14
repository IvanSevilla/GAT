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



class GaGraphicsView : public QGraphicsView
{
Q_OBJECT
public:
explicit GaGraphicsView(QWidget *parent = 0);
    typedef enum {G0, G1, G2, G3, G4, G5, G6, G7} GROUP;

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
            scene->addItem(g.data());
        }
    }
    void setGroup(int g);
    void setGroupVisibility(int vis, bool bvis);

    void removeLastPoint(){
        qDebug()<<groups.first().data()->childItems().last();
        if(scene->items().size() > 16){
            qDebug()<<scene->items();
            redoItems.push(lastItems.pop());
            redoItemsGroup.push(dynamic_cast<QGraphicsItemGroup*>(redoItems.top()->parentItem()));
            scene->removeItem(redoItems.top());
        }
    }
    void redoLastPoint(){
        QGraphicsItem * item = redoItems.pop();
        qDebug()<<item;
        scene->addItem(item);
        qDebug()<<scene->items().first();
        QGraphicsItemGroup * group = redoItemsGroup.pop();
        group->addToGroup(item);
        lastItems.push(group->childItems().last());
        redoItemsGroup.push(group);
    }
    QGraphicsScene* getScene(){
        return scene;
    }
signals:
void sendMousePoint(QPointF point);

public slots:
void mousePressEvent(QMouseEvent * e);

private:
QGraphicsScene * scene;
bool toggle;
int paint;
QPen pen;
QPen penerase;
QBrush brush;
QBrush brusherase;
QMap<int,QGraphicsItem*> itemList;
QMap<int,QPointF> pointList;
QList<QSharedPointer<QGraphicsItemGroup>> groups;
GROUP actualGroup;
QStack <QGraphicsItem*>lastItems;
QStack <QGraphicsItem*>redoItems;
QStack <QGraphicsItemGroup*>redoItemsGroup;
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
