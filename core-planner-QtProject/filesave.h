#ifndef FILESAVE_H
#define FILESAVE_H

#include "fileway.h"
#include "database.h"

class MdiChild;

class MainWindow;

class FileSave : public FileWay
{
public:
    MdiChild *ParenWithScene;
    FileSave();
    ~FileSave();
    void Save(MainWindow *Main);
    void SaveAs(MainWindow *Main);
    void SaveToHistory();
    void InitHistory();
    void LoadFromHistory(int Version);
    void DeleteHighVersions(int Version);

private:
    void SetWay();
    QString HistoryFileWay;
};

#endif // FILESAVE_H
