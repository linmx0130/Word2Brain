#include "Page2.h"
#include <QtGui>

Page2::Page2(QWidget *parent)
	:QWidget(parent)
{
	this->loadWordlistButton=new QPushButton("打开单词表");
	this->loadWordlistLabel=new QLabel("打开单词表文件并进<br/>行编辑、添加或删<br/>除单词");
	this->loadWordlistLayout=new QVBoxLayout;
	this->loadWordlistLayout->addWidget(this->loadWordlistButton);
	this->loadWordlistLayout->addWidget(this->loadWordlistLabel);

	this->loadTrainButton=new QPushButton("打开训练");
	this->loadTrainLabel=new QLabel("打开已有训练文件<br/>并进行设置，并<br/>继续训练进程");
	this->loadTrainLayout=new QVBoxLayout;
	this->loadTrainLayout->addWidget(this->loadTrainButton);
	this->loadTrainLayout->addWidget(this->loadTrainLabel);

	this->mainLayout=new QHBoxLayout;
	this->mainLayout->addLayout(this->loadWordlistLayout);
	this->mainLayout->addLayout(this->loadTrainLayout);

	this->setLayout(this->mainLayout);
	
}
