#ifndef ITEMEDITWINDOW_H
#define ITEMEDITWINDOW_H

#include <QWidget>
#include "ui_itemeditwindow.h"
#include "mdichild.h"

namespace Ui {
class ItemEditWindow;
}

class ItemEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ItemEditWindow(QWidget *parent = 0);
    ItemEditWindow(MainWindow *Main, MdiChild *Parent, QWidget *parent = 0);
    ~ItemEditWindow();

private slots:
    void on_pushButtonApply_clicked();

private:
    Ui::ItemEditWindow *ui;
    MdiChild *FormWithScene;
    MainWindow *MainWin;
};

#endif // ITEMEDITWINDOW_H
