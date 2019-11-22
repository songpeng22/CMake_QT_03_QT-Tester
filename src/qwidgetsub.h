#ifndef QWIDGETSUB_H
#define QWIDGETSUB_H

#include <QDebug>
#include "qwidgetbase.h"
#include <QSemaphore>
#include "qthreadsub.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QQueue>
#include <QCheckBox>

class QWidgetSub : public QWidgetBase
{
    Q_OBJECT
public:
    explicit QWidgetSub(QWidget *parent = nullptr);
public:
    QThreadSub * m_pThread;
    QSemaphore *m_pSemaphore;
    QPushButton *m_buttonFirst;
    QPushButton *m_buttonSecond;
    QPushButton *m_buttonThird;
    QPushButton *m_buttonFourth;
    //

signals:
    void hint(QString);
public slots:
    //hints
    void setHints(QString hints);
};

#endif // QWIDGETSUB_H
