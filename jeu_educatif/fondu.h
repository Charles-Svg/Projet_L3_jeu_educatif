#ifndef FONDU_H
#define FONDU_H

#include <QPlainTextEdit>
#include <QKeyEvent>
enum typeFondu {fondu1,fondu2,fondu3,fin};

class Fondu : public QPlainTextEdit
{
    Q_OBJECT
public:
    Fondu(typeFondu);

    void keyPressEvent(QKeyEvent*) override;
private:
    static QString str1;

signals:
    void end();
};

#endif // FONDU_H
