/********************************************************************************
** Form generated from reading UI file 'mdichild.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDICHILD_H
#define UI_MDICHILD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiChild
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *MdiChild)
    {
        if (MdiChild->objectName().isEmpty())
            MdiChild->setObjectName(QStringLiteral("MdiChild"));
        MdiChild->resize(400, 300);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        MdiChild->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/cube"), QSize(), QIcon::Normal, QIcon::Off);
        MdiChild->setWindowIcon(icon);
        MdiChild->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        horizontalLayout = new QHBoxLayout(MdiChild);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(MdiChild);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setCacheMode(QGraphicsView::CacheBackground);
        graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(MdiChild);

        QMetaObject::connectSlotsByName(MdiChild);
    } // setupUi

    void retranslateUi(QWidget *MdiChild)
    {
        MdiChild->setWindowTitle(QApplication::translate("MdiChild", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MdiChild: public Ui_MdiChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDICHILD_H
