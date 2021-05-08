#include "directoryview.h"

DirectoryView::DirectoryView(Directory* modeldir,QWidget *parent,typeDir type)
    :AbstractfileView(modeldir,parent),_model(modeldir)
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
           QCoreApplication::postEvent(this->parent(),new OpenDirEvent(_model));
        }
        else {
            //event qui change la filewindow qui devrait etre envoyer au desktop et c'est le desktop qui va agir sur le controlleur

            QCoreApplication::postEvent(this->parent(),new ChangeFileWindowEvent(_model));

        }
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Vous n'avez pas accès","Vous n'avez pas accès au dossier");
        message.exec();
    }



}


