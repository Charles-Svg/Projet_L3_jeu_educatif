#ifndef EVENEMENTS_CPP
#define EVENEMENTS_CPP


/*
//evenement personnalisé pour l'ouverture d'un dossier
class OpenDirEvent : public QEvent
{
public:
    OpenDirEvent(Directory *);

    static QEvent::Type type();
    Directory* sender();


private:
    static QEvent::Type MyType;
    Directory * _sender;
};

class ChangeFileWindowEvent : public QEvent
{
public :
    ChangeFileWindowEvent(Directory *);
    static QEvent::Type type();
    Directory* sender();

private:
    static QEvent::Type MyType;
    Directory * _sender;

};*/


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


#endif // EVENEMENTS_CPP
