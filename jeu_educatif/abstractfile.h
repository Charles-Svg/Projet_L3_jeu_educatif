#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include <QString>

class Abstractfile
{

public:
    explicit Abstractfile(QString const & nom);
    virtual ~Abstractfile()=default;
    QString nom(){return _nom;}


private:
    QString _nom;

};

#endif // ABSTRACTFILE_H
