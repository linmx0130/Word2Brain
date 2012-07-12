#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../plusQL/MenuTabWidget/pQMenuTabWidget.h"
#include "Page1/Page1.h"
class mainWindow
	:public QWidget
{
	Q_OBJECT
	private:
		pQMenuTabWidget *mainForm;
		QVBoxLayout *mainlayout;
		Page1 *page1;
	public:
		mainWindow(QWidget *parent=0);
};
#endif
