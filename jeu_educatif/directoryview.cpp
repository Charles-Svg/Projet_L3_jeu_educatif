#include "directoryview.h"

DirectoryView::DirectoryView(Directory* modeldir,QWidget *parent)
    :AbstractfileView(modeldir,parent),_model(modeldir)
{
    setImage(":/folder");
}



void DirectoryView::OpenEvent()
{

    //regarder s'il y a une fenetre ouverte sinon on en créer une autre
    if(_model->parentDir()==nullptr)
    {
       QCoreApplication::postEvent(this->window(),new OpenDirEvent(_model));
    }
    else {
        //event qui change la filewindow qui devrait etre envoyer au desktop et c'est le desktop qui va agir sur le controlleur
       QCoreApplication::postEvent(this->window(),new ChangeFileWindowEvent(_model));

    }

    qDebug()<<"dir oppenned";
}


