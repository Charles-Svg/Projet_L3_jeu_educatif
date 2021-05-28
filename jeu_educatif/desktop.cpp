#include "desktop.h"

#include <QGridLayout>
#include <QtGui>
#include <QStyleFactory>
#include <QApplication>
#include <QFile>
#include <QMessageBox>

Desktop::Desktop(Chapitre chap,QWidget *parent) :
    QMdiArea(parent)
{

    setBackground(QBrush());// permet de modifier/actualiser le background avec le css

    //adapte la fenetre a la taille de l'écran
    setMinimumSize(parent->size());
    setOption(QMdiArea::DontMaximizeSubWindowOnActivation);

    //charge le bureau correspondant au chapitre
    switch(chap)
    {

        case chap1 :
        {

            QFile style(":/styleProf");
            style.open(QFile::ReadOnly);
            QString styleSheet = (style.readAll());
            this->setStyleSheet(styleSheet);
            addFilesProf();

        }
            break;

        case chap2:
        {
            QFile style(":/styleEleve");
            style.open(QFile::ReadOnly);
            QString styleSheet = (style.readAll());
            this->setStyleSheet(styleSheet);
            addFilesEleve();

         }
            break;

        case chap3:
        {
            QFile style(":/styleProf");
            style.open(QFile::ReadOnly);
            QString styleSheet = (style.readAll());
            this->setStyleSheet(styleSheet);
            addFilesProf2();
        }
        break;


    }

}

void Desktop::addFilesProf()
{
    QGridLayout* FileLayout= new QGridLayout(this->viewport());

    //sert pour espacer les dossier sur le bureau
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
        Vid->addDir("NSFW",false); // non ouvrable
        cePC->addDir("Télécharg...",false);
        cePC->addDir("Images",false);


        auto Doc=cePC->addDir("Documents");
        // dans Documents
            auto Notes=Doc->addDir("Notes et resultats", false); //ce doc qu'on ne peut ouvrir dans le chap 1
            Notes->SetCopaiable(true);

            auto Annales= Notes->addDir("Annales Examens");
            Annales->addPdfFile("Examen1 2019-2020",Cesar);
            auto notesExam=Notes->addDir("Notes Examens");
            auto Exam1= notesExam->addDir("Notes examen1");
            Exam1->addPdfFile("Barème.pdf",Cesar);
            Exam1->addFile("Notes exam 1");

            auto cours=Doc->addDir("Cours");
            //ajout des cours
            cours->addPdfFile("Crypto Cesar 2020",Cours::Cesar);
            cours->addPdfFile("Crypto Substi 2020",Cours::Substitution);
            cours->addPdfFile("Crypto Vigenere 2020",Cours::Vigenere);




}


void Desktop::addFilesProf2()
{
    QGridLayout* FileLayout= new QGridLayout(this->viewport());

    //sert pour espacer les dossier sur le bureau
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
        Vid->addDir("NSFW",false); // non ouvrable
        cePC->addDir("Télécharg...",false);
        cePC->addDir("Images",false);


        auto Doc=cePC->addDir("Documents");

            //dans Documents
            auto Notes=Doc->addDir("Notes et resultats");

            auto Annales= Notes->addDir("Annales Examens");
            Annales->addPdfFile("Examen1 2019-2020",Cesar);
            auto notesExam=Notes->addDir("Notes Examens");
            auto Exam1= notesExam->addDir("Notes examen1");
            Exam1->addPdfFile("Barème.pdf",Cesar);

            //fichier que l'on va remplacer pour enigme finale
            auto FileE=Exam1->addFile("Notes exam 1");
            FileE->setRemplacable(true);

            auto cours=Doc->addDir("Cours");
            //ajout des cours
            cours->addPdfFile("Crypto Cesar 2020",Cours::Cesar);
            cours->addPdfFile("Crypto Substi 2020",Cours::Substitution);
            cours->addPdfFile("Crypto Vigenere 2020",Cours::Vigenere);
            cours->addPdfFile("Crypto Freq 2020",Cours::frequentielle);

            //clé usb
            auto notes = UsbKey->addDir("Notes et résultats");
            notes->addPyFile("Programmation examens.xls",Enigme::Substitution,Icon::xls);

            auto exam= notes->addDir("Annales examens");
            exam->addPyFile("Examen1.pdf",Enigme::Vigenere,Icon::pdf);
            auto note2=notes->addDir("Notes examens");
            auto note3=note2->addDir("Notes Examen1");
            note2->addDir("Notes Examen2",false);
            note3->addPyFile("Bareme.pdf",Enigme::Cesar,Icon::pdf);

}


void Desktop::addFilesEleve()
{

    QGridLayout* FileLayout= new QGridLayout(this->viewport());

    //sert pour espacer les dossier sur le bureau
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
    cePC->addDir("Vidéos",false);

    auto tel=cePC->addDir("Télécharg...");
        tel->addFile("fortine.exe",false);
        tel->addFile("glitcher pro v-bucks.bat",false);

    cePC->addDir("Images",false);

    auto doc=cePC->addDir("Documents");
        doc->addDir("Fortnite",false);
        auto cours=cePC->addDir("Cours");
            cours->addDir("Maths",false);
            cours->addDir("Karaté",false);
            cours->addDir("Français",false);

            auto crypto= cours->addDir("Cryptographie");
                crypto->addPdfFile("Vigenere",Vigenere);
                crypto->addPdfFile("Substitution mot-clé",Substitution);
                crypto->addPdfFile("Césaaar",Cesar); //ref à jojo


    //clé usb
    auto notes = UsbKey->addDir("Notes et résultats");
    notes->addPyFile("Programmation examens.xls",Enigme::Substitution,Icon::xls);

    auto exam= notes->addDir("Annales examens");
    exam->addPyFile("Examen1.pdf",Enigme::Vigenere,Icon::pdf);
    auto note2=notes->addDir("Notes examens");
    auto note3=note2->addDir("Notes Examen1");
    note2->addDir("Notes Examen2",false);
    note3->addPyFile("Bareme.pdf",Enigme::Cesar,Icon::pdf);

    note3->addFile("Notes examens1",true);

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
         ajoutePyFileWindow(ev->enigme());
         return true;
     }
     else if (event->type()==OpenPdfFileEvent::type())
     {
        //regarder quel fichier on veut ouvrir
         OpenPdfFileEvent* ev=dynamic_cast<OpenPdfFileEvent*>(event);
         ajoutePdfFileWindow(ev->sender());
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

void Desktop::ajoutePyFileWindow(Enigme e)
{
    IDEWindow* Pywindow = new IDEWindow(e,this);
    QMdiSubWindow* subwindow= this->addSubWindow(Pywindow);

    subwindow->move(this->width()/2-Pywindow->width()/2,this->height()/2-Pywindow->height()/2);
    subwindow->show();

    connect(Pywindow,&IDEWindow::copyExec,this,&Desktop::verifyCopy);
    connect(Pywindow,&IDEWindow::notesExec,this,&Desktop::verifyNotesChange);

    if(e==Enigme::Final)
    {
        connect(Pywindow,&IDEWindow::endGame,this,&Desktop::emitEndGame);
    }

}

void Desktop::ajoutePdfFileWindow(PdfFile* file)
{

    FakePdfViewer* PdfWindow= new FakePdfViewer(file->cours());
    PdfWindow->setWindowTitle(file->nom());
    QMdiSubWindow* subwindow= this->addSubWindow(PdfWindow);

    subwindow->move(this->width()/2-PdfWindow->width()/2,this->height()/2-PdfWindow->height()/2);
    subwindow->show();
}

void Desktop::verifyCopy()
{
    if(deepCopyCompleted())
    {
        QMessageBox bj(QMessageBox::Information,"Bien joué !","Le dossier à bien été copié sur la clé Usb");
        connect(&bj,&QMessageBox::buttonClicked,this,&Desktop::emitEndChap1);
        bj.exec();
    }
}

void Desktop::verifyNotesChange()
{
    if(changeMarkCompleted())
    {
        QMessageBox bv(QMessageBox::Information,"Bravo !","Le fichier des notes est modifé eheh");
        connect(&bv,&QMessageBox::buttonClicked,this,&Desktop::emitEndChap2);
        bv.exec();
    }
}

void Desktop::emitEndGame()
{
    QMessageBox m(QMessageBox::Information,"eazy peazy lemon squeezie","le fichier de note a été remplacé votre année est sauvée !");
    m.exec();
    emit endGame();
}


Desktop::~Desktop()
{
     for (QVector<Abstractfile*>::iterator p=contenu.begin();p!=contenu.end();++p)
    {
        delete *p;
    }
}
