#include "mainwindow.h"
#include <QApplication>
using namespace std;
extern "C" {
  #include <libavcodec/avcodec.h>    // required headers
  #include <libavformat/avformat.h>
  #include <libavutil/dict.h>
}

int main(int argc, char *argv[])
{

    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
    QApplication a(argc, argv);
    MainWindow w;
    av_register_all();
    /*Validate video and audio file */
    /*Get audio stream type of source video*/
    /*Transcode source audio into desired, if necessary*/
    /*Copy audio stream to video's stream */
    w.setWindowTitle(QStringLiteral("ffswap - Replace Audio in Video"));
    w.show();

    return a.exec();
}
