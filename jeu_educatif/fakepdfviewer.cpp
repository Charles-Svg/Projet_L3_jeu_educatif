#include "fakepdfviewer.h"
#include <QDebug>

FakePdfViewer::FakePdfViewer(QString const & course,QWidget* parent)
    :QScrollArea(parent),label(new QLabel(this))
{
    label->setBackgroundRole(QPalette::Base);
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label->setScaledContents(true);
    label->setPixmap(QPixmap(course));
    label->adjustSize();


    setMinimumSize(1024,600);
    setBackgroundRole(QPalette::Dark);
    setWidget(label);
    setAlignment(Qt::AlignCenter);


}

void FakePdfViewer::resizeEvent(QResizeEvent * ev)
{
    qDebug()<<"old "<<ev->oldSize();
    qDebug()<<"new :"<<ev->size();
    setAlignment(Qt::AlignCenter);;
}
