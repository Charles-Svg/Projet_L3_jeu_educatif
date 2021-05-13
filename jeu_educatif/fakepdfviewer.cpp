#include "fakepdfviewer.h"

#include <QDebug>

FakePdfViewer::FakePdfViewer(Cours cours,QWidget* parent)
    :QScrollArea(parent),layout(new QVBoxLayout)
{


    setMinimumSize(1024,600);
    setBackgroundRole(QPalette::Dark);
    setAlignment(Qt::AlignCenter);
    LoadImages(cours);


}


FakePdfViewer::~FakePdfViewer()
{
    delete layout;
    for(auto i=Images.begin();i!=Images.end();i++)
    {
        delete *i;
    }
}


void FakePdfViewer::resizeEvent(QResizeEvent * ev)
{
    qDebug()<<"old "<<ev->oldSize();
    qDebug()<<"new :"<<ev->size();
    setAlignment(Qt::AlignCenter);;
}

QString cours_vig[5]={":/vigenere1",":/vigenere2",":/vigenere3",":/vigenere4",":/vigenere5"};
QString cours_cesar[5]={":/cesar1",":/cesar2",":/cesar3",":/cesar4"};
QString cours_sub[5]={":/substitution1",":substitution2",":/substitution3",":/substitution4"};
QString cours_freq[5]={":/freq1",":freq2",":/freq3",":/freq4"};


void FakePdfViewer::LoadImages(Cours c)
{

    switch (c) {
        case Cesar:

    {
         QWidget* widget=new QWidget(this);
         widget->setFixedSize(1050,610*4);
         widget->setLayout(layout);
         setWidget(widget);
         for(int i=0;i<4;i++)
         {
             QLabel* label= new QLabel();
             label->setBackgroundRole(QPalette::Base);
             label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
             label->setScaledContents(true);
             label->setPixmap(cours_cesar[i]);
             label->adjustSize();

             layout->addWidget(label);

             Images.push_back(label);

         }
     }

        break;

        case Vigenere:
       {
            QWidget* widget=new QWidget(this);
            widget->setFixedSize(1050,610*5);
            widget->setLayout(layout);
            setWidget(widget);
            for(int i=0;i<5;i++)
            {
                QLabel* label= new QLabel();
                label->setBackgroundRole(QPalette::Base);
                label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
                label->setScaledContents(true);
                label->setPixmap(cours_vig[i]);
                label->adjustSize();

                layout->addWidget(label);

                Images.push_back(label);

            }
        }
        break;

        case Substitution:

        {
             QWidget* widget=new QWidget(this);
             widget->setFixedSize(1050,610*4);
             widget->setLayout(layout);
             setWidget(widget);
             for(int i=0;i<4;i++)
             {
                 QLabel* label= new QLabel();
                 label->setBackgroundRole(QPalette::Base);
                 label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
                 label->setScaledContents(true);
                 label->setPixmap(cours_sub[i]);
                 label->adjustSize();

                 layout->addWidget(label);

                 Images.push_back(label);

             }
         }

        break;

        case frequentielle:
    {
         QWidget* widget=new QWidget(this);
         widget->setFixedSize(1050,610*4);
         widget->setLayout(layout);
         setWidget(widget);
         for(int i=0;i<4;i++)
         {
             QLabel* label= new QLabel();
             label->setBackgroundRole(QPalette::Base);
             label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
             label->setScaledContents(true);
             label->setPixmap(cours_freq[i]);
             label->adjustSize();

             layout->addWidget(label);

             Images.push_back(label);

         }
     }
        break;

        case Autre:
        break;
    }

}
