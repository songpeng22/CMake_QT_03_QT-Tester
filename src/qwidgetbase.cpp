#include "qwidgetbase.h"

QWidgetBase::QWidgetBase(QWidget *parent) : QWidget(parent)
{

}

void QWidgetBase::setHints(QString hints)
{
    qDebug() << "QWidgetBase::updateHints()" << hints;
}
