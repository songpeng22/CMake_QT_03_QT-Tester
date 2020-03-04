#include "qthreadsub.h"

QThreadSub::QThreadSub()
{
    m_pSemaphore = nullptr;
/*
    if( m_pSemaphore->tryAcquire(3) ){
        qDebug() << "true:available:" << m_pSemaphore->available();
    }
    else{
        qDebug() << "false:available:" << m_pSemaphore->available();
    }
*/
}

void QThreadSub::run()
{
    qDebug() << "QThreadSub::run()";

    int nCount = 0;
    int nAcquire = 2;
    while( true ){
        qDebug() << "QThreadSub:available:" << m_pSemaphore->available();

        if (QThread::currentThread()->isInterruptionRequested())
        {
            qDebug()<< "isInterruptionRequested:true";
            break;
        }

        if( m_pSemaphore->tryAcquire( nAcquire ) ){
//            m_pSemaphore->acquire( nAcquire );

            sleep( 1 );
            qDebug() << "QThreadSub:count,available:" << nCount++ << m_pSemaphore->available();

            m_pSemaphore->release( nAcquire );
        }
        else{
            sleep( 1 );

            qDebug() << "wait:" << nCount++;
        }


    }
}
