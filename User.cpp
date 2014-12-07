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
	ratedMovies = new Map<Movie*,int>;
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
	if(rentedMovie==NULL)
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

void User::addRatedMovies(Movie *m, int rating)
{
	ratedMovies->add(m,rating);
}


bool User::containsRatedMovie(string m)
{
	//this for loop will loop through the map of rated movies to see if the movie exists
	for(Map<Movie*, int>::Iterator f =ratedMovies->begin(); f!=ratedMovies->end(); ++f)
	{
		Pair<Movie*, int> p = *f;//making pair that return the key and the value
		if(m==p.first->getTitle())
		{
			//in the case that the movie has been rated return false
			return false;
		}
	}

	return true;//this is called only if we reach the end without finding that the movie has been rated 
}
