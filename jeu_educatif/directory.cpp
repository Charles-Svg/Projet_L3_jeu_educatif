#include "directory.h"

Directory::Directory(QString const & nom,bool ouvrable)
    :Abstractfile(nom,ouvrable),_parentDir(nullptr),copiable(false)
{}



//ajoute une fichier ou dossier au Vector
File* Directory::addFile(const QString &nom,bool ouvrable)
{
    File * file=new File(nom,ouvrable);
    FileList.push_back(file);
    return file;
}


PyFile* Directory::addPyFile(const QString &nom,Enigme type,Icon i,bool ouvrable)
{
    PyFile* file=new PyFile(nom,type,i,ouvrable);
    FileList.push_back(file);
    return file;
}



PdfFile* Directory::addPdfFile(const QString &nom,Cours cours ,bool ouvrable)
{
    PdfFile * file= new PdfFile(nom,cours,ouvrable);
    FileList.push_back(file);
    return file;
}


Directory* Directory::addDir(const QString &nom,bool ouvrable)
{
    Directory * dir=new Directory(nom,ouvrable);
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



