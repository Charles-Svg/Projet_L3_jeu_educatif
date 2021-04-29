#ifndef ABSTRACTFILEVIEW_H
#define ABSTRACTFILEVIEW_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include "abstractfile.h"

class AbstractfileView : public QLabel
{
      Q_OBJECT
public:
    AbstractfileView(Abstractfile*, QWidget * parent=nullptr, int size=48);
    virtual ~AbstractfileView()=default;


    QString nom()const{return _nom->text();}

private:
    QLabel* _nom; //ce sera le nom du fichier positionné en bas du Qlabel
    int _taille; //taille de l'icone

protected:
    void mouseDoubleClickEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent * event) override;
    virtual void setImage(QString const & filename);
    virtual void OpenEvent()=0;

signals:
    void open();
    void rightclicked();
    void leftclicked();
};

#endif // ABSTRACTFILEVIEW_H
