#ifndef QDIALOGSUB_H
#define QDIALOGSUB_H

#include "qwidgetbase.h"
#include <QDebug>
#include <QDateTime>
#include <QListWidget>
#include <QPushButton>
#include <QTimerEvent>
#include <QElapsedTimer>
#include <QApplication>
#include <QPoint>

class QDialogSub : public QWidgetBase
{
    Q_OBJECT
public:
    QDialogSub(QWidget *parent);
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
    QPushButton * m_btnExit;
    //timer
    int m_timerRefreshId;
    void timerEvent(QTimerEvent *event);
    QElapsedTimer m_elpaseTimer;
    //hints
    bool m_bTimer;
protected:
    QDateTime m_timeMouseLeftDown;
};

#endif // QDIALOGSUB_H
