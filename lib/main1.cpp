#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <sstream>
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

  Map<string,User*>  mapUser;//map that takes user id and object of type user
  Map<string,Movie*> movieMap;//map that hold the movie objects

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
        string userID1;
        string userName1;
        while(getline(userData,buffer))
        {
          string command;//either begin or add
          stringstream oneByOne(buffer);
          oneByOne>>command;
          //cout<<command<<endl;
          if(command=="BEGIN")
          {
            oneByOne>>userID1;//puts the id into command
          }
          else if(command=="NAME:")
          {
            userName1=buffer.substr(buffer.find_first_of(" ")+1);
            cout<<userName1<<"this should be Aaron Cote"<<endl;
            //PUT NAME INTO MAP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            getline(userData,buffer);
            User *userAccount = new User(userID1,userName1);
            mapUser.add(userID1,userAccount);
          }

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
        string command;//either begin or keyword
        string movieTitle;//will serve as the key to set?

        while(getline(movieData,buffer))
        {
          stringstream oneByOne(buffer);
          oneByOne>>command;//puts command in
          Movie *moviePointer;
          if(command=="BEGIN")
          {
            buffer=buffer.substr(buffer.find_first_of(" ")+1);
            movieTitle=buffer;//puts the movie title in as key
            cout<<movieTitle<<endl;
            //PUT movie title into set!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            moviePointer = new Movie(movieTitle);
            movieMap.add(movieTitle,moviePointer);
          }
          else if(command=="KEYWORD:")
          {
            buffer=buffer.substr(buffer.find_first_of(" ")+1);
            movieTitle=buffer;
            cout<<buffer<<" this should be keyword of:"<<movieTitle<<endl;
            moviePointer->addKeyword(movieTitle); 

            //ADD KEYWORD TO THE SET OF THE MOVIEEEEEEEE
          }
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

