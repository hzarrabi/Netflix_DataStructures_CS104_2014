#include "SignUpWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>

SignUpWindow::SignUpWindow (QWidget *parent) : QWidget (parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	/*

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
	setLayout (mainLayout);*/

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
 	/*qbox->addWidget(rentMovie);//addind button to second layout
 	qbox->addWidget(deleteQueue);
 	qbox->addWidget(movieBack);*/

 	queueBox->setLayout(qbox);


 	//third group box for movie queue===================================================================
 	QGroupBox *searchBox= new QGroupBox(tr("Search for Movie"));//the second group box
 	searchTitle=new QPushButton("Search by &Title");
 	searchKeyword=new QPushButton("Search by &Keyword");
 	search = new QLineEdit;//place where they search for movie
 	QFormLayout *fl = new QFormLayout;
 	fl->addRow("&Search", search);//making that place

 	//adding things to layout
 	QVBoxLayout *sbox = new QVBoxLayout;
 	sbox->addLayout(fl);
 	sbox->addWidget(searchTitle);//addind button to second layout
 	sbox->addWidget(searchKeyword);//addind button to second layout
 	
 	searchBox->setLayout(sbox);


}

