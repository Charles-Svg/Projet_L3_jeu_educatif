#include "directory.h"
#include <QDebug>

Directory::Directory(QString const & nom)
    :Abstractfile(nom),_parentDir(nullptr)
{}



//ajoute une fichier ou dossier au Vector
void Directory::addfile(const QString &nom)
{
    File * file=new File(nom);
    FileList.push_back(file);
}

//mettrre le type de la en methode Directory*
Directory* Directory::addDir(const QString &nom)
{
    Directory * dir=new Directory(nom);
    dir->_parentDir=this;
    FileList.push_back(dir);
    return dir;
}


Directory::~Directory()
{

    for(QVector<Abstractfile*>::iterator p=FileList.begin();p!=FileList.end();++p)
    {
        delete *p;
    }
}



