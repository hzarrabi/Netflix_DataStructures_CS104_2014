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
  Map<string,Movie*> movieMap;//map that hold the movie name and movie objects

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
            //getline(userData,buffer);
          }
          else if(command=="END")//here the userID and the userName are added to the userMap
          {
            User *userAccount = new User(userID1,userName1);
            mapUser.add(userID1,userAccount);
          }
        }
      }
      else
      {
        cout<<"Your user file:"<<userFile<<" could not be found."<<endl;
        return 0;
      }


//==============================================================================================

      //opens movieFile
      movieData.open(movieFile.c_str());
      if(movieData.is_open())
      {
        string command;//either begin or keyword
        string movieTitle;//will serve as the key to set?
        string keyword;

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
            //movieMap.add(movieTitle,moviePointer);
          }
          else if(command=="KEYWORD:")
          {
            buffer=buffer.substr(buffer.find_first_of(" ")+1);
            keyword=buffer;
            //cout<<buffer<<" this should be keyword of:"<<movieTitle<<endl;
            moviePointer->addKeyword(keyword); 

            //ADD KEYWORD TO THE SET OF THE MOVIEEEEEEEE
          }
          else if(command=="END")
          {
            movieMap.add(movieTitle,moviePointer);//add movie object to the movie map
          }

        }
      }
      else
      {
        cout<<"Your user file:"<<movieFile<<" could not be found."<<endl;
        return 0;
      }

//===============================================================================================

  }

  else
  {
      cout<<"The main file name you entered could not be found. File not opened."<<endl;
      return 0;
  }


//===========================================================================================================================



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
  cout<<"What is your log in ID?:";
  cin>>logInID;
  cout<<"\n";
  
  while(mapUser.keyExist(logInID)==false)//prompting them to enter a loginId that exists
  {
    cout<<"You didn't enter the correct login in ID, try again:";
    cin>>logInID;
    cout<<"\n";
    cout<<""<<endl;
  }

  if (mapUser.get(logInID))
  {
    int yellow;
    cout<<"Succesfuly logged in "<<logInID<<"!"<<endl;
    cout<<"\n";
    cout<<"1.Search for a movie by title"<<endl;
    cout<<"2.Search for a movie by keyword"<<endl;
    cout<<"3.Logout"<<endl;
    cout<<"\n";
    cout<<"Enter number of command:";
    cin>>yellow;
    cout<<"\n"<<endl;

    while(yellow<1 || yellow>3)
    {
      cout<<"You did not enter the correct command number. Try again:";
      cin>>yellow;
      cout<<""<<endl;
    }

    if(yellow==1)
    {
      string movieTitle1;
      cout<<"What movie would you like to search for?:";
      cin.ignore();
      getline(cin, movieTitle1);
      //cout<<movieTitle1<<endl;
      cout<<"\n";

      //cout<<"the size of the movie map is:"<<movieMap.getCurrentKey()<<endl;
      if(movieMap.keyExist(movieTitle1)==false)
      {
        cout<<"This movie does not exist!"<<endl;
      }
      else
      {
        cout<<movieTitle1<<endl;
        movieMap.get(movieTitle1)->getAllKeywords().printSet();//should print all keywords
      }


    }

    else if(yellow==2)
    {
      string newKeyWord1;
      cout<<"What keyword would you like to search for?:";
      cin.ignore();
      getline(cin, newKeyWord1);
    }

    else if(yellow==3)
    {
      cout<<"Logged out!"<<endl;
    }
  }
  else
  {
    cout<<"Could not log you in!"<<endl;
  }
}


else if(userCommand==2)//they want to create a new user
{
  string newUserID;
  string newUserName;
  cout<<"Creating New User!"<<endl;
  cout<<"What is your user ID?:";
  cin>>newUserID;
  cout<<""<<endl;
  while(mapUser.keyExist(newUserID)==true)
  {
    cout<<"This ID already exists. Please enter another:";
    cin>>newUserID;
    cout<<""<<endl;
  }
  cout<<"What is your user Name?:";
  cin.ignore();
  getline(cin, newUserName);
  User *userAccount = new User(newUserID,newUserName);//make new user object
  mapUser.add(newUserID,userAccount);//add the user object to your userMap
  cout<<"Your account has been made!"<<endl;

  ofstream myFile;
  myFile.open("../data/userInfo.txt",ios_base::app);//opens the user file and appends so you don't clear all contents
  if(!myFile.is_open())
  {
    cout<<"File could not be found!"<<endl;
  }
  else
  {
    myFile<<"BEGIN "<<newUserID<<endl;
    myFile<<"NAME: "<<newUserName<<endl;
    myFile<<"END"<<endl;
    myFile.close();
  }
}

else if(userCommand==3)//they want to log in
{
  cout<<"QUITTING NOW. THANKS FOR VISITING!"<<endl;
}


  return 0;
}

