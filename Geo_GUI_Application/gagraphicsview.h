#ifndef GAGRAPHICSVIEW_H
#define GAGRAPHICSVIEW_H

#define MAX_GROUPS 8

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QStack>
#include <QDebug>
#include <QPointF>
#include "customelipse.h"
#include <QPushButton>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>


class CustomGraphicsView : public QGraphicsView
{

public:
    typedef enum {ADD,DEL,JOIN,SPLIT,MOVE,NONE} ACTION;
    struct DoneAction
    {
        ACTION a = NONE;
        CustomElipse* point;
        QGraphicsItemGroup* g;

    };
    explicit CustomGraphicsView(QWidget *parent = 0);
    int current;
    std::string _file;
    std::string current_time();
    std::string current_date();
    bool exists_file (const std::string& name);
    void CreateLogFile();
    void WriteLogFile(const char* szString);

    void setToggle(bool t);
    void setPaint(int paint);
    void addElipse(QMouseEvent *e);
    QGraphicsScene* getGraphicsScene();
    void setUpdater(QPushButton* _ui);
    void setStereoPlot(QGraphicsView* _stereo);
    void setSceneG(QGraphicsScene* extsc);
    void setGroup(int g);
    void setGroupVisibility(int vis, bool bvis);
    void setGroupColor(int position, QColor _new);
    QColor getGroupColor(int group);
    QColor getCurrentColor();
    QList<CustomElipse*>* getPolilines(int _group);
    QList<CustomElipse*>* getCurrentGroupPolilines();
    QList<QList<CustomElipse*>*> getAllPolilines();

    void removeLastPoint();
    void redoLastPoint();
    QGraphicsScene* getScene();
    int getNumber(CustomElipse* it);
    int getNumber(CustomLine* _l);
    QGraphicsItemGroup* getGroup(int number);
    void addPolylineGroup(int group, CustomElipse*poly);
    void clear();
signals:
void sendMousePoint(QPointF point);

public slots:
void mousePressEvent(QMouseEvent * e);
void mouseMoveEvent(QMouseEvent * e);

private:
QGraphicsScene * scene;
bool toggle;
int paint;
QPen pen;
QPen penerase;
QBrush brush;
QBrush brusherase;
QList<QGraphicsItemGroup*> groups;
QList<CustomElipse*> lastPoints;
QList<QList<CustomElipse*>*> poliLines;
QStack <DoneAction>lastItems;
QStack <DoneAction>redoItems;
QGraphicsItemGroup* group;
CustomElipse * lastPoint;
QList<QColor> _color;
QPushButton* up_btn;
QGraphicsView* stereoplot;
};


#endif // GAGRAPHICSVIEW_H
