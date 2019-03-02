#ifndef GAGRAPHICSVIEW_H
#define GAGRAPHICSVIEW_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <armadillo>

class GaGraphicsView : public QGraphicsView
{
Q_OBJECT
public:
explicit GaGraphicsView(QWidget *parent = 0);
void setToggle(bool t);
void setPaint(int paint);
void addElipse(QMouseEvent *e);
QGraphicsScene* getGraphicsScene(){
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
QBrush brush;
std::map<arma::vec2,QGraphicsItem*> itemList;
};


#endif // GAGRAPHICSVIEW_H
