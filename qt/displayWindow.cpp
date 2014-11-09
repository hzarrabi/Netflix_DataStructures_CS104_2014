#include "displayWindow.h"


displayWindow::displayWindow (QWidget* parent, string movie, Netflix *n) : QDialog (parent)
{

	parentWidget()->hide();//hides the main login window


	temp= n;
	tempM=n->returnMovieMap();
	tempU=n->returnUserMap();

	if(tempM->keyExist(movie))
	{
		title = QString::fromStdString(movie);//sets the title on the page to the movie's title


	}

	QVBoxLayout *mainLayout = new QVBoxLayout;
	QLabel* label=new QLabel(title);
	label->setAlignment(Qt::AlignCenter);


	//button layout
	QGroupBox *returnBox= new QGroupBox(tr("Movie Info"));//the first group box
 	QHBoxLayout *buttonLayout = new QHBoxLayout;
 	next=new QPushButton("&Next Movie");
 	buttonLayout->addWidget(next);
 	add=new QPushButton("&Add to my Queue");
 	buttonLayout->addWidget(add);
 	returnM=new QPushButton("&Return to Main Menu");
 	buttonLayout->addWidget(returnM);

 	QVBoxLayout *rbox = new QVBoxLayout;
 	//QString qtemp=new QString("The Movie Keywords and Title");
	//movieQueue->setText(qtemp);
 	//rbox->addLayout(buttonLayout);//addind button to first layout
 	rbox->addWidget(everything=new QLabel("Keywords and sheet"));
 	returnBox->setLayout(rbox);

 	mainLayout->addWidget(label);
 	mainLayout->addWidget(returnBox);
 	mainLayout->addLayout(buttonLayout);

 	setLayout (mainLayout);



}


void displayWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}

void displayWindow::nextM(){}
void displayWindow::addM(){}
void displayWindow::returnToMenu(){}