#include "directoryview.h"

DirectoryView::DirectoryView(Directory* modeldir,QWidget *parent)
    :AbstractfileView(modeldir,parent),_model(modeldir)
{
    setImage(":/folder");
}


bool DirectoryView::event(QEvent *event)
{

/*    if(event->type()==ChangeFileWindowEvent::type())
    {

        ChangeFileWindowEvent* ev=dynamic_cast<ChangeFileWindowEvent*>(event);
        if(_model->parentDir()==nullptr)
        {
            // passe l'evenement à desktop
            QCoreApplication::postEvent(this->parentWidget()->parentWidget(),new ChangeFileWindowEvent(ev->sender()));

        }
        else {
            //passe l'evenement à sont parentDir
            QCoreApplication::postEvent(this,new ChangeFileWindowEvent(ev->sender()));

        }
        return true;
    }

    else */return QLabel::event(event);

}


void DirectoryView::OpenEvent()
{
/*
    //regarder s'il y a une fenetre ouverte sinon on en créer une autre
    if(_model->parentDir()==nullptr)
    {
        //est ce propre de faire comme ca ? pas moyen de passer l'event dans a son parent depuis la QMdiArea ?
       QCoreApplication::postEvent(this->parentWidget()->parentWidget(),new OpenDirEvent(this)); //essayer this->window() les events descendent
    }
    else {
        //event qui change la filewindow qui devrait etre envoyer au desktop et c'est le desktop qui va agir sur le controlleur

       QCoreApplication::postEvent(parentDir,new ChangeFileWindowEvent(this)); //!!! comment remonter la chaine d'evenements

    }
*/
    qDebug()<<"dir oppenned";
}


DirectoryView::~DirectoryView()
{
}
