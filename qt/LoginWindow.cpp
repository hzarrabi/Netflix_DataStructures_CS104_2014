#include "LoginWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>

LoginWindow::LoginWindow (QWidget *parent) : QWidget (parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	login = new QLineEdit;

	QFormLayout *fl = new QFormLayout;
	fl->addRow("User ID", login);

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	quitButton = new QPushButton ("&Quit"); // &(letter) underlines letter and if you do alt+(letter) it will click that button
	loginButton = new QPushButton("&Login");
	newUserButton= new QPushButton("&New User");
	buttonLayout->addWidget(loginButton);
	buttonLayout->addWidget(newUserButton);
	buttonLayout->addWidget(quitButton);


	QLabel* label=new QLabel("Welcome to CSCI 104-Flix");
	label->setAlignment(Qt::AlignCenter);

	mainLayout->addWidget (label);
	mainLayout->addLayout(fl);
	mainLayout->addLayout(buttonLayout);
	setLayout (mainLayout);



}

