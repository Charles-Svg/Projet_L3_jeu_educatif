#include "fileview.h"


FileView::FileView(File* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    setImage(":/file");
}

void FileView::OpenEvent()
{
    if(_model->ouvrable())
    {

        if(_model->ecriture()==false) //le fichier est verouillé
        {
            //ouverture du dialog avec les lettres à rentrer
            EnigmaDialog * e= new EnigmaDialog(this->parentWidget());
            connect(e,&EnigmaDialog::accepted,this,&FileView::setEcritureTrue);
            e->exec();
        }
        else{
            //ouverture du script de changement de notes
            QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(Enigme::Notes));
        }

    }
    else {
        QMessageBox message(QMessageBox::Warning,"Accès interdit","Vous n'avez pas accès au fichier");
        message.exec();
    }
}


void FileView::OpenMenu(QPoint const &point)
{
    QMenu * menu=new QMenu(this);
    QAction* replace= new QAction("Remplacer le fichier",this);
    menu->addAction(replace);
    menu->popup(point); // fait apraitre le menu où l'on à cliqué
    connect(replace,&QAction::triggered,this,&FileView::emitReplaced);
}


void FileView::setEcritureTrue()
{
    _model->setEcriture(true);
}



PyFileView::PyFileView(PyFile* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    //initialise l'icone
    switch (filemodel->icone)
    {
        case Icon::python :
             setImage(":/pieThonLogo");
        break;

        case Icon::xls :
             setImage(":/xlsIcon");
        break;

        case Icon::file :
             setImage(":/file");
        break;

        case Icon::pdf:
             setImage(":/pdfIcon");
        break;

    }

}

void PyFileView::OpenEvent()
{
    if(_model->ouvrable())
    {
        //ouvre un script correspondant à l'énigme
        QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(_model->enigmeType()));
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Accès interdit","Vous n'avez pas accès au fichier");
        message.exec();
    }
}


PdfFileView::PdfFileView(PdfFile* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    setImage(":/pdfIcon");
}



void PdfFileView::OpenEvent()
{
    if(_model->ouvrable())
    {
        //ouvre le fichier pdf
        QCoreApplication::postEvent(this->parent(),new OpenPdfFileEvent(_model));
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Accès interdit","Vous n'avez pas accès au fichier");
        message.exec();
    }
}
