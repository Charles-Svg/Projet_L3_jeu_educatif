#include "desktop.h"
#include <QApplication>
#include <QFile>
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile style(":/style");
    style.open(QFile::ReadOnly);
    QString styleSheet = (style.readAll());
    a.setStyleSheet(styleSheet);

    Desktop w;

     //w.showFullScreen(); //solution temporaire
    w.show();
    w.setWindowState(Qt::WindowMaximized);
    return a.exec();
}
