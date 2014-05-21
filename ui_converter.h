/********************************************************************************
** Form generated from reading UI file 'converter.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTER_H
#define UI_CONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_converter
{
public:
    QAction *actionQuit;
    QAction *actionApp;
    QAction *actionExecute;
    QWidget *centralWidget;
    QPushButton *BT_Choose_1;
    QPushButton *BT_Choose_2;
    QPushButton *BT_Quit;
    QPushButton *BT_App;
    QPushButton *BT_Exec;
    QLabel *LB_Input_1;
    QLabel *LB_Input_2;
    QTextEdit *TE_Input_1;
    QTextEdit *TE_Input_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *converter)
    {
        if (converter->objectName().isEmpty())
            converter->setObjectName(QStringLiteral("converter"));
        converter->resize(883, 621);
        actionQuit = new QAction(converter);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionApp = new QAction(converter);
        actionApp->setObjectName(QStringLiteral("actionApp"));
        actionExecute = new QAction(converter);
        actionExecute->setObjectName(QStringLiteral("actionExecute"));
        centralWidget = new QWidget(converter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BT_Choose_1 = new QPushButton(centralWidget);
        BT_Choose_1->setObjectName(QStringLiteral("BT_Choose_1"));
        BT_Choose_1->setGeometry(QRect(420, 30, 150, 50));
        QFont font;
        font.setPointSize(15);
        BT_Choose_1->setFont(font);
        BT_Choose_2 = new QPushButton(centralWidget);
        BT_Choose_2->setObjectName(QStringLiteral("BT_Choose_2"));
        BT_Choose_2->setGeometry(QRect(420, 230, 150, 50));
        BT_Choose_2->setFont(font);
        BT_Quit = new QPushButton(centralWidget);
        BT_Quit->setObjectName(QStringLiteral("BT_Quit"));
        BT_Quit->setGeometry(QRect(80, 450, 150, 50));
        BT_Quit->setFont(font);
        BT_Quit->setCheckable(true);
        BT_Quit->setChecked(false);
        BT_App = new QPushButton(centralWidget);
        BT_App->setObjectName(QStringLiteral("BT_App"));
        BT_App->setGeometry(QRect(370, 450, 150, 50));
        BT_App->setFont(font);
        BT_Exec = new QPushButton(centralWidget);
        BT_Exec->setObjectName(QStringLiteral("BT_Exec"));
        BT_Exec->setGeometry(QRect(620, 450, 150, 50));
        BT_Exec->setFont(font);
        LB_Input_1 = new QLabel(centralWidget);
        LB_Input_1->setObjectName(QStringLiteral("LB_Input_1"));
        LB_Input_1->setGeometry(QRect(100, 30, 150, 40));
        LB_Input_1->setFont(font);
        LB_Input_2 = new QLabel(centralWidget);
        LB_Input_2->setObjectName(QStringLiteral("LB_Input_2"));
        LB_Input_2->setGeometry(QRect(90, 240, 150, 40));
        LB_Input_2->setFont(font);
        TE_Input_1 = new QTextEdit(centralWidget);
        TE_Input_1->setObjectName(QStringLiteral("TE_Input_1"));
        TE_Input_1->setGeometry(QRect(50, 110, 531, 71));
        TE_Input_2 = new QTextEdit(centralWidget);
        TE_Input_2->setObjectName(QStringLiteral("TE_Input_2"));
        TE_Input_2->setGeometry(QRect(50, 310, 531, 71));
        converter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(converter);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 883, 45));
        QFont font1;
        font1.setPointSize(13);
        menuBar->setFont(font1);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        converter->setMenuBar(menuBar);
        mainToolBar = new QToolBar(converter);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        converter->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(converter);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        converter->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionApp);
        menuFile->addAction(actionExecute);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(converter);

        QMetaObject::connectSlotsByName(converter);
    } // setupUi

    void retranslateUi(QMainWindow *converter)
    {
        converter->setWindowTitle(QApplication::translate("converter", "converter", 0));
        actionQuit->setText(QApplication::translate("converter", "&Quit", 0));
        actionApp->setText(QApplication::translate("converter", "App", 0));
        actionExecute->setText(QApplication::translate("converter", "Execute", 0));
        BT_Choose_1->setText(QApplication::translate("converter", "Choose", 0));
        BT_Choose_2->setText(QApplication::translate("converter", "Choose", 0));
        BT_Quit->setText(QApplication::translate("converter", "(Q)uit", 0));
        BT_Quit->setShortcut(QApplication::translate("converter", "Esc, Esc, Ctrl+Q", 0));
        BT_App->setText(QApplication::translate("converter", "App", 0));
        BT_Exec->setText(QApplication::translate("converter", "Execute", 0));
        LB_Input_1->setText(QApplication::translate("converter", "Input 1", 0));
        LB_Input_2->setText(QApplication::translate("converter", "Input 2", 0));
        menuFile->setTitle(QApplication::translate("converter", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class converter: public Ui_converter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTER_H
