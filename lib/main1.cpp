#include <iostream>
#include <exception>
#include <stdexcept>
#include "Set.h"

using namespace std;

int main()
{
  Set<int> setA;

  Set<int> setB;
 

  setB.add(33);

  setA.add(22);

  setA.add(32);

  setB=setA;


  bool gooz=false;

  //cout<<setB.get(343,gooz)<<endl;
  cout<<setB.contains(22)<<endl;

  


  



  
  return 0;
}

