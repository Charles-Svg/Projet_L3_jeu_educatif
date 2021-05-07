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

    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
}



PyFileView::PyFileView(PyFile* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    setImage(":/pieThonLogo");
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
        //ouvre le pdf
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
}
