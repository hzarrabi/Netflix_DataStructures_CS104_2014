#include "RatingWindow.h"



<<<<<<< HEAD
RatingWindow::RatingWindow(QWidget* parent, string movie, Netflix *n): QDialog (parent)
{
	cout<<"gooz1"<<endl;
	parentWidget()->hide();//hides the main login window




=======
RatingWindow::RatingWindow(QWidget* parent, string movie, Netflix *n)
{
	parentWidget()->hide();//hides the main login window

>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a
	this->movie=movie;
	temp= n;
	tempU=n->returnUserMap();

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	rateButton=new QPushButton("&Rate");
	cancel=new QPushButton("&Cancel");
	buttonLayout->addWidget(rateButton);
	buttonLayout->addWidget(cancel);

	QLabel* label=new QLabel("Rate: "+QString::fromStdString(movie)+ " (from 1-worst to 5-best).");
	label->setAlignment(Qt::AlignCenter);

<<<<<<< HEAD
	rate = new QLineEdit;//place where they search for movie
	QFormLayout *fl = new QFormLayout;
	cout<<"gooad4113asgaz"<<endl;
=======
	QFormLayout *fl = new QFormLayout;
>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a
	fl->addRow("Rate", rate);


	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget (label);
	mainLayout->addLayout(fl);
	mainLayout->addLayout(buttonLayout);

<<<<<<< HEAD


	setLayout (mainLayout);



=======
	setLayout (mainLayout);


>>>>>>> 87e48091298b8488cd29655c0d91f2bde374d47a
	//TODO the signals

}

void RatingWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}