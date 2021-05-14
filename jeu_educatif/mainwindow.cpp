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
    connect(Desk,&Desktop::endChap1,this,&MainWindow::loadFondu2);
}


void MainWindow::loadFondu2()
{
    Fondu* fond2= new Fondu(fondu2);
    setCentralWidget(fond2);
    connect(fond2,&Fondu::end,this,&MainWindow::loadChap2);
}

void MainWindow::loadChap2()
{
    Desktop* Desk= new Desktop(Chapitre::chap2,this);
    setCentralWidget(Desk);
    connect(Desk,&Desktop::endChap2,this,&MainWindow::loadFondu3);
}


void MainWindow::loadFondu3()
{
    Fondu* fond3= new Fondu(fondu3);
    setCentralWidget(fond3);
    connect(fond3,&Fondu::end,this,&MainWindow::loadChap3);
}

void MainWindow::loadChap3()
{
    Desktop* Desk= new Desktop(Chapitre::chap3,this);
    setCentralWidget(Desk);
}











