#ifndef EVENEMENTS_CPP
#define EVENEMENTS_CPP

#include "evenements.h"


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



#endif // EVENEMENTS_CPP
