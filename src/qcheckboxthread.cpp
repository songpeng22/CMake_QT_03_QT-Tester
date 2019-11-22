#include "qcheckboxthread.h"

QCheckBoxThread::QCheckBoxThread(const QString &text, QWidget *parent)
    : QCheckBox(text,parent)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked(bool)));
}

void QCheckBoxThread::clicked(bool checked)
{
    qDebug() << "QCheckBoxThread::clicked()" << checked;
    if( checked ){
        emit hint("+thread checked");
    }
    else{
        emit hint("-thread checked");
    }
}


