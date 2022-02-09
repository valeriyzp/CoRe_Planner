#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

#define DATABASE_NAME       "FileHistory.db"
#define TABLE               "FileHistory"
#define TABLE_FNAME         "Name"
#define TABLE_FDATE         "Date"
#define TABLE_FWAY          "Way"
#define TABLE_FSQUARE       "Square"

struct InfoAboutFile {
public:
    QString FileName;
    QString Way;
    QString DateOfSave;
    double Square;
};

class DataBase
{
private:
    QSqlDatabase dataBase;
    int maxItems;
    int itemsLeft;
    int itemsLeftDataBase();
    void createTable();
    void openDataBase();
    void restoreDataBase();
    void removeRecord(const QString &fWay);

public:
    DataBase();
   ~DataBase();
    void connectToDataBase();
    void inserIntoTable(const QString &fName, const QString &fData, const QString &fWay, const double &fSquare);
    void WriteTableToArray(InfoAboutFile *Array, int MaximumCount, int *CurrentCount);
};

#endif // DATABASE_H
