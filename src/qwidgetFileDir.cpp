#include "qwidgetFileDir.h"

#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QString>

QWidgetFileDir::QWidgetFileDir(QWidget *parent) : QWidgetBase(parent)
{

}

void QWidgetFileDir::setHints(QString hints)
{
    qDebug() << "QWidgetFileDir::setHints" << hints;

    if( hints == QString("+QFileInfo/QDir clicked") ){
        qDebug() << "+QFileInfo/QDir clicked";

//        callQDir();
        callQFile();
    }
    if( hints == QString("-QFileInfo/QDir clicked") ){
        qDebug() << "-QFileInfo/QDir clicked";
//        callQFileInfo();
    }
}

void QWidgetFileDir::callQFileInfo()
{
    qDebug() << "callQFileInfo";
    //QFileInfo/QDir
    QFileInfo fileinfo1(QDir(QString("c:/song")),QString("a.txt"));
    qDebug() << "filePath:" << fileinfo1.filePath();
    //
    QFileInfo fileinfo2(QDir(QString("c:/song/")),QString("a.txt"));
    qDebug() << "filePath:" << fileinfo2.filePath();
    //QFileInfo/setFile
    QFileInfo fileinfo3;
    fileinfo3.setFile(QDir(QString("c:/song")),QString("a.txt"));
    qDebug() << "filePath:" << fileinfo3.filePath();
    //
    QString filename = "c:/song/a4.txt";
    QFileInfo fileInfo4(filename);
    qDebug() << fileInfo4.fileName();
}

void QWidgetFileDir::callQDir()
{
    qDebug() << "callQDir";

    QFileInfo filename("c:/");
    qDebug() << "fileName:" << filename.fileName();
    qDebug() << "dir:" << filename.dir();
    qDebug() << "exists:" << filename.exists();
    qDebug() << "isFile:" << filename.isFile();
    qDebug() << "isDir:" << filename.isDir();
    qDebug() << "filePath:" << filename.filePath();

    QDir dir("c:/song/song");
    qDebug() << dir;
    qDebug() << "absolutePath():" << dir.absolutePath();
    qDebug() << "absolutePath():" << dir.absoluteFilePath("hello.txt");

//    qDebug() << "filePath:" << dir.filePath();
    if( !dir.exists() ){
        qDebug() << dir.dirName() << dir.exists();
//        qDebug() << "mkdir ret:" << dir.mkdir(  dir.absolutePath() );
        qDebug() << "mkdir ret:" << dir.mkpath(  dir.absolutePath() );

        qDebug() << dir.dirName() << dir.exists();
    }
    else{
        qDebug() << "dir exist";
    }
}

#include <QFile>
void QWidgetFileDir::callQFile()
{
    qDebug() << "callQFile";

    QString fileName = QString::asprintf("%s", "c:/song/song3.txt");

    QFile file(fileName);
    qDebug() << "fileName:" << file.fileName();

    bool bFile = file.open(QIODevice::WriteOnly | QIODevice::Text);
    qDebug() << "file Create:" << bFile;
    file.close();
    bool bFileRemove = file.remove();
    qDebug() << "file Remove:" << bFileRemove;
}
