/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H

#include <QWidget>
#include <QQueue>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QPushButton;
class QRadioButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
QT_END_NAMESPACE

#include "qwidgetbase.h"
#include "qwidgetsub.h"
#include "qdialogsub.h"
#include "qwidgetFileDir.h"
#include "qcheckboxthread.h"
#include "qcheckboxlayout.h"
#include "qcheckboxtimer.h"

class ControllerWindow : public QWidget
{
    Q_OBJECT

public:
    ControllerWindow();
    enum enumWidgets{
        widget = 0,
        dialog,
        widget_2,
        max_widget
    };
private slots:
    void updatePreview();
private:
    void createTypeGroupBox();
    void recreateHintsGroupBox();
    void recreateHintsGroupBoxWidgets(enumWidgets);
    QVBoxLayout *m_bottomLayout;
    QHBoxLayout *m_mainLayout;
    QGridLayout *m_hintsLayout;
    QCheckBox *createCheckBox(const QString &text);
    QRadioButton *createRadioButton(const QString &text);

    QWidgetBase *previewWindow;

    QGroupBox *typeGroupBox;
    QGroupBox *m_hintsGroupBox;
    QPushButton *quitButton;
    //raido
    QRadioButton *widgetRadioButton;
    QRadioButton *dialogRadioButton;
    QRadioButton *sheetRadioButton;
    QRadioButton *drawerRadioButton;
    QRadioButton *popupRadioButton;
    QRadioButton *toolRadioButton;
    QRadioButton *toolTipRadioButton;
    QRadioButton *splashScreenRadioButton;
    //checkbox
    QCheckBoxThread *checkboxThread;
    QCheckBox *layout;
    QCheckBox *timerCheckBox;
    QCheckBox *fileDirCheckBox;
signals:
    void hints(QString);
public slots:
    void emitQFileHints(bool bChecked);
};

#endif
