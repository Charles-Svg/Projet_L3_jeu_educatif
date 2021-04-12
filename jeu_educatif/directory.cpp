#include "directory.h"
#include "filewindow.h"



Directory::Directory(QString const & nom,QWidget *parent)
    :Abstractfile(nom,parent)
{
    setImage(":/folder");

}

void Directory::OpenEvent()
{
    //ce signal sera capté par la bureau et ouvrira la nouvelle FileWindow

    _explorer=new FileWindow;
    emit DirOpenned(_explorer);
    qDebug()<<"dir oppened";
}
