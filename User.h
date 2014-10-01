#ifndef USER_H
#define USER_H

#include "lib/Set.h"
#include "lib/Map.h"
#include <string>
#include <iostream>
using namespace std;


class User {
  public:
    User (string ID, string name);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User (const User & other); // copy constructor

    ~User ();            // destructor

    string getID () const;    // returns the ID associated with this user

    string getName () const;  // returns the name associated with this user

  private:
    //Map<string,string> Account;//map that holds string ID as well as the string name 
    string userID;
    string userName;
};

#endif