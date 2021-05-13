#ifndef LETTERBYLETTERLABEL_H
#define LETTERBYLETTERLABEL_H

#include <QLabel>
#include <QTimer>

class LetterByLetterLabel : public QLabel
{
    Q_OBJECT
public:

    void setText(const QString & text);
    bool isDisplayed(){return _displayed;};
    void skip();

private:
    QTimer *_timer;
    int _index;
    QString _text;
    bool _displayed;

signals:
    void end();

public slots:
    void displayNextChar();

};

#endif // LETTERBYLETTERLABEL_H
