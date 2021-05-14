#ifndef ABSTRACTFILEVIEW_H
#define ABSTRACTFILEVIEW_H

#include <QLabel>
#include <QMouseEvent>
#include <QFontMetrics>
#include <QFont>
#include <QApplication>
#include <QMessageBox>
#include <QPoint>
#include <QMenu>
#include <QAction>

#include "abstractfile.h"

class AbstractfileView : public QLabel
{
      Q_OBJECT
public:
    AbstractfileView(Abstractfile*, QWidget * parent=nullptr, int largeur=84,int hauteur=64);
    virtual ~AbstractfileView()=default;
    virtual void setImage(QString const & filename);

    QString nom()const{return _nom->text();}

private:
    QLabel* _nom; //ce sera le nom du fichier positionné en bas du Qlabel
    int largeur; //taille de l'icone
    int hauteur;
protected:
    void mouseDoubleClickEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent * event) override;

    virtual void OpenEvent()=0;


signals:
    void open();
    void rightclicked(QPoint const &);
    void leftclicked();
    void Copied();
};

#endif // ABSTRACTFILEVIEW_H
