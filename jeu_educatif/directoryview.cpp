#include "directoryview.h"

DirectoryView::DirectoryView(Directory* modeldir,QWidget* desktop,typeDir type,QWidget *parent)
    :AbstractfileView(modeldir,parent),_model(modeldir),_desktop(desktop)
{
    if(type==classic)
        setImage(":/folder");
    else
        setImage(":/usb");
}



void DirectoryView::OpenEvent()
{
    if(_model->ouvrable())
    {
        //regarder s'il y a une fenetre ouverte sinon on en créer une autre
        if(_model->parentDir()==nullptr)
        {
           //ai-je une autre solution ?
           QCoreApplication::postEvent(_desktop,new OpenDirEvent(_model));
        }
        else {

            QCoreApplication::postEvent(_desktop,new ChangeFileWindowEvent(_model));

        }
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès au dossier");
        message.exec();
    }



}


