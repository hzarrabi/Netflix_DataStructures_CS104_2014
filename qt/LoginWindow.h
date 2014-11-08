#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <iostream>


#include "KeywordWindow.h"
#include "NewUserWindow.h"
#include "../lib/Netflix.h"



class LoginWindow : public QWidget
{
	
	Q_OBJECT

	public:
		LoginWindow (QWidget* parent=NULL, Netflix *n=NULL);
		Map<string,Movie*> *tempM;
		Map<string,User*> *tempU;

	public slots:
		void loggedIn();
		void newUser();
		void quitPushed();


	private:
		QPushButton *quitButton, *loginButton, *newUserButton;
		QLineEdit *login;//this is the text area that takes in the loginID
		Netflix *temp;
		KeywordWindow *w;
		Dialog *mDialog;
};

#endif
