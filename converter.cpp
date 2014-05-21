#include "converter.h"
#include "ui_converter.h"

#include <QMessageBox>
#include <QFileInfo>

converter::converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::converter), proc_Conv(0), proc_App(0)
{
    ui->setupUi(this);

    editor = new TextEdit;

    assistant = new Assistant;

}

converter::~converter()
{
    delete ui;
}

void converter::on_BT_Choose_1_clicked()
{
    QTextEdit *te = ui->TE_Input_1;

////    QTextEdit *te = ui->TE_Input_1;

    FindFileDialog dialog(editor, assistant, te);

    dialog.exec();

}

void converter::on_BT_Choose_2_clicked()
{
    QTextEdit *te = ui->TE_Input_2;

    FindFileDialog dialog(editor, assistant, te);

    dialog.exec();

}

void converter::on_BT_Quit_clicked()
{
    quitApp();
}

void converter::on_BT_App_clicked()
{

}

void converter::on_BT_Exec_clicked()
{
//    QString title = "Notice";
//    QString message = "Starting => proc_Conv";
////    QString *title = "Notice";
////    QString *message = "Starting => proc_Conv";

//    quitApp(title, message);

    /******************************
     *
     * Validate: Input/output files => Written?
     *
     ******************************/
    QString input_file = ui->TE_Input_1->toPlainText();
    QString output_file = ui->TE_Input_2->toPlainText();

    QString msg = "";

    if (input_file == NULL || input_file == "") {
        msg += "Input file => blank\n";
    }

    if (output_file == NULL || output_file == "") {
        msg += "Output file => blank\n";
    }

    if (msg != "") {
        QString title = "Notice";
//        QString message = "Starting => proc_Conv";
        quitApp(title, msg);

        return;

    }

    /******************************
     *
     * Validate: Input/output files => wave file?
     *
     ******************************/
    QFileInfo input(input_file);
    QFileInfo output(output_file);

    if (input.suffix() != "wav") {
        msg += "Input file => not a wav file\n";
    }

    if (output.suffix() != "wav") {
        msg += "Output file => not a wav file\n";
    }


    if (msg != "") {
        QString title = "Notice";
//        QString message = "Starting => proc_Conv";
        quitApp(title, msg);

        return;

    }

    proc_Conv = new QProcess(this);

    QString app = "\"C:\\Program Files\\Windows Media Player\\wmplayer.exe\"";
//    QString app = "%ProgramFiles%\\Windows Media Player\\wmplayer.exe";
//    QString app = "C:\\WORKS\\Programs\\sakura_2.1.1\\sakura.exe";

    proc_Conv->start(app);

}

void converter::quitApp()
{
    QString title = "Converter";

    QString msg;

    msg += "\nDo you really want to quit?\n";

    QMessageBox messageBox;
    messageBox.setWindowTitle(title);
//    messageBox.setWindowTitle(tr("Converter"));

    messageBox.setText(msg);

    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if (messageBox.exec() == QMessageBox::Yes)
        qApp->quit();

}


void converter::on_actionQuit_triggered()
{
    quitApp();
}

void converter::on_actionApp_triggered()
{

}

void converter::on_actionExecute_triggered()
{

}

void converter::quitApp
(QString title, QString message)
//(QString *title, QString *message)
{
//    QString title = "Converter";

//    QString msg;

//    msg += "\nDo you really want to quit?\n";

    QMessageBox messageBox;
    messageBox.setWindowTitle(title);
//    messageBox.setWindowTitle(tr("Converter"));

    messageBox.setText(message);
//    messageBox.setText(msg);

    messageBox.exec();

        messageBox.setStandardButtons(QMessageBox::Ok);
//    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    messageBox.setDefaultButton(QMessageBox::No);
//    if (messageBox.exec() == QMessageBox::Yes)
//        qApp->quit();

}

void converter::setup_Shortcuts()
{
//    ui->BT_Quit->setShortcut(QKeySequence::Quit);

    ui->actionExecute->setShortcut(tr("Ctrl+E"));
    connect(ui->actionExecute,
            SIGNAL(triggered()),
            this,
            SLOT(on_actionExecute_triggered()));

}
