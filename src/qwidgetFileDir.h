#ifndef QWIDGETFILEDIR_H
#define QWIDGETFILEDIR_H

#include <QDebug>
#include "qwidgetbase.h"
#include <QSemaphore>
#include "qthreadsub.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class QWidgetFileDir : public QWidgetBase
{
    Q_OBJECT
public:
    explicit QWidgetFileDir(QWidget *parent = nullptr);
public:
    void callQFileInfo();
    void callQDir();
    void callQFile();
signals:

public slots:
    //hints
    void setHints(QString hints);
};

#endif // QWIDGETFILEDIR_H
