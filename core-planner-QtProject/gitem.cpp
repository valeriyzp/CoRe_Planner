#include <cmath>
#include "gitem.h"

GItem::GItem(QObject *parent) : QObject(parent), QGraphicsItem()
{
    setAcceptHoverEvents(true);
}

GItem::~GItem()
{

}

double GetAngleABC(QPointF a, QPointF b, QPointF c)
{
    QPointF ab(b.x() - a.x(), b.y() - a.y());
    QPointF cb(b.x() - c.x(), b.y() - c.y());

    double dot = (ab.x() * cb.x() + ab.y() * cb.y()); // dot product
    double cross = (ab.x() * cb.y() - ab.y() * cb.x()); // cross product

    float alpha = atan2(cross, dot);

    return (alpha * 180. / 3.14 + 0.5);
}

QRectF GItem::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

void GItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30, -30, 60, 60);

    if (isPressed) {
        QPen pointpen(Qt::black);
        pointpen.setWidth(6);
        painter->setPen(pointpen);

        QPoint leftTop, rightTop, leftDown, rightDown;

        leftTop.setX(-27);
        rightTop.setX(27);

        leftTop.setY(-27);
        rightTop.setY(-27);

        leftDown.setX(-27);
        rightDown.setX(27);

        leftDown.setY(27);
        rightDown.setY(27);

        painter->drawPoint(leftTop);
        painter->drawPoint(rightTop);
        painter->drawPoint(leftDown);
        painter->drawPoint(rightDown);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    isPressed = !isPressed;
    qDebug() << "Pressed";
    this->update();
    Q_UNUSED(event);
}

void GItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << ")(POINT:" << mapToScene(event->pos()) << '\t' << mapToScene(boundingRect().center());

    if (isPressed) {
        QPointF pt = event->pos();

        qreal drx = pt.x(); //- rect().right();    // Distance between the mouse and the right

        qreal dby = pt.y(); //- rect().top();      // Distance between the mouse and the top

        if (drx <= -25 || drx >= 25 || dby <= -25 || dby >= 25)
            setCursor(Qt::SizeBDiagCursor);
        else
            setCursor(Qt::ArrowCursor);
    } else {
        setCursor(Qt::ArrowCursor);
    }
}

void GItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */

    if (isPressed) {
        angle = -GetAngleABC(mapToScene(event->pos()), mapToScene(boundingRect().center()), TESTpos);

        if (angle < 0) {
            angle = 180 + angle;
        }

        if (angle) {
            this->setRotation(angle);
        }

        //координаты мыши относительно поля mapToScene(event->pos());
        //mapToScene(event->pos());
        //координаты центра прямоугольника относительно поля mapToScene(boundingRect().center());
        //mapToScene(boundingRect().center());

    } else {
        this->setPos(mapToScene(event->pos() + m_shiftMouseCoords));
    }
}

void GItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */

    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    TESTpos = event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void GItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);

    // angle += 30;
    //this->setRotation(angle);
}
