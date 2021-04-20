#include "desktop.h"
#include <QGridLayout>
#include <QScreen>
#include <QDebug>
#include <QtGui>
#include <QStyleFactory>
#include <QApplication>


Desktop::Desktop(QWidget *parent) : QMainWindow(parent)
  ,_zone(new QMdiArea(this))
{

    //permet de desactiver le maximize button
    setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint );

    _zone->setBackground(QBrush());// permet de modifier/actualiser le background avec le css
    this->setCentralWidget(_zone);

    setStyleSheet("border : 2px solid green;");
    QGridLayout* FileLayout= new QGridLayout(_zone);


    _zone->setLayout(FileLayout);

    //a remplacer par les tailles de l'ecran
    QScreen* ecran=QGuiApplication::primaryScreen() ;

    this->setFixedSize (ecran->availableSize());;

    _zone->setMinimumSize(this->size());

       int space=50;

       File * fichier = new File("File 1",this);
       FileLayout->addWidget(fichier,0,0);
       FileLayout->setColumnMinimumWidth(1,space);


       File * fichier2 = new File("File 2",this);
       FileLayout->addWidget(fichier2,0,2);
       FileLayout->setColumnMinimumWidth(3,space);


       Directory * dir1 = new Directory("Dir1",this);
       FileLayout->setRowMinimumHeight(1,space);
       FileLayout->addWidget(dir1,2,0);




       dir1->addfile("File 3");
       dir1->addDir("dir2");

       qDebug()<<this->size();

       //permet de compacter les fichiers/dossier en haut a gauche
       FileLayout->setColumnMinimumWidth(FileLayout->columnCount(),this->width());
       FileLayout->setRowMinimumHeight(FileLayout->rowCount(),this->height());



}


bool Desktop::event(QEvent *event)
{
    if(event->type()==OpenDirEvent::type())
    {
        OpenDirEvent* ev= dynamic_cast<OpenDirEvent*>(event);
        qDebug()<<"evenement recue de"<<ev->sender();
        addSubWindow(ev->sender());

        return true;
    }
    else
    {
        //qDebug()<<event->type();
        return QWidget::event(event);
    }
}


void Desktop::addSubWindow(Directory * rootDir)
{
    FileWindow* subwindow = new FileWindow(rootDir);
    QMdiSubWindow* fileWindow= _zone->addSubWindow(subwindow);

    fileWindow->move(this->width()/2-subwindow->width()/2,this->height()/2-subwindow->height()/2);
    fileWindow->show();
}

Desktop::~Desktop()
{
    delete _zone;
}
