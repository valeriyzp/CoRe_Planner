#ifndef JSONDATA_H
#define JSONDATA_H

#include<QJsonObject>
#include<QJsonParseError>
#include<QFile>
#include<QJsonArray>

#include "graphicitem.h"
#include "mdichild.h"
#include "itembycolor.h"
#include "itembypicture.h"

class JsonData
{
private:
    QJsonDocument doc;
    QJsonParseError docError;

public:
    JsonData();
    void inFromFile(const QString &fWay, MdiChild *Parent);
    void outToFile(const QString &fWay, MdiChild *Parent);
    void outHistoryToFile(const QString &fWay, MdiChild *Parent);
    void outInitHistoryFile(const QString &fWay, MdiChild *Parent);
    void InitializeSceneFromFile(MdiChild *Parent,QJsonArray &docArr);
    void InitScenFromFile(const QString &fWay, MdiChild *Parent, int Version);
    void DeleteHighVersions(const QString &fWay, int Version);
};

#endif // JSONDATA_H
