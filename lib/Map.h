#ifndef MAP_H
#define MAP_H


template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map
    
    Map (const Map<keyType, valueType> & other);//copy constructor!!!!!!

    ~Map (); // destructor

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

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;

     /* If you like, you can add further data fields and private
        helper methods. */
	
     int numItems;//keeps track of the number of items
};

#include "map1.h"
#endif
