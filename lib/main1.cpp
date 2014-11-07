#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Set.h"
#include "MergeSort.h"
#include "../Movie.h"
#include "../User.h"
#include "Netflix.h"

#include<QApplication>
#include "../qt/LoginWindow.h"


using namespace std;




int main(int argc, char *argv[])
{
  string mainFileName(argv[1]);

  Netflix *netflix=new Netflix;

  netflix->fileInput(mainFileName);

  QApplication app (argc, argv);
  LoginWindow *w= new LoginWindow(NULL,netflix);
  w->show();
  return app.exec();




  return 0;
}



