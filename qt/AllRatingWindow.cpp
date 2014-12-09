#include "AllRatingWindow.h"


allRatingWindow::allRatingWindow (QWidget* parent, Netflix *n) : QDialog (parent)
{

	parentWidget()->hide();//hides the main login window

	temp= n;
	tempU=n->returnUserMap();
	curUser=tempU->get(n->getID());
	fml=curUser->rateMap();
	nexts=fml->size()-1;
	firstIt = curUser->rateMap()->begin();
	Pair<Movie*, int> temp = *firstIt;
	title=QString::fromStdString(temp.first->getTitle());
	rate=QString::number(temp.second);





	//button layout
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	next=new QPushButton("&Next Rating");
 	buttonLayout->addWidget(next);
 	adjust=new QPushButton("Adjust");
 	buttonLayout->addWidget(adjust);
 	cancel=new QPushButton("&Cancel");
 	buttonLayout->addWidget(cancel);

	

	QVBoxLayout *mainLayout = new QVBoxLayout;
	movieTitle=new QLabel(title);
	movieTitle->setAlignment(Qt::AlignCenter);
	rating=new QLabel(rate);
	rating->setAlignment(Qt::AlignCenter);



 	QVBoxLayout *rbox = new QVBoxLayout;

 	mainLayout->addWidget(movieTitle);
 	mainLayout->addWidget(rating);
 	mainLayout->addLayout(buttonLayout);

 	setLayout (mainLayout);


	connect(next,SIGNAL(clicked()),this,SLOT(nextClicked()));	
	connect(adjust,SIGNAL(clicked()),this,SLOT(adjustClicked()));
	//connect(returnM,SIGNAL(clicked()),this,SLOT(returnToMenu()));




}


void allRatingWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}


void allRatingWindow::nextClicked()
{
	if(nexts==0)
	{
		next->setEnabled(false);
	}
	else
	{
		nexts--;
		++firstIt;
		Pair<Movie*, int> temp = *firstIt;
		title=QString::fromStdString(temp.first->getTitle());
		title=QString::fromStdString(temp.first->getTitle());
		rate=QString::number(temp.second);
		movieTitle->setText(title);
		rating->setText(rate);
	}
}


void allRatingWindow::adjustClicked()
{
	string tempString=title.toStdString();
	Pair<Movie*, int> temp1 = *firstIt;
	w=new RatingWindow(this, tempString, temp1.first,temp,false);
	w->show();

}


void allRatingWindow::rateClicked()
{

}

/*void displayWindow::nextM()
{
	if(nexts<1)//if there are no more keywords to display
	{
		next->setEnabled(false);
	}
	else
	{
		bool chose=true;
	    while(chose)
	    {		
	    		++findIterator;//iterator go to next movieMap item
	            Pair<string, Movie*> findPair = *findIterator;//is a pair that holds the key and value of the iterator
	            if(findPair.second->getAllKeywords().contains(movie) || findPair.second->getTitle()==movie)
	            {
	              nexts--;
	              string hello=findPair.first;
	              QString test=QString::fromStdString(hello);
	              string hello1=findPair.second->getAllKeywords().getSet();
	              //qDebug()<<test;
	              movieTitle->setText(test);//setting title of page to the movie that corresponds to that keyword
	              allkeywords->setText(QString::fromStdString(hello1));
	              break;
	            }
	            try
	            {
	              ++findIterator;//iterator go to next movieMap item
	            }
	            catch(NoSuchElementException)
	            {
	              chose=false;
	            }
	  	}

	}
}
void displayWindow::addM()
{

	Pair<string, Movie*> findPair = *findIterator;
	Movie* addedMovie=new Movie(findPair.first);
	User *tempUser=tempU->get(temp->getID());
	tempUser->movieQueue ()->enqueue(addedMovie);//adding the movie pointer to the users queue

}
void displayWindow::returnToMenu()
{
	emit updateParent();
	parentWidget()->show();
	close();
}
*/