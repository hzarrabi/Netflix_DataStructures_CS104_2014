#include<QApplication>
#include "LoginWindow.h"
#include "SignUpWindow.h"
#include "KeywordWindow.h"


int main (int argc, char *argv[])
{
	QApplication app (argc, argv);
	KeywordWindow w;
	w.show();
	return app.exec();
}