#include "file.h"


File::File(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable),_remplacable(false),_ecriture(false)
{}



PyFile::PyFile(QString const & nom,Enigme enig,Icon i,bool ouvrable)
    : Abstractfile(nom,ouvrable),icone(i),_enigmeType(enig)
{}



PdfFile::PdfFile(QString const & nom,Cours cours,bool ouvrable)
    : Abstractfile(nom,ouvrable),_cours(cours)
{}

