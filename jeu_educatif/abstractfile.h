#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include <QString>

// super classe pour le modele des fichier et dossier
class Abstractfile
{

public:
    explicit Abstractfile(QString const & nom,bool ouvre=true);
    virtual ~Abstractfile()=default;
    QString nom(){return _nom;}
    bool ouvrable(){return _ouvrable;}


private:
    QString _nom;
    bool _ouvrable;

};

#endif // ABSTRACTFILE_H
