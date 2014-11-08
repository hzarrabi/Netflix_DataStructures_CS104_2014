#ifndef NETFLIX_H
#define NETFLIX_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Set.h"
#include "MergeSort.h"
#include "../Movie.h"
#include "../User.h"

using namespace std;


class Netflix
{
public:
	Netflix();
	~Netflix();
	void fileInput(string mainFile);//function that reads in things from the files
	bool userExists(string hello);//menu prompy when u start(login,new user, quit)
	string currentMovie();//returns the current movie that's checked out
	bool returnMovie();//function that checks to see if there is a movie checked out
	string currentName();//returns the current user of who's signed in
	string getID();

	string returnFrontQ();//returns the item at the front of the queue
	bool qEmpty();//tells if the queue is empty


private:

	//all other functions that either get called in eachother or in fileinput()
	void loggedInMenu();//menu when you log in
	void keywordMenu();//menu that appears when you want to search for title,keyword. etc
	void newUserDisplay();//meny for adding new user
	void writeFile();//function that rights to the file
	string getLoggedInID();


	//private varibles
	string loggedInID;//functions that hold the id of the person that just signed in(each NetFlix will have specific ID logged in)
	string mainFileName;//the name of the main file that holds names of the other files
	string userFileName;//this hold the name of the userFile that we will later WRITE TO!!
	
	Map<string,User*>  *mapUser;//map that takes user id and object of type user
    Map<string,Movie*> *movieMap;//map that hold the movie name and movie objects


};

#endif