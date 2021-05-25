#include "filewindow.h"
#include <QPushButton>
#include <QStyle>
#include <QIcon>
#include <QPixmap>

FileWindow::FileWindow(Directory * Dir,QWidget * desk)
    :QWidget(nullptr),rootDir(Dir),layout(new QHBoxLayout()),_desktop(desk)
{


    //pour avoir le chemin du fichier dans le titre de la fenetre
    setWindowTitle("Explorateur de Fichiers :"+Dir->arborescence());
    setWindowIcon(QIcon(":/folder"));
    setMinimumSize(800,600);


     //boutton de retour en arrière
     QPushButton* goPrevious= new QPushButton(this->style()->standardIcon(QStyle::SP_ArrowLeft),"",this);
     goPrevious->setStyleSheet("background:transparent;");
     goPrevious->setMinimumSize(60,40);
     goPrevious->setIconSize(QSize(40,40));
     layout->addWidget(goPrevious);
     connect(goPrevious,&QAbstractButton::clicked,this,&FileWindow::goBack);

    //organise les sous-fichiers de Dir dans un layout (QGridLayout)
    setLayout(layout);
    layout->setAlignment(Qt::AlignTop);
    layout->addStretch(1);


    //création de la vue des fichiers contenu dans le dossier
    for(auto i=0;i<rootDir->filelist().size();++i)
    {

       if(File* a=dynamic_cast<File*>(rootDir->filelist().at(i)))
        {

           FileView* b= new FileView(a,this);
           contenu.push_back(b);
           layout->addWidget(b);

           if(a->remplacable())
           {
               //connecte les signaux slots pour le remplacement d'un fichier pour le chap3
               connect(b,&AbstractfileView::rightclicked,b,&FileView::OpenMenu);
               connect(b,&FileView::replaced,this,&FileWindow::PostReplace);
           }

       }
       else if(PyFile* a=dynamic_cast<PyFile*>(rootDir->filelist().at(i)))
       {

           PyFileView* b= new PyFileView(a,this);
           contenu.push_back(b);
           layout->addWidget(b);

       }
       else if (PdfFile* a=dynamic_cast<PdfFile*>(rootDir->filelist().at(i)))
       {

           PdfFileView* b= new PdfFileView(a,this);
           contenu.push_back(b);
           layout->addWidget(b);
       }

       else if(Directory* a=dynamic_cast<Directory*>(rootDir->filelist().at(i)))
       {

           DirectoryView* b=new DirectoryView(a,_desktop,classic,this);
           contenu.push_back(b);
           layout->addWidget(b);

           if(a->EstCopiable())
           {
               //connecte les signaux slots pour le remplacement du dossier dans le chap1
               connect(b,&AbstractfileView::rightclicked,b,&DirectoryView::OpenMenu);
               connect(b,&DirectoryView::copied,this,&FileWindow::PostCopy);
           }
       }

        layout->addStretch(1);

    }


}

bool FileWindow::event(QEvent * ev)
{
    //sert à re-poster les evenements evoyés des fichiers/dossier de  l'exlorateur vers le bureau
    if (ev->type()==OpenPyFileEvent::type())
    {
        OpenPyFileEvent* event = dynamic_cast<OpenPyFileEvent*>(ev);
        QCoreApplication::postEvent(_desktop,new OpenPyFileEvent(event->enigme()));
        return true;
    }
    else if (ev->type()==OpenPdfFileEvent::type())
    {
        OpenPdfFileEvent* event = dynamic_cast<OpenPdfFileEvent*>(ev);
        QCoreApplication::postEvent(_desktop,new OpenPdfFileEvent(event->sender()));
        return true;
    }
    else{
        return QWidget::event(ev);
    }
}
void FileWindow::goBack(bool)
{
   if(rootDir->parentDir()!=nullptr)
    {
        QCoreApplication::postEvent(_desktop,new goPreviousEvent(rootDir->parentDir()));
    }

}

//envoie l'evenement pour ouvrir la fenetre de copie
void FileWindow::PostCopy()
{
    QCoreApplication::postEvent(_desktop,new OpenPyFileEvent(Enigme::Copie));
}


//envoie l'evenement pour ouvrir la fenetre de l'enigme finale
void FileWindow::PostReplace()
{
    QCoreApplication::postEvent(_desktop,new OpenPyFileEvent(Enigme::Final));
}


FileWindow::~FileWindow()
{
    for(QVector<AbstractfileView*>::iterator p=contenu.begin();p!=contenu.end();++p)
    {
        delete *p;
    }
}



