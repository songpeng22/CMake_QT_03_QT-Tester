#ifndef QWIDGETBASE_H
#define QWIDGETBASE_H

#include <QWidget>
#include <QQueue>
#include <QCheckBox>
#include <QDebug>

class QWidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetBase(QWidget *parent = nullptr);
    //
    QQueue<QCheckBox *> queuedWidgets;
    void addSub(QCheckBox * pCheckbox)
    {
        qDebug() << "addSub";
        queuedWidgets.enqueue(pCheckbox);
    }
    void hideAll()
    {
        qDebug() << "hideAll";
        for (int i=0;queuedWidgets.size();i++) {
            QCheckBox *pCheckbox = (QCheckBox*)queuedWidgets.dequeue();
            pCheckbox->hide();
        }
    }
public slots:
    void setHints(QString hints);
};

#endif // QWIDGETBASE_H
