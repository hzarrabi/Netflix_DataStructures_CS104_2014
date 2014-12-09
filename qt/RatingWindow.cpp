#include "RatingWindow.h"



RatingWindow::RatingWindow(QWidget* parent, string movie, Movie * m, Netflix *n, bool rated): QDialog (parent)
{
	cout<<"gooz1"<<endl;
	parentWidget()->hide();//hides the main login window

	this->rated=rated;
	this->movie=movie;
	theMovie=m;
	temp= n;
	tempU=n->returnUserMap();
	theUser=tempU->get(temp->getID());


	QHBoxLayout *buttonLayout = new QHBoxLayout;
	rateButton=new QPushButton("&1");
	rateButton2=new QPushButton("&2");
	rateButton3=new QPushButton("&3");
	rateButton4=new QPushButton("&4");
	rateButton5=new QPushButton("&5");
	cancel=new QPushButton("&Cancel");
	buttonLayout->addWidget(rateButton);
	buttonLayout->addWidget(rateButton2);
	buttonLayout->addWidget(rateButton3);
	buttonLayout->addWidget(rateButton4);
	buttonLayout->addWidget(rateButton5);
	buttonLayout->addWidget(cancel);

	QLabel* label;

	if(rated)
	{
		label=new QLabel("Rate: "+QString::fromStdString(movie)+ " (from 1-worst to 5-best).");
	}
	else
	{
		label=new QLabel("Modify your rating for: "+QString::fromStdString(movie));
	}
	

	label->setAlignment(Qt::AlignCenter);





	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget (label);
	mainLayout->addLayout(buttonLayout);

	setLayout (mainLayout);



	connect(rateButton,SIGNAL(clicked()),this,SLOT(ratePressed()));	
	connect(rateButton2,SIGNAL(clicked()),this,SLOT(ratePressed2()));
	connect(rateButton3,SIGNAL(clicked()),this,SLOT(ratePressed3()));	
	connect(rateButton4,SIGNAL(clicked()),this,SLOT(ratePressed4()));	
	connect(rateButton5,SIGNAL(clicked()),this,SLOT(ratePressed5()));	

	connect(cancel,SIGNAL(clicked()),this,SLOT(cancelPressed()));	






}


void RatingWindow::ratePressed()
{
		if(rated)//movie has never been rated
		{
			cout<<"rated: "<<1<<endl;
			cout<<"the title of the rated movie is:"<<theMovie->getTitle()<<endl;
			theUser->addRatedMovies(theMovie,1);
			parentWidget()->show();
			//this->close();
		}
		else//movie has been rated before
		{
			Movie* tempMovie;
			Map<Movie*, int>::Iterator firstIt = theUser->rateMap()->begin();//iterator for the map
			while(true)
			{
				cout<<"rated: "<<1<<endl;
				cout<<"the movie has already been rated!!"<<endl;
				Pair<Movie*, int> temp = *firstIt; 
				if(temp.first->getTitle()==movie)
				{
					theUser->rateMap()->remove(temp.first);
					theUser->addRatedMovies(theMovie,1);
					//this->close();
					break;
				}
				++firstIt;
			}

		}
		cout<<"this should close"<<endl;
		this->close();

}



void RatingWindow::ratePressed2()
{
		if(rated)//movie has never been rated
		{
			cout<<"rated: "<<2<<endl;
			cout<<"the title of the rated movie is:"<<theMovie->getTitle()<<endl;
			theUser->addRatedMovies(theMovie,2);
			parentWidget()->show();
			//this->close();
		}
		else//movie has been rated before
		{
			Movie* tempMovie;
			Map<Movie*, int>::Iterator firstIt = theUser->rateMap()->begin();//iterator for the map
			while(true)
			{
				cout<<"rated: "<<2<<endl;
				cout<<"the movie has already been rated!!"<<endl;
				Pair<Movie*, int> temp = *firstIt; 
				if(temp.first->getTitle()==movie)
				{
					theUser->rateMap()->remove(temp.first);
					theUser->addRatedMovies(theMovie,2);
					//this->close();
					break;
				}
				++firstIt;
			}

		}
		cout<<"this should close"<<endl;
		this->close();

}



void RatingWindow::ratePressed3()
{
		if(rated)//movie has never been rated
		{
			cout<<"rated: "<<3<<endl;
			cout<<"the title of the rated movie is:"<<theMovie->getTitle()<<endl;
			theUser->addRatedMovies(theMovie,3);
			parentWidget()->show();
			//this->close();
		}
		else//movie has been rated before
		{
			Movie* tempMovie;
			Map<Movie*, int>::Iterator firstIt = theUser->rateMap()->begin();//iterator for the map
			while(true)
			{
				cout<<"rated: "<<3<<endl;
				cout<<"the movie has already been rated!!"<<endl;
				Pair<Movie*, int> temp = *firstIt; 
				if(temp.first->getTitle()==movie)
				{
					theUser->rateMap()->remove(temp.first);
					theUser->addRatedMovies(theMovie,3);
					//this->close();
					break;
				}
				++firstIt;
			}

		}
		cout<<"this should close"<<endl;
		this->close();

}


void RatingWindow::ratePressed4()
{
		if(rated)//movie has never been rated
		{
			cout<<"rated: "<<4<<endl;
			cout<<"the title of the rated movie is:"<<theMovie->getTitle()<<endl;
			theUser->addRatedMovies(theMovie,4);
			parentWidget()->show();
			//this->close();
		}
		else//movie has been rated before
		{
			Movie* tempMovie;
			Map<Movie*, int>::Iterator firstIt = theUser->rateMap()->begin();//iterator for the map
			while(true)
			{
				cout<<"rated: "<<4<<endl;
				cout<<"the movie has already been rated!!"<<endl;
				Pair<Movie*, int> temp = *firstIt; 
				if(temp.first->getTitle()==movie)
				{
					theUser->rateMap()->remove(temp.first);
					theUser->addRatedMovies(theMovie,4);
					//this->close();
					break;
				}
				++firstIt;
			}

		}
		cout<<"this should close"<<endl;
		this->close();

}


void RatingWindow::ratePressed5()
{
		if(rated)//movie has never been rated
		{
			cout<<"rated: "<<5<<endl;
			cout<<"the title of the rated movie is:"<<theMovie->getTitle()<<endl;
			theUser->addRatedMovies(theMovie,5);
			parentWidget()->show();
			//this->close();
		}
		else//movie has been rated before
		{
			Movie* tempMovie;
			Map<Movie*, int>::Iterator firstIt = theUser->rateMap()->begin();//iterator for the map
			while(true)
			{
				cout<<"rated: "<<5<<endl;
				cout<<"the movie has already been rated!!"<<endl;
				Pair<Movie*, int> temp = *firstIt; 
				if(temp.first->getTitle()==movie)
				{
					theUser->rateMap()->remove(temp.first);
					theUser->addRatedMovies(theMovie,5);
					//this->close();
					break;
				}
				++firstIt;
			}

		}
		cout<<"this should close"<<endl;
		this->close();

}


void RatingWindow::cancelPressed()
{
	parentWidget()->show();
	close();
}



void RatingWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}

