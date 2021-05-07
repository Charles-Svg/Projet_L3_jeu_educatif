#include "mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint |Qt::WindowMaximizeButtonHint );

    QScreen* ecran=QGuiApplication::primaryScreen() ;
    this->setFixedSize (ecran->availableSize());

    Desktop* Desk= new Desktop(User::Eleve,this);
    setCentralWidget(Desk);
}
