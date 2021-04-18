#include "abstractfile.h"
#include <QSizePolicy>
#include <QPixmap>

#include <QDebug>

Abstractfile::Abstractfile(QString const & nom,QWidget *parent,int size)
    :QLabel(parent),_nom(new QLabel(nom,this)) ,_taille(size),locale(nullptr)
{


    setFixedSize(_taille,_taille+16);


    //setStyleSheet("background-color : white ;");


     setAlignment(Qt::AlignTop);
    _nom->setAlignment(Qt::AlignCenter);
    _nom->setGeometry(0,this->height()-15,_taille,15);
    _nom->setStyleSheet("color: White ;");





}
void Abstractfile::setImage(QString const & filename)
{
    QPixmap fileImg(filename);
    fileImg=fileImg.scaledToHeight(_taille,Qt::SmoothTransformation);
    fileImg=fileImg.scaledToWidth(_taille,Qt::SmoothTransformation);

    this->setPixmap(fileImg);
}


void Abstractfile::mouseDoubleClickEvent(QMouseEvent *)
{
    OpenEvent();
}

void Abstractfile::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
       qDebug()<<"left";
       emit leftclicked();

    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug()<<"right";
       emit rightclicked();

    }
}


Abstractfile::~Abstractfile()
{
    delete _nom;
}
