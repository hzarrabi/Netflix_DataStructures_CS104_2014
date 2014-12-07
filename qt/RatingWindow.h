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

<<<<<<< HEAD
	/*	public slots:


		signals:
*/
=======
		public slots:


		signals:

>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a

		private:
			QPushButton *rateButton, *cancel;
			QLineEdit *rate; 
			QString title;//string that has the title

			Netflix *temp;
			Map<string,User*> *tempU;

			QLabel *everything;

			string movie;



};

<<<<<<< HEAD
#endif //RATINGWINDOW_H
=======
#endif //RATINGWINDOW_H
>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a
