#include "filewindow.h"

FileWindow::FileWindow(QWidget * parent)
    :QMdiSubWindow(parent)
{

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Explorateur de Fichiers");
    setWindowIcon(QIcon(":/folder"));
    setFixedSize(800,600);
    move(500,500);
    show();


}


void FileWindow::moveEvent(QMoveEvent *)
{

}

