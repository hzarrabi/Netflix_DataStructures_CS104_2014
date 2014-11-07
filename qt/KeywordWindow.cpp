#include "KeywordWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
 #include <QtGui>

KeywordWindow::KeywordWindow (QWidget* parent, Netflix *n) : QWidget (parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;


	//first group box for returning the movie========================================================
 	QGroupBox *returnBox= new QGroupBox(tr("Your Current Movie"));//the first group box
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	returnMovie=new QPushButton("&Return Movie");
 	buttonLayout->addWidget(returnMovie);

 	QVBoxLayout *rbox = new QVBoxLayout;
 	rbox->addWidget(new QLabel("Citizen Kane"));//adding qlabel to the first layou
 	rbox->addLayout(buttonLayout);//addind button to first layout

 	returnBox->setLayout(rbox);

 	//second group box for movie queue================================================================
 	QGroupBox *queueBox= new QGroupBox(tr("Your Movie Queue"));//the second group box
 	QHBoxLayout *buttonLayout1 = new QHBoxLayout;
 	rentMovie=new QPushButton("R&ent Movie");
 	deleteQueue=new QPushButton("&Delete from Queue");
 	movieBack=new QPushButton("Movie to &Back of Queue");
 	buttonLayout1->addWidget(rentMovie);
 	buttonLayout1->addWidget(deleteQueue);
 	buttonLayout1->addWidget(movieBack);


 	QVBoxLayout *qbox = new QVBoxLayout;
 	qbox->addWidget(new QLabel("Front Queue: Modern Times"));//adding qlabel to the first layou
 	qbox->addLayout(buttonLayout1);


 	queueBox->setLayout(qbox);


 	//third group box for movie queue===================================================================
 	QGroupBox *searchBox= new QGroupBox(tr("Search for Movie"));//the second group box
 	searchTitle=new QPushButton("Search by &Title");
 	searchKeyword=new QPushButton("Search by &Keyword");
 	QHBoxLayout *buttonLayout2 = new QHBoxLayout;
 	buttonLayout2->addWidget(searchTitle);
 	buttonLayout2->addWidget(searchKeyword);

 	search = new QLineEdit;//place where they search for movie
 	QFormLayout *fl = new QFormLayout;
 	fl->addRow("&Search", search);//making that place

 	//adding things to layout
 	QVBoxLayout *sbox = new QVBoxLayout;
 	sbox->addLayout(fl);
 	sbox->addLayout(buttonLayout2);//addind button to third layout
 	
 	searchBox->setLayout(sbox);


 	//=======adding everything to the main layout===================================================

	QLabel* label=new QLabel("Welcome to CSCI 104-Flix, David Kempe (dkempe)");
	label->setAlignment(Qt::AlignCenter);
 	
	logOut=new QPushButton("Log&out");

 	mainLayout->addWidget (label);
	mainLayout->addWidget(returnBox);
	mainLayout->addWidget(queueBox);
	mainLayout->addWidget(searchBox);
	mainLayout->addWidget(logOut);

	setLayout (mainLayout);


	connect(returnMovie,SIGNAL(clicked()),this,SLOT(returnPressed()));	
	connect(rentMovie,SIGNAL(clicked()),this,SLOT(returnPressed()));
	connect(deleteQueue,SIGNAL(clicked()),this,SLOT(deletePressed()));
	connect(movieBack,SIGNAL(clicked()),this,SLOT(backPressed()));
	connect(searchTitle,SIGNAL(clicked()),this,SLOT(titlePressed()));
	connect(searchKeyword,SIGNAL(clicked()),this,SLOT(keywordPressed()));
	connect(logOut,SIGNAL(clicked()),this,SLOT(logOutPressed()));





}



void KeywordWindow::returnPressed()
{

}
void KeywordWindow::rentPressed()
{

}
void KeywordWindow::deletePressed()
{

}
void KeywordWindow::backPressed()
{

}
void KeywordWindow::titlePressed()
{

}
void KeywordWindow::keywordPressed()
{

}
void KeywordWindow::logOutPressed()
{

}

