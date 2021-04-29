#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"



class File : public Abstractfile
{

public:
    explicit File(QString const & nom);
    ~File()=default;


private:
    bool ecriture;


};

#endif // FILE_H
