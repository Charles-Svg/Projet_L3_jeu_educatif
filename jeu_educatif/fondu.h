#ifndef FONDU_H
#define FONDU_H

#include <QWidget>
#include "LetterByLetterLabel.h"
#include <QKeyEvent>

enum typeFondu {fondu1,fondu2,fondu3,fin,merci};

class Fondu : public QWidget
{
    Q_OBJECT
public:
    Fondu(typeFondu);

    void keyPressEvent(QKeyEvent*) override;
private:
    LetterByLetterLabel *_label;

signals:
    void end(); //signal pour passer à la suite
};

#endif // FONDU_H
