#include "abstractfileview.h"
#include <math.h>


AbstractfileView::AbstractfileView(Abstractfile* filemodel, QWidget* parent,int larg,int haut)
    :QLabel(parent),_nom(new QLabel(filemodel->nom(),this)),largeur(larg),hauteur(haut)
{

    //manoeuvre pour agrandir le Qlabel en fonction de la taille du texte
         auto metrics = QFontMetrics(QApplication::font());
         int labelheight=20;
        if(metrics.horizontalAdvance(filemodel->nom())>larg-4)
        {
            int rapport=(metrics.horizontalAdvance(filemodel->nom())/larg)+1;
            labelheight=labelheight*rapport;
        }

    _nom->setAlignment(Qt::AlignCenter);
    _nom->setWordWrap(1);

     setFixedSize(largeur,hauteur+labelheight);
     setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    _nom->setGeometry(0,this->height()-labelheight,largeur,labelheight);
    _nom->setStyleSheet("color : white");

}


void AbstractfileView::setImage(QString const & filename)
{
    QPixmap fileImg(filename);
    fileImg=fileImg.scaledToHeight(48,Qt::SmoothTransformation);
    fileImg=fileImg.scaledToWidth(48,Qt::SmoothTransformation);

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
       emit rightclicked(event->globalPos());

    }
}

