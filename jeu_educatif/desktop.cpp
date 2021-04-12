#include "desktop.h"
#include <QGridLayout>

#include <QDebug>

Desktop::Desktop(QWidget *parent) : QMainWindow(parent)
  ,_zone(new QMdiArea(this))
{

    _zone->setBackground(QBrush());// permet de modifier/actualiser le background avec le css
    this->setCentralWidget(_zone);

    setStyleSheet("border : 2px solid green;");
    QGridLayout* FileLayout= new QGridLayout(_zone);

    _zone->setLayout(FileLayout);

    //a remplacer par les tailles de l'ecran
    this->setFixedWidth(1920);
    this->setFixedHeight(1080);

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

       qDebug()<<this->size();

       //permet de compacter les fichiers/dossier en haut a gauche
       FileLayout->setColumnMinimumWidth(FileLayout->columnCount(),this->width());
       FileLayout->setRowMinimumHeight(FileLayout->rowCount(),this->height());

       //_zone->addSubWindow(test);

       connect(dir1,&Directory::DirOpenned,this,&Desktop::addSubWindow);
}

void Desktop::addSubWindow(FileWindow * subwindow)
{
    _zone->addSubWindow(subwindow);
}

Desktop::~Desktop()
{
    delete _zone;
}
