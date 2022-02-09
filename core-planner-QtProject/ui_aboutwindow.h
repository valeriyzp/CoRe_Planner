/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *labelDescription;
    QPushButton *pushButtonClose;
    QLabel *labelBG;
    QLabel *labelSystemNick;
    QLabel *labelx8357238;
    QLabel *labelvaleriyzp;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(680, 420);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(16);
        AboutWindow->setFont(font);
        AboutWindow->setContextMenuPolicy(Qt::NoContextMenu);
        AboutWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        AboutWindow->setModal(true);
        labelDescription = new QLabel(AboutWindow);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        labelDescription->setGeometry(QRect(20, 120, 641, 191));
        labelDescription->setTextFormat(Qt::RichText);
        labelDescription->setScaledContents(false);
        labelDescription->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        labelDescription->setWordWrap(true);
        pushButtonClose = new QPushButton(AboutWindow);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(650, 0, 31, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonClose->setFont(font1);
        pushButtonClose->setFlat(true);
        labelBG = new QLabel(AboutWindow);
        labelBG->setObjectName(QStringLiteral("labelBG"));
        labelBG->setGeometry(QRect(0, 0, 681, 421));
        labelBG->setPixmap(QPixmap(QString::fromUtf8(":/bg/about")));
        labelSystemNick = new QLabel(AboutWindow);
        labelSystemNick->setObjectName(QStringLiteral("labelSystemNick"));
        labelSystemNick->setGeometry(QRect(40, 300, 171, 41));
        QFont font2;
        font2.setPointSize(20);
        labelSystemNick->setFont(font2);
        labelx8357238 = new QLabel(AboutWindow);
        labelx8357238->setObjectName(QStringLiteral("labelx8357238"));
        labelx8357238->setGeometry(QRect(270, 300, 171, 41));
        labelx8357238->setFont(font2);
        labelvaleriyzp = new QLabel(AboutWindow);
        labelvaleriyzp->setObjectName(QStringLiteral("labelvaleriyzp"));
        labelvaleriyzp->setGeometry(QRect(490, 300, 141, 41));
        labelvaleriyzp->setFont(font2);
        labelBG->raise();
        labelDescription->raise();
        pushButtonClose->raise();
        labelSystemNick->raise();
        labelx8357238->raise();
        labelvaleriyzp->raise();

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "About", 0));
        labelDescription->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#bbe3b4;\">CoRe Planner - \321\206\320\265 \320\277\321\200\320\276\321\201\321\202\320\265 \321\202\320\260 \320\267\321\200\321\203\321\207\320\275\320\265 \321\203 \320\262\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\260\320\275\320\275\321\226 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\275\320\265 \320\267\320\260\320\261\320\265\320\267\320\277\320\265\321\207\320\265\320\275\320\275\321\217, \321\217\320\272\320\265 \320\275\320\260\320\264\320\260\321\224 \320\267\320\274\320\276\320\263\321\203 \321\210\320\262\320\270\320\264\320\272\320\276 \321\201\321\202\320\262\320\276\321\200\321\216\320\262\320\260\321\202\320\270 \320\264\320\270\320\267\320\260\320\271\320\275 \321\226\320\275\321\202\320\265\321\200'\321\224\321\200\321\203 \321\203 2D \320\274\320\276\320\264\320\265\320\273\321\217\321\205 \320\261\320\265\320\267 \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\320\276\321\201\321\202"
                        "\321\226 \320\261\321\203\321\202\320\270 \320\277\321\226\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\274 \320\264\320\276 \320\274\320\265\321\200\320\265\320\266\321\226. \320\222\320\270 \320\274\320\276\320\266\320\265\321\202\320\265 \321\201\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\261\321\203\320\264\320\270\320\275\320\276\320\272 \320\274\321\200\321\226\321\227 \320\261\321\203\320\272\320\262\320\260\320\273\321\214\320\275\320\276 \320\267\320\260 \321\205\320\262\320\270\320\273\320\270\320\275\320\270 \320\261\320\265\320\267 \320\261\321\203\320\264\321\214-\321\217\320\272\320\276\321\227 \320\277\321\226\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\270, \321\201\320\277\320\265\321\206\321\226\320\260\320\273\321\214\320\275\320\270\321\205 \320\275\320\260\320\262\320\270\321\207\320\276\320\272 \320\260\320\261\320\276 \320\277\321\200\320\276\321\207\320\270\321\202\320\260\320\275\320\275\321\217 \321\201\320\272\320\273\320\260\320"
                        "\264\320\275\320\270\321\205 \321\226\320\275\321\201\321\202\321\200\321\203\320\272\321\206\321\226\320\271.</span></p><p><span style=\" font-size:14pt; color:#bbe3b4;\">\320\257\320\272\321\211\320\276 \321\203 \320\262\320\260\321\201 \321\224 \320\261\321\203\320\264\321\214-\321\217\320\272\321\226 \320\277\320\270\321\202\320\260\320\275\320\275\321\217, \320\275\320\265 \321\201\320\276\321\200\320\276\320\274\321\202\320\265\321\201\321\217 \320\267\320\262'\321\217\320\267\320\260\321\202\320\270\321\201\321\217 \320\267 \320\275\320\260\320\274\320\270:</span></p></body></html>", 0));
        pushButtonClose->setText(QApplication::translate("AboutWindow", "X", 0));
        labelBG->setText(QString());
        labelSystemNick->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><a href=\"http://t.me/SystemNick\"><span style=\" font-size:20pt; color:#ffffff; text-decoration:none\">@SystemNick</span></a></p></body></html>", 0));
        labelx8357238->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><a href=\"http://t.me/x8357238\"><span style=\" font-size:20pt; color:#ffffff; text-decoration:none\">@x8357238</span></a></p></body></html>", 0));
        labelvaleriyzp->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><a href=\"http://t.me/valeriyzp\"><span style=\" font-size:20pt; color:#ffffff; text-decoration:none\">@valeriyzp</span></a></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
