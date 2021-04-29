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

    for(auto i=0;i<rootDir->filelist().size();++i)
    {

       if(File* a=dynamic_cast<File*>(rootDir->filelist().at(i)))
        {
           //on ceer un nouveau fichier
           FileView* b= new FileView(a);
           contenu.push_back(b);
           layout->addWidget(b);

       }
       else if(Directory* a=dynamic_cast<Directory*>(rootDir->filelist().at(i)))
       {
           //creer un dossier
           DirectoryView* b=new DirectoryView(a);
           contenu.push_back(b);
           layout->addWidget(b);
       }

        layout->addStretch(1);

    }


}

void FileWindow::goBack(bool)
{
   if(rootDir->parentDir()!=nullptr)
    {
        //faire un event
        QCoreApplication::postEvent(desktop,new goPreviousEvent(rootDir->parentDir()));
    }

}

FileWindow::~FileWindow()
{

    for(QVector<AbstractfileView*>::iterator p=contenu.begin();p!=contenu.end();++p)
    {
        delete *p;
    }
}



