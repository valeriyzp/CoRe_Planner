#ifndef ITEMBYPICTURE_H
#define ITEMBYPICTURE_H

#include "graphicitem.h"

class ItemByPicture : public GraphicItem
{
public:
    ItemByPicture(double setWidth, double setHeight, QString PictureName, MdiChild *MdiChildParent, QObject *parent = 0);
    QString GetType() {return "Picture";}
    GraphicItemInfo GetItemInfo();

private:
    QString NameOfPicture;
    QImage PictureOfItem;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ITEMBYPICTURE_H
