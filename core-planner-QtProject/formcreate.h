#ifndef FORMCREATE_H
#define FORMCREATE_H

#include <QWidget>
#include "ui_formcreate.h"
#include "mdichild.h"
#include "database.h"

namespace Ui {
class FormCreate;
}

class MainWindow;

class FormCreate : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreate(MainWindow *Main, QWidget *parent = 0);
    ~FormCreate();

private slots:
    void on_pushButtonCreateNew_clicked();
    void on_pushButtonProjectName_clicked();
    void on_pushButtonProjectTime_clicked();
    void on_pushButtonProjectSquare_clicked();
    void SetFilesButtons();
    void SetButtonsTextAlign();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButtonOpen_clicked();

private:
    InfoAboutFile *Files;
    int CountOfFiles;
    int WayToOpen;
    MainWindow *MainWin;
    Ui::FormCreate *ui;
};

#endif // FORMCREATE_H
