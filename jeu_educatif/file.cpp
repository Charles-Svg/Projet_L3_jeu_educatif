#include "file.h"
#include <QDebug>

File::File(QString const & nom,QWidget *parent )
    : Abstractfile(nom,parent),ecriture(1)
{
    setImage(":/file");



}


void File::OpenEvent()
{
    qDebug()<<"ouvre le fichier";
    //ouvre un dialog de consultation du fichier

}

