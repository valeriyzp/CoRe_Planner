#include "itemeditwindow.h"

ItemEditWindow::ItemEditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditWindow)
{
    ui->setupUi(this);
}

ItemEditWindow::~ItemEditWindow()
{
    delete ui;
}

void ItemEditWindow::on_pushButtonApply_clicked()
{
    if(ui->doubleSpinBoxWidth->value()*100 >= 20)
        if(ui->doubleSpinBoxHeight->value()*100 >= 20)
            if(ui->doubleSpinBoxPosX->value()*100 >= 0 && ui->doubleSpinBoxPosX->value()*100 <= FormWithScene->scene->sceneRect().toRect().width())
                if(ui->doubleSpinBoxPosY->value()*100 >= 0 && ui->doubleSpinBoxPosY->value()*100 <= FormWithScene->scene->sceneRect().toRect().height())
                {
                    FormWithScene->LastActive->Width = ui->doubleSpinBoxWidth->value()*100;
                    FormWithScene->LastActive->Height = ui->doubleSpinBoxHeight->value()*100;
                    FormWithScene->LastActive->setPos(ui->doubleSpinBoxPosX->value()*100, ui->doubleSpinBoxPosY->value()*100);
                    FormWithScene->LastActive->setRotation(ui->doubleSpinBoxAngle->value());

                    if(FormWithScene->AfterUndo)
                    {
                        FormWithScene->SaveFileInfo.DeleteHighVersions(FormWithScene->VersionOfScene);
                        FormWithScene->AfterUndo = false;
                        FormWithScene->MaximumVersionOfScene = FormWithScene->VersionOfScene;
                    }
                    FormWithScene->VersionOfScene++;
                    FormWithScene->MaximumVersionOfScene++;
                    FormWithScene->SaveFileInfo.SaveToHistory();
                    FormWithScene->SaveFileInfo.LoadFromHistory(FormWithScene->VersionOfScene);

                    this->close();
                }
}

ItemEditWindow::ItemEditWindow(MainWindow *Main, MdiChild *Parent, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditWindow)
{
    ui->setupUi(this);
    FormWithScene = Parent;
    MainWin = Main;

    ui->doubleSpinBoxWidth->setValue(Parent->LastActive->GetWidth()/100);
    ui->doubleSpinBoxHeight->setValue(Parent->LastActive->GetHeight()/100);
    ui->doubleSpinBoxPosX->setValue(Parent->LastActive->pos().x()/100);
    ui->doubleSpinBoxPosY->setValue(Parent->LastActive->pos().y()/100);
    ui->doubleSpinBoxAngle->setValue(Parent->LastActive->rotation());

    QPixmap NullPicture = QPixmap(1,1);
    NullPicture.fill(QColor(0,0,0,0));
    setWindowIcon(QIcon(NullPicture));
}
