#ifndef RATINGWINDOWS_H
#define RATINGWINDOWS_H

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
#include <QMessageBox>

#include "../lib/Netflix.h"


class RatingWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit RatingWindow (QWidget* parent=NULL, string movie="", Movie * m=NULL , Netflix *n=NULL, bool rated=true);


	protected:

		void closeEvent(QCloseEvent *);

		public slots:
			void ratePressed();
			void cancelPressed();

		signals:


		private:
			QPushButton *rateButton, *cancel;
			QLineEdit *rate; 
			QString title;//string that has the title
			QMessageBox *msgBox;

			Netflix *temp;
			User *idiot;
			Map<string,User*> *tempU;
			Movie *theMovie;
			User* theUser;

			QLabel *everything;

			string movie;
			bool rated;



};


#endif //RATINGWINDOW_H

