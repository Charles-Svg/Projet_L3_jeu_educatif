#include "directory.h"

Directory::Directory(QString const & nom,bool ouvrable)
    :Abstractfile(nom,ouvrable),_parentDir(nullptr),copiable(false)
{}

QString Directory::arborescence()
{
    if(_parentDir==nullptr)
    {
        return "/"+nom();
    }
    else{
        return _parentDir->arborescence()+"/"+nom();
    }
}

//ajoute une fichier ou dossier au Vector
File* Directory::addFile(const QString &nom,bool ouvrable)
{
    File * file=new File(nom,ouvrable);
    _fileList.push_back(file);
    return file;
}


PyFile* Directory::addPyFile(const QString &nom,Enigme type,Icon i,bool ouvrable)
{
    PyFile* file=new PyFile(nom,type,i,ouvrable);
    _fileList.push_back(file);
    return file;
}



PdfFile* Directory::addPdfFile(const QString &nom,Cours cours ,bool ouvrable)
{
    PdfFile * file= new PdfFile(nom,cours,ouvrable);
    _fileList.push_back(file);
    return file;
}


Directory* Directory::addDir(const QString &nom,bool ouvrable)
{
    Directory * dir=new Directory(nom,ouvrable);
    dir->_parentDir=this;
    _fileList.push_back(dir);
    return dir;
}


Directory::~Directory()
{

    for(QVector<Abstractfile*>::iterator p=_fileList.begin();p!=_fileList.end();++p)
    {
        delete *p;
    }
}



