#ifndef FILEVIEW_H
#define FILEVIEW_H

#include "file.h"
#include "abstractfileview.h"
#include "evenements.h"
#include "enigmadialog.h"
#include <QCoreApplication>


class FileView : public AbstractfileView
{
      Q_OBJECT
public:
    FileView(File*,QWidget *parent = nullptr);

private:
    File * _model;
    bool _ecriture;
private slots:
    void setEcritureTrue();

protected:
void OpenEvent() override;

};




class PyFileView : public AbstractfileView
{
Q_OBJECT

public:
    PyFileView(PyFile*,QWidget *parent = nullptr);

private:
    PyFile* _model;

protected:
    void OpenEvent() override;
};


class PdfFileView : public AbstractfileView
{
Q_OBJECT

public:
    PdfFileView(PdfFile*,QWidget *parent = nullptr);

private:
    PdfFile* _model;

protected:
    void OpenEvent() override;
};
#endif // FILEVIEW_H
