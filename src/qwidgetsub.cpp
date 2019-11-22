#include "qwidgetsub.h"

QWidgetSub::QWidgetSub(QWidget *parent) : QWidgetBase(parent)
{
    //Semaphore
    m_pThread = new QThreadSub;
    m_pSemaphore = new QSemaphore(5);
    m_pThread->setSemaphore(m_pSemaphore);

    //Layout
    m_buttonFirst = new QPushButton("first");
    m_buttonSecond = new QPushButton("second");
    m_buttonThird = new QPushButton("third");
    m_buttonFourth = new QPushButton("fourth");
    m_buttonFirst->setMinimumHeight(50); //set initial height of widget
    m_buttonSecond->setMinimumHeight(50); //set initial height of widget
    m_buttonThird->setMinimumHeight(50); //set initial height of widget
    m_buttonFourth->setMinimumHeight(50); //set initial height of widget
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_buttonFirst);
    layout->addWidget(m_buttonSecond);
    layout->addWidget(m_buttonThird);
    layout->addWidget(m_buttonFourth);
    setLayout(layout);
}

void QWidgetSub::setHints(QString hints)
{
    qDebug() << "QWidgetSub::updateHints" << hints;

    //thread
    if( hints == QString("+thread checked") ){
        qDebug() << "+thread";
        m_pThread->start();
    }
    if( hints == QString("-thread checked") ){
        qDebug() << "-thread";
        m_pThread->terminate();
    }

    //layout
    if( hints == QString("+layout checked") ){
        qDebug() << "+layout";
    }
    if( hints == QString("-layout checked") ){
        qDebug() << "-layout";
    }
}
