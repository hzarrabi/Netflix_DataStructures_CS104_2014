#include "LoginWindow.h"

using namespace std;

LoginWindow::LoginWindow (QWidget* parent, Netflix *n) : QWidget (parent)
{
	temp=n;

	tempM=n->returnMovieMap();
	tempU=n->returnUserMap();

	QVBoxLayout *mainLayout = new QVBoxLayout;

	login = new QLineEdit;
	password=new QLineEdit;

	QFormLayout *fl = new QFormLayout;
	fl->addRow("User ID", login);
	fl->addRow("Password", password);

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

	connect(login, SIGNAL(returnPressed()),loginButton,SIGNAL(clicked()));//when they press enter
}


void LoginWindow::loggedIn()
{
	string userID = login->text().toStdString();//making qlineEdit into string
	string aPassword=password->text().toStdString();
	cout<<tempU->get(userID)->getPassword()<<endl;
	cout<<sha256(aPassword)<<endl;
	if(tempU->keyExist(userID) && tempU->get(userID)->getPassword()== sha256(aPassword))
	{
		temp->setLogginID(userID);
		w=new KeywordWindow(this,temp);
  		w->show();
  		login->clear();//clears the user ID

	}
}

void LoginWindow::newUser()
{
  		mDialog = new Dialog(this,temp);
		mDialog->show();
		login->clear();
}

void LoginWindow::quitPushed()
{
	temp->writeFile();//write to file when we exit
	close();
}


void LoginWindow::closeEvent (QCloseEvent *event)
{
	temp->writeFile();//write to file when we exit
	close();
}
