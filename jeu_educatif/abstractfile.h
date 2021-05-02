#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include <QString>

class Abstractfile
{

public:
    explicit Abstractfile(QString const & nom,bool ouvre=1);
    virtual ~Abstractfile()=default;
    QString nom(){return _nom;}
    bool ouvrable(){return _ouvrable;}


private:
    QString _nom;
    bool _ouvrable;

};

#endif // ABSTRACTFILE_H
