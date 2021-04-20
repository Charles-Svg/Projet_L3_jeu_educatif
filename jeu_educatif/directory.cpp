#include "filewindow.h"
#include <QCoreApplication>

Directory::Directory(QString const & nom,QWidget *parent)
    :Abstractfile(nom,parent)
{
    setImage(":/folder");

}

void Directory::OpenEvent()
{

    //regarder s'il y a une fenetre ouverte sinon on en créer une autre
    if(this->getLocale()==nullptr)
    {
        qDebug()<<"dir oppened";
        //est ce propre de faire comme ca ? pas moyen de passer l'event dans a son parent depuis la QMdiArea ?
        QCoreApplication::postEvent(this->parentWidget()->parentWidget(),new OpenDirEvent(this));
    }

    //faire l'intanciation du FileWindow dans le desktop

}

//ajoute une fichier ou dossier au Vector

void Directory::addfile(const QString &nom)
{
    File * file=new File(nom,nullptr);
    file->setLocale(this);
    FileList.push_back(file);
    emit FileListUpdated();
}

void Directory::addDir(const QString &nom)
{
    Directory * dir=new Directory(nom,nullptr);
    dir->setLocale(this);
    FileList.push_back(dir);
    emit FileListUpdated();
}



//redefinition de l'evenement

QEvent::Type OpenDirEvent::MyType= static_cast<QEvent::Type>(QEvent::registerEventType());

OpenDirEvent::OpenDirEvent(Directory * send)
    :QEvent(MyType),_sender(send)
{}

QEvent::Type OpenDirEvent::type() {return MyType ;}

Directory* OpenDirEvent::sender() {return _sender;}



