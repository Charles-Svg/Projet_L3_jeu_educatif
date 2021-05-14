#include "LetterByLetterLabel.h"

void LetterByLetterLabel::setText(const QString & text)
{
    _displayed = false;
    this->_text = text;
    this->_index = 0;
    this->_timer = new QTimer();
    connect(_timer, &QTimer::timeout, this, &LetterByLetterLabel::displayNextChar);
    this->_timer->start(8);
}

void LetterByLetterLabel::skip()
{
    this->_timer->stop();
    QLabel::setText(this->_text);
    _displayed = true;
}

void LetterByLetterLabel::displayNextChar(){
    QLabel::setText(this->text() + this->_text.at(this->_index++));
    if(this->_index >= this->_text.size()){
        this->_timer->stop();
        _displayed = true;
    }
}
