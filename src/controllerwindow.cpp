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

/*
 * 新增界面 - 左侧主分类 - RadioButton
 */
void ControllerWindow::insertRadioButton()
{
    m_radioBtnVector.append( createRadioButton(tr("QThread/QLayout")) );
    m_radioBtnVector.append( createRadioButton(tr("Timer")) );
    m_radioBtnVector.append( createRadioButton(tr("QFileInfo/QDir")) );
    m_radioBtnVector.append( createRadioButton(tr("Network/QSocketNotifier")) );
}

/*
 * 新增界面 - 点击RadioButton 出现Window
 */
QWidgetBase * ControllerWindow::insertWindow(int nIndexOfWindow)
{
    if (0 == nIndexOfWindow)
       return (QWidgetBase *) new QWidgetSub(this);
    else if( 1 == nIndexOfWindow )
       return (QWidgetBase *) new QDialogSub(this);
    else if( 2 == nIndexOfWindow )
       return (QWidgetBase *) new QWidgetFileDir(this);
    else if( 3 == nIndexOfWindow )
       return (QWidgetBase *) new QDialog4(this);
    else
    {

    }
    return nullptr;
}

/*
 * End of 新增界面 - 左侧主分类
 */

/*
 * 新增界面 - 右侧辅助分类
 */
void ControllerWindow::updatePreview()
{
    qDebug() << "ControllerWindow::updatePreview()";

    Qt::WindowFlags flags = Qt::Window;

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
#if 1
    if (m_radioBtnVector[0]->isChecked()) {
#else
    if (widgetRadioButton->isChecked()) {
#endif
        flags = Qt::Window;
        /*
         * QWidgetSub
         */
        qDebug() << "ControllerWindow::updatePreview()::new QWidgetSub";
        previewWindow = insertWindow(0);
        recreateHintsGroupBoxWidgets(ControllerWindow::widget);
#if 1
    } else if (m_radioBtnVector[1]->isChecked()) {
#else
    } else if (dialogRadioButton->isChecked()) {
#endif
        flags = Qt::Dialog;
        /*
         * QDialogSub
         */
        previewWindow = insertWindow(1);
        setWindowTitle("Enter your age");
        recreateHintsGroupBoxWidgets(ControllerWindow::dialog);
#if 1
    } else if (m_radioBtnVector[2]->isChecked()) {
#else
    } else if (sheetRadioButton->isChecked()) {
#endif
        flags = Qt::Window;
        /*
         * QWidgetFileDir
         */
        previewWindow = insertWindow(2);
        recreateHintsGroupBoxWidgets(ControllerWindow::widget_2);
    }
    else if (m_radioBtnVector[3]->isChecked()) {
        qDebug() << "QSocketNotifier";
        previewWindow = insertWindow(3);
        recreateHintsGroupBoxWidgets(ControllerWindow::widget_4);
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
    else if( widget == ControllerWindow::dialog )
    {
        timerCheckBox = new QCheckBoxTimer(tr("timer"));

        //create relation
        previewWindow->addSub(timerCheckBox);
        //add widget
        m_hintsLayout->addWidget(timerCheckBox, 0, 0);
        //emit hints to observer
        connect(timerCheckBox, SIGNAL(hint(QString)), previewWindow, SLOT(setHints(QString)));
    }
    else if( widget == ControllerWindow::widget_2 )
    {
        fileDirCheckBox = new QCheckBox(tr("QFileInfo/QDir"));
        //create relation
        previewWindow->addSub(fileDirCheckBox);
        //add widget
        m_hintsLayout->addWidget(fileDirCheckBox, 0, 0);
        connect(fileDirCheckBox,SIGNAL(clicked(bool)),this,SLOT(emitQFileHints(bool)));
        connect(this,SIGNAL(hints(QString)),previewWindow,SLOT(setHints(QString)));
    }
    else
    {

    }
}

/*
 * End of 新增界面 - 右侧辅助分类
 */

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

ControllerWindow::~ControllerWindow()
{
    qDebug() << "~ControllerWindow()";
    if(previewWindow){
        delete previewWindow;
        previewWindow = nullptr;
    }
}

void ControllerWindow::createTypeGroupBox()
{
    typeGroupBox = new QGroupBox(tr("Type"));
#if 1
    insertRadioButton();
#else
    widgetRadioButton = createRadioButton(tr("QThread/QLayout"));
    dialogRadioButton = createRadioButton(tr("Timer"));
    sheetRadioButton = createRadioButton(tr("QFileInfo/QDir"));
#endif
    /*
     * default checked
    */
#if 1
    m_radioBtnVector[0]->setChecked(true);
#else
    widgetRadioButton->setChecked(true);
#endif
    QGridLayout *layout = new QGridLayout;
#if 1
    for( int i=0;i < m_radioBtnVector.size();i++ )
    {
        layout->addWidget(m_radioBtnVector[i],i,0);
    }
#else
    layout->addWidget(widgetRadioButton, 0, 0);
    layout->addWidget(dialogRadioButton, 1, 0);
    layout->addWidget(sheetRadioButton, 2, 0);
#endif
    typeGroupBox->setLayout(layout);
}

QRadioButton *ControllerWindow::createRadioButton(const QString &text)
{
    QRadioButton *button = new QRadioButton(text);
    connect(button, SIGNAL(clicked()), this, SLOT(updatePreview()));
    return button;
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

