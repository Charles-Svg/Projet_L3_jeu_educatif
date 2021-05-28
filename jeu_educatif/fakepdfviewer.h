#ifndef FAKEPDFVIEWER_H
#define FAKEPDFVIEWER_H

#include <QScrollArea>
#include <QLabel>
#include <QResizeEvent>
#include <QVector>
#include <QVBoxLayout>

#include "file.h"

//fenêtre de lecture d'un fichier pdf
class FakePdfViewer : public QScrollArea
{
public:
    FakePdfViewer(Cours cours,QWidget* parent=nullptr);
    ~FakePdfViewer();
    void resizeEvent(QResizeEvent*) override;
    void LoadImages(Cours c);

private:

    QVector<QLabel*> Images;
    QVBoxLayout* layout;

};

#endif // FAKEPDFVIEWER_H
