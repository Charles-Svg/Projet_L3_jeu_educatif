#include "filewindow.h"
#include <QCoreApplication>

Directory::Directory(QString const & nom,QWidget *parent)
    :Abstractfile(nom,parent),parentDir(nullptr)
{
    setImage(":/folder");
    qDebug()<<parentDir;
}

void Directory::OpenEvent()
{

    //regarder s'il y a une fenetre ouverte sinon on en créer une autre
    if(this->parentDir==nullptr)
    {
        qDebug()<<"desktop dir oppened";
        //est ce propre de faire comme ca ? pas moyen de passer l'event dans a son parent depuis la QMdiArea ?
        QCoreApplication::postEvent(this->parentWidget()->parentWidget(),new OpenDirEvent(this));
    }
    else {
        qDebug()<<"inside dir oppened";
        //event qui change la filewindow qui devrait etre envoyer au desktop et c'est le desktop qui va agir sur le controlleur
        qDebug()<<this->parentDir;
        QCoreApplication::postEvent(parentDir,new ChangeFileWindowEvent(this));

    }



}

bool Directory::event(QEvent *event)
{

    if(event->type()==ChangeFileWindowEvent::type())
    {

        ChangeFileWindowEvent* ev=dynamic_cast<ChangeFileWindowEvent*>(event);
        if(parentDir==nullptr)
        {
            // passe l'evenement à desktop
            ChangeFileWindowEvent* ev=dynamic_cast<ChangeFileWindowEvent*>(event);
            QCoreApplication::postEvent(this->parentWidget()->parentWidget(),new ChangeFileWindowEvent(ev->sender()));

        }
        else {
            //passe l'evenement à sont parentDir
            qDebug()<<"envoie a son parent Dir";
            QCoreApplication::postEvent(parentDir,new ChangeFileWindowEvent(ev->sender()));

        }
        return true;
    }

    else return QLabel::event(event);

}

//ajoute une fichier ou dossier au Vector
void Directory::addfile(const QString &nom)
{
    File * file=new File(nom,nullptr);

    FileList.push_back(file);
    emit FileListUpdated();
}

void Directory::addDir(const QString &nom)
{
    Directory * dir=new Directory(nom,nullptr);
    dir->parentDir=this;
    FileList.push_back(dir);
    emit FileListUpdated();
}





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
