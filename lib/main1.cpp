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


using namespace std;




int main(int argc, char *argv[])
{
  string mainFileName(argv[1]);

  Netflix netflix;

  netflix.fileInput(mainFileName);


  return 0;
}



