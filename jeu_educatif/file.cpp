#include "file.h"

File::File(QString const & nom,QWidget *parent )
    : Abstractfile(nom,parent)
{
    setImage(":/file");

}


void File::OpenEvent()
{};
