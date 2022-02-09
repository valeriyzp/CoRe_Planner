#ifndef FILEWAY_H
#define FILEWAY_H

#include <QString>

class FileWay
{
public:
    QString Way;
    QString FileName;

    QString GetFileNameFromWay(QString &AdressFile);
    FileWay();
    FileWay(QString &WayToFile);
    virtual ~FileWay();
    virtual void SetWay() = 0;
};

#endif // FILEWAY_H
