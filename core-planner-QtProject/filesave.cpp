#include "filesave.h"
#include "mdichild.h"
#include "mainwindow.h"
#include "jsondata.h"

FileSave::FileSave() : FileWay()
{
    ParenWithScene = NULL;
    QDate DateNow = QDate::currentDate();
    QTime TimeNow = QTime::currentTime();
    HistoryFileWay = DateNow.toString("yyyyMMdd") + TimeNow.toString("hhmmss") + ".json";
}

void FileSave::SetWay()
{
    QString adress = QFileDialog::getSaveFileName(nullptr, "Зберегти в... | Save to...  | Сохранить в...","D:\\","Project files (*.json);;JPG file (*.jpg);;BMP file(*.bmp);;PNG file(*.png)");
    try {
        if(adress == "")
        {
            throw QString("ERROR ADRESS IS CLEAR");
        }
        Way = adress;
        FileName = GetFileNameFromWay(adress);
    }
    catch (QString error) {
        qDebug()<<error;
    }
}

FileSave::~FileSave()
{
    QFile file;
    file.setFileName(HistoryFileWay);
    if(file.open(QIODevice::ReadWrite|QFile::Text))
    {
        file.remove();
    }
}

void FileSave::Save(MainWindow *Main)
{
    if(FileName != "" && Way != "")
    {
       JsonData JsonWriter;
       JsonWriter.outToFile(Way, ParenWithScene);

       QDate DateNow = QDate::currentDate();
       QTime TimeNow = QTime::currentTime();
       QString Date = DateNow.toString("yyyy.MM.dd ") + TimeNow.toString("hh:mm");
       double Square = (ParenWithScene->scene->sceneRect().toRect().width() * ParenWithScene->scene->sceneRect().toRect().height()) / 10000.0;
       Main->database.inserIntoTable(FileName, Date, Way, Square);
    }
    else
    {
        SaveAs(Main);
    }
}

void FileSave::SaveAs(MainWindow *Main)
{
    SetWay();
    if(Way != "" && FileName != "")
    {
        ParenWithScene->setWindowTitle(FileName);
        if(FileName[FileName.length()-1] == 'n')
        {
            JsonData JsonWriter;
            JsonWriter.outToFile(Way, ParenWithScene);
            ParenWithScene->setWindowTitle(FileName);

            QDate DateNow = QDate::currentDate();
            QTime TimeNow = QTime::currentTime();
            QString Date = DateNow.toString("yyyy.MM.dd ") + TimeNow.toString("hh:mm");
            double Square = (ParenWithScene->scene->sceneRect().toRect().width() * ParenWithScene->scene->sceneRect().toRect().height()) / 10000.0;
            Main->database.inserIntoTable(FileName, Date, Way, Square);
        }
        else
        {
            ParenWithScene->SaveAsImage(Way);
        }
    }
}

void FileSave::SaveToHistory()
{
    JsonData JsonWriter;
    JsonWriter.outHistoryToFile(HistoryFileWay, ParenWithScene);
}

void FileSave::InitHistory()
{
    JsonData JsonWriter;
    JsonWriter.outInitHistoryFile(HistoryFileWay, ParenWithScene);
}

void FileSave::LoadFromHistory(int Version)
{
    JsonData JsonWriter;
    JsonWriter.InitScenFromFile(HistoryFileWay, ParenWithScene, Version);
}

void FileSave::DeleteHighVersions(int Version)
{
    JsonData JsonWriter;
    JsonWriter.DeleteHighVersions(HistoryFileWay ,Version);
}
