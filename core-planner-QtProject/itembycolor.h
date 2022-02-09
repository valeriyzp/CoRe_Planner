#ifndef ITEMBYCOLOR_H
#define ITEMBYCOLOR_H

#include "graphicitem.h"

class ItemByColor : public GraphicItem
{
public:
    ItemByColor(double setWidth, double setHeight, QColor setColor, MdiChild *MdiChildParent, QObject *parent = 0);
    QString GetType() {return "Color";}
    GraphicItemInfo GetItemInfo();

private:
    QColor ColorOfItem;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ITEMBYCOLOR_H
