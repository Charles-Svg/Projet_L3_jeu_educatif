#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include <QLabel>
#include <QMouseEvent>

class Abstractfile : public QLabel
{
    Q_OBJECT

public:
    explicit Abstractfile(QString const & nom,QWidget *parent = nullptr,int size=48);

signals:
    void open();
    void rightclicked();
    void leftclicked();


private:
    QLabel * _nom; //ce sera le nom du fichier positionné en bas du Qlabel
    int _taille;

protected:

    void mouseDoubleClickEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent * event) override;
    virtual void setImage(QString const & filename);


protected slots:
    virtual void OpenEvent()=0;

};

#endif // ABSTRACTFILE_H
