#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"


enum FileType {PDF,PY};

class File : public Abstractfile
{

public:
    explicit File(QString const & nom,FileType file,bool ouvrable=1);
    ~File()=default;

    FileType type() const{return _type;}

private:
    FileType _type;
    bool ecriture;


};

#endif // FILE_H
