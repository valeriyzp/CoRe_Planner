#include "database.h"
DataBase::DataBase()
{
    maxItems = 5;
}

DataBase::~DataBase()
{
    dataBase.close();
}

void DataBase::connectToDataBase()
{
    if(!QFile(DATABASE_NAME).exists())
    {
        this->restoreDataBase();
    }
    else
    {
        this->openDataBase();
    }
}

void DataBase::restoreDataBase()
{
    this->openDataBase();
    this->createTable();
}

void DataBase::openDataBase()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(DATABASE_NAME);
    try {
        if(!dataBase.open())
        {
            throw QString("NOT OPEN SQLITE: "  DATABASE_NAME);
        }

    }
    catch (QString error) {
        qDebug()<<error;
    }
}

void DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            TABLE_FNAME     " BLOB    NOT NULL,"
                            TABLE_FDATE     " VARCHAR(50)    NOT NULL,"
                            TABLE_FWAY      " BLOB    NOT NULL,"
                            TABLE_FSQUARE   " REAL    NOT NULL"
                    " )"
                    ))
    {
        throw QString("NOT CREATE TABLE SQLITE: " TABLE);
    }
}

void DataBase::inserIntoTable(const QString&fName,const QString&fData,const QString&fWay,const double&fSquare)
{
    removeRecord(fWay);
    itemsLeft = itemsLeftDataBase();
    QSqlQuery query;
    if(itemsLeft < 0)
    {
        query.exec("SELECT * FROM " TABLE );
        query.first();
        removeRecord(query.value(2).toString());
    }
    query.prepare("INSERT INTO " TABLE " ( " TABLE_FNAME ", "
                                             TABLE_FDATE ", "
                                             TABLE_FWAY ", "
                                             TABLE_FSQUARE" ) "
                  "VALUES (:FName, :FData, :FWay, :FSquare)");
    query.bindValue(":FName", fName);
    query.bindValue(":FData", fData);
    query.bindValue(":FWay", fWay);
    query.bindValue(":FSquare", fSquare);
    if(!query.exec())
    {
        throw QString("ERROR INSERT INTO SQLITE TABLE:" TABLE);
    }
}

void DataBase::WriteTableToArray(InfoAboutFile *Array, int MaximumCount, int *CurrentCount)
{
    QSqlQuery query;
    query.exec("SELECT * FROM " TABLE );
    try{
        if(!query.exec())
        {
            throw QString("ERROR WRITE TO ARRAY SQLITE: " TABLE);
        }

        while (query.next() && *CurrentCount < MaximumCount)
        {
            QFile file;
            file.setFileName(query.value(2).toString());
            if(file.open(QIODevice::ReadOnly|QFile::Text))
            {
                file.close();

                Array[*CurrentCount].FileName = query.value(0).toString();
                Array[*CurrentCount].Way = query.value(2).toString();
                Array[*CurrentCount].DateOfSave = query.value(1).toString();
                Array[*CurrentCount].Square = query.value(3).toDouble();
                *CurrentCount += 1;
            }
            else
            {
                removeRecord(query.value(2).toString());
            }
        }
    }
    catch (QString error) {
        qDebug()<<error;
    }


}

void DataBase::removeRecord(const QString&fWay)
{
    try{

        QSqlQuery query;
        query.prepare("DELETE FROM " TABLE " WHERE " TABLE_FWAY "= '" + fWay+"'");
        query.bindValue(TABLE_FWAY,fWay);
        if(!query.exec())
        {
            throw QString("ERROR REMOVE FROM SQLITE: " TABLE);
        }
    }
    catch (QString error) {
        qDebug()<<error;
    }

}

int DataBase::itemsLeftDataBase(){
    int res = maxItems-1;
    QSqlQuery query;
    query.exec("SELECT * FROM " TABLE );
    while(query.next())
        res--;
    return res;
}
