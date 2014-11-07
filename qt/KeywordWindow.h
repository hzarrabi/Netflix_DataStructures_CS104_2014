#ifndef KEYWORDWINDOWS_H
#define KEYWORDWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class KeywordWindow : public QWidget
{
	
	Q_OBJECT

	public:
		KeywordWindow (QWidget *parent = NULL);

	private:
		
		QPushButton *returnMovie, *rentMovie, *deleteQueue, *movieBack, *searchTitle, *searchKeyword;
		QLineEdit *search;

};

#endif
