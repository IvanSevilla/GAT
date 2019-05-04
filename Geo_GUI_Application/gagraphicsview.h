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
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>


class GaGraphicsView : public QGraphicsView
{
Q_OBJECT
public:
    explicit GaGraphicsView(QWidget *parent = 0);
    typedef enum {ADD,DELETE,JOIN,SPLIT,MOVE,NONE} ACTION;
    int current;

    void WriteLogFile(const char* szString)
    {

      FILE* pFile = fopen("logFile.txt", "a");
      fprintf(pFile, "%s\n",szString);
      fclose(pFile);


    }
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
    void setUpdater(QPushButton* _ui){
        up_btn = _ui;
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
    void setGroupColor(int position, QColor _new){
        if(position <= _color.size())
            _color.replace(position,_new);
    }
    QColor getCurrentColor(){
        return _color.value(current);
    }
    QList<CustomElipse*>* getPolilines(int _group){
        return poliLines.value(_group);
    }
    QList<CustomElipse*>* getCurrentGroupPolilines(){
        return poliLines.value(current);
    }
    QList<QList<CustomElipse*>*> getAllPolilines(){
        return poliLines;
    }

    void removeLastPoint(){
        //qDebug()<<groups.first().data()->childItems().last();
        if(scene->items().size() > 16){
            //qDebug()<<scene->items();

            while(!scene->items().contains(lastItems.top().point) && lastItems.top().a == ADD){
                lastItems.pop();
            }
            redoItems.push(lastItems.pop());


            //qDebug()<<redoItems.top().a;
            switch (redoItems.top().a) {
            case DELETE:
                WriteLogFile("UNDO DELETE");
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                if(redoItems.top().point->hasInitLine()){
                    scene->addItem(redoItems.top().point->getInitLine());
                    redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                }if(redoItems.top().point->hasFinalLine()){
                    scene->addItem(redoItems.top().point->getFinalLine());
                    redoItems.top().g->addToGroup(redoItems.top().point->getFinalLine());
                    if(lastPoint != nullptr){
                        lastPoint = redoItems.top().point;
                    }

                }
                if(poliLines.value(redoItems.top().point->getGroupNumber())->contains(redoItems.top().point->getFinalLine()->getInit())){
                    int _position = poliLines.value(redoItems.top().point->getGroupNumber())->indexOf(redoItems.top().point->getFinalLine()->getInit());
                    poliLines.value(redoItems.top().point->getGroupNumber())->replace(_position,redoItems.top().point);
                }

                break;
            case ADD:
                WriteLogFile("UNDO ADD");
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
                WriteLogFile("UNDO JOIN");
                redoItems.top().point->getFinalLine()->setFinal(redoItems.top().point);
                redoItems.top().point->getFinalLine()->updatel();
                redoItems.top().point->getInitLine()->getFinal()->setFinalLine(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point->getInitLine());
                redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                break;
            case SPLIT:
                WriteLogFile("UNDO SPLIT");
                CustomElipse* p1,*p3;
                p1 = redoItems.top().point->getFinalLine()->getInit();
                p3 = redoItems.top().point->getInitLine()->getFinal();
                p3->setFinalLine(p1->getInitLine());
                p3->getFinalLine()->setFinal(p3);
                p3->getFinalLine()->updatel();
                scene->removeItem(redoItems.top().point->getInitLine());
                scene->removeItem(redoItems.top().point);
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
                WriteLogFile("REDO DELETE");
                scene->removeItem(redoItems.top().point);
                if(redoItems.top().point->hasInitLine()){
                    scene->removeItem(redoItems.top().point->getInitLine());
                }if(redoItems.top().point->hasFinalLine()){
                    scene->removeItem(redoItems.top().point->getFinalLine());
                    if(lastPoint != nullptr){
                        lastPoint = redoItems.top().point->getFinalLine()->getInit();
                        lastPoints.replace(redoItems.top().point->getGroupNumber(),lastPoint);
                    }

                }
                if(poliLines.value(redoItems.top().point->getGroupNumber())->contains(redoItems.top().point->getFinalLine()->getInit())){
                    int _position = poliLines.value(redoItems.top().point->getGroupNumber())->indexOf(redoItems.top().point->getFinalLine()->getInit());
                    poliLines.value(redoItems.top().point->getGroupNumber())->replace(_position,redoItems.top().point);
                }
                lastItems.push(redoItems.pop());
                break;
            case ADD:
                WriteLogFile("REDO ADD");
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
                WriteLogFile("REDO JOIN");
                CustomElipse* p1,*p3;
                p1 = redoItems.top().point->getFinalLine()->getInit();
                p3 = redoItems.top().point->getInitLine()->getFinal();
                p3->setFinalLine(p1->getInitLine());
                p3->getFinalLine()->setFinal(p3);
                p3->getFinalLine()->updatel();
                scene->removeItem(redoItems.top().point->getInitLine());
                scene->removeItem(redoItems.top().point);
                lastItems.push(redoItems.pop());
                break;
            case SPLIT:
                WriteLogFile("REDO SPLIT");
                redoItems.top().point->getFinalLine()->setFinal(redoItems.top().point);
                redoItems.top().point->getFinalLine()->updatel();
                redoItems.top().point->getInitLine()->getFinal()->setFinalLine(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point->getInitLine());
                redoItems.top().g->addToGroup(redoItems.top().point->getInitLine());
                scene->addItem(redoItems.top().point);
                redoItems.top().g->addToGroup(redoItems.top().point);
                lastItems.push(redoItems.pop());
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
    int getNumber(CustomLine* _l){
        for(int i = 0; i<groups.size();i++){
            if(groups.mid(i,1).first().data() == dynamic_cast<QGraphicsItemGroup*>(_l->parentItem())){
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
QList<QList<CustomElipse*>*> poliLines;
//GROUP actualGroup;
QStack <DoneAction>lastItems;
QStack <DoneAction>redoItems;
QSharedPointer<QGraphicsItemGroup> group;
CustomElipse * lastPoint;
QList<QColor> _color;
QPushButton* up_btn;
};


#endif // GAGRAPHICSVIEW_H
