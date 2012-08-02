#include <iostream>
#include <QtCore>
#include "xmlWordEngine.h"
xmlWordReader xmr;
int main()
{
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));	

	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	xmr.readFile("example.xml");
	for (int i=0;i<xmr.wordlist.size();++i) std::cout<<qPrintable(xmr.wordlist[i].word)<<std::endl
			<<qPrintable(xmr.wordlist[i].mean)<<std::endl;
}
