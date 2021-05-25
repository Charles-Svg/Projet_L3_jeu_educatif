#ifndef ENIGMADIALOG_H
#define ENIGMADIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QKeyEvent>
#include <QDragEnterEvent>


class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget* parent=nullptr);

    void keyPressEvent(QKeyEvent*) override;
    void focusInEvent(QFocusEvent *) override;
    void dragEnterEvent(QDragEnterEvent *) override;


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

    //sous classe de QtextEdit pour redéfinir ses evenements


    Ui::EnigmaDialog *ui;
    TextEdit* lettre1;
    TextEdit* lettre2;
    TextEdit* lettre3;

private slots:
    void testResult();
};



#endif // ENIGMADIALOG_H
