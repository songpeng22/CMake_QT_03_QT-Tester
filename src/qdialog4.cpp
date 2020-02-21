#include "qdialog4.h"

QDialog4::QDialog4(QWidget *parent) : QWidgetBase(parent)
{
    //Controls
    m_list = new QListWidget(this);
    m_list->addItem( "5 item" );
    m_button1 = new QPushButton("Posconfig");
    //Layout
    QVBoxLayout * pVLayout = new QVBoxLayout;
    pVLayout->addWidget(m_button1);
    //
    QHBoxLayout * pMainLayout = new QHBoxLayout;
    pMainLayout->addWidget(m_list);
    pMainLayout->addLayout(pVLayout);
    //
    setLayout(pMainLayout);
    //Server
    serverTcp = new QTcpServer(this);
    // whenever a user connects, it will emit signal
    connect(serverTcp, SIGNAL(newConnection()),this, SLOT(newConnection()));
    if(!serverTcp->listen(QHostAddress::Any, 1025))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

/*
    //Socket
    socketTcp = new QTcpSocket(this);
    connect(socketTcp, SIGNAL(connected()),this, SLOT(connected()));
    connect(socketTcp, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socketTcp, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socketTcp, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting...";
    // this is not blocking call
    socketTcp->connectToHost("127.0.0.1", 1025);
    // we need to wait...
    if(!socketTcp->waitForConnected(5000))
    {
        qDebug() << "Error: " << socketTcp->errorString();
    }

    socketServer = new QSocketNotifier(1025,(QSocketNotifier::Type)( QSocketNotifier::Read | QSocketNotifier::Write ) );
    qDebug() << "isEnabled:" << socketServer->isEnabled();
    connect(socketServer,SIGNAL(activated(int)),this,SLOT(socketEvent(int)));
*/
}

QDialog4::~QDialog4()
{
    qDebug() << "~QDialog4()";
    if(socketTcp){
        delete socketTcp;
        socketTcp = nullptr;
    }
    if(socketServer){
        delete socketServer;
        socketServer = nullptr;
    }
}

void QDialog4::newConnection()
{
    qDebug() << "QDialog4::newConnection.";

    // need to grab the socket
    qDebug() << "+serverTcp->hasPendingConnections:" << serverTcp->hasPendingConnections();
    socketTcp = serverTcp->nextPendingConnection();
    qDebug() << "-serverTcp->hasPendingConnections:" << serverTcp->hasPendingConnections();
    qDebug() << "server address:" << serverTcp->serverAddress();
    qDebug() << "server port:" << serverTcp->serverPort();
    qDebug() << "server socketDescriptor:" << serverTcp->socketDescriptor();

    connect(socketTcp, SIGNAL(connected()),this, SLOT(connected()));
    connect(socketTcp, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socketTcp, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socketTcp, SIGNAL(readyRead()),this, SLOT(readyRead()));

    if(socketTcp)
    {
        qDebug() << "socket valid.";
    }
    else
    {
        qDebug() << "socket invalid.";
    }
#if 0
    socket->write("Hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
#endif
}

void QDialog4::connected()
{
    qDebug() << "connected...";

    // Hey server, tell me about you.
    socketTcp->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void QDialog4::disconnected()
{
    qDebug() << "disconnected...";
}

void QDialog4::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void QDialog4::readyRead()
{
    qDebug() << "QDialog4::readyRead:";

    // read the data from the socket
    qDebug() << socketTcp->readAll();
}

void QDialog4::socketEvent(int nEvent)
{
    qDebug() << "QDialog4::socketEvent:" << nEvent;

}

void QDialog4::setHints(QString hints)
{
    qDebug() << "QDialog4::setHints" << hints;

    if( hints == QString("+timer checked") ){
        qDebug() << "+timer";
    }
    if( hints == QString("-timer checked") ){
        qDebug() << "-timer";
    }
}

void QDialog4::showEvent(QShowEvent * event)
{
    qDebug() << "QDialog4::showEvent";

}

void QDialog4::mousePressEvent(QMouseEvent *event)
{
/*
    qDebug() << "QDialog4::mousePressEvent";
    m_timeMouseLeftDown = QDateTime::currentDateTime();

    qDebug() << "mousePressEvent:" << event->flags() << event->button();
*/
}

void QDialog4::mouseReleaseEvent(QMouseEvent *event)
{
/*
    qDebug() << "QDialog4::mouseReleaseEvent";
    QDateTime now = QDateTime::currentDateTime();
    qint64 msecs = m_timeMouseLeftDown.msecsTo(now);
    qDebug() << "msecs" << msecs;

    qDebug() << "mouseReleaseEvent:" << event->flags() << event->button();
*/
}


