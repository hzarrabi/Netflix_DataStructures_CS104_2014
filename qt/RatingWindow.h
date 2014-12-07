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

#include "../lib/Netflix.h"


class RatingWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit RatingWindow (QWidget* parent=NULL, string movie="", Netflix *n=NULL);


	protected:

		void closeEvent(QCloseEvent *);

	/*	public slots:


		signals:
*/

		private:
			QPushButton *rateButton, *cancel;
			QLineEdit *rate; 
			QString title;//string that has the title

			Netflix *temp;
			Map<string,User*> *tempU;

			QLabel *everything;

			string movie;



};

#endif //RATINGWINDOW_H