#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    w.setWindowState(Qt::WindowMaximized);

    return a.exec();
}
