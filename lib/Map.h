#ifndef MAP_H
#define MAP_H


template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


class NoSuchElementException//for exception handling
{
public:
    NoSuchElementException(){};//excption
    ~NoSuchElementException (){};
};


//pair struct
template <class FirstType, class SecondType> 
struct Pair 
{
   FirstType first;
   SecondType second;

   Pair (FirstType first, SecondType second)
      { 
        this->first = first; 
        this->second = second; 
      }
   // we're very nice and give you this piece of difficult code for free :-P
};





template <class keyType, class valueType>
class Map
{
  public:
    Map (); // constructor for a new empty map
    
    Map (const Map<keyType, valueType> & other);//copy constructor!!!!!!

    ~Map (); // destructor

    Map<keyType, valueType>& operator=(const Map<keyType, valueType> &other);//operator overloading for "="
    //returns Map type incase we do a=b=c;

    int size () const; // returns the number of key-value pairs

    void add (keyType key, valueType value);
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (keyType key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    const valueType & get (const keyType & key) const;
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

    bool keyExist(keyType key) const;

    void printKeys();//prints the keys of the map (also used for set)
    //====================================================================================================================
    //iterator stuff
    class Iterator 
    {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */

         public:
            friend class Map<keyType, valueType>;

           Pair<keyType, valueType> operator* () const;
              // return the current (key, value) pair the iterator is at

           Map<keyType, valueType>::Iterator operator++ ();
              // advances the iterator (pre-increment)

           Map<keyType, valueType>::Iterator operator= (const Map<keyType, valueType>::Iterator & other);
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Map<keyType, valueType>::Iterator & other) const;
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Map<keyType, valueType>::Iterator & other) const;
              // returns whether this iterator is not equal to the other iterator

           Iterator();//will help you for set iterator when you try to initialize a iterator for your 
           //set because you can't access the assignment operator


           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */

           /* You may define a public copy constructor and/or default constructor
              if you think it would be helpful. */

        private:

            const Map<keyType, valueType> *mapParent;//this will store the map that the iterator belongs to

            MapItem<keyType, valueType> *itemIt; //this is the mapItem pointer that will point to a specific item

            Iterator(const Map<keyType, valueType> *mapPtr, MapItem<keyType, valueType> *item);//constuctor of Iterator

    };    



     Map<keyType, valueType>::Iterator begin () const;
       // returns an iterator initialized to the first element

     Map<keyType, valueType>::Iterator end () const;
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;

     MapItem <keyType, valueType> *curEl;//this is the mapItem pointer we will use for the traversal funtions 




     /* If you like, you can add further data fields and private
        helper methods. */
	
     int numItems;//keeps track of the number of items
};

#include "map1.h"
#endif
