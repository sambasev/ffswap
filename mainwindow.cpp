#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QObject::connect(&commandProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(outputCommand()));
    QObject::connect(&commandProcess, SIGNAL(readyReadStandardError()),this, SLOT(outputCommand()));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*test:
 * Each arg to ffmpeg will be a seperate string into the args list, don't combine them
 * into a single string
 *
 * To replace video's audio stream:
ffmpeg -i INPUT.mp4 -i AUDIO.wav -map 0:0 -map 1:0
-c:v copy -c:a aac -b:a 256k -shortest OUTPUT.mp4

To strip video's audio:
ffmpeg -i video.mp4 -codec copy -an OUTPUT.mp4
*/
void MainWindow::executeCommand()
{
    QStringList args;
    qDebug() << "EXECUTE COMMAND PRESSED\n" << endl;
    args << "-i";
    args << ui->lineEdit_Video->text();
    args << "-i";
    args << ui->lineEdit_Audio->text();
    args << "-map";
    args << "0:0";
    args << "-map";
    args << "1:0";
    args << "-c:v";
    args << "copy";
    args << "-c:a";
    args << "aac";
    args << "-b:a";
    args << "256k";
    args << "-shortest";
    args << ui->lineEdit_Dest->text();
    commandProcess.start("C:\\ffmpeg\\bin\\ffmpeg.exe", args);
    qDebug() << args << endl;

}

void MainWindow::outputCommand()
{
    QByteArray cmdoutput = commandProcess.readAllStandardOutput();
    QString txtoutput = cmdoutput;
    ui->textBrowser_Output->append(txtoutput);
    cmdoutput = commandProcess.readAllStandardError();
    txtoutput = cmdoutput;
    ui->textBrowser_Output->append(txtoutput);
    qDebug() << txtoutput;

}

void MainWindow::cancelCommand()
{

}

void MainWindow::setDestination()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Select Destination"),
             "", tr("All Files (*)"));
    ui->lineEdit_Dest->setText(file);
}

void MainWindow::setAudio()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select Audio File"),
           "", tr("All Files (*)"));
    ui->lineEdit_Audio->setText(file);
}

void MainWindow::setVideo()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select Video File"),
           "", tr("All Files (*)"));
    ui->lineEdit_Video->setText(file);
}

