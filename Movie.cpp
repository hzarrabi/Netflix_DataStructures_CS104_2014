#include "Movie.h"
#include <iostream> 
#include <stdlib.h>
#include <string>

using namespace std; 


//constructor for movie class
Movie::Movie(string title)
{
	movieTitle=title;
}


//copy constucture 
Movie::Movie (const Movie & other)
{
	movieTitle=other.getTitle();//copying the other movie's title to the constructed one's title
	keywords=other.getAllKeywords();//copy the set of other into this new one using operator overload

}


//deconstructor
Movie::~Movie ()
{

}

//getTitle
string Movie::getTitle () const
{
return movieTitle;
} 

//addKeyword
void Movie::addKeyword (string keyword)
{
	keywords.add(keyword);//adds keyword to the keywords set
}



//getAllKeywords
Set<string> Movie::getAllKeywords () const
{
	return keywords;
}

