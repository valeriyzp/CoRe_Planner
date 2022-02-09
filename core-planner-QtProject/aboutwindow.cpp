#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    setupOtherUi();
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::setupOtherUi()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->pushButtonClose->setStyleSheet("QPushButton {color: white;}");
}

void AboutWindow::on_pushButtonClose_clicked()
{
    close();
}

void AboutWindow::on_labelSystemNick_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}

void AboutWindow::on_labelx8357238_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}

void AboutWindow::on_labelvaleriyzp_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}
