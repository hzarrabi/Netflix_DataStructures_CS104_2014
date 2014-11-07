#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class SignUpWindow : public QWidget
{
	
	Q_OBJECT

	public:
		SignUpWindow (QWidget *parent = NULL);

	private:
		QPushButton *confirm, *cancel;
		QLineEdit *login, *password;

};

#endif
