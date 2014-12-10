#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Netflix.h"


//constructor
Netflix::Netflix()
{
mapUser = new Map<string,User*>;//map that takes user id and object of type user
movieMap = new Map<string,Movie*>;//map that hold the movie name and movie objects
}

//destructor 
Netflix::~Netflix()
{

}

//FILEINPUT
void Netflix::fileInput(string mainFile)
{
ifstream file;//the file object for the main file 
    string buffer;//this will take in lines from the file

    //string userFile;//string that holds the name of the userfile 
    string movieFile;//string that hold the name for the movie file

    
    file.open(mainFile.c_str());//opens the file in your command line argumen
    if (file.is_open())
    {
        getline(file,userFileName);//reads in the first line that holds userFile
        getline(file,movieFile);//reads in the second line that holds movieFile


        ifstream userData;
        ifstream movieData;


        //opens userFile
        userData.open(userFileName.c_str());
        if(userData.is_open())
        {
          string userID1;
          string userName1;
          string checkedMovie;//movied that is checked out
          string password;
          int whichBegin=1;//used to do specific begin command
          while(getline(userData,buffer))
          {
            string command;//either begin or add
            stringstream oneByOne(buffer);
            oneByOne>>command;
            User *userAccount;//declaring userAccount of type User
            if(command=="BEGIN" && whichBegin==1)
            {
              oneByOne>>userID1;//puts the id into command
              whichBegin=2;
            }
            else if(command=="NAME:")
            {
              userName1=buffer.substr(buffer.find_first_of(" ")+1);
              //userAccount = new User(userID1,userName1);
            }
            else if(command=="PASSWORD:")
            {
              password=buffer.substr(buffer.find_first_of(" ")+1);
              userAccount = new User(userID1,userName1,password);
            }
            else if(command=="MOVIE:")
            {
              cout<<"setting the rented movie"<<endl;
              checkedMovie=buffer.substr(buffer.find_first_of(" ")+1);
              Movie *rentedMovie=new Movie(checkedMovie);
              userAccount->rentMovie(rentedMovie);//putting the movie* object into the rented movie of the user
            }
            else if(command=="BEGIN" && whichBegin==2)
            {
              getline(userData,buffer);
              while(buffer!="END QUEUE")
              {
                Movie *rentedMovie=new Movie(buffer);//making movie object pointer of 
                userAccount->movieQueue()->enqueue(rentedMovie);
                getline(userData,buffer);
              }
              whichBegin=3;
            }
            else if(command=="BEGIN" && whichBegin==3)
            {
              cout<<"reading in the rating"<<endl;
              getline(userData,buffer);
              while(buffer!="END RATINGS")
              {
                int rating;
                string movieName;
                stringstream keeram(buffer);
                keeram>>rating;
                cout<<rating<<endl;
                movieName=buffer.substr(buffer.find_first_of(" ")+1);;
                cout<<movieName<<endl;
                Movie *ratedMovie=new Movie(movieName);
                userAccount->addRatedMovies(ratedMovie,rating);
                cout<<"the size of the rated movies is::::"<<userAccount->rateMap()->size()<<endl;
                getline(userData,buffer);
              }
            }
            else if(command=="END")//here the userID and the userName are added to the userMap
            {
              mapUser->add(userID1,userAccount);
              whichBegin=1;
            }
          }
        }
        else
        {
          cout<<"Your user file:"<<userFileName<<" could not be found."<<endl;
        }

  //==============================================================================================

        //opens movieFile
        movieData.open(movieFile.c_str());
        if(movieData.is_open())
        {
          string command;//either begin or keyword
          string movieTitle;//will serve as the key to set?
          string keyword;
          string actor;

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
              cout<<"new movie!----------"<<movieTitle<<endl;
              moviePointer = new Movie(movieTitle);
              //movieMap.add(movieTitle,moviePointer);
            }
            else if(command=="KEYWORD:")
            {
              buffer=buffer.substr(buffer.find_first_of(" ")+1);
              keyword=buffer;
              cout<<buffer<<" this should be keyword of:"<<movieTitle<<endl;
              moviePointer->addKeyword(keyword);
              cout<<"added keyword:"<<keyword<<endl;;

              //ADD KEYWORD TO THE SET OF THE MOVIEEEEEEEE
            }
            else if(command =="ACTOR:")
            {
              buffer=buffer.substr(buffer.find_first_of(" ")+1);
              actor=buffer;
              moviePointer->addActors(actor);
              cout<<"added:"<<actor<<endl;
            }
            else if(command=="END")
            {
              movieMap->add(movieTitle,moviePointer);//add movie object to the movie map
            }

          }
        //******************************************************************************************
        //cout<<"WELCOME TO GETFLIX!!\n"<<endl;
       // mainDisplay();//starting the program when the file contents read in
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


Map<string,Movie*>* Netflix::returnMovieMap()
{
  return movieMap;
}

Map<string,User*>* Netflix::returnUserMap()
{
  return mapUser;
}



string Netflix::getLoggedInID()
{
  return loggedInID;
}


void Netflix::setLogginID(string an)
{
  loggedInID=an;
}

//LOGGEDINMENU
void Netflix::loggedInMenu()
{
 	cout<<"Welcome!"<<endl;
    cout<<"What is your log in ID?:";
    cin>>loggedInID;
    cout<<"\n";
    
    while(mapUser->keyExist(loggedInID)==false)//prompting them to enter a loginId that exists
    {
      cout<<"You didn't enter the correct login in ID, try again:";
      cin>>loggedInID;
      cout<<"\n";
      cout<<""<<endl;
    }

    if (mapUser->get(loggedInID))
    {
      keywordMenu();
    }
}


//KEYWORDMENU
void Netflix::keywordMenu()
{

      cout<<"\n";
      cout<<"1.Search for a movie by title"<<endl;
      cout<<"2.Search for a movie by keyword"<<endl;
      cout<<"3.Return Current Movie"<<endl;
      cout<<"4.View Queue"<<endl;
      cout<<"5.Logout"<<endl;
      cout<<"\n";
      cout<<"Enter number of command:";
      int yellow;
      cin>>yellow;
      cout<<"\n"<<endl;

      while(yellow<1 || yellow>5)
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
        keywordMenu();


      }

else if(yellow==2)
      {
            string newKeyWord1;
            cout<<"What keyword would you like to search for?:";
            cin.ignore();
            getline(cin, newKeyWord1);

            //checking if the movie map has movies with current keyword
            Map<string, Movie*>::Iterator firstIt = movieMap->begin();//makes iterator that points to first element of movieMap
            bool chose=true;
            int counter1=0;
            while(chose)
            {
              if(movieMap->size()!=0)//if map is not emppty
              {
                Pair<string, Movie*> temp = *firstIt;//temp is a pair that holds the key and value of the iterator
                if(temp.second->getAllKeywords().contains(newKeyWord1) || temp.second->getTitle()==newKeyWord1)
                {
                  counter1++;
                }
                try
                {
                  ++firstIt;//iterator go to next movieMap item
                }
                catch(NoSuchElementException)
                {
                  if(counter1==0)//if statement used to test wether keyword was found
                  {
                    cout<<"No match"<<endl;
                    keywordMenu();
                  }
                  chose=false;
                }
              }
              else
              {
                chose=false;
              }
            }

            //------------------------------------------------------------------------------------------------
            if(counter1>0)//if the keyword was found
            {
              //this second while loop prompts them to keep going to the next keyword
              Map<string, Movie*>::Iterator firstIt2 = movieMap->begin();//another iterator that we want to point to movieMap
              bool gooz=true;
              while(gooz)
              {
                Pair<string, Movie*> temp = *firstIt2;//temp is a pair that holds the key and value of the iterator
                int choice;
                if(temp.second->getAllKeywords().contains(newKeyWord1)|| temp.second->getTitle()==newKeyWord1)
                {
                  cout<<temp.first<<endl;
                  temp.second->getAllKeywords().printSet();//prints all keywords of the movie who's keyword was found
                  counter1--;
                  if(counter1>-1)
                  {
                    //int choice;
                    //counter1--;
                    if(counter1>0)
                    {
                    cout<<"\n1.Next movie"<<endl;
                    cout<<"2.Add movie to queue"<<endl;
                    cout<<"3.Return to menu"<<endl;
                    cin>>choice;
                    }
                    else if(counter1==0)
                    {
                    cout<<"2.Add movie to queue"<<endl;
                    cout<<"3.Return to menu"<<endl;
                    cin>>choice;
                    }
                    if(choice==1)
                    {
                      cout<<"\nGoing to next keyword:"<<endl;
                      //counter1--;
                    }
                    else if(choice==2)
                    {
                      Movie* newMovie = new Movie(temp.first);
                      mapUser->get(loggedInID)->movieQueue()->enqueue(newMovie);//added new movie to queue
                      counter1++;
                    }
                    else if(choice==3)
                    {
                      keywordMenu();
                    }
                  }
                  else if(counter1==-1)
                  {
                    cout<<"No more keywords to display! Going to main menu.\n"<<endl;
                    keywordMenu();
                  }
                }
                if(choice!=2)//so it will keep prompting them with same movie
                {
                  try
                  {
                    ++firstIt2;
                  }
                  catch(NoSuchElementException)
                  {
                    gooz=false;
                  }
                }
              }
            }
      }

      //return current movie
      else if(yellow==3)
      {
            if(mapUser->get(loggedInID)->currentMovie() == NULL)
            {
              cout<<"No current movie."<<endl<<endl;
              keywordMenu();
            }
            else
            {
              cout<<mapUser->get(loggedInID)->currentMovie()->getTitle()<<" has been removed."<<endl;
              mapUser->get(loggedInID)->returnMovie();//deleting the movie in currentMovie
            }
      }


      //printing queue
      else if(yellow==4)
      {
            Queue<Movie*> *temp = mapUser->get(loggedInID)->movieQueue();//making a temp que
            if(temp->isEmpty())
            {
              cout<<"Movie queue is empty"<<endl;
              keywordMenu();
            }
            else
            {
              bool test = true;    
              while(test==true)
              {
                string tempMovie=temp->peekFront()->getTitle();//making temp string for movie at head front of queue
                //cout<<tempMovie<<"\n"<<endl;

                  cout<<tempMovie<<endl;
                  int p;//this will take in their choice for the following menu
                  cout<<"1. Order movie" <<endl;
                  cout<<"2. Remove movie from queue" <<endl;
                  cout<<"3. Move movie to back of queue" <<endl;
                  cout<<"4. Return to user menu" <<endl;
                  cin>>p;

                  while(p<1 || p> 4)
                  {
                    cout<<"You entered the wrong choice. What option would you like?:";
                    cin>>p;
                  }
                  cout<<endl;

                  if(p==1)//if they want to order movie
                  {
                      if(mapUser->get(loggedInID)->currentMovie() == NULL)
                      {
                        Movie *chose = new Movie(temp->peekFront()->getTitle());//making new movie pointer to put into checked out movie(getting name from the front queue)
                        mapUser->get(loggedInID)->rentMovie(chose);//putting new movie pointer within the rented movie
                        temp->dequeue();
                        cout<<"Successfully checked out "<<tempMovie<<"."<<endl<<endl;
                      }
                      else
                      {
                        cout<<"You currently have a movie check out"<<endl;
                      }
                  }

                  else if(p==2)//if they want to remove movie from queue
                  {
                     
                        temp->dequeue();
                  }

                  else if(p==3)//if they want to movie movie to the back of queue
                  {
                      Movie *movieTemp=new Movie(tempMovie);
                      temp->dequeue();
                      temp->enqueue(movieTemp);
                  }

                  else if(p==4)//if they want to return to user menu
                  {
                      keywordMenu();
                  }

                  if(temp->isEmpty())//checks to see if movie queue is empty
                  {
                    cout<<"Movie queue is empty"<<endl<<endl;
                    keywordMenu();
                  }
              }
            }
      }



      else if(yellow==5)
      {
        cout<<"LOGGED OUT!"<<endl;
        cout<<" "<<endl;
        //mainDisplay();//prompts them with mainDisplay function if they logout

      }
}


/*//NEWUSERDISPLAY
void Netflix::newUserDisplay()
{
string newUserName;
    cout<<"Creating New User!"<<endl;
    cout<<"What is your user ID?:";
    cin>>loggedInID;
    cout<<""<<endl;
    while(mapUser->keyExist(loggedInID)==true)
    {
      cout<<"This ID already exists. Please enter another:";
      cin>>loggedInID;
      cout<<""<<endl;
    }
    cout<<"What is your user Name?:";
    cin.ignore();
    getline(cin, newUserName);
    User *userAccount = new User(loggedInID,newUserName);//make new user object
    mapUser->add(loggedInID,userAccount);//add the user object to your userMap
    cout<<"Your account has been made!"<<endl;
    keywordMenu();
}
*/

//WRITEFILE
void Netflix::writeFile()
{
	ofstream myFile;
    myFile.open(userFileName.c_str());//opens the user file and appends so you don't clear all contents
    if(!myFile.is_open())
    {
      cout<<"File could not be found!"<<endl;
    }


    else
    {
      try
      {
            for(Map<string, User*>::Iterator f =mapUser->begin(); f!=mapUser->end(); ++f)//looping through users
            {
              Pair<string, User*> p = *f;
              myFile<<"BEGIN "<<p.first<<endl;
              myFile<<"NAME: "<<p.second->getName()<<endl;
              myFile<<"PASSWORD: "<<p.second->getPassword()<<endl;
              if(p.second->currentMovie()!=NULL)
              {
                myFile<<"MOVIE: "<<p.second->currentMovie()->getTitle()<<endl;
              }
              if(!p.second->movieQueue()->isEmpty())
              {
                myFile<<"BEGIN QUEUE"<<endl;
                while(!p.second->movieQueue()->isEmpty())
                {
                  myFile<<p.second->movieQueue()->peekFront()->getTitle()<<endl;
                  p.second->movieQueue()->dequeue();
                }
                myFile<<"END QUEUE"<<endl;
              }
              //------------------
              Map<Movie*,int> *gayeed=p.second->rateMap();
              if(gayeed->size()!=0)
              {
                myFile<<"BEGIN RATINGS"<<endl;
                for(Map<Movie*, int>::Iterator g =gayeed->begin(); g!=gayeed->end(); ++g)
                {
                  Pair<Movie*, int> p = *g;//making pair that return the key and the value
                  myFile<<p.second<<" ";
                  myFile<<p.first->getTitle()<<endl;
                }
                myFile<<"END RATINGS"<<endl;
              }
              //----------
              myFile<<"END"<<endl;
            }
            myFile.close();
            exit(1);
      }
      catch (NoSuchElementException e)
      {
        cout<<"there was an exception caught! check your writing to file"<<endl;
        myFile<<"END RATINGS"<<endl;
        myFile<<"END"<<endl;
        myFile.close();
        exit(1);
      }
      
    }

    //when they succesfully login, display loginDisplay to them
}


  string Netflix::currentMovie()
  {
    User *idiot = mapUser->get(loggedInID);//getting the user pointer of the user
    if(idiot->currentMovie()==NULL)
    {
      return "";
    }
    Movie* khar = idiot->currentMovie();
    return khar->getTitle();
  }


  string Netflix::currentName()
  {
    User *idiot = mapUser->get(loggedInID);
    return idiot->getName();
  }

  string Netflix::getID()
  {
    return loggedInID;
  }

  bool Netflix::returnEmpty()
  {
    User *idiot = mapUser->get(loggedInID);
    if(idiot->currentMovie()==NULL)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  string Netflix::returnFrontQ()
  {
    User *idiot = mapUser->get(loggedInID);
    Queue<Movie*>* temp;
    temp=idiot->movieQueue();
    if(temp->isEmpty())
    {
      return "";
    }
    else
    {
      return temp->peekFront()->getTitle();
    }
  }


  bool Netflix::qEmpty()
  {
    User *idiot = mapUser->get(loggedInID);
    Queue<Movie*>* temp;
    temp=idiot->movieQueue();
    if(temp->isEmpty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void Netflix::dequeue()
  {
    User *idiot = mapUser->get(loggedInID);
    Queue<Movie*>* temp;
    temp=idiot->movieQueue();
    if(temp->isEmpty())
    {
    }
    else
    {
      temp->dequeue();
    }
  }

  void Netflix::returnTheMovie()
  {
    User *idiot = mapUser->get(loggedInID);
    idiot->returnMovie();
  }

  void Netflix::checkOut(Movie *m)
  {
     User *idiot = mapUser->get(loggedInID);
     idiot->rentMovie(m);
  }

  void Netflix::pushQ(Movie *m)
  {
    User *idiot = mapUser->get(loggedInID);
    Queue<Movie*> *gooz=idiot->movieQueue();
    gooz->enqueue(m);
  }


  //**IMPORTANT**
  int Netflix::findKeywords(string keyword)
  {
    Map<string, Movie*>::Iterator firstIt = movieMap->begin();//iterator that will check if keyword exists
    cerr << "Movie size: " << movieMap->size()<<endl;
    int counter1=0;
    bool chose=true;
    for (Map<string, Movie*>::Iterator it = movieMap->begin(); it != movieMap->end(); ++it) 
    {
      
            Pair<string, Movie*> temp = *it;//temp is a pair that holds the key and value of the iterator
            if(temp.second->getAllKeywords().contains(keyword) || temp.second->getAllActors().contains(keyword))
            {
              cout<<temp.second->getTitle()<<endl;
              cout<<"omggg"<<endl;
              counter1++;
            }
    }
    cout<<counter1<<endl;
    return counter1;//returns how many times the keyword was in there

  }
