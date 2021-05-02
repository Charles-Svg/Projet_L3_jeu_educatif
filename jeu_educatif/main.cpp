#include "desktop.h"
#include <QApplication>
#include <QFile>
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Desktop w(User::Prof);

     //w.showFullScreen(); //solution temporaire
    w.show();
    w.setWindowState(Qt::WindowMaximized);
    return a.exec();
}
