#include "fileview.h"


FileView::FileView(File* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent),_model(filemodel)
{
    switch (_model->type()) {

    case PDF :
        setImage(":/file");
    break;

    case PY :
        setImage(":/pieThonLogo");
    break;

    }

}


void FileView::OpenEvent()
{
    if(_model->ouvrable())
    {

        switch (_model->type())
        {
            case PDF:
            //post evenements ouverture pdf
            break;

            case PY:
            //post event ouverture PyIde
            QCoreApplication::postEvent(this->parent(),new OpenPyFileEvent(_model));
            break;

        }

    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès a fichier");
        message.exec();
    }
}


