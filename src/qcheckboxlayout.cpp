#include "qcheckboxlayout.h"

QCheckBoxLayout::QCheckBoxLayout(const QString &text, QWidget *parent)
    : QCheckBox(text,parent)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked(bool)));
}

void QCheckBoxLayout::clicked(bool checked)
{
    qDebug() << "QCheckBoxLayout::clicked()" << checked;
    if( checked ){
        emit hint("+layout checked");
    }
    else{
        emit hint("-layout checked");
    }
}
