#include "file.h"
#include <QDebug>

File::File(QString const & nom,FileType type,bool ouvrable)
    : Abstractfile(nom,ouvrable),_type(type),ecriture(1)
{
}



