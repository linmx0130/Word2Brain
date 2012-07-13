#ifndef PAGE2
#define PAGE2

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
class Page2
	:public QWidget
{
	Q_OBJECT
	private:
		QPushButton *loadWordlistButton,*loadTrainButton;
		QLabel *loadWordlistLabel,*loadTrainLabel;
		QVBoxLayout *loadWordlistLayout,*loadTrainLayout;
		QHBoxLayout *mainLayout;
	public:
		Page2(QWidget *parent=0);
};

#endif
