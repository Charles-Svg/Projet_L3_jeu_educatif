#ifndef FAKEPDFVIEWER_H
#define FAKEPDFVIEWER_H

#include <QScrollArea>
#include <QLabel>
#include <QResizeEvent>
class FakePdfViewer : public QScrollArea
{
public:
    FakePdfViewer(QString const & course,QWidget* parent=nullptr);
    void resizeEvent(QResizeEvent*) override;


private:
    QImage image; //peut etre useless
    QLabel *label;
};

#endif // FAKEPDFVIEWER_H
