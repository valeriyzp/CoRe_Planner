/********************************************************************************
** Form generated from reading UI file 'formcreate.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCREATE_H
#define UI_FORMCREATE_H

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

class Ui_FormCreate
{
public:
    QGroupBox *groupBoxSizeNew;
    QLabel *labelHeight;
    QLabel *labelWidth;
    QDoubleSpinBox *doubleSpinBoxHeight;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonCreateNew;
    QLabel *labelCreateNew;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButtonProjectName;
    QPushButton *pushButtonProjectTime;
    QPushButton *pushButtonProjectSquare;
    QLabel *labelRecent;

    void setupUi(QWidget *FormCreate)
    {
        if (FormCreate->objectName().isEmpty())
            FormCreate->setObjectName(QStringLiteral("FormCreate"));
        FormCreate->setWindowModality(Qt::WindowModal);
        FormCreate->resize(550, 280);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormCreate->sizePolicy().hasHeightForWidth());
        FormCreate->setSizePolicy(sizePolicy);
        FormCreate->setMinimumSize(QSize(550, 280));
        FormCreate->setMaximumSize(QSize(550, 280));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        FormCreate->setFont(font);
        FormCreate->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        groupBoxSizeNew = new QGroupBox(FormCreate);
        groupBoxSizeNew->setObjectName(QStringLiteral("groupBoxSizeNew"));
        groupBoxSizeNew->setGeometry(QRect(10, 50, 171, 91));
        QFont font1;
        font1.setPointSize(12);
        groupBoxSizeNew->setFont(font1);
        groupBoxSizeNew->setFlat(false);
        groupBoxSizeNew->setCheckable(false);
        labelHeight = new QLabel(groupBoxSizeNew);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));
        labelHeight->setGeometry(QRect(10, 35, 61, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        labelHeight->setFont(font2);
        labelWidth = new QLabel(groupBoxSizeNew);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setGeometry(QRect(10, 65, 61, 16));
        labelWidth->setFont(font2);
        doubleSpinBoxHeight = new QDoubleSpinBox(groupBoxSizeNew);
        doubleSpinBoxHeight->setObjectName(QStringLiteral("doubleSpinBoxHeight"));
        doubleSpinBoxHeight->setGeometry(QRect(70, 30, 91, 22));
        QFont font3;
        font3.setPointSize(8);
        doubleSpinBoxHeight->setFont(font3);
        doubleSpinBoxHeight->setMinimum(1);
        doubleSpinBoxHeight->setMaximum(9999.99);
        doubleSpinBoxHeight->setValue(10);
        doubleSpinBoxWidth = new QDoubleSpinBox(groupBoxSizeNew);
        doubleSpinBoxWidth->setObjectName(QStringLiteral("doubleSpinBoxWidth"));
        doubleSpinBoxWidth->setGeometry(QRect(70, 60, 91, 22));
        doubleSpinBoxWidth->setFont(font3);
        doubleSpinBoxWidth->setMinimum(1);
        doubleSpinBoxWidth->setMaximum(9999.99);
        doubleSpinBoxWidth->setValue(10);
        pushButtonOpen = new QPushButton(FormCreate);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(290, 230, 171, 41));
        pushButtonOpen->setFont(font1);
        pushButtonCreateNew = new QPushButton(FormCreate);
        pushButtonCreateNew->setObjectName(QStringLiteral("pushButtonCreateNew"));
        pushButtonCreateNew->setGeometry(QRect(10, 230, 171, 41));
        pushButtonCreateNew->setFont(font1);
        labelCreateNew = new QLabel(FormCreate);
        labelCreateNew->setObjectName(QStringLiteral("labelCreateNew"));
        labelCreateNew->setGeometry(QRect(10, 10, 171, 31));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        labelCreateNew->setFont(font4);
        labelCreateNew->setScaledContents(false);
        labelCreateNew->setAlignment(Qt::AlignCenter);
        labelCreateNew->setTextInteractionFlags(Qt::NoTextInteraction);
        pushButton_1 = new QPushButton(FormCreate);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(210, 80, 331, 23));
        QFont font5;
        font5.setFamily(QStringLiteral("Courier New"));
        pushButton_1->setFont(font5);
        pushButton_1->setStyleSheet(QStringLiteral("text-align: left"));
        pushButton_2 = new QPushButton(FormCreate);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 110, 331, 23));
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QStringLiteral("text-align: left"));
        pushButton_3 = new QPushButton(FormCreate);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 140, 331, 23));
        pushButton_3->setFont(font5);
        pushButton_3->setStyleSheet(QStringLiteral("text-align: left"));
        pushButton_4 = new QPushButton(FormCreate);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 170, 331, 23));
        pushButton_4->setFont(font5);
        pushButton_4->setStyleSheet(QStringLiteral("text-align: left"));
        pushButton_5 = new QPushButton(FormCreate);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 200, 331, 23));
        pushButton_5->setFont(font5);
        pushButton_5->setStyleSheet(QStringLiteral("text-align: left"));
        pushButtonProjectName = new QPushButton(FormCreate);
        pushButtonProjectName->setObjectName(QStringLiteral("pushButtonProjectName"));
        pushButtonProjectName->setGeometry(QRect(210, 50, 121, 21));
        pushButtonProjectTime = new QPushButton(FormCreate);
        pushButtonProjectTime->setObjectName(QStringLiteral("pushButtonProjectTime"));
        pushButtonProjectTime->setGeometry(QRect(340, 50, 111, 21));
        pushButtonProjectSquare = new QPushButton(FormCreate);
        pushButtonProjectSquare->setObjectName(QStringLiteral("pushButtonProjectSquare"));
        pushButtonProjectSquare->setGeometry(QRect(460, 50, 81, 21));
        labelRecent = new QLabel(FormCreate);
        labelRecent->setObjectName(QStringLiteral("labelRecent"));
        labelRecent->setGeometry(QRect(210, 10, 331, 31));
        labelRecent->setFont(font4);
        labelRecent->setScaledContents(false);
        labelRecent->setAlignment(Qt::AlignCenter);
        labelRecent->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(FormCreate);

        QMetaObject::connectSlotsByName(FormCreate);
    } // setupUi

    void retranslateUi(QWidget *FormCreate)
    {
        FormCreate->setWindowTitle(QApplication::translate("FormCreate", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", 0));
        groupBoxSizeNew->setTitle(QApplication::translate("FormCreate", "\320\240\320\276\320\267\320\274\321\226\321\200", 0));
        labelHeight->setText(QApplication::translate("FormCreate", "\320\222\320\270\321\201\320\276\321\202\320\260", 0));
        labelWidth->setText(QApplication::translate("FormCreate", "\320\250\320\270\321\200\320\270\320\275\320\260", 0));
        doubleSpinBoxHeight->setSuffix(QApplication::translate("FormCreate", " m.", 0));
        doubleSpinBoxWidth->setSuffix(QApplication::translate("FormCreate", " m.", 0));
        pushButtonOpen->setText(QApplication::translate("FormCreate", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270", 0));
        pushButtonCreateNew->setText(QApplication::translate("FormCreate", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270", 0));
        labelCreateNew->setText(QApplication::translate("FormCreate", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\275\320\276\320\262\320\270\320\271", 0));
        pushButton_1->setText(QApplication::translate("FormCreate", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("FormCreate", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("FormCreate", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("FormCreate", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("FormCreate", "PushButton", 0));
        pushButtonProjectName->setText(QApplication::translate("FormCreate", "\320\206\320\274'\321\217", 0));
        pushButtonProjectTime->setText(QApplication::translate("FormCreate", "\320\224\320\260\321\202\320\260", 0));
        pushButtonProjectSquare->setText(QApplication::translate("FormCreate", "\320\237\320\273\320\276\321\211\320\260", 0));
        labelRecent->setText(QApplication::translate("FormCreate", "\320\235\320\265\321\211\320\276\320\264\320\260\320\262\320\275\321\226", 0));
    } // retranslateUi

};

namespace Ui {
    class FormCreate: public Ui_FormCreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCREATE_H
