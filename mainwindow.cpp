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
 * To replace video's audio stream:
ffmpeg -i OUTPUT.mp4 -i audio.wav -shortest -c:v
copy -c:a aac -b:a 256k OUTPUT2.mp4

To strip video's audio:
ffmpeg -i video.mp4 -codec copy -an OUTPUT.mp4
*/
void MainWindow::executeCommand()
{
    QStringList args;
    qDebug() << "EXECUTE COMMAND PRESSED\n" << endl;
    args << "-i";
    args <<ui->lineEdit_Video->text();
    args << "-i";
    args <<ui->lineEdit_Audio->text();
    args << "-shortest";
    args <<"-c:v";
    args <<"copy";
    args << "-c:a";
    args << "aac";
    args << "-b:a";
    args <<"256k";
    args <<"OUTPUT2.mp4";
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

