#ifndef CUSTOMLINE_H
#define CUSTOMLINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include <QPen>

//class CustomElipse;

class CustomLine: public QGraphicsLineItem,QObject
{
public:
    explicit CustomLine(QObject *parent = 0);
    //void setFirst(CustomElipse *initial){
    //    init = initial;
    //    if(final){
    //        this->setLine(initial->getCenter().x(),initial->getCenter().y(),final->getCenter().x(),final->getCenter().y());

       // }
   // }
    void mouseMove(QGraphicsSceneMouseEvent *event){
        mouseMoveEvent(event);
    }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton) {
            if(event->modifiers() == Qt::ShiftModifier) {
                qDebug() << "Custom item left clicked with shift key.";

            } else if(event->modifiers() == Qt::AltModifier){
                qDebug() << "Custom item left clicked with alt key.";

            } else {
                qDebug() << "Custom item left clicked.";
                QGraphicsItem::mousePressEvent(event);
                event->accept();
            }
        } else if(event->button() == Qt::RightButton) {
            qDebug() << "Custom item right clicked.";
            event->ignore();
        }
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->modifiers() == Qt::AltModifier && _isResizing){

        } else if(event->modifiers() != Qt::AltModifier) {
            qDebug() << "Custom item moved.";
            QGraphicsItem::mouseMoveEvent(event);
            qDebug()<<"moved"<<pos();
        }
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->modifiers() == Qt::AltModifier && _isResizing) {
            _isResizing = false;
        } else if(event->modifiers() != Qt::ShiftModifier) {
            QGraphicsItem::mouseReleaseEvent(event);
        }
    }

private:
    //CustomElipse * init;
    //CustomElipse * final;
    bool _isResizing;
};


#endif // CUSTOMLINE_H
