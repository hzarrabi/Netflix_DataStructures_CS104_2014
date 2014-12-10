#include "User.h"
#include <iostream> 
#include <stdlib.h>
#include <string>

using namespace std; 
//constuctor
User::User (string ID, string name, string aPassword,string address, int ccNUM, int charges)
{
	userID=ID;
	userName=name;
	password=aPassword;
	this->address=address;
	ccNum=ccNUM;
	this->charges=charges;
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


string User::getPassword() const
{
	return password;
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
		int cost= m->getTitle().size();
		charges+=cost;
	}
}

//returnMovie
void User::returnMovie ()
{
	if(rentedMovie!=NULL)
	{
		//delete rentedMovie;
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
	try
	{
		for(Map<Movie*, int>::Iterator f =ratedMovies->begin(); f!=ratedMovies->end(); ++f)
		{
			Pair<Movie*, int> p = *f;//making pair that return the key and the value
			if(m==p.first->getTitle())
			{
				//in the case that the movie has been rated return false
				return false;
			}
		}
	}
	catch(NoSuchElementException)
	{
		return true;
	}

	return true;//this is called only if we reach the end without finding that the movie has been rated 
}


Map<Movie*,int> * User::rateMap()
{
	return ratedMovies;
}