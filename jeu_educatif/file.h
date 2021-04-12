#ifndef FILE_H
#define FILE_H

#include "abstractfile.h"



class File : public Abstractfile
{
    Q_OBJECT

public:
    explicit File(QString const & nom,QWidget *parent = nullptr);




protected slots:
    void OpenEvent() override;

private:
    bool ecriture;


};

#endif // FILE_H
