#include "NewUserWindow.h"


Dialog::Dialog(QWidget *parent, Netflix *n) : QDialog(parent)//,ui(new Ui::Dialog)
{
    //ui->setupUi(this);
    parentWidget()->hide();

    tempM=n->returnMovieMap();
	tempU=n->returnUserMap();

	QVBoxLayout *mainLayout = new QVBoxLayout;

	login = new QLineEdit;
	password= new QLineEdit;

	QFormLayout *fl = new QFormLayout;
	fl->addRow("&User ID", login);
	fl->addRow("&Name", password);

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	confirm = new QPushButton ("Confir&m"); // &(letter) underlines letter and if you do alt+(letter) it will click that button
	cancel = new QPushButton("&Cancel");
	buttonLayout->addWidget(confirm);
	buttonLayout->addWidget(cancel);


	QLabel* label=new QLabel("Please sign up for CSCI 104-Flix");
	label->setAlignment(Qt::AlignCenter);

	mainLayout->addWidget (label);
	mainLayout->addLayout(fl);
	mainLayout->addLayout(buttonLayout);
	setLayout (mainLayout);

	connect(confirm,SIGNAL(clicked()),this,SLOT(add()));	
	connect(cancel,SIGNAL(clicked()),this,SLOT(cancelPage()));

}

Dialog::~Dialog()
{

}


//closeEvent
void Dialog::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}

void Dialog::add()
{
	string userID = login->text().toStdString();//making qlineEdit into string
	string userName = password->text().toStdString();//making qlineEdit into string
	if(tempU->keyExist(userID)||userName=="")
	{
		  QWidget *popup = new QWidget();
      	  popup->show();
	}
	else
	{
		User *tempUser=new User(userID,userName);
		tempU->add(userID,tempUser);
		close();
	}

}

void Dialog::cancelPage()
{
	close();
}