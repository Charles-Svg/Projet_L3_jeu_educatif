#include "fileview.h"

FileView::FileView(File* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    switch (_model->type()) {

    case PDF :
        setImage(":/file");
    break;

    case PY :
        setImage("");
    break;

    }

}


void FileView::OpenEvent()
{
    if(_model->ouvrable())
    {
        qDebug()<<"ouvre le fichier";
        //ouvre un dialog de consultation du fichier

    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }


}
