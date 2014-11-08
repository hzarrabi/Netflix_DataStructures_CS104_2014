#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "KeywordWindow.h"
#include "SignUpWindow.h"
#include "../lib/Netflix.h"



class displayWindow : public QWidget
{
	
	Q_OBJECT

	public:
		displayWindow (string movie, Netflix *n=NULL);

	public slots:
		void nextM();
		void addM();
		void returnToMenu();


	private:
		QPushButton *next, *add, *returnM; 
		Netflix *temp;
		QLabel *movieTitle, keywords;

};

#endif