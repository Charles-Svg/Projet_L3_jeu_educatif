#include "fileview.h"

FileView::FileView(File* filemodel,QWidget *parent)
    :AbstractfileView(filemodel,parent)
{
    setImage(":/file");
}


void FileView::OpenEvent()
{
    qDebug()<<"ouvre le fichier";
    //ouvre un dialog de consultation du fichier

}
