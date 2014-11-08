#ifndef KEYWORDWINDOWS_H
#define KEYWORDWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>
#include "../lib/Netflix.h"


class KeywordWindow : public QWidget
{
	
	Q_OBJECT

	public:
		KeywordWindow (QWidget* parent=NULL, Netflix *n=NULL);

	public slots:
		void returnPressed();
		void rentPressed();
		void deletePressed();
		void backPressed();
		void titlePressed();
		void keywordPressed();
		void logOutPressed();

	private:

		QPushButton *returnMovie, *rentMovie, *deleteQueue, *movieBack, *searchTitle, *searchKeyword, *logOut;
		QLineEdit *search;
		Netflix *temp;
		QLabel *currentMovie, *movieQueue;


};

#endif
