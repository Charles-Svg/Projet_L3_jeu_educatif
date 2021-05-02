#include "abstractfile.h"
#include <QSizePolicy>
#include <QPixmap>
#include <QDebug>

Abstractfile::Abstractfile(QString const & nom,bool ouvre)
    :_nom(nom),_ouvrable(ouvre)
{}
