#include <QApplication>
#include <QtGui>
#include <cstdlib>
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
	
	this->page2=new Page2;
	this->mainForm->addPage("打开",page2);

	this->createMenu();
	this->mainForm->setCurrentPage(0);
	this->setLayout(mainlayout);
}
void mainWindow::createMenu()
{
	aboutAction=new QAction("关于(&A)",this);
	aboutAction->setStatusTip("查看Word2Brain关于");
	connect(aboutAction,SIGNAL(triggered()),this,SLOT(callAbout()));
	this->mainForm->menuObject()->addAction(aboutAction);
	exitAction=new QAction("退出(&Q)",this);
	exitAction->setShortcut(QKeySequence::Quit);
	exitAction->setStatusTip("退出Word2Brain");
	connect(exitAction,SIGNAL(triggered()),this,SLOT(callQuit()));
	this->mainForm->menuObject()->addAction(exitAction);
}

void mainWindow::callAbout()
{
	QString aboutTitle="关于Word2Brain";

	QString aboutComment="<p>Word2Brain ";
	aboutComment+=VERSION;
	aboutComment+=" Copyright (C) Michael Lin <linmx0130@gmail.com></p>\
			<p>Word2Brain是能帮你记住单词的好工具！</p>\
			<p>这个软件是自由软件，在GPLv3授权下发布。该软件不带有任何<br/>\
			使用担保，如果想了解更多，您可以在如下网站获得本程序源代码：</p>\
			<p><a href='https://github.com/linmx0130/Word2Brain'>https://github.com/linmx0130/Word2Brain</a></p>";
	QMessageBox::about(this,aboutTitle,aboutComment);
}
void mainWindow::callQuit()
{
	//maybe I should try to show a dialog in the future.
	exit(EXIT_SUCCESS);
}
