#include <QApplication>
#include <QtGui>
#include "mainWindow.h"
#include "../plusQL/MenuTabWidget/pQMenuTabWidget.h"
#include "Page1/Page1.h"

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));	
	mainWindow *win=new mainWindow;
	win->show();
	return app.exec();
}

mainWindow::mainWindow(QWidget *parent)
	:QWidget(parent)
{
	this->mainForm=new pQMenuTabWidget;
	this->mainlayout=new QVBoxLayout;
	mainlayout->addWidget(this->mainForm);
	this->mainForm->setMenuButtonText(QString("菜单"));

	this->page1=new Page1;
	this->mainForm->addPage("新建",page1);
	this->mainForm->setCurrentPage(0);

	this->setLayout(mainlayout);
}
