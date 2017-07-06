#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>

using namespace std;
extern "C" {
  #include <libavcodec/avcodec.h>    // required headers
  #include <libavformat/avformat.h>
  #include <libavutil/dict.h>
}

int probeMediaFile(QString file);
int printMetaData(QString file);

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

TODO:
1). Make it unpressable till ffmpeg is done
2). Determine if audio needs to be transcoded
3). Surround vs. stereo vs. mono?
4). Output overwrite
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
    close();
}

void MainWindow::ffprobeCommand()
{
    //QString file = ui->lineEdit_Video->text();
    QString file = "C:/Users/samba_000/Desktop/1 video.mp4";
    if(probeMediaFile(file) < 0) {
        qDebug() << "PROBE FILE FAILED BY CODEC";
    }

    //close();
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
    //ui->lineEdit_Video->setText(file);
    ui->lineEdit_Video->setText("C:/Users/samba_000/Desktop/1 video.mp4");

}

/*
 * probeMediaFile(Videofile)
 * Probes video for audio stream and finds its media format (MP4/WAV etc).
 * If no stream present, it will return a type that the video format can hold.
*/

int probeMediaFile(QString file)
{
    AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
    QByteArray array = file.toLocal8Bit();
    char *fileName = array.data();
    int err;

    qDebug() << file << " FILE " << fileName;

    ifmt_ctx = avformat_alloc_context();

    /* Try opening media file*/
    if((err = avformat_open_input(&ifmt_ctx, fileName, NULL, NULL)) < 0) {
        qDebug() << err << " : file " << fileName << " could not be opened" << endl;
    }

    /* Fill the streams in the format context */
    if ((err = avformat_find_stream_info(ifmt_ctx, NULL)) < 0) {
        qDebug() << err << " : Can't find stream info" << endl;
    }

    av_dump_format(ifmt_ctx, 0, fileName, 0);
    /* Get Audio/Video Stream info */
    for (int i = 0; i < ifmt_ctx->nb_streams; i++) {
        AVStream *stream;
        AVCodecContext *codec_ctx;
        const AVCodec *iCodec;
        stream = ifmt_ctx->streams[i];
        if(codec_ctx = stream->codec) {
            qDebug() << "xStream: " << i << " bit rate " << codec_ctx->bit_rate;
            if(codec_ctx->codec_type == AVMEDIA_TYPE_AUDIO) {
                qDebug() << "Audio";
            }
            if(codec_ctx->codec_type == AVMEDIA_TYPE_VIDEO) {
                qDebug() << "Video";
            }
            iCodec = avcodec_find_decoder(codec_ctx->codec_id);

            if(iCodec) {
                qDebug() << i << ": " << iCodec->id << iCodec->name << iCodec->capabilities << endl;
                qDebug() << "Stream: " << i << " codec: " << iCodec->long_name << endl;
            } else {
                qDebug() << "Unknown Codec Name for stream " << i << endl;
            }
        }
    }


    return 0;

}

/*
 * printMetaData(FileName)
 * Outputs the metadata of that file. Used for debugging.
*/

int printMetaData(QString file)
{
    AVFormatContext *fmt_ctx = NULL;
    AVDictionaryEntry *tag = NULL;
    QString stats;
    QByteArray array = file.toLocal8Bit();
    char *fileName = array.data();
    int ret;

    qDebug() << file << " FILE " << fileName;

    if ((ret = avformat_open_input(&fmt_ctx, fileName, NULL, NULL))) {
        qDebug() << " OPEN FAILED BY CODEC";
        stats.sprintf("FAIL");
        return -1;
    }

    while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
        stats.sprintf(" %s = %s", tag->key, tag->value);
        qDebug() << stats;
    }
   // probe_file(fileName);

    avformat_close_input(&fmt_ctx);
    return 0;

}

