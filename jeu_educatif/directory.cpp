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


/*
//evenement d'ouverture depuis le bureau

QEvent::Type OpenDirEvent::MyType= static_cast<QEvent::Type>(QEvent::registerEventType());

OpenDirEvent::OpenDirEvent(Directory * send)
    :QEvent(MyType),_sender(send)
{}

QEvent::Type OpenDirEvent::type() {return MyType ;}

Directory* OpenDirEvent::sender() {return _sender;}


//evenement d'ouverture depuis un explorateur de fichiers

QEvent::Type ChangeFileWindowEvent::MyType= static_cast<QEvent::Type>(QEvent::registerEventType());

ChangeFileWindowEvent::ChangeFileWindowEvent(Directory * send)
 :QEvent(MyType),_sender(send)
{}

QEvent::Type ChangeFileWindowEvent::type(){return MyType;}

Directory* ChangeFileWindowEvent::sender(){return _sender;}
*/
