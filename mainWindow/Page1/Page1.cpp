#include "Page1.h"
#include <QtGui>
Page1::Page1(QWidget *parent)
	:QWidget(parent)	
{
	newWordlistButton=new QPushButton("新建单词表");
	newWordlistLabel=new QLabel("在建立新的训练之<br/>前，您需要新建一<br/>个单词表，记录您<br/>所希望测试练习到<br/>的单词。");
	newWordlistLayout=new QVBoxLayout;
	newWordlistLayout->addWidget(newWordlistButton);
	newWordlistLayout->addWidget(newWordlistLabel);

	newTrainButton=new QPushButton("新建训练");
	newTrainLabel=new QLabel("您可以根据已有的<br>单词表建立一个背<br/>单词训练，设置训<br/>练的细节。");
	newTrainLayout=new QVBoxLayout;
	newTrainLayout->addWidget(newTrainButton);
	newTrainLayout->addWidget(newTrainLabel);
	
	mainLayout=new QHBoxLayout;
	mainLayout->addLayout(newWordlistLayout);
	mainLayout->addLayout(newTrainLayout);

	this->setLayout(mainLayout);

}
