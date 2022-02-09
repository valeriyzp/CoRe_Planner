#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupOtherUi();
    database.connectToDataBase();
    settings = new QSettings("settings.ini", QSettings::IniFormat, this);
    changeTranslator(loadSettings());
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete settings;
    delete ui;
}

void MainWindow::setupOtherUi()
{
    setupBuildTools();
    setupFurnitureTools();
    setupDecorTools();
}
void MainWindow::saveSettings()
{
    if(ui->actionRu->isChecked())
    {
        settings->setValue("language","ru");
    }
    else if(ui->actionEn->isChecked())
    {
        settings->setValue("language","en");
    }
    else
    {
        settings->setValue("language","uk");
    }
    settings->setValue("geometry",geometry());
}
QString MainWindow::loadSettings()
{
    setGeometry(settings->value("geometry",QRect(50,50,700,460)).toRect());
    return settings->value("language","uk").toString();
}

void MainWindow::setupBuildTools()
{
    modelBuildTools = new QStandardItemModel(this);
    proxyModelBuildTools = new QSortFilterProxyModel(this);

    modelBuildTools->insertColumn(0);
    int numRows = 4;
    modelBuildTools->insertRows(0, numRows);

    modelBuildTools->setData(modelBuildTools->index(0, 0), QPixmap(":/list/build/wall"), Qt::DecorationRole);
    modelBuildTools->setData(modelBuildTools->index(0, 0), "Стіна", Qt::EditRole);
    modelBuildTools->setData(modelBuildTools->index(1, 0), QPixmap(":/list/build/window"), Qt::DecorationRole);
    modelBuildTools->setData(modelBuildTools->index(1, 0), "Вікно", Qt::EditRole);
    modelBuildTools->setData(modelBuildTools->index(2, 0), QPixmap(":/list/build/door"), Qt::DecorationRole);
    modelBuildTools->setData(modelBuildTools->index(2, 0), "Двері", Qt::EditRole);
    modelBuildTools->setData(modelBuildTools->index(3, 0), QPixmap(":/list/build/door-garage"), Qt::DecorationRole);
    modelBuildTools->setData(modelBuildTools->index(3, 0), "Гаражні\nдвері", Qt::EditRole);

    proxyModelBuildTools->setSourceModel(modelBuildTools);
    proxyModelBuildTools->setFilterKeyColumn(0);
    ui->listViewBuildTools->setModel(modelBuildTools);
}

void MainWindow::setupFurnitureTools()
{
    modelFurnitureTools = new QStandardItemModel(this);
    proxyModelFurnitureTools = new QSortFilterProxyModel(this);

    modelFurnitureTools->insertColumn(0);
    int numRows = 13;
    modelFurnitureTools->insertRows(0, numRows);

    modelFurnitureTools->setData(modelFurnitureTools->index(0, 0), QPixmap(":/list/furniture/sofa"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(0, 0), "Диван", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(1, 0), QPixmap(":/list/furniture/chair"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(1, 0), "Стілець", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(2, 0), QPixmap(":/list/furniture/bed-single"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(2, 0), "Ліжко", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(3, 0), QPixmap(":/list/furniture/bed-double"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(3, 0), "Двомісне\nліжко", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(4, 0), QPixmap(":/list/furniture/bedside"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(4, 0), "Тумбочка", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(5, 0), QPixmap(":/list/furniture/table-dining"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(5, 0), "Кухонний\nстіл", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(6, 0), QPixmap(":/list/furniture/table-rect"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(6, 0), "Квадратний\nстіл", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(7, 0), QPixmap(":/list/furniture/table-work"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(7, 0), "Робочий\nстіл", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(8, 0), QPixmap(":/list/furniture/table-glass"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(8, 0), "Скляний\nстіл", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(9, 0), QPixmap(":/list/furniture/table-wood"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(9, 0), "Диванний\nстолик", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(10, 0), QPixmap(":/list/furniture/oven"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(10, 0), "Духовка", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(11, 0), QPixmap(":/list/furniture/bath"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(11, 0), "Ванна", Qt::EditRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(12, 0), QPixmap(":/list/furniture/toilet"), Qt::DecorationRole);
    modelFurnitureTools->setData(modelFurnitureTools->index(12, 0), "Туалет", Qt::EditRole);

    proxyModelFurnitureTools->setSourceModel(modelFurnitureTools);
    proxyModelFurnitureTools->setFilterKeyColumn(0);
    ui->listViewFurnitureTools->setModel(modelFurnitureTools);
}

void MainWindow::setupDecorTools()
{
    modelDecorTools = new QStandardItemModel(this);
    proxyModelDecorTools = new QSortFilterProxyModel(this);

    modelDecorTools->insertColumn(0);
    int numRows = 2;
    modelDecorTools->insertRows(0, numRows);

    modelDecorTools->setData(modelDecorTools->index(0, 0), QPixmap(":/list/decor/plant"), Qt::DecorationRole);
    modelDecorTools->setData(modelDecorTools->index(0, 0), "Рослина", Qt::EditRole);
    modelDecorTools->setData(modelDecorTools->index(1, 0), QPixmap(":/list/decor/car"), Qt::DecorationRole);
    modelDecorTools->setData(modelDecorTools->index(1, 0), "Автомобіль", Qt::EditRole);

    proxyModelDecorTools->setSourceModel(modelDecorTools);
    proxyModelDecorTools->setFilterKeyColumn(0);
    ui->listViewDecorTools->setModel(modelDecorTools);
}

MdiChild *MainWindow::activeMdiChild() const
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

void MainWindow::on_actionNew_triggered()
{
    FormCreate *Window = new FormCreate(this);
    Window->show();
}

void MainWindow::on_actionOpen_triggered()
{
    FileOpen OpenFile(this);
    OpenFile.OpenFile();
}

void MainWindow::on_actionSave_triggered()
{
    if(activeMdiChild() != NULL)
    {
        activeMdiChild()->SaveFileInfo.Save(this);
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    if(activeMdiChild() != NULL)
    {
        activeMdiChild()->SaveFileInfo.SaveAs(this);
    }
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionHelp_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow *about = new AboutWindow();
    about->show();
}

void MainWindow::loadProject(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget);
    if (ui->mdiArea->subWindowList().size() == 1) window->showMaximized();
    else window->show();
}

void MainWindow::on_listViewBuildTools_clicked(const QModelIndex &index)
{
    MdiChild *activeChild = activeMdiChild();
    if (!activeChild)
        return;

    int i = index.row();

    switch (i) {
        case 0:
            activeChild->addItem(Qt::darkGray, 500, 30);
            break;
        case 1:
            activeChild->addItem(QColor("#87CEFA"), 100, 30);
            break;
        case 2:
            activeChild->addItem(QColor("#CB6843"), 80, 30);
            break;
        case 3:
            activeChild->addItem(QColor("#202020"), 250, 30);
            break;
    }
}

void MainWindow::on_listViewFurnitureTools_clicked(const QModelIndex &index)
{
    MdiChild *activeChild = activeMdiChild();
    if (!activeChild)
        return;

    int i = index.row();

    switch (i) {
        case 0:
            activeChild->addItem(QString(":scene/sofa"), 200, 70);
            break;
        case 1:
            activeChild->addItem(QString(":scene/chair"), 50, 60);
            break;
        case 2:
            activeChild->addItem(QString(":scene/bed-single"), 90, 200);
            break;
        case 3:
            activeChild->addItem(QString(":scene/bed-double"), 150, 200);
            break;
        case 4:
            activeChild->addItem(QString(":scene/bedside"), 50, 50);
            break;
        case 5:
            activeChild->addItem(QString(":scene/table-dining"), 180, 180);
            break;
        case 6:
            activeChild->addItem(QString(":scene/table-rect"), 140, 140);
            break;
        case 7:
            activeChild->addItem(QString(":scene/table-work"), 150, 90);
            break;
        case 8:
            activeChild->addItem(QString(":scene/table-glass"), 150, 90);
            break;
        case 9:
            activeChild->addItem(QString(":scene/table-wood"), 150, 70);
            break;
        case 10:
            activeChild->addItem(QString(":scene/oven"), 70, 70);
            break;
        case 11:
            activeChild->addItem(QString(":scene/bath"), 190, 80);
            break;
        case 12:
            activeChild->addItem(QString(":scene/toilet"), 50, 80);
            break;
    }
}

void MainWindow::on_listViewDecorTools_clicked(const QModelIndex &index)
{
    MdiChild *activeChild = activeMdiChild();
    if (!activeChild)
        return;

    int i = index.row();

    switch (i) {
        case 0:
            activeChild->addItem(QString(":/scene/plant"), 50, 50);
            break;
        case 1:
            activeChild->addItem(QString(":/scene/car"), 150, 350);
            break;
    }
}

void MainWindow::on_actionUk_triggered()
{
    changeTranslator("uk");

}

void MainWindow::on_actionEn_triggered()
{
    changeTranslator("en");

}

void MainWindow::on_actionRu_triggered()
{
    changeTranslator("ru");
}

void MainWindow::changeTranslator(QString postfix)
{
    if(postfix=="uk")
    {
        ui->actionEn->setChecked(false);
        ui->actionRu->setChecked(false);
        ui->actionUk->setChecked(true);
    }
    else if(postfix=="en")
    {
        ui->actionEn->setChecked(true);
        ui->actionRu->setChecked(false);
        ui->actionUk->setChecked(false);
    }
    else
    {
        ui->actionEn->setChecked(false);
        ui->actionRu->setChecked(true);
        ui->actionUk->setChecked(false);
    }
    QApplication::removeTranslator(translator);
    translator = new QTranslator(this);
    translator->load("Core_Planner_" + postfix);
    QApplication::installTranslator(translator);
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
       ui->retranslateUi(this);
       modelBuildTools->setData(modelBuildTools->index(0, 0), tr("Стіна"), Qt::EditRole);
       modelBuildTools->setData(modelBuildTools->index(1, 0), tr("Вікно"), Qt::EditRole);
       modelBuildTools->setData(modelBuildTools->index(2, 0), tr("Двері"), Qt::EditRole);
       modelBuildTools->setData(modelBuildTools->index(3, 0), tr("Гаражні\nдвері"), Qt::EditRole);

       modelFurnitureTools->setData(modelFurnitureTools->index(0, 0),  tr("Диван"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(1, 0),  tr("Стілець"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(2, 0),  tr("Ліжко"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(3, 0),  tr("Двомісне\nліжко"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(4, 0),  tr("Тумбочка"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(5, 0),  tr("Кухонний\nстіл"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(6, 0),  tr("Квадратний\nстіл"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(7, 0),  tr("Робочий\nстіл"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(8, 0),  tr("Скляний\nстіл"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(9, 0),  tr("Диванний\nстолик"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(10, 0), tr("Духовка"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(11, 0), tr("Ванна"), Qt::EditRole);
       modelFurnitureTools->setData(modelFurnitureTools->index(12, 0), tr("Туалет"), Qt::EditRole);

       modelDecorTools->setData(modelDecorTools->index(0, 0), tr("Рослина"), Qt::EditRole);
       modelDecorTools->setData(modelDecorTools->index(1, 0), tr("Автомобіль"), Qt::EditRole);
    }
    else
    {
        QMainWindow::changeEvent(event);
    }

}

void MainWindow::on_actionUndo_triggered()
{
    if(activeMdiChild() != NULL)
    {
        if(activeMdiChild()->VersionOfScene > 0)
        {
            activeMdiChild()->AfterUndo = true;
            activeMdiChild()->VersionOfScene--;
            activeMdiChild()->SaveFileInfo.LoadFromHistory(activeMdiChild()->VersionOfScene);
        }
    }
}

void MainWindow::on_actionRedo_triggered()
{
    if(activeMdiChild() != NULL)
    {
        if(activeMdiChild()->VersionOfScene < activeMdiChild()->MaximumVersionOfScene)
        {
            activeMdiChild()->VersionOfScene++;
            activeMdiChild()->SaveFileInfo.LoadFromHistory(activeMdiChild()->VersionOfScene);
        }
    }
}

void MainWindow::on_actionDelete_triggered()
{
    if(activeMdiChild() != NULL && activeMdiChild()->LastActive != NULL)
    {
        delete activeMdiChild()->LastActive;
        activeMdiChild()->LastActive = NULL;
        if(activeMdiChild()->AfterUndo)
        {
            activeMdiChild()->SaveFileInfo.DeleteHighVersions(activeMdiChild()->VersionOfScene);
            activeMdiChild()->AfterUndo = false;
            activeMdiChild()->MaximumVersionOfScene = activeMdiChild()->VersionOfScene;
        }
        activeMdiChild()->VersionOfScene++;
        activeMdiChild()->MaximumVersionOfScene++;
        activeMdiChild()->SaveFileInfo.SaveToHistory();
        activeMdiChild()->SaveFileInfo.LoadFromHistory(activeMdiChild()->VersionOfScene);
    }

}

void MainWindow::on_actionClear_triggered()
{
    if(activeMdiChild() != NULL)
    {
        activeMdiChild()->DeleteGrid();
        activeMdiChild()->scene->clear();
        activeMdiChild()->DrawGrid();
        if(activeMdiChild()->AfterUndo)
        {
            activeMdiChild()->SaveFileInfo.DeleteHighVersions(activeMdiChild()->VersionOfScene);
            activeMdiChild()->AfterUndo = false;
            activeMdiChild()->MaximumVersionOfScene = activeMdiChild()->VersionOfScene;
        }
        activeMdiChild()->VersionOfScene++;
        activeMdiChild()->MaximumVersionOfScene++;
        activeMdiChild()->SaveFileInfo.SaveToHistory();
        activeMdiChild()->SaveFileInfo.LoadFromHistory(activeMdiChild()->VersionOfScene);
    }
}

void MainWindow::on_actionZoomIn_triggered()
{
    if(activeMdiChild() != NULL) activeMdiChild()->setScaleToView(1.5, 1.5);
}

void MainWindow::on_actionZoomOut_triggered()
{
    if(activeMdiChild() != NULL) activeMdiChild()->setScaleToView(0.75, 0.75);
}

void MainWindow::on_actionSetItemSize_triggered()
{
    if(activeMdiChild() != NULL && activeMdiChild()->LastActive != NULL)
    {
        ItemEditWindow *window = new ItemEditWindow(this, activeMdiChild());
        window->show();
    }
}
