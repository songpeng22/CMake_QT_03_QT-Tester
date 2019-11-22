#ifndef QCHECKBOXTIMER_H
#define QCHECKBOXTIMER_H

#include <QCheckBox>
#include <QString>
#include <QDebug>

class QCheckBoxTimer : public QCheckBox
{
    Q_OBJECT
public:
    QCheckBoxTimer(const QString &text, QWidget *parent = Q_NULLPTR);
signals:
    void hint(QString);
public slots:
    void clicked(bool checked);
};

#endif // QCHECKBOXTIMER_H
