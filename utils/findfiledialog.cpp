/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/QDir>
#include <QtWidgets/QLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

#include <QMessageBox>
#include <QMainWindow>
#include <QScrollArea>

#include <QMenu>

#include <QMenuBar>

#include "../include/findfiledialog.h"
#include "../include/assistant.h"
#include "../include/textedit.h"

#include "../ui_converter.h"

QString cur_dir_path = NULL;


void open_window(void);

//! [0]
FindFileDialog::FindFileDialog
//(TextEdit *editor, Assistant *assistant, TextEdit *te)
//(TextEdit *editor, Assistant *assistant)
(TextEdit *editor, Assistant *assistant, QTextEdit *te)
    : QDialog(editor)
//    : QDialog(editor), process_conv(0)
{
    currentAssistant = assistant;
    currentEditor = editor;

    te_dialog = te;

//    te_dialog = te;

    mw = new QMainWindow;

//! [0]

    createButtons();
    createComboBoxes();
    createFilesTree();
    createLabels();
    createLayout();

//    QString dir_path;

//    if (cur_dir_path != NULL) {

//        dir_path = cur_dir_path;

//    } else {

//        dir_path = "C:\\WORKS\\WS\\WS_Android_20130929_122122\\image_processing_Nagao_2\\D-4\\images";
//    }

    QString dir_path(
                QDir::currentPath());

    QString dir_path_2(
                "C:\\WORKS\\WS\\NetBeans\\Learn_Sound\\audio");

    directoryComboBox->addItem(QDir::toNativeSeparators(dir_path));
    directoryComboBox->addItem(QDir::toNativeSeparators(dir_path_2));
//    directoryComboBox->addItem(QDir::toNativeSeparators(QDir::currentPath()));
    fileNameComboBox->addItem("*");
    findFiles();

    setWindowTitle(tr("Find File"));
//! [1]
}
//! [1]

void FindFileDialog::browse()
{
    QString currentDirectory = directoryComboBox->currentText();
    QString newDirectory = QFileDialog::getExistingDirectory(this,
                               tr("Select Directory"), currentDirectory);
    if (!newDirectory.isEmpty()) {
        directoryComboBox->addItem(QDir::toNativeSeparators(newDirectory));
        directoryComboBox->setCurrentIndex(directoryComboBox->count() - 1);
        update();
    }
}

//! [2]
void FindFileDialog::help()
{
    currentAssistant->showDocumentation("filedialog.html");    
}
//! [2]

void FindFileDialog::openFile(QTreeWidgetItem *item)
{

    if (!item) {
        item = foundFilesTree->currentItem();
        if (!item)
            return;
    }

    QString fileName = item->text(0);
    QString path = directoryComboBox->currentText() + QDir::separator();

    cur_dir_path = QString(path);



    te_dialog->setPlainText(path + fileName);
//    te_dialog->setPlainText(path + fileName);


////    te_dialog->setContents(path + fileName);
////    currentEditor->setContents(path + fileName);

//    QString image_file_path(path + fileName);

//    //log
//    QMessageBox messageBox;
//    messageBox.setWindowTitle(tr("debug"));
//    messageBox.setText(tr("Calling... => open_ImageWindow()"));
//    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//    messageBox.setDefaultButton(QMessageBox::No);
//    messageBox.exec();

////    if (messageBox.exec() == QMessageBox::Yes)

//    open_ImageWindow(image_file_path);
////    open_ImageWindow(path + fileName);
////    open_window();

    close();
}

void FindFileDialog::update()
{
    findFiles();
    buttonBox->button(QDialogButtonBox::Open)->setEnabled(
            foundFilesTree->topLevelItemCount() > 0);
}

void FindFileDialog::dialog_rejected()
{
    reject();
}

void FindFileDialog::findFiles()
{
    QRegExp filePattern(fileNameComboBox->currentText() + "*");
    filePattern.setPatternSyntax(QRegExp::Wildcard);

    QDir directory(directoryComboBox->currentText());

    QStringList allFiles = directory.entryList(QDir::Files | QDir::NoSymLinks);
    QStringList matchingFiles;

    foreach (QString file, allFiles) {
        if (filePattern.exactMatch(file))
            matchingFiles << file;
    }
    showFiles(matchingFiles);
}

void FindFileDialog::showFiles(const QStringList &files)
{
    foundFilesTree->clear();

    for (int i = 0; i < files.count(); ++i) {
        QTreeWidgetItem *item = new QTreeWidgetItem(foundFilesTree);
        item->setText(0, files[i]);
    }

    if (files.count() > 0)
        foundFilesTree->setCurrentItem(foundFilesTree->topLevelItem(0));
}

void FindFileDialog::createButtons()
{
    browseButton = new QToolButton;
    browseButton->setText(tr("..."));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Open
                                     | QDialogButtonBox::Cancel
                                     | QDialogButtonBox::Help);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(openFile()));

    connect(buttonBox, SIGNAL(rejected()), this, SLOT(dialog_rejected()));
//    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(help()));
}

void FindFileDialog::createComboBoxes()
{
    directoryComboBox = new QComboBox;
    fileNameComboBox = new QComboBox;

    fileNameComboBox->setEditable(true);
    fileNameComboBox->setSizePolicy(QSizePolicy::Expanding,
                                    QSizePolicy::Preferred);

    directoryComboBox->setMinimumContentsLength(30);
    directoryComboBox->setSizeAdjustPolicy(
            QComboBox::AdjustToMinimumContentsLength);
    directoryComboBox->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Preferred);

    connect(fileNameComboBox, SIGNAL(editTextChanged(QString)),
            this, SLOT(update()));
    connect(directoryComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(update()));
}

void FindFileDialog::createFilesTree()
{
    foundFilesTree = new QTreeWidget;
    foundFilesTree->setColumnCount(1);
    foundFilesTree->setHeaderLabels(QStringList(tr("Matching Files")));
    foundFilesTree->setRootIsDecorated(false);
    foundFilesTree->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(foundFilesTree, SIGNAL(itemActivated(QTreeWidgetItem*,int)),
            this, SLOT(openFile(QTreeWidgetItem*)));
}

void FindFileDialog::createLabels()
{
    directoryLabel = new QLabel(tr("Search in:"));
    fileNameLabel = new QLabel(tr("File name (including wildcards):"));
}

void FindFileDialog::createLayout()
{
    QHBoxLayout *fileLayout = new QHBoxLayout;
    fileLayout->addWidget(fileNameLabel);
    fileLayout->addWidget(fileNameComboBox);

    QHBoxLayout *directoryLayout = new QHBoxLayout;
    directoryLayout->addWidget(directoryLabel);
    directoryLayout->addWidget(directoryComboBox);
    directoryLayout->addWidget(browseButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(fileLayout);
    mainLayout->addLayout(directoryLayout);
    mainLayout->addWidget(foundFilesTree);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}

void open_window(void)
{
//    QMessageBox::information(this, QString("Image Viewer"),
//                             QString("Opened"));
//    QMessageBox::information(this, tr("Image Viewer"),
//                             tr("Opened"));

}

void FindFileDialog::open_ImageWindow(const QString file_path)
//void FindFileDialog::open_ImageWindow(QString &file_path)
{

//    mw = new QMainWindow;
//    QMainWindow *mw = new QMainWindow;

    QImage image(file_path);

    QFileInfo file(file_path);

    if (image.isNull()) {
        QMessageBox::information(this, tr("Image Viewer"),
                                 tr("Cannot load %1.").arg(file_path));
        return;
    }

    // Build window
//    fileMenu = new QMenu(tr("&File"), mw);
////    QMenu *fileMenu = new QMenu(tr("&File"), mw);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    mw->connect(exitAct, SIGNAL(triggered()), this, SLOT(mw->close();));
//    mw->connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
//    connect(exitAct, SIGNAL(triggered()), this, SLOT(QMainWindow.close()));

    exitAct->setEnabled(false);

    // File menu
    fileMenu = new QMenu(tr("&File"), mw);
    fileMenu->addAction(exitAct);

//    fileMenu->setEnabled(true);

//    exitAct->setEnabled(true);

    // Edit menu
    editMenu = new QMenu(tr("&Edit"), mw);
    editMenu->addAction(exitAct);

    // Set: enable menu
    fileMenu->setEnabled(true);
    editMenu->setEnabled(true);
//    fileMenu->setEnabled(false);
//    editMenu->setEnabled(false);

    // Add menues
    mw->menuBar()->addMenu(fileMenu);
    mw->menuBar()->addMenu(editMenu);


    QLabel *imageLabel;
    imageLabel = new QLabel;



    imageLabel->setPixmap(QPixmap::fromImage(image));

//    QScrollArea scrollArea = new QScrollArea;
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
//    setCentralWidget(scrollArea);

    mw->setWindowTitle(file.fileName());
//    mw->setWindowTitle(file_path);


    mw->setCentralWidget(scrollArea);
//    mw->setCentralWidget(imageLabel);
        // no known conversion for argument 1 from 'QLabel' to 'QWidget*'

    mw->show();



//    QMessageBox::information(this, QString("Image Viewer"),
//                             QString("Opening: %1").arg(file_path));
}
