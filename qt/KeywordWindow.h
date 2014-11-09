#ifndef KEYWORDWINDOWS_H
#define KEYWORDWINDOWS_H

#include <QDialog>
#include <QCloseEvent>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QtGui>
#include "displayWindow.h"
#include "../lib/Netflix.h"





class KeywordWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit KeywordWindow (QWidget* parent=NULL, Netflix *n=NULL);

    	

	public slots:
		void returnPressed();
		void rentPressed();
		void deletePressed();
		void backPressed();
		void titlePressed();
		void keywordPressed();
		void logOutPressed();

	protected:

    void closeEvent(QCloseEvent *);

	private:

		QPushButton *returnMovie, *rentMovie, *deleteQueue, *movieBack, *searchTitle, *searchKeyword, *logOut;
		QLineEdit *search;
		QLabel *currentMovie, *movieQueue;

		Netflix *temp;
		Map<string,Movie*> *tempM;
		Map<string,User*> *tempU;
		//displayWindow *l;


};

#endif //KEYWORDWINDOWS_H
