#include "fileview.h"


FileView::FileView(File* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel),_ecriture(false)
{
    setImage(":/file");

}



void FileView::OpenEvent()
{
    if(_model->ouvrable())
    {
        if(_ecriture==false){
            //ouverture du dialog avec les lettres à rentrer
            EnigmaDialog * e= new EnigmaDialog(this->parentWidget());
            connect(e,&EnigmaDialog::accepted,this,&FileView::setEcritureTrue);
            e->exec();
        }
        else{
            //ouverture du scrpt de changement de notes
            QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(Enigme::Notes));
        }

    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
}

void FileView::setEcritureTrue()
{
    _ecriture=true;
}

PyFileView::PyFileView(PyFile* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
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
        QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(_model->enigmeType()));
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
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
        QCoreApplication::postEvent(this->parent(),new OpenPdfFileEvent(_model));
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
}
