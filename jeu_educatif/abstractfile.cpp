#include "abstractfile.h"
#include <QSizePolicy>
#include <QPixmap>

Abstractfile::Abstractfile(QString const & nom,bool ouvre)
    :_nom(nom),_ouvrable(ouvre)
{}
