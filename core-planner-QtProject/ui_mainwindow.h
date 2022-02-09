/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionClose;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionUk;
    QAction *actionRu;
    QAction *actionEn;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDelete;
    QAction *actionClear;
    QAction *actionSetItemSize;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabBuildTools;
    QVBoxLayout *verticalLayout;
    QListView *listViewBuildTools;
    QWidget *tabFurnitureTools;
    QVBoxLayout *verticalLayout_2;
    QListView *listViewFurnitureTools;
    QWidget *tabDecorTools;
    QVBoxLayout *verticalLayout_3;
    QListView *listViewDecorTools;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuLanguage;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 460);
        MainWindow->setMinimumSize(QSize(700, 460));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionNew->setShortcutContext(Qt::WindowShortcut);
        //actionNew->setShortcutVisibleInContextMenu(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHelp->setIconVisibleInMenu(false);
        //actionHelp->setShortcutVisibleInContextMenu(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setMenuRole(QAction::AboutRole);
        actionAbout->setIconVisibleInMenu(false);
        actionUk = new QAction(MainWindow);
        actionUk->setObjectName(QStringLiteral("actionUk"));
        actionUk->setCheckable(true);
        actionUk->setChecked(true);
        actionRu = new QAction(MainWindow);
        actionRu->setObjectName(QStringLiteral("actionRu"));
        actionRu->setCheckable(true);
        actionRu->setChecked(false);
        actionEn = new QAction(MainWindow);
        actionEn->setObjectName(QStringLiteral("actionEn"));
        actionEn->setCheckable(true);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionSetItemSize = new QAction(MainWindow);
        actionSetItemSize->setObjectName(QStringLiteral("actionSetItemSize"));
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(200, 401));
        tabWidget->setMaximumSize(QSize(200, 16777215));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        //tabWidget->setTabBarAutoHide(false);
        tabBuildTools = new QWidget();
        tabBuildTools->setObjectName(QStringLiteral("tabBuildTools"));
        verticalLayout = new QVBoxLayout(tabBuildTools);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listViewBuildTools = new QListView(tabBuildTools);
        listViewBuildTools->setObjectName(QStringLiteral("listViewBuildTools"));
        listViewBuildTools->setMinimumSize(QSize(194, 356));
        listViewBuildTools->setFrameShape(QFrame::NoFrame);
        listViewBuildTools->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewBuildTools->setProperty("showDropIndicator", QVariant(false));
        listViewBuildTools->setDefaultDropAction(Qt::IgnoreAction);
        listViewBuildTools->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(listViewBuildTools);

        QIcon icon1;
        icon1.addFile(QStringLiteral(":/tool-tabs/build"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabBuildTools, icon1, QString());
        tabFurnitureTools = new QWidget();
        tabFurnitureTools->setObjectName(QStringLiteral("tabFurnitureTools"));
        verticalLayout_2 = new QVBoxLayout(tabFurnitureTools);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listViewFurnitureTools = new QListView(tabFurnitureTools);
        listViewFurnitureTools->setObjectName(QStringLiteral("listViewFurnitureTools"));
        listViewFurnitureTools->setMinimumSize(QSize(194, 356));
        listViewFurnitureTools->setFrameShape(QFrame::NoFrame);
        listViewFurnitureTools->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listViewFurnitureTools->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewFurnitureTools->setProperty("showDropIndicator", QVariant(false));
        listViewFurnitureTools->setDefaultDropAction(Qt::IgnoreAction);
        listViewFurnitureTools->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(listViewFurnitureTools);

        QIcon icon2;
        icon2.addFile(QStringLiteral(":/tool-tabs/furniture"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabFurnitureTools, icon2, QString());
        tabDecorTools = new QWidget();
        tabDecorTools->setObjectName(QStringLiteral("tabDecorTools"));
        verticalLayout_3 = new QVBoxLayout(tabDecorTools);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listViewDecorTools = new QListView(tabDecorTools);
        listViewDecorTools->setObjectName(QStringLiteral("listViewDecorTools"));
        listViewDecorTools->setMinimumSize(QSize(194, 356));
        listViewDecorTools->setFrameShape(QFrame::NoFrame);
        listViewDecorTools->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewDecorTools->setProperty("showDropIndicator", QVariant(false));
        listViewDecorTools->setDefaultDropAction(Qt::IgnoreAction);
        listViewDecorTools->setIconSize(QSize(32, 32));

        verticalLayout_3->addWidget(listViewDecorTools);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/tool-tabs/decor"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabDecorTools, icon3, QString());

        horizontalLayout->addWidget(tabWidget);

        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setMinimumSize(QSize(476, 401));
        QBrush brush(QColor(199, 216, 200, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        horizontalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QStringLiteral("menuLanguage"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuWindow->addAction(actionZoomIn);
        menuWindow->addAction(actionZoomOut);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuLanguage->addAction(actionUk);
        menuLanguage->addAction(actionRu);
        menuLanguage->addAction(actionEn);
        menu->addAction(actionUndo);
        menu->addAction(actionRedo);
        menu->addSeparator();
        menu->addAction(actionDelete);
        menu->addAction(actionClear);
        menu->addSeparator();
        menu->addAction(actionSetItemSize);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CoRe Planner", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\270\320\271...", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270...", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\321\226\320\263\321\202\320\270", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\321\226\320\263\321\202\320\270 \321\217\320\272...", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionClose->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\272\320\260", 0));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 CoRe Planner...", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actionUk->setText(QApplication::translate("MainWindow", "\320\243\320\272\321\200\320\260\321\227\320\275\321\201\321\214\320\272\320\260", 0));
        actionRu->setText(QApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", 0));
        actionEn->setText(QApplication::translate("MainWindow", "English", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270", 0));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\270", 0));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", 0));
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionClear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\320\270", 0));
        actionClear->setShortcut(QApplication::translate("MainWindow", "C", 0));
        actionSetItemSize->setText(QApplication::translate("MainWindow", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270 \321\200\320\276\320\267\320\274\321\226\321\200", 0));
        actionSetItemSize->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "\320\227\320\261\321\226\320\273\321\214\321\210\320\270\321\202\320\270", 0));
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "\320\227\320\274\320\265\320\275\321\210\320\270\321\202\320\270", 0));
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabBuildTools), QString());
        tabWidget->setTabToolTip(tabWidget->indexOf(tabBuildTools), QApplication::translate("MainWindow", "\320\221\321\203\320\264\321\203\320\262\320\260\321\202\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabFurnitureTools), QString());
        tabWidget->setTabToolTip(tabWidget->indexOf(tabFurnitureTools), QApplication::translate("MainWindow", "\320\234\320\265\320\261\320\273\321\226", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDecorTools), QString());
        tabWidget->setTabToolTip(tabWidget->indexOf(tabDecorTools), QApplication::translate("MainWindow", "\320\224\320\265\320\272\320\276\321\200", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "\320\222\321\226\320\272\320\275\320\276", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260", 0));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\262\320\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
