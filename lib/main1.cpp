#include <iostream>
#include <exception>
#include <stdexcept>
#include "Set.h"

using namespace std;

int main()
{
  Map<int,int> mapA;

  Map<int,int> mapB;
 

  mapA.add(33,25);

  mapA.add(34,25);


  mapA.first();

  try
  {
  	mapA.next();
  }

  catch(NoSuchElementException)
  {
  	cout<<"You are already at the last map item!"<<endl;
  }
  



  


  



  
  return 0;
}

