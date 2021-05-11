#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QtDebug>
#include <fstream>


int main(int argc, char *argv[])
{
    fstream save;
    if (FILE *file = !fopen("save.json", "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }

    QApplication a(argc, argv);

    MainWindow w;

     //w.showFullScreen(); //solution temporaire
    w.show();
    w.setWindowState(Qt::WindowMaximized);
    return a.exec();
}
