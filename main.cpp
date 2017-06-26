#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QStringLiteral("ffswap - Replace Audio in Video"));
    w.show();

    return a.exec();
}
