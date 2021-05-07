#include "file.h"
#include <QDebug>

File::File(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}



PyFile::PyFile(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}



PdfFile::PdfFile(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}
