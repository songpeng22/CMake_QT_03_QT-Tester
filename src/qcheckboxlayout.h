#ifndef QCHECKBOXLAYOUT_H
#define QCHECKBOXLAYOUT_H

#include <QCheckBox>
#include <QString>
#include <QDebug>

class QCheckBoxLayout : public QCheckBox
{
    Q_OBJECT
public:
    QCheckBoxLayout(const QString &text, QWidget *parent = Q_NULLPTR);

signals:
    void hint(QString);
public slots:
    void clicked(bool checked);
};

#endif // QCHECKBOXLAYOUT_H
