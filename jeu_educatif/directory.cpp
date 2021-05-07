#include "directory.h"
#include <QDebug>

Directory::Directory(QString const & nom,bool ouvrable)
    :Abstractfile(nom,ouvrable),_parentDir(nullptr)
{}



//ajoute une fichier ou dossier au Vector
void Directory::addFile(const QString &nom,FileType type,bool ouvrable)
{
    switch (type) {
        case Txt :
        {
            File * file=new File(nom,ouvrable);
            FileList.push_back(file);
        }
        break;

        case PY:
        {
            PyFile * file=new PyFile(nom,ouvrable);
            FileList.push_back(file);
        }
        break;

        case PDF:
        {
            PdfFile * file= new PdfFile(nom,ouvrable);
            FileList.push_back(file);

        }
        break;


    }

}

//mettrre le type de la en methode Directory*
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



