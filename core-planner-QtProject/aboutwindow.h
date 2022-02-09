#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QtWidgets>
#include "ui_aboutwindow.h"

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private slots:
    void on_pushButtonClose_clicked();
    void on_labelSystemNick_linkActivated(const QString &link);
    void on_labelx8357238_linkActivated(const QString &link);
    void on_labelvaleriyzp_linkActivated(const QString &link);

private:
    Ui::AboutWindow *ui;
    QPixmap backgroundImage;
    void setupOtherUi();
};

#endif // ABOUTWINDOW_H
