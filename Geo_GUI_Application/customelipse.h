#ifndef CUSTOMELIPSE_H
#define CUSTOMELIPSE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include <QPen>
#include <QSharedPointer>

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
    void setGroupNumber(int number){
        this->groupnumber = number;
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
    int getGroupNumber(){
        return groupnumber;
    }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton) {
            if(event->modifiers() == Qt::ShiftModifier) {
                //qDebug() << "Custom item left clicked with shift key.";

            } else if(event->modifiers() == Qt::AltModifier){
                //qDebug() << "Custom item left clicked with alt key.";

            } else {
                //qDebug() << "Custom item left clicked.";
                event->accept();
            }
        } else if(event->button() == Qt::RightButton) {
            //qDebug() << "Custom item right clicked.";
            event->ignore();
        }
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsItem::mouseMoveEvent(event);
        center = event->scenePos();
        event->accept();
        if(event->modifiers() == Qt::AltModifier && _isResizing){

        }
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsItem::mouseReleaseEvent(event);
        event->accept();
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
    int groupnumber = 0;
    bool _isResizing;
};

class CustomLine: public QGraphicsLineItem,QObject
{
public:
    explicit CustomLine(QObject *parent = 0);
    void setInitial(CustomElipse *initial){
        init = initial;
        if(final != nullptr){
            this->setPos(init->getCenter());
            this->setLine(0,0,final->getCenter().x()-init->getCenter().x(),final->getCenter().y()-init->getCenter().y());

        }else {
             this->setLine(0,0,0,0);
        }

    }
    void setFinal(CustomElipse *fin){
        final = fin;
        if(init!= nullptr){
            this->setPos(init->getCenter());
            this->setLine(0,0,final->getCenter().x()-init->getCenter().x(),final->getCenter().y()-init->getCenter().y());

        }else {
            this->setLine(0,0,0,0);
        }
    }

    void updatel(){
        this->setPos(init->getCenter());
        this->setLine(0,0,final->getCenter().x()-init->getCenter().x(),final->getCenter().y()-init->getCenter().y());

    }
    CustomElipse * getInit(){
        return init;
    }
    CustomElipse * getFinal(){
        return final;
    }

    void mouseMove(QGraphicsSceneMouseEvent *event){
        mouseMoveEvent(event);
    }

    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return UserType+2;
    }
    bool hasFinal(){
        return final != nullptr;
    }

    bool hasInital(){
        return init != nullptr;
    }
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton) {
            if(event->modifiers() == Qt::ShiftModifier) {
                //qDebug() << "Custom item left clicked with shift key.";

            } else if(event->modifiers() == Qt::AltModifier){
                //qDebug() << "Custom item left clicked with alt key.";

            } else {
                //qDebug() << "Custom item left clicked.";
                event->accept();
            }
        } else if(event->button() == Qt::RightButton) {
            //qDebug() << "Custom item right clicked.";
            event->ignore();
        }
    }
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        //qDebug() << "Custom item moved.";
        if(event->modifiers() == Qt::AltModifier && _isResizing){

        } else if(event->modifiers() != Qt::AltModifier) {
            //qDebug() << "Custom item moved.";
            QGraphicsItem::mouseMoveEvent(event);
            //qDebug()<<"moved"<<pos();
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
