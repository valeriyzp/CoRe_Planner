#include "graphicitem.h"
#include "mdichild.h"

double GetAngleABC( QPointF A, QPointF B, QPointF C)
{
    QPointF AB( B.x() - A.x(), B.y() - A.y() );
    QPointF CB ( B.x() - C.x(), B.y() - C.y() );
    double ScalarProduct = (AB.x() * CB.x() + AB.y() * CB.y());
    double Proection = (AB.x() * CB.y() - AB.y() * CB.x());
    double RadianAngle = qAtan2(Proection, ScalarProduct);
    return -(RadianAngle * 180. / M_PI + 0.5);
}

GraphicItem::GraphicItem(double setWidth, double setHeight, MdiChild *MdiChildParent, QObject *parent) : QObject(parent), QGraphicsItem()
{
    IsEditNow = false;
    IsResizeModNow = false;
    SizeOfPoint = 6;
    MinimumWidth = 20;
    MinimumHeight = 20;
    CurrentAngleOfRotation = 0;
    SetHeight(setHeight);
    SetWidth(setWidth);
    ParenWithScene = MdiChildParent;
    setAcceptHoverEvents(true);
    IsSceneEdited = false;
    if(ParenWithScene->LastActive != NULL && ParenWithScene->LastActive != this) ParenWithScene->LastActive->SetUnActive();
    ParenWithScene->LastActive = this;
}

GraphicItem::~GraphicItem()
{

}

QRectF GraphicItem::boundingRect() const
{
    return QRectF (-Width/2,-Height/2,Width,Height);
}

void GraphicItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    IsEditNow = !IsEditNow;
    update();
}

void GraphicItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    ResetCursor(event->pos().x(), event->pos().y(), false);
}

void GraphicItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    IsSceneEdited = true;
    if(IsEditNow)
    {
        if(IsResizeModNow)
        {
            double dHeight = Height, dWidth = Width;
            switch(FlagCorner)
            {
                case Top:
                {
                    Height -= (event->pos().y() + Height/2);
                    if(Height >= MinimumHeight) this->setPos(mapToScene(0, (event->pos().y() + Height/2)));
                    else {Height = MinimumHeight; this->setPos(MidlePoints.GetBottomMinimumCenter());}

                    break;
                }
                case Bottom:
                {
                    Height += (event->pos().y() - Height/2);
                    if(Height >= MinimumHeight) this->setPos(mapToScene(0, (event->pos().y() - Height/2)));
                    else {Height = MinimumHeight; this->setPos(MidlePoints.GetTopMinimumCenter());}

                    break;
                }
                case Left:
                {
                    Width -= (event->pos().x() + Width/2);
                    if(Width >= MinimumWidth) this->setPos(mapToScene((event->pos().x() + Width/2), 0));
                    else {Width = MinimumWidth; this->setPos(MidlePoints.GetRightMinimumCenter());}

                    break;
                }
                case Right:
                {
                    Width += (event->pos().x() - Width/2);
                    if(Width >= MinimumWidth) this->setPos(mapToScene((event->pos().x() - Width/2), 0));
                    else {Width = MinimumWidth; this->setPos(MidlePoints.GetLeftMinimumCenter());}

                    break;
                }
                case TopLeft:
                {
                    Height -= (event->pos().y() + Height/2);
                    Width -= (event->pos().x() + Width/2);
                    Height = Height < MinimumHeight ? MinimumHeight : Height;
                    Width = Width < MinimumWidth ? MinimumWidth : Width;

                    dHeight -= Height;
                    dWidth -= Width;

                    this->setPos(mapToScene(dWidth/2, dHeight/2));

                    break;
                }
                case TopRight:
                {
                    Height -= (event->pos().y() + Height/2);
                    Width += (event->pos().x() - Width/2);
                    Height = Height < MinimumHeight ? MinimumHeight : Height;
                    Width = Width < MinimumWidth ? MinimumWidth : Width;

                    dHeight -= Height;
                    dWidth -= Width;

                    this->setPos(mapToScene(-dWidth/2, dHeight/2));

                    break;
                }
                case BottomLeft:
                {
                    Height += (event->pos().y() - Height/2);
                    Width -= (event->pos().x() + Width/2);
                    Height = Height < MinimumHeight ? MinimumHeight : Height;
                    Width = Width < MinimumWidth ? MinimumWidth : Width;

                    dHeight -= Height;
                    dWidth -= Width;

                    this->setPos(mapToScene(dWidth/2, -dHeight/2));

                    break;
                }
                case BottomRight:
                {
                    Height += (event->pos().y() - Height/2);
                    Width += (event->pos().x() - Width/2);
                    Height = Height < MinimumHeight ? MinimumHeight : Height;
                    Width = Width < MinimumWidth ? MinimumWidth : Width;

                    dHeight -= Height;
                    dWidth -= Width;

                    this->setPos(mapToScene(-dWidth/2, -dHeight/2));

                    break;
                }
            }
            update();
        }
        else
        {
            double Angle= GetAngleABC(mapToScene(event->pos()),mapToScene(0,0),ClickedPointOnScene);
            this->setRotation(CurrentAngleOfRotation+Angle);
        }
    }
    else
    {
        this->setPos(mapToScene(event->pos()).x() + m_shiftMouseCoords.x(), mapToScene(event->pos()).y()+m_shiftMouseCoords.y());
    }

    if (this->pos().x() < 0) this->setPos(0, pos().y());
    else if (this->pos().x() > ParenWithScene->scene->sceneRect().toRect().width()) this->setPos(ParenWithScene->scene->sceneRect().toRect().width(), pos().y());

    if (this->pos().y() < 0) this->setPos(pos().x(), 0);
    else if (this->pos().y() > ParenWithScene->scene->sceneRect().toRect().height()) this->setPos(pos().x(), ParenWithScene->scene->sceneRect().toRect().height());
}

void GraphicItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    CurrentAngleOfRotation=this->rotation();
    ClickedPointOnScene= mapToScene(event->pos());

    ResetCursor(event->pos().x(), event->pos().y(), true);
    SetPoints();

    if(ParenWithScene->LastActive != NULL && ParenWithScene->LastActive != this) ParenWithScene->LastActive->SetUnActive();
    ParenWithScene->LastActive = this;

    ParenWithScene->UpdateScene();
}

void GraphicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    ResetCursor(event->pos().x(), event->pos().y(), false);
    if(IsSceneEdited)
    {
        if(ParenWithScene->AfterUndo)
        {
            ParenWithScene->SaveFileInfo.DeleteHighVersions(ParenWithScene->VersionOfScene);
            ParenWithScene->AfterUndo = false;
            ParenWithScene->MaximumVersionOfScene = ParenWithScene->VersionOfScene;
        }
        ParenWithScene->VersionOfScene++;
        ParenWithScene->MaximumVersionOfScene++;
        ParenWithScene->SaveFileInfo.SaveToHistory();
        ParenWithScene->SaveFileInfo.LoadFromHistory(ParenWithScene->VersionOfScene);
        IsSceneEdited = false;
    }
}

void GraphicItem::ResetCursor(double CursorX, double CursorY, bool MouseMove)
{
    if(IsEditNow)
    {
        if(CursorX <= -Width/2+SizeOfPoint || CursorX >= Width/2-SizeOfPoint  || CursorY <= -Height/2+SizeOfPoint || CursorY >= Height/2-SizeOfPoint)
        {
            QString NameOfCursor;
            IsResizeModNow = true;
            FlagCorner = 0;
            if(CursorX <= (-Width/2 + SizeOfPoint)) FlagCorner |= Left;
            if(CursorX >= (Width/2 - SizeOfPoint)) FlagCorner |= Right;
            if(CursorY <= (-Height/2 + SizeOfPoint)) FlagCorner |= Top;
            if(CursorY >= (Height/2 - SizeOfPoint)) FlagCorner |= Bottom;
            switch(FlagCorner)
            {
                case Top:
                case Bottom:
                {
                    NameOfCursor = ":/cursors/ResizeV";
                    break;
                }
                case Left:
                case Right:
                {
                    NameOfCursor = ":/cursors/ResizeH";
                    break;
                }
                case TopLeft:
                case BottomRight:
                {
                    NameOfCursor = ":/cursors/ResizeD1";
                    break;
                }
                case TopRight:
                case BottomLeft:
                {
                    NameOfCursor = ":/cursors/ResizeD2";
                    break;
                }
            }

            QPixmap Item(NameOfCursor);
            QTransform trans = transform();
            trans.rotate(this->rotation());
            Item.transformed(trans);
            this->setCursor(Item.transformed(trans).scaled(24,24,Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {
            IsResizeModNow = false;
            this->setCursor(QPixmap(":/cursors/Rotation").scaled(24,24,Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
    else
    {
        if(MouseMove) this->setCursor(Qt::ClosedHandCursor);
        else this->setCursor(Qt::ArrowCursor);
    }
}

void GraphicItem::SetPoints()
{
    MidlePoints.SetTopMinimumCenter(mapToScene(0, - Height/2 + MinimumHeight/2));
    MidlePoints.SetLeftMinimumCenter(mapToScene(-Width/2 + MinimumWidth/2, 0));
    MidlePoints.SetRightMinimumCenter(mapToScene(Width - Width/2 - MinimumWidth/2, 0));
    MidlePoints.SetBottomMinimumCenter(mapToScene(0, Height - Height/2 - MinimumHeight/2));
}
