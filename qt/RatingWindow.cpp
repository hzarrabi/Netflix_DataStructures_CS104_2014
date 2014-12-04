#include "RatingWindow.h"



RatingWindow::RatingWindow(QWidget* parent, string movie, Netflix *n)
{
	parentWidget()->hide();//hides the main login window

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

	QFormLayout *fl = new QFormLayout;
	fl->addRow("Rate", rate);


	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget (label);
	mainLayout->addLayout(fl);
	mainLayout->addLayout(buttonLayout);

	setLayout (mainLayout);


	//TODO the signals

}

void RatingWindow::closeEvent(QCloseEvent *)
{
	parentWidget()->show();
}