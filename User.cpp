#include "User.h"
#include <iostream> 
#include <stdlib.h>
#include <string>

using namespace std; 
//constuctor
User::User (string ID, string name)
{
	userID=ID;
	userName=name;
	rentedMovie=NULL;
	numMovies=0;
	movieQ = new Queue<Movie*>;
}


//copy constructor
User::User (const User & other)
{
	userID=other.getID();
	userName=other.getName();
}

//deconstructor
User::~User ()
{
	if (rentedMovie!=NULL)
	{
		delete rentedMovie;
	}
	delete movieQ;
}

//getID
string User::getID () const
{
	return userID;
}


//getName
string User::getName () const
{
	return userName;
}

//movieQueue
Queue<Movie*>* User::movieQueue ()
{
	return movieQ;
}

//rentMovie
void User::rentMovie (Movie *m)
{
	if(rentedMovie!=NULL)
	{
		rentedMovie=m;//if there isn't aready a movie rented out
	}
}

//returnMovie
void User::returnMovie ()
{
	if(rentedMovie!=NULL)
	{
		delete rentedMovie;
		rentedMovie=NULL;
	}
}


//currentMovie
Movie* User::currentMovie ()
{
	return rentedMovie;
}

