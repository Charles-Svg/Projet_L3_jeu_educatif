#ifndef ENIGMADIALOG_H
#define ENIGMADIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QKeyEvent>

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget* parent=nullptr);

void keyPressEvent(QKeyEvent*) override;

};

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
    TextEdit* lettre1;
    TextEdit* lettre2;
    TextEdit* lettre3;

private slots:
    void testResult();
};



#endif // ENIGMADIALOG_H
