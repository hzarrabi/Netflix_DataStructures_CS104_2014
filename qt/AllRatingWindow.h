#ifndef ALLRATINGWINDOW_H
#define ALLRATINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QWidget>
#include <QGroupBox>
#include <QDialog>
#include <QCloseEvent>
#include <QtGui>
#include <QDebug>
#include "RatingWindow.h"

#include "../lib/Netflix.h"



class allRatingWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit allRatingWindow (QWidget* parent=NULL,  Netflix *n=NULL);


	protected:

	    void closeEvent(QCloseEvent *);

	public slots:
		void nextClicked();
		void rateClicked();
		void adjustClicked();


	private:
		QPushButton *next,*adjust, *cancel; 
		QLabel *movieTitle, *rating;
		QString title;//string that has the title
		QString rate;//string that has the keywords

		Netflix *temp;
		Map<string,User*> *tempU;
		User* curUser;
		Map<Movie*, int> *fml;

		int nexts;

		RatingWindow *w;

		Map<Movie*,int>::Iterator firstIt;

};

#endif //DISPLAYWINDOW_H