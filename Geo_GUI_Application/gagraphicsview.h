#ifndef GAGRAPHICSVIEW_H
#define GAGRAPHICSVIEW_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>

class GaGraphicsView : public QGraphicsView
{
Q_OBJECT
public:
explicit GaGraphicsView(QWidget *parent = 0);
void setToggle(bool t);

signals:
void sendMousePoint(QPointF point);

public slots:
void mousePressEvent(QMouseEvent * e);

private:
QGraphicsScene * scene;
bool toggle;
};


#endif // GAGRAPHICSVIEW_H
