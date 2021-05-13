#include "mainwindow.h"
#include <QScreen>
#include <QDesktopServices>

#include "fondu.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint |Qt::WindowMaximizeButtonHint );

    QScreen* ecran=QGuiApplication::primaryScreen() ;
    this->setFixedSize (ecran->availableSize());




    Fondu* fond1= new Fondu(fondu1);
    setCentralWidget(fond1);

    connect(fond1,&Fondu::end,this,&MainWindow::loadChap1);

}

void MainWindow::loadChap1()
{
    Desktop* Desk= new Desktop(Chapitre::chap1,this);
    setCentralWidget(Desk);
}
