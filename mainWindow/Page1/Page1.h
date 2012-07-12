#ifndef PAGE1
#define PAGE1
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class Page1
	:public QWidget
{
private:
	QVBoxLayout *newWordlistLayout,*newTrainLayout;
	QHBoxLayout *mainLayout;
	QPushButton *newWordlistButton,*newTrainButton;
	QLabel *newWordlistLabel,*newTrainLabel;
public:
	Page1(QWidget *parent=0);
};

#endif
