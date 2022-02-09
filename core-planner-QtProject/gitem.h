#ifndef GITEM_H
#define GITEM_H

#include <QtWidgets>

class GItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GItem(QObject *parent = nullptr);
    ~GItem();

    int angle = 0;
    bool isPressed = false;

signals:

public slots:

private:
    QPointF TESTpos;
    QPointF m_shiftMouseCoords;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    QPointF startPosPoint;
};

#endif // GITEM_H
