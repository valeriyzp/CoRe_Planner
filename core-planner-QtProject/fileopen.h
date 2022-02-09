#ifndef FILEOPEN_H
#define FILEOPEN_H

#include "fileway.h"
#include "jsondata.h"

class MainWindow;

class MdiChild;

class FileOpen : public FileWay
{
private:
    MainWindow *Main;

public:
    FileOpen(MainWindow *Parent);
    void SetWay();
    void OpenFile();
    void OpenFileByWay(QString &Way, QString &FileName);
};

#endif // FILEOPEN_H
