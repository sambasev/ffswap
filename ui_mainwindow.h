/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_Main;
    QLineEdit *lineEdit_Video;
    QPushButton *pushButton_Audio;
    QLineEdit *lineEdit_Dest;
    QLineEdit *lineEdit_Audio;
    QPushButton *pushButton_Process;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Video;
    QPushButton *pushButton_Dest;
    QTextBrowser *textBrowser_Output;
    QLabel *label;
    QPushButton *pushButton_ffprobe;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(424, 358);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 421, 331));
        tab_Main = new QWidget();
        tab_Main->setObjectName(QStringLiteral("tab_Main"));
        lineEdit_Video = new QLineEdit(tab_Main);
        lineEdit_Video->setObjectName(QStringLiteral("lineEdit_Video"));
        lineEdit_Video->setGeometry(QRect(70, 20, 301, 21));
        pushButton_Audio = new QPushButton(tab_Main);
        pushButton_Audio->setObjectName(QStringLiteral("pushButton_Audio"));
        pushButton_Audio->setGeometry(QRect(20, 50, 41, 21));
        lineEdit_Dest = new QLineEdit(tab_Main);
        lineEdit_Dest->setObjectName(QStringLiteral("lineEdit_Dest"));
        lineEdit_Dest->setGeometry(QRect(70, 90, 301, 21));
        lineEdit_Audio = new QLineEdit(tab_Main);
        lineEdit_Audio->setObjectName(QStringLiteral("lineEdit_Audio"));
        lineEdit_Audio->setGeometry(QRect(70, 50, 301, 21));
        pushButton_Process = new QPushButton(tab_Main);
        pushButton_Process->setObjectName(QStringLiteral("pushButton_Process"));
        pushButton_Process->setGeometry(QRect(120, 270, 80, 22));
        pushButton_Cancel = new QPushButton(tab_Main);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(210, 270, 80, 22));
        pushButton_Video = new QPushButton(tab_Main);
        pushButton_Video->setObjectName(QStringLiteral("pushButton_Video"));
        pushButton_Video->setGeometry(QRect(20, 20, 41, 21));
        pushButton_Dest = new QPushButton(tab_Main);
        pushButton_Dest->setObjectName(QStringLiteral("pushButton_Dest"));
        pushButton_Dest->setGeometry(QRect(20, 90, 41, 21));
        textBrowser_Output = new QTextBrowser(tab_Main);
        textBrowser_Output->setObjectName(QStringLiteral("textBrowser_Output"));
        textBrowser_Output->setGeometry(QRect(20, 140, 351, 121));
        label = new QLabel(tab_Main);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 91, 16));
        pushButton_ffprobe = new QPushButton(tab_Main);
        pushButton_ffprobe->setObjectName(QStringLiteral("pushButton_ffprobe"));
        pushButton_ffprobe->setGeometry(QRect(300, 270, 80, 22));
        tabWidget->addTab(tab_Main, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Cancel, SIGNAL(clicked()), MainWindow, SLOT(cancelCommand()));
        QObject::connect(pushButton_Video, SIGNAL(clicked()), MainWindow, SLOT(setVideo()));
        QObject::connect(pushButton_Process, SIGNAL(clicked()), MainWindow, SLOT(executeCommand()));
        QObject::connect(pushButton_Audio, SIGNAL(clicked()), MainWindow, SLOT(setAudio()));
        QObject::connect(pushButton_Dest, SIGNAL(clicked()), MainWindow, SLOT(setDestination()));
        QObject::connect(pushButton_ffprobe, SIGNAL(clicked()), MainWindow, SLOT(ffprobeCommand()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lineEdit_Video->setText(QApplication::translate("MainWindow", "<Video whose audio stream will be replaced>", Q_NULLPTR));
        pushButton_Audio->setText(QApplication::translate("MainWindow", "Audio..", Q_NULLPTR));
        lineEdit_Dest->setText(QApplication::translate("MainWindow", "<Destination - leave empty to overwrite Video File>", Q_NULLPTR));
        lineEdit_Audio->setText(QApplication::translate("MainWindow", "<Audio stream>", Q_NULLPTR));
        pushButton_Process->setText(QApplication::translate("MainWindow", "Process", Q_NULLPTR));
        pushButton_Cancel->setText(QApplication::translate("MainWindow", "Cancel", Q_NULLPTR));
        pushButton_Video->setText(QApplication::translate("MainWindow", "Video..", Q_NULLPTR));
        pushButton_Dest->setText(QApplication::translate("MainWindow", "Dest..", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        pushButton_ffprobe->setText(QApplication::translate("MainWindow", "ffprobe", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_Main), QApplication::translate("MainWindow", "Main", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
