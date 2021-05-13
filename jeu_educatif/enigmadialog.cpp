#include "enigmadialog.h"
#include "ui_enigmadialog.h"
#include <QtGui>

EnigmaDialog::EnigmaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnigmaDialog)
{
    ui->setupUi(this);
    setWindowTitle("???");


    TextEdit* lettre1= new TextEdit(this);
    TextEdit* lettre2= new TextEdit(this);
    TextEdit* lettre3= new TextEdit(this);

    lettre1->setAlignment(Qt::AlignVCenter |Qt::AlignHCenter);
    lettre2->setAlignment(Qt::AlignVCenter |Qt::AlignHCenter);
    lettre3->setAlignment(Qt::AlignVCenter |Qt::AlignHCenter);

    QFont font ;
    font.setPointSize(26);

    lettre1->setFont(font);
    lettre2->setFont(font);
    lettre3->setFont(font);

    lettre1->setPlaceholderText("1");
    lettre2->setPlaceholderText("2");
    lettre3->setPlaceholderText("3");

    ui->letterLayout->addWidget(lettre1);
    ui->letterLayout->addWidget(lettre2);
    ui->letterLayout->addWidget(lettre3);

}


EnigmaDialog::~EnigmaDialog()
{
    delete ui;
}

TextEdit::TextEdit(QWidget* parent)
    :QTextEdit(parent)
{}

void TextEdit::keyPressEvent(QKeyEvent *ev)
{
    if(this->toPlainText()=="" or ev->key()==Qt::Key_Backspace)
    {
        QTextEdit::keyPressEvent(ev);
    }
}
