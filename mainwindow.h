#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define QT_AUTO_SCREEN_SCALE_FACTOR 1

#include <QMainWindow>
#include <QProcess>
#include <QByteArray>
#include <QTextBrowser>
#include <QFileDialog>
#include <QDesktopServices>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void executeCommand();
    void outputCommand();
    void cancelCommand();
    void setDestination();
    void setAudio();
    void setVideo();

private:
    Ui::MainWindow *ui;
    QProcess commandProcess;
};

#endif // MAINWINDOW_H
