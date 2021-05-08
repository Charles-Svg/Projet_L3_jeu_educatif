#include "desktop.h"


#include <QGridLayout>
#include <QDebug>
#include <QtGui>
#include <QStyleFactory>
#include <QApplication>
#include <QFile>

Desktop::Desktop(User user,QWidget *parent) :
    QMdiArea(parent)
{

    setBackground(QBrush());// permet de modifier/actualiser le background avec le css

    //s'adapte a la taille de l'écran

    setMinimumSize(parent->size());
    setOption(QMdiArea::DontMaximizeSubWindowOnActivation);

    switch(user)
    {

        case Eleve:
        {
            QFile style(":/styleEleve");
            style.open(QFile::ReadOnly);
            QString styleSheet = (style.readAll());
            this->setStyleSheet(styleSheet);
            addFilesEleve();

         }
            break;

        case Prof :
        {
            //methode prof
            QFile style(":/styleProf");
            style.open(QFile::ReadOnly);
            QString styleSheet = (style.readAll());
            this->setStyleSheet(styleSheet);
            addFilesProf();

        }
            break;
    }

}

void Desktop::addFilesProf()
{
    QGridLayout* FileLayout= new QGridLayout(this);


    this->setLayout(FileLayout);

    int space=50;

    Directory * cePC=new Directory("Ce PC");
    contenu.push_back(cePC);
    DirectoryView * cePCView =new DirectoryView(cePC,this);
    FileLayout->addWidget(cePCView,0,0);
    FileLayout->setColumnMinimumWidth(1,space);


    Directory* UsbKey=new Directory("Clé USB");
    contenu.push_back(UsbKey);
    DirectoryView * UsbKeyView= new DirectoryView(UsbKey,this,usb);
    FileLayout->setRowMinimumHeight(1,space);
    FileLayout->addWidget(UsbKeyView,2,0);


     //permet de compacter les fichiers/dossier en haut a gauche
    FileLayout->setColumnMinimumWidth(FileLayout->columnCount(),this->width());
    FileLayout->setRowMinimumHeight(FileLayout->rowCount(),this->height());

    //ce PC
        auto Vid=cePC->addDir("Vidéos");
        Vid->addDir("NSFW",0); // non ouvrable
        cePC->addDir("Téléchargements",false);
        cePC->addDir("Images",false);


        auto Doc=cePC->addDir("Documents");
        // dans Documents
            auto Notes=Doc->addDir("Notes et resultats");
            auto Annales= Notes->addDir("Annales Examens");
            Annales->addPdfFile("Examen1 2019-2020");
            auto notesExam=Notes->addDir("Notes Examens");
            auto Exam1= notesExam->addDir("Notes examen 1 2019");
            Exam1->addPdfFile("Barème.pdf");
            Exam1->addFile("Notes exam 1");

            Doc->addDir("Cours");

    //contenu clé USB



}

void Desktop::addFilesEleve()
{

    QGridLayout* FileLayout= new QGridLayout(this);


    this->setLayout(FileLayout);

    int space=50;

    Directory * cePC=new Directory("Ce PC");
    contenu.push_back(cePC);
    DirectoryView * cePCView =new DirectoryView(cePC,this);
    FileLayout->addWidget(cePCView,0,0);
    FileLayout->setColumnMinimumWidth(1,space);


    Directory* UsbKey=new Directory("Clé USB");
    contenu.push_back(UsbKey);
    DirectoryView * UsbKeyView= new DirectoryView(UsbKey,this,usb);
    FileLayout->setRowMinimumHeight(1,space);
    FileLayout->addWidget(UsbKeyView,2,0);


    //permet de compacter les fichiers/dossier en haut a gauche
   FileLayout->setColumnMinimumWidth(FileLayout->columnCount(),this->width());
   FileLayout->setRowMinimumHeight(FileLayout->rowCount(),this->height());


    //contenu de CePC
    cePC->addPyFile("Test.py",Enigme::Vigenere);
    cePC->addDir("Vidéos");

    auto tel=cePC->addDir("Téléchargements");
        tel->addFile("fortine.exe");
        tel->addFile("glitcher pro v-bucks.bat");

    cePC->addDir("Images");

    auto doc=cePC->addDir("Documents");
        doc->addDir("Fortnite");
        auto cours=cePC->addDir("Cours");
            cours->addDir("Maths");
            cours->addDir("Karaté");
            cours->addDir("Français");

            auto crypto= cours->addDir("Cryptographie");
                crypto->addPdfFile("Vigenere");
                crypto->addPdfFile("Substitution mot-clé");
                crypto->addPdfFile("Césaaaaar"); //ref à jojo


}

bool Desktop::event(QEvent *event)
{

     if(event->type()==OpenDirEvent::type())
    {
        OpenDirEvent* ev= dynamic_cast<OpenDirEvent*>(event);
        ajouteSubWindow(ev->sender());
        return true;
    }
    else if(event->type()==ChangeFileWindowEvent::type())
      {
            ChangeFileWindowEvent* ev= dynamic_cast<ChangeFileWindowEvent*>(event);
            changeSubWindow(ev->sender());
            return true;
       }
    else if(event->type()==goPreviousEvent::type())
    {
        goPreviousEvent* ev= dynamic_cast<goPreviousEvent*>(event);
        changeSubWindow(ev->previousDir());

        return true;
    }
     else if (event->type()==OpenPyFileEvent::type())
     {
        //regarder quel fichier on veut ouvrir
         OpenPyFileEvent* ev=dynamic_cast<OpenPyFileEvent*>(event);
         ajoutePyFileWindow(ev->sender());
         return true;
     }

    else
        return QMdiArea::event(event);
}


void Desktop::ajouteSubWindow(Directory * rootDir)
{
    FileWindow* subwindow = new FileWindow(rootDir,this);
    connect(subwindow,&FileWindow::goPrevious,this,&Desktop::changeSubWindow);

    QMdiSubWindow* fileWindow= this->addSubWindow(subwindow);

    fileWindow->move(this->width()/2-subwindow->width()/2,this->height()/2-subwindow->height()/2);
    fileWindow->show();
}

void Desktop::changeSubWindow(Directory* sender)
{

    if(this->activeSubWindow()!=nullptr)
    {
     FileWindow* newfile= new FileWindow(sender,this);
     this->activeSubWindow()->setWidget(newfile);
    }
}

void Desktop::ajoutePyFileWindow(PyFile* file)
{
    IDEWindow* Pywindow = new IDEWindow(file->enigmeType(),this);
    QMdiSubWindow* subwindow= this->addSubWindow(Pywindow);
    subwindow->move(this->width()/2-Pywindow->width()/2,this->height()/2-Pywindow->height()/2);
    subwindow->show();

}


Desktop::~Desktop()
{
     for (QVector<Abstractfile*>::iterator p=contenu.begin();p!=contenu.end();++p)
    {
        delete *p;
    }
}
