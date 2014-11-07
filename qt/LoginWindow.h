#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class LoginWindow : public QWidget
{
	
	Q_OBJECT

	public:
		LoginWindow (QWidget *parent = NULL);

	private:
		QPushButton *quitButton, *loginButton, *newUserButton;
		QLineEdit *login;//this is the text area that takes in the loginID

};

#endif
