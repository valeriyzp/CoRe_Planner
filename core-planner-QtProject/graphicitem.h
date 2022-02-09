#ifndef GRAPHICITEM_H
#define GRAPHICITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QtMath>

#include "points.h"

struct GraphicItemInfo{
    QString Type;
    QString Value;
    double X;
    double Y;
    double Width;
    double Height;
    double Angle;
};

enum CornerFlags{
    Top = 1,
    Bottom = 2,
    Left = 4,
    Right = 8,
    TopLeft = Top|Left,
    TopRight = Top|Right,
    BottomLeft = Bottom|Left,
    BottomRight = Bottom|Right
};

class MdiChild;

class GraphicItem : public QObject, public QGraphicsItem
{
public:
    points MidlePoints;
    double Width;
    double Height;
    int FlagCorner;
    bool IsEditNow;
    bool IsResizeModNow;
    int SizeOfPoint;
    double MinimumWidth;
    double MinimumHeight;
    double CurrentAngleOfRotation;
    QPointF ClickedPointOnScene;
    QPointF m_shiftMouseCoords;
    MdiChild *ParenWithScene;
    bool IsSceneEdited;

    GraphicItem(double setWidth, double setHeight, MdiChild *MdiChildParent, QObject *parent = 0);
    ~GraphicItem();
    virtual QString GetType() = 0;
    double GetHeight() {return Height;}
    double GetWidth() {return  Width;}
    double GetRotationAngle() {return this->rotation();}
    void SetRotationAngle(double RotationAngleToSet) {this->setRotation(RotationAngleToSet);}
    void SetHeight(double HeightToSet) {Height = HeightToSet > MinimumHeight ? HeightToSet : MinimumHeight;}
    void SetWidth(double WidthToSet) {Width = WidthToSet > MinimumWidth ? WidthToSet : MinimumWidth;}
    void SetUnActive() {IsEditNow = false;}
    virtual GraphicItemInfo GetItemInfo() = 0;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void ResetCursor(double CursorX, double CursorY, bool MouseMove);
    void SetPoints();
};

#endif // GRAPHICITEM_H
