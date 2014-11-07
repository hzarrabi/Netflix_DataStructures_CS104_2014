#ifndef KEYWORDWINDOWS_H
#define KEYWORDWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>

class KeywordWindow : public QWidget
{
	
	Q_OBJECT

	public:
		KeywordWindow (QWidget *parent = NULL);

	private:

		QPushButton *returnMovie, *rentMovie, *deleteQueue, *movieBack, *searchTitle, *searchKeyword, *logOut;
		QLineEdit *search;

};

#endif
