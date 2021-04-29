#include "directory.h"


Directory::Directory(QString const & nom)
    :Abstractfile(nom),_parentDir(nullptr)
{}



//ajoute une fichier ou dossier au Vector
void Directory::addfile(const QString &nom)
{
    File * file=new File(nom);
    FileList.push_back(file);
}

void Directory::addDir(const QString &nom)
{
    Directory * dir=new Directory(nom);
    dir->_parentDir=this;
    FileList.push_back(dir);
}


Directory::~Directory()
{
    delete _parentDir;
}



