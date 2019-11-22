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

#include <QtWidgets>

#include "controllerwindow.h"

ControllerWindow::ControllerWindow()
{
    previewWindow = nullptr;
    m_hintsGroupBox = nullptr;
    m_bottomLayout = nullptr;
    m_mainLayout = nullptr;
    m_hintsLayout = nullptr;
    //hints checkbox
    checkboxThread = nullptr;
    layout = nullptr;
    timerCheckBox = nullptr;

#if defined(CODE_OFF)
	qDebug() << "&msWindowsFixedSizeDialogCheckBox" << &msWindowsFixedSizeDialogCheckBox;
    checkboxThread = new QCheckBoxThread;
    QCheckBoxThread ** pp = &checkboxThread;
	qDebug() << "msWindowsFixedSizeDialogCheckBox" << msWindowsFixedSizeDialogCheckBox;
	qDebug() << "&msWindowsFixedSizeDialogCheckBox" << &msWindowsFixedSizeDialogCheckBox;
	qDebug() << "pp" << pp;
	qDebug() << "*pp" << *pp;
	queuedWidgets.enqueue(&msWindowsFixedSizeDialogCheckBox);
	QCheckBox ** ppGet = queuedWidgets.dequeue();
	delete *ppGet;
	*ppGet = nullptr;
//	ppGet = nullptr;
	qDebug() << "msWindowsFixedSizeDialogCheckBox" << msWindowsFixedSizeDialogCheckBox;
#endif

    //group && radio
    createTypeGroupBox();
    recreateHintsGroupBox();

    quitButton = new QPushButton(tr("&Quit"));
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    m_bottomLayout = new QVBoxLayout;
//    m_bottomLayout->addStretch();
    m_bottomLayout->addWidget(quitButton);

    m_mainLayout = new QHBoxLayout;
    m_mainLayout->addWidget(typeGroupBox);
    m_mainLayout->addWidget(m_hintsGroupBox);
    m_mainLayout->addLayout(m_bottomLayout);
    setLayout(m_mainLayout);

    setWindowTitle(tr("Window Flags"));
    updatePreview();
}

void ControllerWindow::createTypeGroupBox()
{
    typeGroupBox = new QGroupBox(tr("Type"));

    widgetRadioButton = createRadioButton(tr("QThread/QLayout"));
    dialogRadioButton = createRadioButton(tr("Timer"));
    sheetRadioButton = createRadioButton(tr("QFileInfo/QDir"));
/*
    drawerRadioButton = createRadioButton(tr("Drawer"));
    popupRadioButton = createRadioButton(tr("Popup"));
    toolRadioButton = createRadioButton(tr("Tool"));
    toolTipRadioButton = createRadioButton(tr("Tooltip"));
    splashScreenRadioButton = createRadioButton(tr("Splash screen"));
*/
    /*
     * default checked
    */
    widgetRadioButton->setChecked(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(widgetRadioButton, 0, 0);
    layout->addWidget(dialogRadioButton, 1, 0);
    layout->addWidget(sheetRadioButton, 2, 0);
/*
    layout->addWidget(drawerRadioButton, 3, 0);
    layout->addWidget(popupRadioButton, 0, 1);
    layout->addWidget(toolRadioButton, 1, 1);
    layout->addWidget(toolTipRadioButton, 2, 1);
    layout->addWidget(splashScreenRadioButton, 3, 1);
*/
    typeGroupBox->setLayout(layout);
}

QRadioButton *ControllerWindow::createRadioButton(const QString &text)
{
    QRadioButton *button = new QRadioButton(text);
    connect(button, SIGNAL(clicked()), this, SLOT(updatePreview()));
    return button;
}

void ControllerWindow::updatePreview()
{
    qDebug() << "ControllerWindow::updatePreview()";

    Qt::WindowFlags flags = 0;

    //hide/clean every related control
    qDebug() << "ControllerWindow::updatePreview()::hideAll";
    if( previewWindow != nullptr ){
        previewWindow->hideAll();
    }

    qDebug() << "ControllerWindow::updatePreview()::deleteAll";
    if( previewWindow != nullptr ){
        delete previewWindow;
        previewWindow = nullptr;
    }

    if (widgetRadioButton->isChecked()) {
        flags = Qt::Window;
        /*
         * QWidgetSub
         */
        qDebug() << "ControllerWindow::updatePreview()::new QWidgetSub";
        previewWindow = (QWidgetBase *) new QWidgetSub(this);
        recreateHintsGroupBoxWidgets(ControllerWindow::widget);
    } else if (dialogRadioButton->isChecked()) {
        flags = Qt::Dialog;
        /*
         * QDialogSub
         */
        previewWindow =(QWidgetBase *) new QDialogSub(this);
        setWindowTitle("Enter your age");
        recreateHintsGroupBoxWidgets(ControllerWindow::dialog);
    } else if (sheetRadioButton->isChecked()) {
        flags = Qt::Window;
        /*
         * QWidgetFileDir
         */
        previewWindow =(QWidgetBase *)  new QWidgetFileDir(this);
        recreateHintsGroupBoxWidgets(ControllerWindow::widget_2);
    }

    if(nullptr == previewWindow)
        return;

    previewWindow->setWindowFlags(flags);

    QPoint pos = previewWindow->pos();
    if (pos.x() < 0)
        pos.setX(0);
    if (pos.y() < 0)
        pos.setY(0);
    previewWindow->move(pos);
    previewWindow->show();

    qApp->processEvents();

//    connect(this,SIGNAL(hint(QString)),previewWindow,SLOT(setHints(QString)));
}

void ControllerWindow::recreateHintsGroupBoxWidgets(enumWidgets widget)
{
    if( widget == ControllerWindow::widget )
    {
        //create CheckBox
//        if( checkboxThread == nullptr ){
            checkboxThread = new QCheckBoxThread(tr("QThread/QSemaphore"));
//        }
//        if( layout == nullptr ){
            layout = new QCheckBoxLayout(tr("QBoxLayout"));
//        }

        //create relation
        previewWindow->addSub(checkboxThread);
        previewWindow->addSub(layout);
        //add widget
        m_hintsLayout->addWidget(checkboxThread, 0, 0);
        m_hintsLayout->addWidget(layout, 1, 0);
        //emit hints to observer
        connect(checkboxThread, SIGNAL(hint(QString)), previewWindow, SLOT(setHints(QString)));
        connect(layout, SIGNAL(hint(QString)), previewWindow, SLOT(setHints(QString)));
    }
    if( widget == ControllerWindow::dialog )
    {
        timerCheckBox = new QCheckBoxTimer(tr("timer"));

        //create relation
        previewWindow->addSub(timerCheckBox);
        //add widget
        m_hintsLayout->addWidget(timerCheckBox, 0, 0);
        //emit hints to observer
        connect(timerCheckBox, SIGNAL(hint(QString)), previewWindow, SLOT(setHints(QString)));
    }

    if( widget == ControllerWindow::widget_2 )
    {
        fileDirCheckBox = new QCheckBox(tr("QFileInfo/QDir"));
        //create relation
        previewWindow->addSub(fileDirCheckBox);
        //add widget
        m_hintsLayout->addWidget(fileDirCheckBox, 0, 0);
        connect(fileDirCheckBox,SIGNAL(clicked(bool)),this,SLOT(emitQFileHints(bool)));
        connect(this,SIGNAL(hints(QString)),previewWindow,SLOT(setHints(QString)));
    }
}

void ControllerWindow::recreateHintsGroupBox()
{
    m_hintsGroupBox = new QGroupBox(tr("Hints"));

    if( nullptr == m_hintsLayout )
        m_hintsLayout = new QGridLayout;

    m_hintsGroupBox->setLayout(m_hintsLayout);
}

void ControllerWindow::emitQFileHints(bool bChecked)
{
    if(bChecked){
        emit hints("+QFileInfo/QDir clicked");
    }
    else{
        emit hints("-QFileInfo/QDir clicked");
    }

}

