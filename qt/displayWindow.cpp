#include "displayWindow.h"


displayWindow::displayWindow (QWidget* parent, string movie, Netflix *n) : QDialog (parent)
{

	parentWidget()->hide();//hides the main login window

	this->movie=movie;
	temp= n;
	tempM=n->returnMovieMap();
	tempU=n->returnUserMap();

	//button layout
	QGroupBox *returnBox= new QGroupBox(tr("Movie Info"));//the first group box
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	next=new QPushButton("&Next Movie");
 	buttonLayout->addWidget(next);
 	add=new QPushButton("&Add to my Queue");
 	buttonLayout->addWidget(add);
 	returnM=new QPushButton("&Return to Main Menu");
 	buttonLayout->addWidget(returnM);

 	//word entered was a movie
	if(tempM->keyExist(movie))
	{
		title = QString::fromStdString(movie);//sets the title on the page to the movie's title
		keywords=QString::fromStdString(tempM->get(movie)->getAllKeywords().getSet());//sets the qstring to the keywords of that movie
		next->setEnabled(false);
	}


	//word entered was a keyword 
	else
	{
		nexts=temp->findKeywords(movie);//setting the number of nexts
		findIterator=tempM->begin();
		bool chose=true;
	    while(chose)
	    {
	            Pair<string, Movie*> findPair = *findIterator;//temp is a pair that holds the key and value of the iterator
	            if(findPair.second->getAllKeywords().contains(movie) || findPair.second->getTitle()==movie)
	            {
	              nexts--;
	              title=QString::fromStdString(findPair.first);//setting title of page to the movie that corresponds to that keyword
	              keywords=QString::fromStdString(findPair.second->getAllKeywords().getSet());
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

	QVBoxLayout *mainLayout = new QVBoxLayout;
	movieTitle=new QLabel(title);
	movieTitle->setAlignment(Qt::AlignCenter);

 	QVBoxLayout *rbox = new QVBoxLayout;
 	rbox->addWidget(allkeywords=new QLabel(keywords));
 	returnBox->setLayout(rbox);

 	mainLayout->addWidget(movieTitle);
 	mainLayout->addWidget(returnBox);
 	mainLayout->addLayout(buttonLayout);

 	setLayout (mainLayout);


	connect(next,SIGNAL(clicked()),this,SLOT(nextM()));	
	connect(add,SIGNAL(clicked()),this,SLOT(addM()));
	connect(returnM,SIGNAL(clicked()),this,SLOT(returnToMenu()));




}


void displayWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}

void displayWindow::nextM()
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
	            Pair<string, Movie*> findPair = *findIterator;//is a pair that holds the key and value of the iterator
	            if(findPair.second->getAllKeywords().contains(movie) || findPair.second->getTitle()==movie)
	            {
	              nexts--;
	              QString done=QString::fromStdString(findPair.first);
	              //cout<<done<<endl;
	              QString done2=QString::fromStdString(findPair.second->getAllKeywords().getSet());
	              //cout<<done2<<endl;
	              movieTitle->setText("dfgdfsg");//setting title of page to the movie that corresponds to that keyword
	              allkeywords->setText("ddfgdsfg");
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
