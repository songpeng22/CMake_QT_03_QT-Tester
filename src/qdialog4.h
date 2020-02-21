#ifndef QDIALOG4_H
#define QDIALOG4_H

#include "qwidgetbase.h"
#include "global_include.h"

class QDialog4 : public QWidgetBase
{
    Q_OBJECT
public:
    QDialog4(QWidget *parent);
    ~QDialog4();
public slots:
    //hints
    void setHints(QString hints);
public:
    //show
    void showEvent(QShowEvent * event);
    //mouse
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //widget
    QListWidget * m_list;
    QPushButton * m_button1;
//    QPushButton * m_btnExit;
    //Server/Socket
    QTcpServer *serverTcp;
    QTcpSocket *socketTcp;
    QSocketNotifier * socketServer;

public slots:
    void newConnection();
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void socketEvent(int nEvent);
protected:
    QDateTime m_timeMouseLeftDown;
};

#endif // QDIALOG4_H
