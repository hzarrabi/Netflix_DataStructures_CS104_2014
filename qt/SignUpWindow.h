#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "../lib/Netflix.h"

class SignUpWindow : public QWidget
{
	
	Q_OBJECT

	public:
		SignUpWindow (QWidget* parent=NULL, Netflix *n=NULL);

	public slots:
		void add();
		void cancelPage();

	private:
		QPushButton *confirm, *cancel;
		QLineEdit *login, *password;
};

#endif
