#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include "Set.h"
#include "../Movie.h"
#include "../User.h"

using namespace std;

int main(int argc, char *argv[])
{



  ifstream file;//the file object for the main file 
  string buffer;//this will take in lines from the file

  string userFile;//string that holds the name of the userfile 
  string movieFile;//string that hold the name for the movie file

  file.open(argv[1]);//opens the file in your command line argumen

  if (file.is_open())
  {
      getline(file,userFile);//reads in the first line that holds userFile 
      getline(file,movieFile);//reads in the second line that holds movieFile

      ifstream userData;
      ifstream movieData;


      //opens userFile
      userData.open(userFile.c_str());
      if(userData.is_open())
      {
        while(getline(userData,buffer))
        {
          cout<<buffer<<endl;
        }
      }
      else
      {
        cout<<"Your user file:"<<userFile<<" could not be found."<<endl;
      }


      //opens movieFile
      movieData.open(movieFile.c_str());
      if(movieData.is_open())
      {
        while(getline(movieData,buffer))
        {
          cout<<buffer<<endl;
        }
      }
      else
      {
        cout<<"Your user file:"<<movieFile<<" could not be found."<<endl;
      }



  }

  else
  {
      cout<<"The main file name you entered could not be found. File not opened."<<endl;
      return 0;
  }






  /*Set<int> mapA;

 // Map<int,int> mapB;
 

  


  //mapA.add(232);
  //mapA.add(445,3534);
  //mapA.add(434,3434);

  mapA.add(633);


try
  {
   mapA.first();
  }

  catch(NoSuchElementException)
  {
  	cout<<"The map is empty, can't set the treaversal pointer to the first element!"<<endl;
  }
 



 mapA.add(663);


  //--------------------------------------

  try
  {
  	mapA.next();
  }

  catch(NoSuchElementException)
  {
  	cout<<"You are already at the last map item!"<<endl;
  }
  


cout<<mapA.getCurrent()<<endl;


  


  
*/

/*
Set<int> setA;
Set<int> setB;

setA.add(3);
setA.add(5);
setA.add(7);

setB.add(8);
setB.add(9);
setB.add(2);
setB.add(3);

setA.setIntersection(setB);



Movie cos("antar chose");
Movie keer(cos);


cout<<"hello"<<endl;*/


  
  return 0;
}

