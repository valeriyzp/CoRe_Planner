#include "formcreate.h"
#include "mainwindow.h"

FormCreate::FormCreate(MainWindow *Main, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreate)
{
    ui->setupUi(this);
    Files = new InfoAboutFile[5];
    CountOfFiles = 0;
    MainWin = Main;

    MainWin->database.WriteTableToArray(Files, 5, &CountOfFiles);
    SetFilesButtons();
    WayToOpen = -1;

    QPixmap NullPicture = QPixmap(1,1);
    NullPicture.fill(QColor(0,0,0,0));
    setWindowIcon(QIcon(NullPicture));
}

FormCreate::~FormCreate()
{
    delete ui;
}

void FormCreate::on_pushButtonCreateNew_clicked()
{
    if(ui->doubleSpinBoxWidth->value() > 0)
        if(ui->doubleSpinBoxHeight->value() > 0)
        {
            MdiChild *child = new MdiChild(MainWin);
            child->setWindowTitle("Untitled " + QString::number(MainWin->uniqueProjectID++));
            child->SaveFileInfo.FileName = child->windowTitle();
            child->setWindowIcon(QIcon(":/menu/cube"));
            child->SetSceneParametrs(int(ui->doubleSpinBoxWidth->value()*100), int(ui->doubleSpinBoxHeight->value()*100));

            MainWin->loadProject(child);
            this->close();
        }
}

void SwapInfoAboutFile(InfoAboutFile *File1, InfoAboutFile *File2)
{
    InfoAboutFile temp;
    temp.DateOfSave = File1->DateOfSave;
    temp.FileName = File1->FileName;
    temp.Way = File1->Way;
    temp.Square = File1->Square;

    File1->DateOfSave = File2->DateOfSave;
    File1->FileName = File2->FileName;
    File1->Way = File2->Way;
    File1->Square = File2->Square;

    File2->DateOfSave = temp.DateOfSave;
    File2->FileName = temp.FileName;
    File2->Way = temp.Way;
    File2->Square = temp.Square;
}

void ShellSortByDate(InfoAboutFile *File, int Count)
{
    for (int gap = Count/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < Count; ++i)
        {
            for (int j = i-gap; j >= 0; j -= gap)
            {
                if (File[j+gap].DateOfSave <= File[j].DateOfSave) break;
                else
                {
                    SwapInfoAboutFile(&File[j], &File[j+gap]);
                }
            }
        }
    }
}

void BubbleSortBySquare(InfoAboutFile *File, int Count)
{
    for(int i = 0; i < Count-1; i++)
        for(int j = 0; j < Count-1; j++)
            if(File[j].Square > File[j+1].Square)
                SwapInfoAboutFile(&File[j], &File[j+1]);
}

void InsertionSortByFileName(InfoAboutFile *File, int Count)
{
    int i, j;
    InfoAboutFile key;

    for(i = 0; i < Count; i++)
    {
        j = i-1;
        while(j >= 0 && File[j+1].FileName < File[j].FileName)
        {
            SwapInfoAboutFile(&File[j], &File[j+1]);
            j--;
        }
    }
}

void FormCreate::on_pushButtonProjectName_clicked()
{
    InsertionSortByFileName(Files, CountOfFiles);
    SetFilesButtons();
}

void FormCreate::on_pushButtonProjectTime_clicked()
{
    ShellSortByDate(Files, CountOfFiles);
    SetFilesButtons();
}

void FormCreate::on_pushButtonProjectSquare_clicked()
{
    BubbleSortBySquare(Files, CountOfFiles);
    SetFilesButtons();
}

void FormCreate::SetFilesButtons()
{
    if(CountOfFiles >= 1)   ui->pushButton_1->setText((Files[0].FileName).leftJustified(16, ' ') + "  " + (Files[0].DateOfSave).leftJustified(16, ' ') + "  " + (QVariant(Files[0].Square).toString()).rightJustified(10, ' '));
    else ui->pushButton_1->setVisible(false);
    if(CountOfFiles >= 2)   ui->pushButton_2->setText((Files[1].FileName).leftJustified(16, ' ') + "  " + (Files[1].DateOfSave).leftJustified(16, ' ') + "  " + (QVariant(Files[1].Square).toString()).rightJustified(10, ' '));
    else ui->pushButton_2->setVisible(false);
    if(CountOfFiles >= 3)   ui->pushButton_3->setText((Files[2].FileName).leftJustified(16, ' ') + "  " + (Files[2].DateOfSave).leftJustified(16, ' ') + "  " + (QVariant(Files[2].Square).toString()).rightJustified(10, ' '));
    else ui->pushButton_3->setVisible(false);
    if(CountOfFiles >= 4)   ui->pushButton_4->setText((Files[3].FileName).leftJustified(16, ' ') + "  " + (Files[3].DateOfSave).leftJustified(16, ' ') + "  " + (QVariant(Files[3].Square).toString()).rightJustified(10, ' '));
    else ui->pushButton_4->setVisible(false);
    if(CountOfFiles >= 5)   ui->pushButton_5->setText((Files[4].FileName).leftJustified(16, ' ') + "  " + (Files[4].DateOfSave).leftJustified(16, ' ') + "  " + (QVariant(Files[4].Square).toString()).rightJustified(10, ' '));
    else ui->pushButton_5->setVisible(false);
    SetButtonsTextAlign();
}

void FormCreate::SetButtonsTextAlign()
{
    ui->pushButton_1->setStyleSheet("text-align: left;");
    ui->pushButton_2->setStyleSheet("text-align: left;");
    ui->pushButton_3->setStyleSheet("text-align: left;");
    ui->pushButton_4->setStyleSheet("text-align: left;");
    ui->pushButton_5->setStyleSheet("text-align: left;");
}

void FormCreate::on_pushButton_1_clicked()
{
    WayToOpen = 0;
    SetButtonsTextAlign();
    ui->pushButton_1->setStyleSheet("background-color: rgb(173, 255, 153); text-align: left;");
}

void FormCreate::on_pushButton_2_clicked()
{
    WayToOpen = 1;
    SetButtonsTextAlign();
    ui->pushButton_2->setStyleSheet("background-color: rgb(173, 255, 153); text-align: left;");
}

void FormCreate::on_pushButton_3_clicked()
{
    WayToOpen = 2;
    SetButtonsTextAlign();
    ui->pushButton_3->setStyleSheet("background-color: rgb(173, 255, 153); text-align: left;");
}

void FormCreate::on_pushButton_4_clicked()
{
    WayToOpen = 3;
    SetButtonsTextAlign();
    ui->pushButton_4->setStyleSheet("background-color: rgb(173, 255, 153); text-align: left;");
}

void FormCreate::on_pushButton_5_clicked()
{
    WayToOpen = 4;
    SetButtonsTextAlign();
    ui->pushButton_5->setStyleSheet("background-color: rgb(173, 255, 153); text-align: left;");
}

void FormCreate::on_pushButtonOpen_clicked()
{
    if(WayToOpen != -1)
    {
        FileOpen OpenFile(MainWin);
        OpenFile.OpenFileByWay(Files[WayToOpen].Way, Files[WayToOpen].FileName);
        this->close();
    }
}
