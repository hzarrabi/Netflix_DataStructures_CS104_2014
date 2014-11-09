#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

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

#include "../lib/Netflix.h"



class displayWindow : public QDialog
{
	
	Q_OBJECT

	public:
		explicit displayWindow (QWidget* parent=NULL, string movie="", Netflix *n=NULL);


	protected:

	    void closeEvent(QCloseEvent *);

	public slots:
		void nextM();
		void addM();
		void returnToMenu();


	private:
		QPushButton *next, *add, *returnM; 
		QLabel *movieTitle, *allkeywords;
		QString title;//string that has the title
		QString keywords;//string that has the keywords

		Netflix *temp;
		Map<string,Movie*> *tempM;
		Map<string,User*> *tempU;

		QLabel *everything;

};

#endif //DISPLAYWINDOW_H