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
    //setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint );

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

       //changer les parents des fichiers et dossier a QMdiArea
       File fichier("File 1");
       FileView * file1 = new FileView(&fichier,_zone);
       FileLayout->addWidget(file1,0,0);
       FileLayout->setColumnMinimumWidth(1,space);


       File fichier2("File 2");
       FileView * file2 = new FileView(&fichier2,_zone);
       FileLayout->addWidget(file2,0,2);
       FileLayout->setColumnMinimumWidth(3,space);


       Directory dossier1("Dir1");
       qDebug()<<"dossier crée, son parent :"<<dossier1.parentDir();
       DirectoryView * dir1 =new DirectoryView(&dossier1,_zone);
       FileLayout->setRowMinimumHeight(1,space);
       FileLayout->addWidget(dir1,2,0);



      //  dir1->addfile("File 3");
      //  dir1->addDir("dir2");

       qDebug()<<this->size();

       //permet de compacter les fichiers/dossier en haut a gauche
       FileLayout->setColumnMinimumWidth(FileLayout->columnCount(),this->width());
       FileLayout->setRowMinimumHeight(FileLayout->rowCount(),this->height());



}


bool Desktop::event(QEvent *event)
{

     if(event->type()==OpenDirEvent::type())
    {
       // OpenDirEvent* ev= dynamic_cast<OpenDirEvent*>(event);
       // addSubWindow(ev->sender());
        qDebug()<<"Open Dir event";
        return true;
    }
    else if(event->type()==ChangeFileWindowEvent::type())
      {
           // ChangeFileWindowEvent* ev= dynamic_cast<ChangeFileWindowEvent*>(event);
            //changeSubWindow(ev->sender());
            qDebug()<<"Change file Window event";
            return true;
       }
 /*   else if(event->type()==goPreviousEvent::type())
    {
        goPreviousEvent* ev= dynamic_cast<goPreviousEvent*>(event);
        changeSubWindow(ev->previousDir());

        return true;
    }

    else */
        return QWidget::event(event);
}


void Desktop::addSubWindow(Directory * rootDir)
{
    FileWindow* subwindow = new FileWindow(rootDir,this);
    connect(subwindow,&FileWindow::goPrevious,this,&Desktop::changeSubWindow);

    QMdiSubWindow* fileWindow= _zone->addSubWindow(subwindow);

    fileWindow->move(this->width()/2-subwindow->width()/2,this->height()/2-subwindow->height()/2);
    fileWindow->show();
}

void Desktop::changeSubWindow(Directory* sender)
{
    qDebug()<<"change subwindow";
    if(_zone->activeSubWindow()!=nullptr)
    {
     FileWindow* newfile= new FileWindow(sender,this);
     _zone->activeSubWindow()->setWidget(newfile);
    }
}

Desktop::~Desktop()
{
    delete _zone;
}
