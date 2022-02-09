#ifndef POINTS_H
#define POINTS_H

#include <QPointF>

class points
{
private:
    QPointF TopMinimumCenter;
    QPointF LeftMinimumCenter;
    QPointF RightMinimumCenter;
    QPointF BottomMinimumCenter;

public:
    points();
    void SetTopMinimumCenter(QPointF point) {TopMinimumCenter = point;}
    void SetLeftMinimumCenter(QPointF point) {LeftMinimumCenter = point;}
    void SetRightMinimumCenter(QPointF point) {RightMinimumCenter = point;}
    void SetBottomMinimumCenter(QPointF point) {BottomMinimumCenter = point;}
    QPointF GetTopMinimumCenter() {return TopMinimumCenter;}
    QPointF GetLeftMinimumCenter() {return LeftMinimumCenter;}
    QPointF GetRightMinimumCenter() {return RightMinimumCenter;}
    QPointF GetBottomMinimumCenter() {return BottomMinimumCenter;}
};

#endif // POINTS_H
