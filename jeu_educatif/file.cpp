#include "file.h"
#include <QDebug>

File::File(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}



PyFile::PyFile(QString const & nom,Enigme enig,bool ouvrable)
    : Abstractfile(nom,ouvrable),_enigmeType(enig)
{}



PdfFile::PdfFile(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}
