#ifndef QCHECKBOXTHREAD_H
#define QCHECKBOXTHREAD_H

#include <QCheckBox>
#include <QString>
#include <QDebug>

class QCheckBoxThread : public QCheckBox
{
    Q_OBJECT
public:
    QCheckBoxThread(const QString &text, QWidget *parent = Q_NULLPTR);
signals:
    void hint(QString);
public slots:
    void clicked(bool checked);
};

#endif // QCHECKBOXTHREAD_H
