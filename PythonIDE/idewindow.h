#ifndef IDEWINDOW_H
#define IDEWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QToolButton>
#include "codeeditor.h"
#include "pythonhighlighter.h"

namespace Ui {
class IDEWindow;
}

class IDEWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IDEWindow(QWidget *parent = nullptr);
    ~IDEWindow();
    void writeInFile(QString filename, QString data);
    void executeFile(QString filename);
    void runProgram();
    void stopProgram();


private slots:
    void on_actionRun_triggered();
    void on_actionStop_triggered();
    void cursorPosition_changed();
    void codeExecution_finished(int exitCode);
    void displayStandard_output();
    void displayStandard_error();

private:
    Ui::IDEWindow *ui;
    CodeEditor* _codeEditor;
    PythonHighlighter* _highlighter;
    QTabWidget* _consoleTab;
    QPlainTextEdit* _consoleOutput;
    QProcess _executor;
    QToolButton* _startProgram;
    QToolButton* _stopProgram;


};

#endif // IDEWINDOW_H
