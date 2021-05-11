#include "file.h"
#include <QDebug>

File::File(QString const & nom,bool ouvrable)
    : Abstractfile(nom,ouvrable)
{}



PyFile::PyFile(QString const & nom,Enigme enig,bool ouvrable)
    : Abstractfile(nom,ouvrable),_enigmeType(enig)
{}



PdfFile::PdfFile(QString const & nom,Cours cours,bool ouvrable)
    : Abstractfile(nom,ouvrable),_cours(cours)
{}

QString PdfFile::cours()
{
    switch (_cours) {


        case Cesar:
           return ":/cesar.pdf";


        case Vigenere:
           return ":/vigenere";


        case Substitution:
            return ":/substitution";

        case Fin:
           return ":/fin";


        default:
            return "";

    }
}
