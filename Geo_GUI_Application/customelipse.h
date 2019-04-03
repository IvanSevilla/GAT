#ifndef CUSTOMELIPSE_H
#define CUSTOMELIPSE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include <QPen>

class CustomLine;

class CustomElipse: public QGraphicsEllipseItem,QObject
{
public:
    explicit CustomElipse(QObject *parent = 0);
    bool hasInitLine(){
        return initLine != nullptr;
    }
    bool hasFinalLine(){
        return finalLine != nullptr;
    }
    void setInitLine(CustomLine *init){
        initLine = init;
    }
    void setFinalLine(CustomLine *fin){
        finalLine = fin;
    }
    void setCenter(QPointF c){
        center = c;
    }
    CustomLine* getInitLine(){
        return initLine;
    }
    CustomLine* getFinalLine(){
        return finalLine;
    }
    QPointF getCenter(){
        return center;
    }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug()<<"here";
        if(event->button() == Qt::LeftButton) {
            if(event->modifiers() == Qt::ShiftModifier) {
                qDebug() << "Custom item left clicked with shift key.";

            } else if(event->modifiers() == Qt::AltModifier){
                qDebug() << "Custom item left clicked with alt key.";

            } else {
                qDebug() << "Custom item left clicked.";
                event->accept();
            }
        } else if(event->button() == Qt::RightButton) {
            qDebug() << "Custom item right clicked.";
            event->ignore();
        }
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << "Custom item moved.";

        event->accept();
        if(event->modifiers() == Qt::AltModifier && _isResizing){

        } else if(event->modifiers() != Qt::AltModifier) {
            qDebug() << "Custom item moved.";
            QGraphicsItem::mouseMoveEvent(event);
            qDebug()<<"moved"<<pos();
        }
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug()<<"here";
        QGraphicsItem::mouseReleaseEvent(event);
        center = event->scenePos();
        event->ignore();
        if(event->modifiers() == Qt::AltModifier && _isResizing) {
            _isResizing = false;
        } else if(event->modifiers() != Qt::ShiftModifier) {
            QGraphicsItem::mouseReleaseEvent(event);
        }
    }

    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return UserType+1;
    }



private:
    QPointF center;
    CustomLine *initLine = nullptr;
    CustomLine *finalLine = nullptr;

    //bool initial, final = false;
    bool _isResizing;
};

class CustomLine: public QGraphicsLineItem,QObject
{
public:
    explicit CustomLine(QObject *parent = 0);
    void setInitial(CustomElipse *initial){
        init = initial;
        if(final != nullptr){
            this->setLine(init->getCenter().x(),init->getCenter().y(),final->getCenter().x(),final->getCenter().y());

        }else {
             this->setLine(init->getCenter().x(),init->getCenter().y(),init->getCenter().x(),init->getCenter().y());
        }

    }
    void setFinal(CustomElipse *fin){
        final = fin;
        if(init!= nullptr){
            this->setLine(init->getCenter().x(),init->getCenter().y(),final->getCenter().x(),final->getCenter().y());

        }else {
            this->setLine(final->getCenter().x(),final->getCenter().y(),final->getCenter().x(),final->getCenter().y());
        }
    }

    void updatel(){
        qDebug()<<"noooo";
        this->setLine(init->getCenter().x(),init->getCenter().y(),final->getCenter().x(),final->getCenter().y());
        qDebug()<<init->getCenter();
    }

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
        qDebug() << "Custom item moved.";
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
    CustomElipse * init = nullptr;
    CustomElipse * final = nullptr;
    bool _isResizing;
};


#endif // CUSTOMELIPSE_H
