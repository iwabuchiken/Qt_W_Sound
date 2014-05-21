#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>

#include "include/assistant.h"
#include "include/findfiledialog.h"
#include "include/textedit.h"

namespace Ui {
class converter;
}

class converter : public QMainWindow
{
    Q_OBJECT

public:
    explicit converter(QWidget *parent = 0);
    ~converter();

private slots:
    void on_BT_Choose_1_clicked();

    void on_BT_Choose_2_clicked();

    void on_BT_Quit_clicked();

    void on_BT_App_clicked();

    void on_BT_Exec_clicked();

    void on_actionQuit_triggered();

    void on_actionApp_triggered();

    void on_actionExecute_triggered();

private:
    Ui::converter *ui;

    TextEdit *editor;
    Assistant *assistant;

    QTextEdit *te_dialog;

    QProcess *proc_Conv;
    QProcess *proc_App;

    void quitApp(void);
    void quitApp(QString, QString);

    void setup_Shortcuts(void);

};

#endif // CONVERTER_H
