#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSettings>
#include <QTranslator>
#include <QtWidgets>
#include "ui_mainwindow.h"
#include "jsondata.h"
#include "aboutwindow.h"
#include "mdichild.h"
#include "graphicitem.h"
#include "itembycolor.h"
#include "itembypicture.h"
#include "fileopen.h"
#include "itemeditwindow.h"
#include "formcreate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MdiChild *activeMdiChild() const;
    void loadProject(QWidget *widget);
    DataBase database;
    int uniqueProjectID = 1;

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionClose_triggered();
    void on_actionHelp_triggered();
    void on_actionAbout_triggered();
    void on_listViewBuildTools_clicked(const QModelIndex &index);
    void on_listViewFurnitureTools_clicked(const QModelIndex &index);
    void on_listViewDecorTools_clicked(const QModelIndex &index);
    void on_actionUk_triggered();
    void on_actionEn_triggered();
    void on_actionRu_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionDelete_triggered();
    void on_actionClear_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionSetItemSize_triggered();

private:
    void saveSettings();
    QString loadSettings();
    Ui::MainWindow *ui;

    QStandardItemModel *modelBuildTools;
    QSortFilterProxyModel *proxyModelBuildTools;
    QStandardItemModel *modelFurnitureTools;
    QSortFilterProxyModel *proxyModelFurnitureTools;
    QStandardItemModel *modelDecorTools;
    QSortFilterProxyModel *proxyModelDecorTools;

    int FilesCount = 0;
    void setupOtherUi();
    void setupBuildTools();
    void setupFurnitureTools();
    void setupDecorTools();

    QSettings*settings;
    QTranslator* translator;
    void changeTranslator(QString postfix);
    void changeEvent(QEvent *event);
};

#endif // MAINWINDOW_H
