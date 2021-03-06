#include "KeywordWindow.h"


KeywordWindow::KeywordWindow (QWidget* parent, Netflix *n) : QDialog (parent)
{

	parentWidget()->hide();//hides the main login window


	temp=n;
	tempM=n->returnMovieMap();
	tempU=n->returnUserMap();


	QVBoxLayout *mainLayout = new QVBoxLayout;


	//first group box for returning the movie========================================================
 	QGroupBox *returnBox= new QGroupBox(tr("Your Current Movie"));//the first group box
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	returnMovie=new QPushButton("&Return Movie");
 	buttonLayout->addWidget(returnMovie);
 	ratings=new QPushButton("&See Ratings");
 	buttonLayout->addWidget(ratings);


 	string ID1=n->getID();
 	string gooz=n->currentMovie();
 	QString qstr = QString::fromStdString(gooz);

 	/*QString qstr50;
 	if(tempU->get(ID1)->currentMovie())
 	{
 		qstr50= "Price: $" +QString::number(tempU->get(ID1)->currentMovie()->getTitle().size());
	}
	else
	{
		//cout<<"this should get called"<<endl;
		qstr50="";
	}*/

 	QVBoxLayout *rbox = new QVBoxLayout;
 	rbox->addWidget(currentMovie=new QLabel(qstr));//adding qlabel to the first layou
 	//rbox->addWidget(price=new QLabel(qstr50));//adding qlabel to the first layou
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
 	searchActor=new QPushButton("Search by &Actor");\
 	QHBoxLayout *buttonLayout2 = new QHBoxLayout;
 	buttonLayout2->addWidget(searchTitle);
 	buttonLayout2->addWidget(searchKeyword);
 	buttonLayout2->addWidget(searchActor);

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
 	string total1="ADDRESS :"+tempU->get(ID)->address;
 	QString qstr5 = QString::fromStdString(total1);//address
 	QString qstr3= 	"Credit Card# :" + QString::number(tempU->get(ID)->ccNum);
 	QString qstr4 = "CHARGES : $"+QString::number(tempU->get(ID)->charges);//charges



	QLabel* label=new QLabel(qstr1);
	label->setAlignment(Qt::AlignCenter);
	QLabel* label2=new QLabel(qstr5);
	label2->setAlignment(Qt::AlignCenter);
	QLabel* label3=new QLabel(qstr3);
	label3->setAlignment(Qt::AlignCenter);
	QLabel* label4=new QLabel(qstr4);
	label4->setAlignment(Qt::AlignCenter);
 	
	logOut=new QPushButton("Log&out");

 	mainLayout->addWidget (label);
 	mainLayout->addWidget (label2);
 	mainLayout->addWidget (label3);
 	mainLayout->addWidget (label4);

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
	connect(searchActor,SIGNAL(clicked()),this,SLOT(actorPressed()));
	connect(logOut,SIGNAL(clicked()),this,SLOT(logOutPressed()));
	connect(ratings,SIGNAL(clicked()),this,SLOT(ratingsPressed()));

	connect(search, SIGNAL(returnPressed()),searchTitle,SIGNAL(clicked()));



	User *idiot = tempU->get(temp->getID());
	Queue<Movie*>* t=idiot->movieQueue();
	if(t->isEmpty())
	{
		rentMovie->setEnabled(false);
		deleteQueue->setEnabled(false);
		movieBack->setEnabled(false);
	}





}


void KeywordWindow::closeEvent(QCloseEvent *)
{
    parentWidget()->show();
}


void KeywordWindow::returnPressed()
{
	User *idiot = tempU->get(temp->getID());
    if(idiot->currentMovie()==NULL)//if doesn't have a movie checked out do nothing
    {
      //return false;
    }
    else//else return the movie
    {
      Movie* actualMovie=idiot->currentMovie();//this will get keep the movie pointer so we can add to user's rated movies
      string rentedMovie=idiot->currentMovie()->getTitle();//saving the title for rating
      idiot->returnMovie();
      returnMovie->setEnabled(false);
	  currentMovie->setText("");
	  rentMovie->setEnabled(true);//makes its button grey
	  	
	  	r=new RatingWindow(this,rentedMovie,actualMovie,temp,idiot->containsRatedMovie(rentedMovie));
		r->show();
  
    }
}

void KeywordWindow::ratingsPressed()
{
	s=new allRatingWindow(this,temp);
	s->show();
}


void KeywordWindow::rentPressed()
{

	User *idiot = tempU->get(temp->getID());
	Queue<Movie*>* t=idiot->movieQueue();
	if(t->isEmpty())//if queue is empty 
	{
		rentMovie->setEnabled(false);//makes its button grey
		deleteQueue->setEnabled(false);//makes its button grey
		movieBack->setEnabled(false);//makes its button grey
	}
	else//if queue is not empty
	{
		if(idiot->currentMovie()==NULL)//if there is no movie rented 
		{
			string antar1=t->peekFront()->getTitle();
 			QString qstr2=QString::fromStdString(antar1);
			currentMovie->setText(qstr2);//sets the current rented movie to front of queue
			returnMovie->setEnabled(true);
			Movie *m=new Movie(antar1);//making a new movie that is the movie you're renting out
			idiot->rentMovie(m);//checking the movie out
			t->dequeue();
			string antar=t->peekFront()->getTitle();
 			QString qtemp=QString::fromStdString(antar);
 			movieQueue->setText(qtemp);


		}

		else//there is a movie rented
		{
			rentMovie->setEnabled(false);//makes its button grey
		}

	}

}


void KeywordWindow::deletePressed()
{
	User *idiot = tempU->get(temp->getID());
	Queue<Movie*>* t=idiot->movieQueue();
	if(t->isEmpty())//if queue is empty 
	{
		rentMovie->setEnabled(false);//makes its button grey
		deleteQueue->setEnabled(false);//makes its button grey
		movieBack->setEnabled(false);//makes its button grey
	}
	else
	{
		t->dequeue();
		if(!t->isEmpty())//if queue is empty 
		{
			string antar=t->peekFront()->getTitle();
			QString qtemp=QString::fromStdString(antar);
			movieQueue->setText(qtemp);
		}
		else
		{
			rentMovie->setEnabled(false);//makes its button grey
			movieQueue->setText("");
		}
	}
}
void KeywordWindow::backPressed()
{
User *idiot = tempU->get(temp->getID());
Queue<Movie*>* t=idiot->movieQueue();
	if(!t->isEmpty())
	{
		string antar=t->peekFront()->getTitle();
		t->dequeue();
		Movie *m=new Movie(antar);//making a new movie that is the movie you're renting out
		t->enqueue(m);
		antar=t->peekFront()->getTitle();
		QString qtemp=QString::fromStdString(antar);
		movieQueue->setText(qtemp);
	}
	else
	{
		movieBack->setEnabled(false);//makes its button grey
	}
}

void KeywordWindow::titlePressed()
{

	string keyword= search->text().toStdString();//making qlineEdit into string
	if(tempM->keyExist(keyword))
	{
		l=new displayWindow(this,keyword,temp);
		l->show();
	}

}
void KeywordWindow::keywordPressed()
{
	string keyword = search->text().toStdString();//making qlineEdit into string
	if(temp->findKeywords(keyword)>0)
	{
		l=new displayWindow(this,keyword,temp);
		QObject::connect(l, SIGNAL(updateParent()), this, SLOT(update()));
		l->show();
	}


}


void KeywordWindow::actorPressed()
{
	string theActor = search->text().toStdString();//making qlineEdit into string
	if(temp->findKeywords(theActor)>0)
	{
		l=new displayWindow(this,theActor,temp);
		QObject::connect(l, SIGNAL(updateParent()), this, SLOT(update()));
		l->show();
	}

}


void KeywordWindow::logOutPressed()//returns them to previous logout page
{
	parentWidget()->show();
	//QObject::connect(l, SIGNAL(updateParent()), this, SLOT(update()));
	close();
}

void KeywordWindow::update()
{
	User *idiot = tempU->get(temp->getID());
	Queue<Movie*>* t=idiot->movieQueue();
	if(!t->isEmpty())
	{
		string antar=t->peekFront()->getTitle();
		QString qtemp=QString::fromStdString(antar);
		movieQueue->setText(qtemp);
		deleteQueue->setEnabled(true);
		movieBack->setEnabled(true);
	}
}