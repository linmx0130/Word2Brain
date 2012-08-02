#ifndef XMLWORDENGINE_H
#define XMLWORDENGINE_H

#include <QXmlStreamReader>
#include <QString>
#include <vector>

struct wordNode
{
	QString word,mean;
};
class xmlWordReader
{
private:
	QXmlStreamReader reader;
	void readW2BV1();
	void readWordNode();
public:
	xmlWordReader();
	bool readFile(const QString &filename);
	std::vector<wordNode> wordlist;
};

#endif
