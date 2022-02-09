#include "fileway.h"

FileWay::FileWay()
{
    Way = "";
    FileName = "";
}

FileWay::FileWay(QString &WayToFile)
{
    Way = WayToFile;
    FileName = GetFileNameFromWay(Way);
}

FileWay::~FileWay()
{

}

QString FileWay::GetFileNameFromWay(QString &AdressFile)
{
    QString NameFile = "";
    for(int i = AdressFile.length()-1; i >= 0; i--)
    {
        if(AdressFile[i] == '\\' || AdressFile[i] == '/')
        {
            for(int j = i+1; j < AdressFile.length(); j++)
                NameFile += AdressFile[j];
            break;
        }
    }
    return NameFile;
}
