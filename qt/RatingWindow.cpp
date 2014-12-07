#include "RatingWindow.h"



RatingWindow::RatingWindow(QWidget* parent, string movie, Movie * m, Netflix *n): QDialog (parent)
{
	cout<<"gooz1"<<endl;
	parentWidget()->hide();//hides the main login window

	this->movie=movie;
	theMovie=m;
	temp= n;
	tempU=n->returnUserMap();
	theUser=tempU->get(temp->getID());


	QHBoxLayout *buttonLayout = new QHBoxLayout;
	rateButton=new QPushButton("&Rate");
	cancel=new QPushButton("&Cancel");
	buttonLayout->addWidget(rateButton);
	buttonLayout->addWidget(cancel);

	QLabel* label=new QLabel("Rate: "+QString::fromStdString(movie)+ " (from 1-worst to 5-best).");
	label->setAlignment(Qt::AlignCenter);


	rate = new QLineEdit;//place where they search for movie
	QFormLayout *fl = new QFormLayout;
	cout<<"gooad4113asgaz"<<endl;

	fl->addRow("Rate", rate);


	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget (label);
	mainLayout->addLayout(fl);
	mainLayout->addLayout(buttonLayout);

	setLayout (mainLayout);



	connect(rateButton,SIGNAL(clicked()),this,SLOT(ratePressed()));	



}


void RatingWindow::ratePressed()
{
	int rating = rate->text().toInt();//making qlineEdit into string
	
	if(rating == 1 || rating == 2 || rating == 3 || rating == 4 || rating == 5)
	{
		theUser->addRatedMovies(theMovie,rating);
	}

	else
	{
	 QMessageBox *msgBox;
	 msgBox= new QMessageBox();
	 msgBox->setText("You didn't enter a number 1-5! Try again");
	 msgBox->exec();
	}

}

void RatingWindow::cancelPressed()
{


}



void RatingWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}

