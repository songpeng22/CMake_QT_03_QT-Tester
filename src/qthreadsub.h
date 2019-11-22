#ifndef QTHREADSUB_H
#define QTHREADSUB_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QSemaphore>

class QThreadSub : public QThread
{
public:
    QThreadSub();
    void run();
    void setSemaphore( QSemaphore *pSemaphore ){
        m_pSemaphore = pSemaphore;
    }
    QSemaphore * m_pSemaphore;
};

#endif // QTHREADSUB_H
