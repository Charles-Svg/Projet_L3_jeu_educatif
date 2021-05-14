#include "codeeditor.h"
#include "linenumberarea.h"
#include <QPainter>
#include <QTextBlock>
#include <QFontMetrics>
#include <map>
#include <vector>



CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    //Ajout du widget permettant de noter les lignes
    lineNumberArea = new LineNumberArea(this);

    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
    connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

    QFont f;
    f.setFamily("Courier");
    f.setPointSize(13);
    this->setFont(f);

}

/*
 * Permet d'automatiquement calculer la largeur du widget lineNumberArea
 */
int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

/*
 *Permet de passer en surlignage la ligne courante
 *
 */
void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

/*
 *  Evenement de surlignage
*/
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::keyPressEvent(QKeyEvent *e){
    //Récupération des caractères précédents et suivants
    QString line = textCursor().block().text();
    QStringList str = this->toPlainText().split('\n', Qt::KeepEmptyParts);
    QString lastChar = str[this->textCursor().blockNumber()].mid(this->textCursor().columnNumber() -1 ,1);
    QString nextChar = str[this->textCursor().blockNumber()].mid(this->textCursor().columnNumber() ,1);



    //L'ensemble des caractères que nous voulons "refermer" automatiquement
    std::map<QString, QString> autoComplete = {{"{", "}"},
                                       {"(",")"},
                                       {"[", "]"},
                                       {"\'", "\'"},
                                       {"\"", "\""}};

    //L'ensemble des caractères que nous voulons "passer" automatiquement
    std::vector<QString> autoSkip = {"}",
                                 ")",
                                 "]",
                                 "\'",
                                 "\""};

    //Si le caractère entré est dans la liste des "a passer", que le caractère suivant est identique et que le caractère précédent n'est pas le caractère d'échappement, alors on passe juste le caractère
    if(std::find(autoSkip.begin(), autoSkip.end(), e->text()) != autoSkip.end() && lastChar != "\\" && e->text() == nextChar){
        this->moveCursor(QTextCursor::NextCharacter);

    }
    //Si le caractère entré est tab, on le remplace par 4 espaces
    else if(e->key() == Qt::Key_Tab){
        this->insertPlainText("    ");
    }

    else {
        this->QPlainTextEdit::keyPressEvent(e);
        //Si la touche entrée a été appuyée
        if(e->key() == Qt::Key_Return){
            //On ajoute 4 espaces
            if(lastChar == ":" || lastChar == "\\"){
                this->insertPlainText("    ");
            }
            QString space;
            for(int i = 0; i < line.size(); i++) {
                    QChar c = line[i];

                    if(!c.isSpace()) {
                        space = line.left(i);
                        break;
                     }
                    if(i + 1 == line.size()){
                        space = line.left(i+1);
                        break;
                    }
            }
            insertPlainText(space);


        }

        //Si le caractère d'avant n'est pas celui échappé
        else if(lastChar != "\\"){
            //Si le caractère fait partie de la liste auto-compléter, alors on rajoute le caractère à rajouter après le curseur
            if(autoComplete.find(e->text()) != autoComplete.end()){
                QString enteredText = autoComplete.at(e->text());
                this->insertPlainText(enteredText);
                this->moveCursor(QTextCursor::PreviousCharacter);

            }

        }
    }

}

