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
        //ouverture du dialog avec les lettre a rentrer
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
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
        QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(_model));
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
