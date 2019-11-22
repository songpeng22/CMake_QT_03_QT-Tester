#include "qdialogsub.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

QDialogSub::QDialogSub(QWidget *parent) : QWidgetBase(parent)
{
    m_list = new QListWidget(this);
    m_list->addItem( "1 item" );
    m_list->addItem( "2 item" );
    m_list->addItem( "3 item" );
    m_btnExit = new QPushButton("buttonExit");
    m_button1 = new QPushButton("Posconfig");

    QVBoxLayout * pVLayout = new QVBoxLayout;
    pVLayout->addWidget(m_button1);
    pVLayout->addStretch();
    pVLayout->addWidget(m_btnExit);


    QHBoxLayout * pMainLayout = new QHBoxLayout;
    pMainLayout->addWidget(m_list);
    pMainLayout->addLayout(pVLayout);

    setLayout(pMainLayout);

    //timer
    m_timerRefreshId = startTimer(1000);
    m_elpaseTimer.start();

    //hints
    m_bTimer = false;
}

void QDialogSub::setHints(QString hints)
{
    qDebug() << "QDialogSub::setHints" << hints;

    if( hints == QString("+timer checked") ){
        qDebug() << "+timer";
        m_bTimer = true;
    }
    if( hints == QString("-timer checked") ){
        qDebug() << "-timer";
        m_bTimer = false;
    }

}

void QDialogSub::showEvent(QShowEvent * event)
{
    qDebug() << "QDialogSub::showEvent";

}

void QDialogSub::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "QDialogSub::mousePressEvent";
    m_timeMouseLeftDown = QDateTime::currentDateTime();

    qDebug() << "mousePressEvent:" << event->flags() << event->button();
}

void QDialogSub::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "QDialogSub::mouseReleaseEvent";
    QDateTime now = QDateTime::currentDateTime();
    qint64 msecs = m_timeMouseLeftDown.msecsTo(now);
    qDebug() << "msecs" << msecs;

    qDebug() << "mouseReleaseEvent:" << event->flags() << event->button();
}

void QDialogSub::timerEvent(QTimerEvent *event)
{
    if( !m_bTimer )
        return;

    if( event->timerId() == m_timerRefreshId )
    {
        qDebug() << "m_timerRefreshId arrives:" << m_elpaseTimer.elapsed();

        QPoint ptScreen;
        ptScreen = mapToGlobal(QPoint(10,10));
        if( QApplication::widgetAt(ptScreen) )
            qDebug() << "found from widgetAt" << ptScreen;
        else
            qDebug() << "not found from widgetAt" << ptScreen;


    }
}

