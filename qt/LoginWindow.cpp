#include "LoginWindow.h"
#include "KeywordWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <iostream>

using namespace std;

LoginWindow::LoginWindow (QWidget* parent, Netflix *n) : QWidget (parent)
{
	temp=n;

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

	connect(loginButton,SIGNAL(clicked()),this,SLOT(loggedIn()));	
	connect(newUserButton,SIGNAL(clicked()),this,SLOT(newUser()));
	connect(quitButton,SIGNAL(clicked()),this,SLOT(quitPushed()));
}


void LoginWindow::loggedIn()
{
	string userID = login->text().toStdString();//making qlineEdit into string
	if(temp->userExists(userID))
	{
		w=new KeywordWindow(NULL,temp);
  		w->show();
  		this->hide();
	}
}

void LoginWindow::newUser()
{
	cout<<"loggin windows"<<endl;
}

void LoginWindow::quitPushed()
{
	close();
}
