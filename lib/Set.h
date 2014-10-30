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
   
    void remove (const T &item);

    bool contains (const T &item) const;

    void merge (const Set<T> & other);

    Set<T> setUnion (const Set<T> & other) const;

    Set<T> setIntersection (const Set<T> & other) const;

    void printSet();//prints all keys of the set
    //============================================================================
     class Iterator 
     {
         public:
          friend class Set<T>;

           T operator* () const;
              // return the item the iterator is at

           Set<T>::Iterator operator++ ();
              // advances the iterator (pre-increment)

           Set<T>::Iterator operator= (const Set<T>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Set<T>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Set<T>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */

           /* You may define a public copy constructor and/or default constructor
              if you think it would be helpful. */

         private:

          const Set<T> *setParent;//pointer to the set that the iterator belongs to

          const typename Map<T, string>::Iterator *mapIt;

          Iterator(const Set<T>* setPtr, typename Map<T, string>::Iterator mapIt);
     };

  private:
    Map<T, string> internalStorage;

    Set<T>::Iterator begin () const;
       // returns an iterator initialized to the first element

    Set<T>::Iterator end () const;
     /* returns an iterator initialized past the last element,
        to designate that the end of the map has been reached. */


     

    
};

#include "set1.h"
#endif
