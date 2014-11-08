#include "KeywordWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
 #include <QtGui>

KeywordWindow::KeywordWindow (QWidget* parent, Netflix *n) : QWidget (parent)
{

	temp=n;

	QVBoxLayout *mainLayout = new QVBoxLayout;


	//first group box for returning the movie========================================================
 	QGroupBox *returnBox= new QGroupBox(tr("Your Current Movie"));//the first group box
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	returnMovie=new QPushButton("&Return Movie");
 	buttonLayout->addWidget(returnMovie);

 	string gooz=n->currentMovie();
 	QString qstr = QString::fromStdString(gooz);


 	QVBoxLayout *rbox = new QVBoxLayout;
 	rbox->addWidget(currentMovie=new QLabel(qstr));//adding qlabel to the first layou
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


 	string antar=n->returnFrontQ();
 	QString qstr2=QString::fromStdString(antar);

 	QVBoxLayout *qbox = new QVBoxLayout;
 	qbox->addWidget(movieQueue=new QLabel(qstr2));//adding qlabel to the first layou
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

 	string ID=n->getID();
 	string name=n->currentName();
 	string total="Welcome to CSCI 104-Flix, "+name+" "+"("+ID+")";
 	QString qstr1 = QString::fromStdString(total);


	QLabel* label=new QLabel(qstr1);
	label->setAlignment(Qt::AlignCenter);
 	
	logOut=new QPushButton("Log&out");

 	mainLayout->addWidget (label);
	mainLayout->addWidget(returnBox);
	mainLayout->addWidget(queueBox);
	mainLayout->addWidget(searchBox);
	mainLayout->addWidget(logOut);

	setLayout (mainLayout);


	connect(returnMovie,SIGNAL(clicked()),this,SLOT(returnPressed()));	
	connect(rentMovie,SIGNAL(clicked()),this,SLOT(rentPressed()));
	connect(deleteQueue,SIGNAL(clicked()),this,SLOT(deletePressed()));
	connect(movieBack,SIGNAL(clicked()),this,SLOT(backPressed()));
	connect(searchTitle,SIGNAL(clicked()),this,SLOT(titlePressed()));
	connect(searchKeyword,SIGNAL(clicked()),this,SLOT(keywordPressed()));
	connect(logOut,SIGNAL(clicked()),this,SLOT(logOutPressed()));





}



void KeywordWindow::returnPressed()
{
	if(temp->returnMovie()==false)
	{

	}

	else
	{
		returnMovie->setEnabled(false);
		currentMovie->setText("");
	}
}
void KeywordWindow::rentPressed()
{
	if(temp->qEmpty())//if queue is empty 
	{
		rentMovie->setEnabled(false);//makes its button grey
	}
	else//if queue is not empty
	{
		if(temp->returnMovie()==false)//if there is no movie rented 
		{
			string antar1=temp->returnFrontQ();
 			QString qstr2=QString::fromStdString(antar1);
			currentMovie->setText(qstr2);//sets the current rented movie to front of queue

		}

		else//there is a movie rented
		{

		}

	}

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
