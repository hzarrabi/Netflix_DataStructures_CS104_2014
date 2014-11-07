#include<QApplication>
#include "LoginWindow.h"
#include "SignUpWindow.h"


int main (int argc, char *argv[])
{
	QApplication app (argc, argv);
	SignUpWindow w;
	w.show();
	return app.exec();
}