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

void mainDisplay(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName);
void loggedInMenu(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName);
void keywordMenu(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName);
void newUserDisplay(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName);
void fileInput(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap,string &fileName,string mainFile);



int main(int argc, char *argv[])
{

  string mainFileName(argv[1]);
  string userFileName;



  Map<string,User*>  *mapUser = new Map<string,User*>;//map that takes user id and object of type user
  Map<string,Movie*> *movieMap = new Map<string,Movie*>;//map that hold the movie name and movie objects



  fileInput(mapUser, movieMap,userFileName,mainFileName);
  //deallocating memory 
   while (true)
    {
      movieMap->first();
      delete movieMap->getCurrentValue();
      try
      {
        movieMap->next();
      }
      catch(NoSuchElementException)
      {
        break;
      }
    }
    delete mapUser;
    delete movieMap;

  return 0;
}






//****************************************************************************************************************
//FUNCTION IMPLEMENTATIONS

//fileinput
void fileInput(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string &fileName, string mainFile)
{

    ifstream file;//the file object for the main file 
    string buffer;//this will take in lines from the file

    //string userFile;//string that holds the name of the userfile 
    string movieFile;//string that hold the name for the movie file

    
    file.open(mainFile.c_str());//opens the file in your command line argumen

    if (file.is_open())
    {
        getline(file,fileName);//reads in the first line that holds userFile
        getline(file,movieFile);//reads in the second line that holds movieFile


        ifstream userData;
        ifstream movieData;


        //opens userFile
        userData.open(fileName.c_str());
        if(userData.is_open())
        {
          string userID1;
          string userName1;
          string checkedMovie;//movied that is checked out
          bool whichBegin=true;//used to do specific begin command
          while(getline(userData,buffer))
          {
            string command;//either begin or add
            stringstream oneByOne(buffer);
            oneByOne>>command;
            User *userAccount;//declaring userAccount of type User
            if(command=="BEGIN" && whichBegin==true)
            {
              oneByOne>>userID1;//puts the id into command
              whichBegin=false;
            }
            else if(command=="NAME:")
            {
              userName1=buffer.substr(buffer.find_first_of(" ")+1);
              userAccount = new User(userID1,userName1);
            }
            else if(command=="MOVIE:")
            {
              checkedMovie=buffer.substr(buffer.find_first_of(" ")+1);
              Movie *rentedMovie=new Movie("checkedMovie");
              userAccount->rentMovie(rentedMovie);//putting the movie* object into the rented movie of the user
            }
            else if(command=="BEGIN" && whichBegin==false)
            {
              whichBegin=true;
              getline(userData,buffer);
              while(buffer!="END QUEUE")
              {
                cout<<buffer<<endl;
                Movie *rentedMovie=new Movie(buffer);//making movie object pointer of 
                userAccount->movieQueue()->enqueue(rentedMovie);
                getline(userData,buffer);

              }
            }
            else if(command=="END")//here the userID and the userName are added to the userMap
            {
              mapUser->add(userID1,userAccount);
            }
          }
        }
        else
        {
          cout<<"Your user file:"<<fileName<<" could not be found."<<endl;
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
              movieMap->add(movieTitle,moviePointer);//add movie object to the movie map
            }

          }
        //******************************************************************************************
        cout<<"WELCOME TO GETFLIX!!\n"<<endl;
        mainDisplay(mapUser,movieMap,fileName);//starting the program when the file contents read in
        //******************************************************************************************
        }
        else
        {
          cout<<"Your user file:"<<movieFile<<" could not be found."<<endl;
        }
    }

    //==========================================================================
    else
    {
        cout<<"The main file name you entered could not be found. File not opened."<<endl;
    }
}


//---------------------------------

//---------------------------------

//function log in menu
void mainDisplay(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName)
{
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
    loggedInMenu(mapUser,movieMap,fileName);
  }


  else if(userCommand==2)//they want to create a new user
  {
    newUserDisplay(mapUser,movieMap,fileName);
  }

  else if(userCommand==3)//they want to log in
  {
    cout<<"QUITTING NOW. THANKS FOR VISITING!"<<endl;
    
  }
}
//------------------------





//------------------------
//loggedInDisplay which prompts them to login etc
void loggedInMenu(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName)
{
    string logInID;
    cout<<"Welcome!"<<endl;
    cout<<"What is your log in ID?:";
    cin>>logInID;
    cout<<"\n";
    
    while(mapUser->keyExist(logInID)==false)//prompting them to enter a loginId that exists
    {
      cout<<"You didn't enter the correct login in ID, try again:";
      cin>>logInID;
      cout<<"\n";
      cout<<""<<endl;
    }

    if (mapUser->get(logInID))
    {
      keywordMenu(mapUser,movieMap,fileName);
    }
}
//----------------------------------------

//this is for when they have alreedy logged in
void keywordMenu(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName)
{

      cout<<"\n";
      cout<<"1.Search for a movie by title"<<endl;
      cout<<"2.Search for a movie by keyword"<<endl;
      cout<<"3.Logout"<<endl;
      cout<<"\n";
      cout<<"Enter number of command:";
      int yellow;
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
        if(movieMap->keyExist(movieTitle1)==false)
        {
          cout<<"This movie does not exist!"<<endl;
        }
        else
        {
          cout<<movieTitle1<<endl;
          movieMap->get(movieTitle1)->getAllKeywords().printSet();//should print all keywords
        }
        keywordMenu(mapUser,movieMap,fileName);


      }

      else if(yellow==2)
      {
        string newKeyWord1;
        cout<<"What keyword would you like to search for?:";
        cin.ignore();
        getline(cin, newKeyWord1);
        //checking if the movie map has movies with current keyword
        movieMap->first();//makes curEl point to first element
        bool chose=true;
        int counter1=0;
        while(chose)
        {
          if(movieMap->size()!=0)//if map is not emppty
          {
            if(movieMap->getCurrentValue()->getAllKeywords().contains(newKeyWord1)|| movieMap->getCurrentValue()->getTitle()==newKeyWord1)
            {
              counter1++;
            }
            try
            {
              movieMap->next();
            }
            catch(NoSuchElementException)
            {
              if(counter1==0)//if statement used to test wether keyword was found
              {
                cout<<"No match"<<endl;
                keywordMenu(mapUser,movieMap,fileName);
              }
              chose=false;
            }
          }
          else
          {
            chose=false;
          }
        }

        if(counter1>0)//if the keyword was found
        {
          //this second while loop prompts them to keep going to the next keyword
          movieMap->first();
          bool gooz=true;
          while(gooz)
          {
            if(movieMap->getCurrentValue()->getAllKeywords().contains(newKeyWord1)|| movieMap->getCurrentValue()->getTitle()==newKeyWord1)
            {
              cout<<movieMap->getCurrentKey()<<endl;
              movieMap->getCurrentValue()->getAllKeywords().printSet();//prints all keywords of the movie who's keyword was found
              counter1--;
              if(counter1>0)
              {
                int choice;
                cout<<"\n1.Next movie"<<endl;
                cout<<"2.Return to menu"<<endl;
                cin>>choice;
                if(choice==1)
                {
                  cout<<"\nGoing to next keyword:"<<endl;
                }
                else if(choice==2)
                {
                  keywordMenu(mapUser,movieMap,fileName);
                }
              }
              else if(counter1==0)
              {
                cout<<"No more keywords to display! Going to main menu.\n"<<endl;
                keywordMenu(mapUser,movieMap,fileName);
              }
            }
            try
            {
              movieMap->next();
            }
            catch(NoSuchElementException)
            {
              gooz=false;
            }
          }
        }

      }



      else if(yellow==3)
      {
        cout<<"LOGGED OUT!"<<endl;
        cout<<" "<<endl;
        mainDisplay(mapUser, movieMap, fileName);//prompts them with mainDisplay function if they logout

      }
}
//----------------------------------------





//----------------------------------------
void newUserDisplay(Map<string,User*>  *mapUser, Map<string,Movie*> *movieMap, string fileName)
{
  string newUserID;
    string newUserName;
    cout<<"Creating New User!"<<endl;
    cout<<"What is your user ID?:";
    cin>>newUserID;
    cout<<""<<endl;
    while(mapUser->keyExist(newUserID)==true)
    {
      cout<<"This ID already exists. Please enter another:";
      cin>>newUserID;
      cout<<""<<endl;
    }
    cout<<"What is your user Name?:";
    cin.ignore();
    getline(cin, newUserName);
    User *userAccount = new User(newUserID,newUserName);//make new user object
    mapUser->add(newUserID,userAccount);//add the user object to your userMap
    cout<<"Your account has been made!"<<endl;

    ofstream myFile;
    myFile.open(fileName.c_str(),ios_base::app);//opens the user file and appends so you don't clear all contents
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
    //when they succesfully login, display loginDisplay to them
    keywordMenu(mapUser, movieMap, fileName);
}