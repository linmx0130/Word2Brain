/*
 Copyright (c) 2012 Sweetdumplings <linmx0130@163.com>
 All rights reserved.
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/

#ifndef PQMENUTABWIDGET_H
#define PQMENUTABWIDGET_H

#include <QPushButton>
#include <QMenu>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QButtonGroup>
class pQMenuTabWidget;
class pQMenuTabItem:public QObject
{
	Q_OBJECT
	private:
		QPushButton *__button;
		QWidget *__page;
		pQMenuTabWidget *parent;
	public slots:
		void button_clicked();
	public:
		pQMenuTabItem();
		void setButton(QPushButton *button);
		void setPage(QWidget *page);
		QPushButton *button();
		QWidget *page();
		void setParent(pQMenuTabWidget*);
};
class pQMenuTabWidget:public QWidget
{
	Q_OBJECT
	private:
		QVBoxLayout *mainlayout;
		QHBoxLayout *buttonbar;
		QStackedLayout *view;
		QPushButton *menubutton;
		QMenu *menu;
		QButtonGroup *buttongroup;
		QList <pQMenuTabItem*> *item_list;
		bool clicked;
	signals:
		void currentChanged(int index);
		void menuAboutToShow();
		void menuAboutToHide();
	public slots:
		void setCurrentPage(int page_num);
		void setCurrentButton(QPushButton *button);
		void setMenuButtonText(const QString & text);
	public:
		pQMenuTabWidget(QWidget *parent=0);
		void addMenuTabItem(pQMenuTabItem *item);
		void addPage(const QString &text,QWidget *page);
		void removeMenuTabItem(pQMenuTabItem *item);
		void removePage(QWidget *page);
		pQMenuTabItem* itemAt(int pos);
		QMenu *menuObject();
		QPushButton *menuButton();
};

#endif
