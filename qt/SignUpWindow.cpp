#include "SignUpWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>

SignUpWindow::SignUpWindow (QWidget* parent, Netflix *n) : QWidget (parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	login = new QLineEdit;
	password= new QLineEdit;

	QFormLayout *fl = new QFormLayout;
	fl->addRow("&User ID", login);
	fl->addRow("&Name", password);

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
	setLayout (mainLayout);


	connect(confirm,SIGNAL(clicked()),this,SLOT(add()));	
	connect(cancel,SIGNAL(clicked()),this,SLOT(cancelPage()));



}


void SignUpWindow::add()
{

}
void SignUpWindow::cancelPage()
{

}

