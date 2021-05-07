#include "mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QScreen* ecran=QGuiApplication::primaryScreen() ;
    this->setFixedSize (ecran->availableSize());

    Desktop* Desk= new Desktop(User::Eleve,this);
    setCentralWidget(Desk);
}
