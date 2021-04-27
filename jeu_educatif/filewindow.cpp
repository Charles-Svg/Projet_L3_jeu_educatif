#include "filewindow.h"
#include <QPushButton>

FileWindow::FileWindow(Directory * Dir,QWidget * desk)
    :QWidget(nullptr),rootDir(Dir),layout(new QHBoxLayout()),desktop(desk)
{

    setWindowTitle("Explorateur de Fichiers");
    setWindowIcon(QIcon(":/folder"));
    setMinimumSize(800,600);


    //boutton de retour en arrière

     QPushButton* goPrevious= new QPushButton("Go Back",this);
     connect(goPrevious,&QAbstractButton::clicked,this,&FileWindow::goBack);

    //organise les sous-fichiers de Dir dans un layout (QGridLayout)
    setLayout(layout);
    layout->setAlignment(Qt::AlignTop);
    layout->addStretch(1);

 /*   for(auto i=0;i<rootDir->filelist().size();++i)
    {

        auto fl= rootDir->filelist();
        auto a =fl.at(i);
        a->show();
        layout->addWidget(a);
        layout->addStretch(1);

    } */


}

void FileWindow::goBack(bool)
{
 /*   if(rootDir->getparentDir()!=nullptr)
    {
        //faire un event
        QCoreApplication::postEvent(desktop,new goPreviousEvent(rootDir->getparentDir()));
    }
    */
}

FileWindow::~FileWindow()
{
   /* for (auto i = 0;i<rootDir->filelist().size();i++)
    {
        layout->removeWidget(rootDir->filelist().at(i));
        rootDir->filelist().at(i)->setParent(0); //potentielle fuite mémoire
    }*/
}


//Event
/*
QEvent::Type goPreviousEvent::MyType= static_cast<QEvent::Type>(QEvent::registerEventType());

goPreviousEvent::goPreviousEvent(Directory* previousDir)
    :QEvent(MyType),_previousDir(previousDir)
{}
*/


