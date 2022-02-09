#ifndef MDICHILD_H
#define MDICHILD_H

#include <QtWidgets>
#include "ui_mdichild.h"
#include "graphicitem.h"
#include "itembypicture.h"
#include "itembycolor.h"
#include "filesave.h"

namespace Ui {
class MdiChild;
}

class FileSave;

class MdiChild : public QWidget
{
    Q_OBJECT

public:
    explicit MdiChild(MainWindow *Main, QWidget *parent = 0);
    ~MdiChild();
    GraphicItem *LastActive = 0;
    QGraphicsScene *scene;
    void addItem(QString Name, double setWidth, double setHeight);
    void addItem(QColor ItemColor, double setWidth, double setHeight);
    void UpdateScene();
    void SaveAsImage(QString NameOfFile);
    void setScaleToView(double X, double Y);
    void DrawGrid();
    void DeleteGrid();
    void SetSceneParametrs(int setWidth, int setHeight);
    FileSave SaveFileInfo;
    int VersionOfScene;
    int MaximumVersionOfScene;
    bool AfterUndo;

private:
    Ui::MdiChild *ui;
    MainWindow *MainWind;
    int Width, Height;
    QVector<QGraphicsLineItem*> HorizontalLines;
    QVector<QGraphicsLineItem*> VerticalLines;
    void DrawHorizontalLines();
    void DrawVerticalLines();
};

#endif // MDICHILD_H
