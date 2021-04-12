#include "filewindow.h"

FileWindow::FileWindow(QWidget * parent)
    :QWidget(parent)
{

    setWindowTitle("Explorateur de Fichiers");
    setWindowIcon(QIcon(":/folder"));
    setMinimumSize(800,600);

}


void FileWindow::moveEvent(QMoveEvent *)
{

}

