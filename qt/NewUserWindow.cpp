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
	thePassword= new QLineEdit;
	address=new QLineEdit;
	CC=new QLineEdit;


	QFormLayout *fl = new QFormLayout;
	fl->addRow("&User ID", login);
	fl->addRow("&Name", password);
	fl->addRow("&Password", thePassword);
	fl->addRow("&Address", address);
	fl->addRow("&Credit Card #", CC);




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

	connect(password, SIGNAL(returnPressed()),confirm,SIGNAL(clicked()));

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
	string actualPassword=thePassword->text().toStdString();//making qlineEdit into string
	string actualAdress=address->text().toStdString();//making qlineEdit into string
	string actualCC=CC->text().toStdString();//making qlineEdit into string
	
	if(tempU->keyExist(userID)||userName==""||userID=="" || actualPassword=="" || actualAdress=="" || actualCC==""  )
	{

	}
	else
	{
		actualPassword=sha256(actualPassword);
		int gooz=atoi( actualCC.c_str() );
		User *tempUser=new User(userID,userName,actualPassword,actualAdress,gooz,0);
		tempU->add(userID,tempUser);
		close();
	}

}

void Dialog::cancelPage()
{
	close();
}