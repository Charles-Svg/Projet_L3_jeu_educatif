#include "filewindow.h"


Directory::Directory(QString const & nom,QWidget *parent)
    :Abstractfile(nom,parent)
{
    setImage(":/folder");


}

void Directory::OpenEvent()
{

    //regarder s'il y a une fenetre ouverte sinon on en créer une autre

    //faire l'intanciantion du FileWindow dans le desktop
    emit DirOpenned(this);
    qDebug()<<"dir oppened";
}

//ajoute une fichier ou dossier au Vector

void Directory::addfile(const QString &nom)
{
    File * file=new File(nom,this->parentWidget());
    file->setLocale(location::dossier);
    file->hide();
    FileList.push_back(file);
    emit FileListUpdated();
}

void Directory::addDir(const QString &nom)
{
    Directory * dir=new Directory(nom,this->parentWidget());
    dir->setLocale(location::dossier);
    dir->hide();
    FileList.push_back(dir);
    emit FileListUpdated();
}
