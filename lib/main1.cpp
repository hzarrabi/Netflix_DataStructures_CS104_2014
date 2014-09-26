#include <iostream>
#include <exception>
#include <stdexcept>
#include "Set.h"

using namespace std;

int main()
{
  Set<int> setA;

  setA.add(12);
  
  Set<int> setB(setA);

  
  return 0;
}

