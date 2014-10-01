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



