#include "qcheckboxtimer.h"

QCheckBoxTimer::QCheckBoxTimer(const QString &text, QWidget *parent)
    : QCheckBox(text,parent)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked(bool)));
}

void QCheckBoxTimer::clicked(bool checked)
{
    qDebug() << "QCheckBoxTimer::clicked()" << checked;
    if( checked ){
        emit hint("+timer checked");
    }
    else{
        emit hint("-timer checked");
    }
}
