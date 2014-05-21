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

#include <QtCore/QByteArray>
#include <QtCore/QDir>
#include <QtCore/QLibraryInfo>
#include <QtCore/QProcess>

#include <QtWidgets/QMessageBox>

#include "../include/assistant.h"

Assistant::Assistant()
    : proc(0)
{
}

//! [0]
Assistant::~Assistant()
{
    if (proc && proc->state() == QProcess::Running) {
        proc->terminate();
        proc->waitForFinished(3000);
    }
    delete proc;
}
//! [0]

//! [1]
void Assistant::showDocumentation(const QString &page)
{
    if (!startAssistant())
        return;

    QByteArray ba("SetSource ");
    ba.append("qthelp://org.qt-project.examples.simpletextviewer/doc/");
    
    proc->write(ba + page.toLocal8Bit() + '\n');
}
//! [1]

//! [2]
bool Assistant::startAssistant()
{
    if (!proc)
        proc = new QProcess();

    if (proc->state() != QProcess::Running) {
        QString app = QLibraryInfo::location(QLibraryInfo::BinariesPath) + QDir::separator();
#if !defined(Q_OS_MAC)
        app += QLatin1String("assistant");
#else
        app += QLatin1String("Assistant.app/Contents/MacOS/Assistant");    
#endif

        QStringList args;
        args << QLatin1String("-collectionFile")
            << QLibraryInfo::location(QLibraryInfo::ExamplesPath)
            + QLatin1String("/assistant/simpletextviewer/documentation/simpletextviewer.qhc")
            << QLatin1String("-enableRemoteControl");

//        QString app2 = "sakura";

//        proc->start(app2);
        proc->start(app, args);

        if (!proc->waitForStarted()) {
            QMessageBox::critical(0, QObject::tr("Simple Text Viewer"),
                QObject::tr("Unable to launch Qt Assistant (%1)").arg(app));
            return false;
        }    
    }
    return true;
}
//! [2]

void Assistant::start_process()
{
    if (!proc)
        proc = new QProcess();

    if (proc->state() != QProcess::Running) {

//        QString app = "C:/WORKS/PROGRAMS/sakura/sakura.exe";

//        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4/OpenSeeIt.exe";
//        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4/OpenSeeIt.exe";

//        QStringList args;
//        args << "C:/WORKS/WS/WS_Android_20130929_122122/image_processing_Nagao_2/D-4/images/lena512.pgm";
//        QString args = "C:/WORKS/WS/WS_Android_20130929_122122/"
//                + "image_processing_Nagao_2/D-4/images/lena512.pgm";

    //    QString app = "sakura";

        QString app("C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
                    "/OpenSeeIt.exe ");

        QStringList args;

//        QLatin1String arg1(" C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
        QLatin1String arg1("C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
//                     QString arg1("C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
                     "image_processing_Nagao_2\\D-4\\images\\rose_2.ppm"
                     );

        args << arg1;


//                QString app("C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
//                            "/OpenSeeIt.exe C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
//                            "image_processing_Nagao_2\\D-4\\images\\lena512.pgm")
//                ;
//        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
//                + "/OpenSeeIt.exe C:/WORKS/WS/WS_Android_20130929_122122/image_processing_Nagao_2/D-4/images/lena512.pgm";

//        proc->start(app);

        proc->start(app, args);
//        proc->start(app);

    //    proc->start(app2);

    }

}
void Assistant::start_process_file_path(const QString &file_path)
{
    if (!proc)
        proc = new QProcess();

    if (proc->state() != QProcess::Running) {

        //        QString app = "C:/WORKS/PROGRAMS/sakura/sakura.exe";

        //        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4/OpenSeeIt.exe";
        //        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4/OpenSeeIt.exe";

        //        QStringList args;
        //        args << "C:/WORKS/WS/WS_Android_20130929_122122/image_processing_Nagao_2/D-4/images/lena512.pgm";
        //        QString args = "C:/WORKS/WS/WS_Android_20130929_122122/"
        //                + "image_processing_Nagao_2/D-4/images/lena512.pgm";

        //    QString app = "sakura";

        QString app("C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
                    "/OpenSeeIt.exe ");

        QStringList args;

        //        QLatin1String arg1(" C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
        QLatin1String arg1("C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
                           //                     QString arg1("C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
                           "image_processing_Nagao_2\\D-4\\images\\rose_2.ppm"
                           );

        args << file_path;
//        args << arg1;


        //                QString app("C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
        //                            "/OpenSeeIt.exe C:\\WORKS\\WS\\WS_Android_20130929_122122\\"
        //                            "image_processing_Nagao_2\\D-4\\images\\lena512.pgm")
        //                ;
        //        QString app = "C:/WORKS/PROGRAMS/FreeWares/OpenSeeIt_v0.47.16.4"
        //                + "/OpenSeeIt.exe C:/WORKS/WS/WS_Android_20130929_122122/image_processing_Nagao_2/D-4/images/lena512.pgm";

        //        proc->start(app);

        proc->startDetached(app, args);
//        proc->start(app, args);
        //        proc->start(app);

        //    proc->start(app2);

    }

}
