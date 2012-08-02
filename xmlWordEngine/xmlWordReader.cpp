#include <QtXml>
#include <QtGui>
#include <iostream>
#include "xmlWordEngine.h"
xmlWordReader::xmlWordReader()
{
	//now it is empty
}

bool xmlWordReader::readFile(const QString &filename)
{
	QFile file(filename);
	if (!file.open(QFile::ReadOnly|QFile::Text))
	{
		std::cerr <<"Error: Cannot read file "<< qPrintable(filename)<<": " <<qPrintable(file.errorString())<<std::endl;
		return false;
	}
	reader.setDevice(&file);
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isStartElement())
		{
			if (reader.name()=="W2BV1")
			{
				readW2BV1();
			}
			else 
			{
				reader.raiseError("Not a W2BV1 file.");
			}
		}else 
		{
			reader.readNext();
		}
	}
	file.close();
	if (reader.hasError())
	{
		std::cerr<< "Error while parse file." <<std::endl;
		return false;
	}
	if (file.error()!=QFile::NoError)
	{
		std::cerr<<"Error while reading file." <<std::endl;
		return false;
	}
	return true;
}
void xmlWordReader::readW2BV1()
{
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement())
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement())
		{ 
			if (reader.name()=="WN")
			{
				readWordNode();
			}
			else 
			{
				reader.raiseError("Wrong W2BV1 file.");
				return;
			}
		}else 
		{
			reader.readNext();
		}
	}
}
void xmlWordReader::readWordNode()
{
	wordNode t;
	int getIndex=0;
	while (!reader.atEnd())
	{
		reader.readNext();
		if (reader.isEndElement())
		{
			if (reader.name()=="WN") 
			{
				this->wordlist.push_back(t);
				reader.readNext();
				return;
			}
			else
			{
				reader.readNext();
			}
		}
		if (reader.isStartElement())
		{
			getIndex++;
			if (reader.name()=="Word")
			{
				t.word=reader.readElementText();
			}
			else if (reader.name()=="Mean")
			{
				t.mean=reader.readElementText();
			}
			else reader.raiseError("Wrong W2BV1 file.");
		}
		if (getIndex>2) reader.raiseError("Wrong W2BV1 file.");
	}
}
