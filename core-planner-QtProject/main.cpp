#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QSplashScreen *splash = new QSplashScreen(QPixmap(":/bg/splash"));
    splash->show();
    splash->showMessage("Loading...", Qt::AlignCenter | Qt::AlignBottom, QColor(57, 62, 65, 127));

    QCoreApplication::setApplicationName("CoRe Planner");
    QCoreApplication::setOrganizationName("CoRe Team");
    QCoreApplication::setApplicationVersion("1.0");

    MainWindow window;
    app.processEvents(QEventLoop::ExcludeUserInputEvents);

    window.show();
    splash->finish(&window);
    delete splash;
    QApplication::restoreOverrideCursor();

    return app.exec();
}
