#ifndef ENIGMADIALOG_H
#define ENIGMADIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QKeyEvent>

namespace Ui {
class EnigmaDialog;
}

class EnigmaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnigmaDialog(QWidget *parent = nullptr);
    ~EnigmaDialog();


private:
    Ui::EnigmaDialog *ui;
};



class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget* parent=nullptr);

void keyPressEvent(QKeyEvent*) override;

};
#endif // ENIGMADIALOG_H
