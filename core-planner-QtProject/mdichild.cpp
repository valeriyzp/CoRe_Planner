#include "mdichild.h"

MdiChild::MdiChild(MainWindow *Main, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiChild)
{
    ui->setupUi(this);
    MainWind = Main;
    Width = 2000; Height = 1000;
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0,0,Width,Height);
    ui->graphicsView->setScene(scene);

    SaveFileInfo.ParenWithScene = this;
    SaveFileInfo.FileName = this->windowTitle();
    DrawGrid();
    SaveFileInfo.InitHistory();
    VersionOfScene = 0;
    MaximumVersionOfScene = 0;
    AfterUndo = false;
}

void MdiChild::SetSceneParametrs(int setWidth, int setHeight)
{
    DeleteGrid();
    Width = setWidth;
    Height = setHeight;
    scene->setSceneRect(0,0,Width,Height);
    DrawGrid();
}

MdiChild::~MdiChild()
{
    QString Message = tr("Зберегти проект ");
    Message += SaveFileInfo.FileName;
    Message += tr(" перед закриттям?");
    if(QMessageBox::Yes == QMessageBox::question(this, tr("Увага"), Message))
    {
        SaveFileInfo.Save(MainWind);
    }
    delete ui;
}

void MdiChild::addItem(QString Name, double setWidth, double setHeight)
{
    if(AfterUndo)
    {
        SaveFileInfo.DeleteHighVersions(VersionOfScene);
        AfterUndo = false;
        MaximumVersionOfScene = VersionOfScene;
    }

    ItemByPicture *item = new ItemByPicture(setWidth, setHeight, Name, this);
    item->setPos(scene->sceneRect().toRect().width()/2, scene->sceneRect().toRect().height()/2);
    scene->addItem(item);

    VersionOfScene++;
    MaximumVersionOfScene++;
    SaveFileInfo.SaveToHistory();
    SaveFileInfo.LoadFromHistory(VersionOfScene);
}

void MdiChild::addItem(QColor ItemColor, double setWidth, double setHeight)
{
    if(AfterUndo)
    {
        SaveFileInfo.DeleteHighVersions(VersionOfScene);
        AfterUndo = false;
        MaximumVersionOfScene = VersionOfScene;
    }

    ItemByColor *item = new ItemByColor(setWidth, setHeight, ItemColor, this);
    item->setPos(scene->sceneRect().toRect().width()/2, scene->sceneRect().toRect().height()/2);
    scene->addItem(item);

    VersionOfScene++;
    MaximumVersionOfScene++;
    SaveFileInfo.SaveToHistory();
    SaveFileInfo.LoadFromHistory(VersionOfScene);
}

void MdiChild::UpdateScene()
{
    scene->update();
}

void MdiChild::DrawHorizontalLines()
{
    for(int i = 0; i <= Height; i+=10)
    {
        QGraphicsLineItem *HLine = new QGraphicsLineItem();
        HLine->setLine(0,i,Width,i);
        if(i%100 == 0) HLine->setPen(QPen(Qt::darkGray));else HLine->setPen(QPen(Qt::lightGray));
        HorizontalLines.push_back(HLine);
        scene->addItem(HLine);
    }
}

void MdiChild::DrawVerticalLines()
{
    for(int i = 0; i <= Width; i+=10)
    {
        QGraphicsLineItem *VLine = new QGraphicsLineItem();
        VLine->setLine(i,0,i,Height);
        if(i%100 == 0) VLine->setPen(QPen(Qt::darkGray));else VLine->setPen(QPen(Qt::lightGray));
        VerticalLines.push_back(VLine);
        scene->addItem(VLine);
    }
}

void MdiChild::DrawGrid()
{
    if(VerticalLines.size() == 0) DrawVerticalLines();
    if(HorizontalLines.size() == 0) DrawHorizontalLines();
}

void MdiChild::DeleteGrid()
{
    while(HorizontalLines.size() > 0)
    {
        delete HorizontalLines.back();
        HorizontalLines.pop_back();
    }
    while(VerticalLines.size() > 0)
    {
        delete VerticalLines.back();
        VerticalLines.pop_back();
    }
}

void MdiChild::SaveAsImage(QString NameOfFile)
{
    DeleteGrid();

    QImage image(int(scene->sceneRect().toRect().width()), int(scene->sceneRect().toRect().height()), QImage::Format_ARGB32);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter);
    image.save(NameOfFile);

    DrawGrid();
}

void MdiChild::setScaleToView(double X, double Y)
{
    ui->graphicsView->scale(X, Y);
}
