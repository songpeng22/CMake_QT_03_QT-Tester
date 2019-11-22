#include <QApplication>
#include <QGuiApplication>

#include "global_include.h"
#include <QQuickWindow>
#include <QPushButton>
#include <QQuickItem>
//For Debug
#include <QDebug>
//QT Tester
#include <QLabel>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QDialog>
#include <QWindow>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include "controllerwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    //QString
    QString str = "123456789";
    int nIndex = str.indexOf("345");
    qDebug() << "index:" << nIndex;

    //Widget
#if 1
    ControllerWindow * widget = new ControllerWindow;
    widget->show();

    QElapsedTimer timer;
    qDebug() << "elpase:" << timer.elapsed();
    QThread::msleep( 105 );
    qDebug() << "elpase:" << timer.elapsed();

#elif 1
	QMessageBox msgBox;
	msgBox.setText("The document has been modified.");
	msgBox.setWindowTitle("confirm");
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.setIcon(QMessageBox::Critical);
	int ret = msgBox.exec();

#elif 0
    QWindow * pWindow = new QWindow;
//    pWindow->setWindowTitle("Enter your age");
    pWindow->show();
#elif 1
	QWidget * pWidget = new QWidget;
	pWidget->setWindowTitle("Enter your age");

	QSpinBox * pSpin = new QSpinBox;
	QSlider * pSlider = new QSlider;
	pSpin->setRange(0, 130);
	pSlider->setRange(0, 130);

	QObject::connect(pSlider, SIGNAL(valueChanged(int)), pSpin, SLOT(setValue(int)));
	QObject::connect(pSpin, SIGNAL(valueChanged(int)), pSlider, SLOT(setValue(int)));
	pSpin->setValue(35);

	QHBoxLayout * pLayout = new QHBoxLayout;
	pLayout->addWidget(pSpin);
	pLayout->addWidget(pSlider);
	pWidget->setLayout(pLayout);

	pWidget->show();
#elif 1
	/*
	 * QLabel
	 */
	QLabel label("Hello World");
	label.show();
#endif
	return a.exec();
}

