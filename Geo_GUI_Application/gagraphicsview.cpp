#include "gagraphicsview.h"
#include "mainwindow.h"
#include <QPointF>
#include <QDebug>

GaGraphicsView::GaGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
    {
    scene = new QGraphicsScene();
    this->setSceneRect(50, 50, 350, 350);
    this->setScene(scene);
    this->setToggle(false);
    this->setPaint(false);

    }
void GaGraphicsView::mousePressEvent(QMouseEvent * e)
{
    if(toggle){
        if(paint == 1){
            pen.setColor(QColor(255,255,0));
            brush = QBrush(Qt::SolidPattern);
            brush.setColor(QColor(255,255,0));
            double rad = 1;
            QPointF pt = mapToScene(e->pos());
            qDebug()<<scene->addEllipse(pt.x()-rad, pt.y()-rad, rad+2.0, rad+2.0,
            pen, brush);
        }if(paint == 2){
            pen.setColor(QColor(0,0,0));
            brush.setColor(QColor(0,0,0));
            double rad = 1;
            QPointF pt = mapToScene(e->pos());
            scene->addEllipse(pt.x()-rad, pt.y()-rad, rad+2.0, rad+2.0,
            pen, brush);
            qDebug()<<scene->items();


        }
    }
}
void GaGraphicsView::setToggle(bool t){
    this->toggle = t;
}
void GaGraphicsView::setPaint(int p){
    this->paint = p;
}
