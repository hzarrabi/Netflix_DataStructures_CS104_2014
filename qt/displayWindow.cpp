#include "LoginWindow.h"
#include "KeywordWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QWidget>
#include <iostream>

using namespace std;

displayWindow::displayWindow (string movie, Netflix *n)
{
	//need the netflix opbject (but as a pointer so changes are made to all of the windows)
	temp= n;

	QVBoxLayout *mainLayout = new QVBoxLayout;

	movieTitle=new QLabel("Title");

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
 	rbox->addLayout(buttonLayout);//addind button to first layout
 	returnBox->setLayout(rbox);

 	mainLayout->addWidget(returnBox);

 	setLayout (mainLayout);



}

void displayWindow::nextM(){}
void displayWindow::addM(){}
void displayWindow::returnToMenu(){}