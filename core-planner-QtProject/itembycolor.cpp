#include "itembycolor.h"

ItemByColor::ItemByColor(double setWidth, double setHeight, QColor setColor, MdiChild *MdiChildParent, QObject *parent)
    : GraphicItem(setWidth, setHeight, MdiChildParent, parent)
{
    ColorOfItem = setColor;
}

GraphicItemInfo ItemByColor::GetItemInfo()
{
    GraphicItemInfo Information;
    Information.Angle = this->rotation();
    Information.Width = this->Width;
    Information.Height = this->Height;
    Information.X = this->pos().x();
    Information.Y = this->pos().y();
    Information.Type = "Color";
    Information.Value = ColorOfItem.name();
    return Information;
}

void ItemByColor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    QPen pointpen(Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(ColorOfItem);
    painter->drawRect(int(-Width/2), int(-Height/2), int(Width), int(Height));

    if(IsEditNow)
    {
        painter->setPen(Qt::DashLine);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(int(-Width/2), int(-Height/2), int(Width), int(Height));
        pointpen.setWidth(SizeOfPoint);
        painter->setPen(pointpen);

        int LeftTopPointX = int(-Width/2+SizeOfPoint/2);
        int LeftTopPointY = int(-Height/2+SizeOfPoint/2);
        int RightBottomPointX = int(Width)%2 == 0 ? int(Width-Width/2-SizeOfPoint/2) : int(Width-Width/2-SizeOfPoint/2+1);
        int RightBottomPointY = int(Height)%2 == 0 ? int(Height-Height/2-SizeOfPoint/2) : int(Height-Height/2-SizeOfPoint/2+1);

        painter->drawPoint(LeftTopPointX, LeftTopPointY);
        painter->drawPoint(RightBottomPointX, LeftTopPointY);
        painter->drawPoint(LeftTopPointX, RightBottomPointY);
        painter->drawPoint(RightBottomPointX, RightBottomPointY);
    }
    painter->restore();
}
