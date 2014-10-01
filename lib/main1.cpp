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
            //cout<<userName1<<"this should be Aaron Cote"<<endl;
            //PUT NAME INTO MAP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            getline(userData,buffer);
            User *userAccount = new User(userID1,userName1);
            mapUser.add(userID1,userAccount);
          }

          //bool gooa;
          //mapUser.get("aaroncot",gooa);

        }
      }
      else
      {
        cout<<"Your user file:"<<userFile<<" could not be found."<<endl;
        return 0;
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
            //cout<<movieTitle<<endl;
            //PUT movie title into set!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            moviePointer = new Movie(movieTitle);
            movieMap.add(movieTitle,moviePointer);
          }
          else if(command=="KEYWORD:")
          {
            buffer=buffer.substr(buffer.find_first_of(" ")+1);
            movieTitle=buffer;
            //cout<<buffer<<" this should be keyword of:"<<movieTitle<<endl;
            moviePointer->addKeyword(movieTitle); 

            //ADD KEYWORD TO THE SET OF THE MOVIEEEEEEEE
          }
        }
      }
      else
      {
        cout<<"Your user file:"<<movieFile<<" could not be found."<<endl;
        return 0;
      }



  }

  else
  {
      cout<<"The main file name you entered could not be found. File not opened."<<endl;
      return 0;
  }






cout<<"WELCOME TO GETFLIX!!\n"<<endl;

cout<<"What would you like to do?:"<<endl;
cout<<"1. Log In"<<endl;
cout<<"2. Create a new user"<<endl;
cout<<"3. QUIT\n"<<endl;


int userCommand;
cout<<"Enter number of command:";
cin>>userCommand;
cout<<""<<endl;




while(userCommand<1 || userCommand>3)
  {
  cout<<"You did not enter the correct command number. Try again:";
  cin>>userCommand;
  cout<<""<<endl;
  }


if(userCommand==1)//they want to log in
{
  string logInID;
  cout<<"Welcome!"<<endl;
  cout<<"What is your log in ID";
  cin>>logInID;
  bool gooz=false;
  if (mapUser.get(logInID,gooz))
  {
    int yellow;
    cout<<"Succesfuly logged in!"<<endl;
    cout<<"1.Search for a movie by title"<<endl;
    cout<<"2.Search for a movie by keyword"<<endl;
    cout<<"3.Logout";

    while(yellow<1 || yellow>3)
    {
      cout<<"You did not enter the correct command number. Try again:";
      cin>>yellow;
      cout<<""<<endl;
    }

    if(yellow==1)
    {
      string movieTitle1;
      cout<<"What movie would you like to search?:";
      cin>>movieTitle1;
    }

    else if(yellow==2)
    {
      string newKeyWord1;
      cout<<"What keyword would you like to search for?:";
      cin>> newKeyWord1;
    }

    else if(yellow==3)
    {
      cout<<"Logged out!"<<endl;
    }


/*cout<<"1.Search for a movie by title"<<endl;
cout<<"2.Search for a movie by keyword"<<endl;
cout<<"3.Logout"<<endl;
cout<<"What would you like to do?:"<<endl;
cin>>logInCommand;
cout<<""<<endl;*/
  }
  else
  {
    cout<<"Could not log you in!"<<endl;
  }
}


else if(userCommand==2)//they want to log in
{
string newUserID;
string newUserName;
cout<<"Creating New User!"<<endl;
cout<<"What is your user ID?:";
cin>>newUserID;
cout<<""<<endl;
cout<<"What is your user Name?:";
//getline(cin
cin>>newUserName;
//cout<<newUserName;
User *userAccount = new User(newUserID,newUserName);//make new user object
mapUser.add(newUserID,userAccount);//add the user object to your userMap
cout<<"Your account has been made!"<<endl;
}

else if(userCommand==3)//they want to log in
{
cout<<"QUITTING NOW. THANKS FOR VISITING!"<<endl;
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

