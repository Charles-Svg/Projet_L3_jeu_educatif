#include "abstractfile.h"
#include <QSizePolicy>
#include <QPixmap>

Abstractfile::Abstractfile(QString const & nom,QWidget *parent,int size)
    :QLabel(parent),_nom(new QLabel(nom,this)) ,_taille(size)
{


    setFixedSize(_taille,_taille+16);


    //setStyleSheet("background-color : white ;");


     setAlignment(Qt::AlignTop);
    _nom->setAlignment(Qt::AlignCenter);
    _nom->setGeometry(0,this->height()-15,_taille,15);





}
void Abstractfile::setImage(QString const & filename)
{
    QPixmap fileImg(filename);
    fileImg=fileImg.scaledToHeight(_taille);
    fileImg=fileImg.scaledToWidth(_taille);

    this->setPixmap(fileImg);
}


void Abstractfile::mouseDoubleClickEvent(QMouseEvent *)
{
    OpenEvent();
}
