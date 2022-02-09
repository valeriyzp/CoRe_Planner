#include "fileopen.h"
#include "mdichild.h"
#include "mainwindow.h"

FileOpen::FileOpen(MainWindow *Parent) : FileWay()
{
    Main = Parent;
    FileName = "";
    Way = "";
}

void FileOpen::SetWay()
{
    Way = QFileDialog::getOpenFileName(nullptr, "Відкрити... | Open...  | Открыть...", "D:\\", "*.json");
    FileName = GetFileNameFromWay(Way);
}

void FileOpen::OpenFile()
{
    try {
        SetWay();
        if(FileName == "" || Way == "")
        {
            throw QString("File open error!");
        }
        MdiChild *Child = new MdiChild(Main);
        Child->setWindowTitle(FileName);
        Child->setWindowIcon(QIcon(":/menu/cube"));
        Child->SaveFileInfo.Way = Way;
        Child->SaveFileInfo.FileName = FileName;

        JsonData JsonReader;
        JsonReader.inFromFile(Way, Child);
        Main->loadProject(Child);

        Child->SaveFileInfo.InitHistory();
        Child->VersionOfScene = 0;
        Child->MaximumVersionOfScene = 0;
    }
    catch (QString error) {
        QMessageBox::critical(Main, "Warning", error);
        qDebug()<<error;
    }
}

void FileOpen::OpenFileByWay(QString &Way, QString &FileName)
{
    MdiChild *Child = new MdiChild(Main);
    Child->setWindowTitle(FileName);
    Child->setWindowIcon(QIcon(":/menu/cube"));
    Child->SaveFileInfo.Way = Way;
    Child->SaveFileInfo.FileName = FileName;

    JsonData JsonReader;
    JsonReader.inFromFile(Way, Child);
    Main->loadProject(Child);

    Child->SaveFileInfo.InitHistory();
    Child->VersionOfScene = 0;
    Child->MaximumVersionOfScene = 0;
}
