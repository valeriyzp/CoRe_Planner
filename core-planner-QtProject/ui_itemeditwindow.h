/********************************************************************************
** Form generated from reading UI file 'itemeditwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMEDITWINDOW_H
#define UI_ITEMEDITWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemEditWindow
{
public:
    QGroupBox *groupBoxSize;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QDoubleSpinBox *doubleSpinBoxHeight;
    QLabel *labelHeight;
    QLabel *label_2;
    QGroupBox *groupBoxPosition;
    QDoubleSpinBox *doubleSpinBoxAngle;
    QLabel *label_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxPosY;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxPosX;
    QPushButton *pushButtonApply;

    void setupUi(QWidget *ItemEditWindow)
    {
        if (ItemEditWindow->objectName().isEmpty())
            ItemEditWindow->setObjectName(QStringLiteral("ItemEditWindow"));
        ItemEditWindow->setWindowModality(Qt::WindowModal);
        ItemEditWindow->resize(190, 280);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ItemEditWindow->sizePolicy().hasHeightForWidth());
        ItemEditWindow->setSizePolicy(sizePolicy);
        ItemEditWindow->setMinimumSize(QSize(190, 280));
        ItemEditWindow->setMaximumSize(QSize(190, 280));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        ItemEditWindow->setFont(font);
        ItemEditWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        groupBoxSize = new QGroupBox(ItemEditWindow);
        groupBoxSize->setObjectName(QStringLiteral("groupBoxSize"));
        groupBoxSize->setGeometry(QRect(10, 10, 171, 91));
        doubleSpinBoxWidth = new QDoubleSpinBox(groupBoxSize);
        doubleSpinBoxWidth->setObjectName(QStringLiteral("doubleSpinBoxWidth"));
        doubleSpinBoxWidth->setGeometry(QRect(80, 60, 81, 22));
        doubleSpinBoxWidth->setMinimum(0.1);
        doubleSpinBoxWidth->setMaximum(9999.99);
        doubleSpinBoxWidth->setValue(1);
        doubleSpinBoxHeight = new QDoubleSpinBox(groupBoxSize);
        doubleSpinBoxHeight->setObjectName(QStringLiteral("doubleSpinBoxHeight"));
        doubleSpinBoxHeight->setGeometry(QRect(80, 30, 81, 22));
        doubleSpinBoxHeight->setMinimum(0.1);
        doubleSpinBoxHeight->setMaximum(9999.99);
        doubleSpinBoxHeight->setValue(1);
        labelHeight = new QLabel(groupBoxSize);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));
        labelHeight->setGeometry(QRect(10, 35, 47, 13));
        label_2 = new QLabel(groupBoxSize);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 65, 47, 13));
        groupBoxPosition = new QGroupBox(ItemEditWindow);
        groupBoxPosition->setObjectName(QStringLiteral("groupBoxPosition"));
        groupBoxPosition->setGeometry(QRect(10, 110, 171, 121));
        doubleSpinBoxAngle = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxAngle->setObjectName(QStringLiteral("doubleSpinBoxAngle"));
        doubleSpinBoxAngle->setGeometry(QRect(80, 90, 81, 22));
        doubleSpinBoxAngle->setMaximum(360);
        label_5 = new QLabel(groupBoxPosition);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 95, 61, 16));
        label_3 = new QLabel(groupBoxPosition);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 35, 61, 16));
        doubleSpinBoxPosY = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxPosY->setObjectName(QStringLiteral("doubleSpinBoxPosY"));
        doubleSpinBoxPosY->setGeometry(QRect(80, 60, 81, 22));
        doubleSpinBoxPosY->setMaximum(9999.99);
        label_4 = new QLabel(groupBoxPosition);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 65, 61, 16));
        doubleSpinBoxPosX = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxPosX->setObjectName(QStringLiteral("doubleSpinBoxPosX"));
        doubleSpinBoxPosX->setGeometry(QRect(80, 30, 81, 22));
        doubleSpinBoxPosX->setMaximum(9999.99);
        pushButtonApply = new QPushButton(ItemEditWindow);
        pushButtonApply->setObjectName(QStringLiteral("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(10, 240, 171, 31));

        retranslateUi(ItemEditWindow);

        QMetaObject::connectSlotsByName(ItemEditWindow);
    } // setupUi

    void retranslateUi(QWidget *ItemEditWindow)
    {
        ItemEditWindow->setWindowTitle(QApplication::translate("ItemEditWindow", "\320\227\320\274\321\226\320\275\320\260 \320\276\320\261'\321\224\320\272\321\202\320\260", 0));
        groupBoxSize->setTitle(QApplication::translate("ItemEditWindow", "\320\240\320\276\320\267\320\274\321\226\321\200\320\270", 0));
        doubleSpinBoxWidth->setSuffix(QApplication::translate("ItemEditWindow", " m.", 0));
        doubleSpinBoxHeight->setSuffix(QApplication::translate("ItemEditWindow", " m.", 0));
        labelHeight->setText(QApplication::translate("ItemEditWindow", "\320\222\320\270\321\201\320\276\321\202\320\260", 0));
        label_2->setText(QApplication::translate("ItemEditWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", 0));
        groupBoxPosition->setTitle(QApplication::translate("ItemEditWindow", "\320\240\320\276\320\267\320\274\321\226\321\211\320\265\320\275\320\275\321\217", 0));
        doubleSpinBoxAngle->setSuffix(QApplication::translate("ItemEditWindow", "\302\260", 0));
        label_5->setText(QApplication::translate("ItemEditWindow", "\320\232\321\203\321\202 \320\275\320\260\321\205\320\270\320\273\321\203", 0));
        label_3->setText(QApplication::translate("ItemEditWindow", "\320\237\320\276\320\267\320\270\321\206\321\226\321\217 \320\245", 0));
        doubleSpinBoxPosY->setSuffix(QApplication::translate("ItemEditWindow", " m.", 0));
        label_4->setText(QApplication::translate("ItemEditWindow", "\320\237\320\276\320\267\320\270\321\206\321\226\321\217 \320\243", 0));
        doubleSpinBoxPosX->setSuffix(QApplication::translate("ItemEditWindow", " m.", 0));
        pushButtonApply->setText(QApplication::translate("ItemEditWindow", "\320\227\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270", 0));
        pushButtonApply->setShortcut(QApplication::translate("ItemEditWindow", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class ItemEditWindow: public Ui_ItemEditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMEDITWINDOW_H
