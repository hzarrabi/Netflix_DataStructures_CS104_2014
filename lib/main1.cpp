#include <iostream>
#include <exception>
#include <stdexcept>
#include "Set.h"

using namespace std;

int main()
{
  Set<int> setA;

  setA.add(12);

  setA.add(22);

  setA.add(32);

  cout<<setA.contains(12)<<endl;

  


  



  
  return 0;
}

