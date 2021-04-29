#include "abstractfileview.h"

AbstractfileView::AbstractfileView(Abstractfile* filemodel, QWidget* parent,int size)
    :QLabel(parent),_nom(new QLabel(filemodel->nom(),this)),_taille(size)
{
     setFixedSize(_taille,_taille+16);
     setAlignment(Qt::AlignTop);
    _nom->setAlignment(Qt::AlignCenter);
    _nom->setGeometry(0,this->height()-15,_taille,15);
    _nom->setStyleSheet("color : white");
}


void AbstractfileView::setImage(QString const & filename)
{
    QPixmap fileImg(filename);
    fileImg=fileImg.scaledToHeight(_taille,Qt::SmoothTransformation);
    fileImg=fileImg.scaledToWidth(_taille,Qt::SmoothTransformation);

    this->setPixmap(fileImg);
}

void AbstractfileView::mouseDoubleClickEvent(QMouseEvent *)
{
    OpenEvent();
}


void AbstractfileView::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
       emit leftclicked();

    }
    else if(event->button() == Qt::RightButton)
    {
       emit rightclicked();

    }
}


