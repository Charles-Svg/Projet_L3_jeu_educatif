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

           QCoreApplication::postEvent(_desktop,new OpenDirEvent(_model));
        }
        else {

           QCoreApplication::postEvent(_desktop,new ChangeFileWindowEvent(_model));

        }
    }
    else {
        QMessageBox message(QMessageBox::Warning,"Accès interdit","Vous n'avez pas accès au dossier");
        message.exec();
    }

}
void DirectoryView::emitCopied()
{
    emit copied();
}


void DirectoryView::OpenMenu(QPoint const &point)
{
    QMenu * menu=new QMenu(this);
    QAction* copy= new QAction("Copier",this);
    menu->addAction(copy);
    menu->popup(point);
    connect(copy,&QAction::triggered,this,&DirectoryView::emitCopied);
}



