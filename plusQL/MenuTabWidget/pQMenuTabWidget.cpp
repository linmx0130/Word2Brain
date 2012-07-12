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
#include <QtGui>
#include "pQMenuTabWidget.h"
// -*- pQMenuTabItem code 
void pQMenuTabItem::setButton(QPushButton *button)
{
	this->__button=button;
}
void pQMenuTabItem::setPage(QWidget *page)
{
	this->__page=page;
}
QPushButton *pQMenuTabItem::button()
{
	return this->__button;
}
QWidget *pQMenuTabItem::page()
{
	return this->__page;
}
void pQMenuTabItem::button_clicked()
{
	parent->setCurrentButton(this->__button);
}
pQMenuTabItem::pQMenuTabItem()
{
	this->parent=0;
}
void pQMenuTabItem::setParent(pQMenuTabWidget *parent)
{
	this->parent=parent;
}
// -*- pQMenuTabItem code 

pQMenuTabWidget::pQMenuTabWidget(QWidget *parent)
	:QWidget(parent)
{
	this->mainlayout=new QVBoxLayout;
	this->buttonbar=new QHBoxLayout;
	this->view=new QStackedLayout;
	this->menubutton=new QPushButton;
	this->menu=new QMenu;
	QSizePolicy button_size_policy(QSizePolicy::Fixed,QSizePolicy::Fixed);
	this->menubutton->setSizePolicy(button_size_policy);
	this->item_list=new QList<pQMenuTabItem*>;
	this->buttongroup=new QButtonGroup;

	this->menubutton->setMenu(this->menu);
	this->buttonbar->addWidget(this->menubutton);
	this->buttonbar->addStretch();
	this->buttonbar->setSpacing(0);
	mainlayout->addLayout(buttonbar);
	mainlayout->addLayout(view);
	
	connect(this->menu,SIGNAL(aboutToShow()),
			this,SIGNAL(menuAboutToShow()));
	connect(this->menu,SIGNAL(aboutToHide()),
			this,SIGNAL(menuAboutToHide()));
	this->setLayout(mainlayout);
};

void pQMenuTabWidget::addMenuTabItem(pQMenuTabItem *item)
{
	QSizePolicy button_size_policy(QSizePolicy::Fixed,QSizePolicy::Fixed);
	this->setSizePolicy(button_size_policy);
	item->button()->setSizePolicy(button_size_policy);
	item->button()->setCheckable(true);
	//item->button()->setToggleType(QButton::Toggle);
	item->setParent(this);
	this->item_list->push_back(item);
	
	connect(item->button(),SIGNAL(clicked()),item,SLOT(button_clicked()));
	this->buttongroup->addButton(item->button());
	this->buttonbar->insertWidget(buttonbar->count()-1,item->button());
	this->view->addWidget(item->page());
}
void pQMenuTabWidget::addPage(const QString &text,QWidget *page)
{
	pQMenuTabItem *newitem=new pQMenuTabItem;
	QPushButton *new_button=new QPushButton(text);
	newitem->setButton(new_button);
	newitem->setPage(page);
	this->addMenuTabItem(newitem);
}
void pQMenuTabWidget::setMenuButtonText(const QString &text)
{
	this->menubutton->setText(text);
}
QMenu *pQMenuTabWidget::menuObject()
{
	return this->menu;
}
void pQMenuTabWidget::setCurrentPage(int page_num)
{
	this->view->setCurrentIndex(page_num);
	if (!this->item_list->operator[](page_num)->button()->isChecked()){
		this->item_list->operator[](page_num)->button()->setChecked(true);
	}
	emit currentChanged(page_num);
}
//setCurrentButton is based on setCurrentPage
void pQMenuTabWidget::setCurrentButton(QPushButton *button)
{
	QList<pQMenuTabItem*> list_c=*(this->item_list);
	QList<pQMenuTabItem*>::const_iterator i=list_c.begin();
	for(int now=0;i!=list_c.end();now++,i++){
		if (button==((*i)->button())){
			this->setCurrentPage(now);
			break;
		}
	}
}
QPushButton* pQMenuTabWidget::menuButton(){
	return this->menubutton;
}
//Attention: you need to delete the button and the page yourself only when
//you use removeMenuTabItem. Other remove functions are based on it.
void pQMenuTabWidget::removeMenuTabItem(pQMenuTabItem *item){
	this->buttonbar->removeWidget(item->button());
	this->buttongroup->removeButton(item->button());
	this->view->removeWidget(item->page());
	this->item_list->removeAll(item);
}
pQMenuTabItem* pQMenuTabWidget::itemAt(int pos){
	return this->item_list->operator[](pos);
}
void pQMenuTabWidget::removePage(QWidget *page){
	QList<pQMenuTabItem*> list_c=*(this->item_list);
	QList<pQMenuTabItem*>::const_iterator i=list_c.begin();
	for(int now=0;i!=list_c.end();now++,i++){
		if (page==((*i)->page())){
			this->removeMenuTabItem(*i);
			delete (*i)->button();
			delete (*i)->page();
			break;
		}
	}
}
