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
#include <string>
#include "displayWindow.h"
#include "RatingWindow.h"
#include "AllRatingWindow.h"
#include "../lib/Netflix.h"





class KeywordWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit KeywordWindow (QWidget* parent=NULL, Netflix *n=NULL);

    	

	public slots:
		void returnPressed();
		void ratingsPressed();
		void rentPressed();
		void deletePressed();
		void backPressed();
		void titlePressed();
		void keywordPressed();
		void actorPressed();
		void logOutPressed();
		void update();

	protected:

    void closeEvent(QCloseEvent *);

	private:

		QPushButton *returnMovie,*ratings , *rentMovie, *deleteQueue, *movieBack, *searchTitle, *searchKeyword, *searchActor, *logOut;
		QLineEdit *search;
		QLabel *currentMovie,*price, *movieQueue;

		Netflix *temp;
		Map<string,Movie*> *tempM;
		Map<string,User*> *tempU;
		
		displayWindow *l;
		RatingWindow * r;
		allRatingWindow *s;


};

#endif //KEYWORDWINDOWS_H
