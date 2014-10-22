#include "Map.h"

#ifndef SET_H
#define SET_H

template <class T>
class Set
{
  public:
    Set ();  // constructor for a new empty set


    Set (const Set<T> & other);//COPY CONSTRUCTOR
	

    ~Set (); // destructor



    Set<T>& operator=(const Set<T> & other);//overload operator for set

    int size () const; // returns the number of elements in the set

    void add (const T &item); 
      /* Adds the item to the set.
         If the item is already in the set, it should do nothing.
      */

    void remove (const T &item);
     /* Removes the item from the set.
        If the item was not in the set, it should do nothing. */

    bool contains (const T &item) const;
     /* Returns whether the item is in the set. */

    void merge (const Set<T> & other);
     /* Adds all elements of other to this set. 
        However, will not create duplicates, i.e., it ignores elements
        already in the set. */

    void first();//makes curEl pointer point to the first element so head?

    void next();//makes curEl point to the next element;

    const T & getCurrent ();//gets curent key that curEl is at

    Set<T> setUnion (const Set<T> & other) const;


    Set<T> setIntersection (const Set<T> & other) const;

    void printSet();//prints all keys of the set

    void deleteSet();//deallocates set


  private:
    Map<T, string> internalStorage;
     

    
};

#include "set1.h"
#endif
