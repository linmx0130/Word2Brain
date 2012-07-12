#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../plusQL/MenuTabWidget/pQMenuTabWidget.h"
#include "Page1/Page1.h"
#include <QAction>
#define VERSION "0.0.1"
class mainWindow
	:public QWidget
{
	Q_OBJECT
	private:
		pQMenuTabWidget *mainForm;
		QVBoxLayout *mainlayout;
		Page1 *page1;
		QAction *aboutAction,*exitAction;
		void createMenu();
	private slots:
		void callAbout();
	public:
		mainWindow(QWidget *parent=0);
};
#endif
