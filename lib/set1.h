#include "Set.h"
#include <iostream> 
#include <stdlib.h>

using namespace std; 


template <class T>
Set<T>::Set()//constructor
{

}

template <class T>
Set<T>::Set (const Set<T> & other):internalStorage(other.internalStorage)//copy constructor
{

}



template <class T>
Set<T>::~Set()//deconstructor
{

}



template <class T>
void Set<T>::add (const T & item)
{
	internalStorage.add(item, "");//adding item to set, second thing in parameter is empty quotes for useless string :)
}


template <class T>
int Set<T>::size () const
{
	return internalStorage.size ();//returns size of set
}


template <class T>
void Set<T>::remove (const T & item)
{
	internalStorage.remove(item);//removes item if key found
}


template <class T>
bool Set<T>::contains (const T &item) const 
{
	bool success = false; 
	string s = internalStorage.get(item);//if item found then change success to true, and return success?
	return success;
}


template <class T>
void Set<T>::merge (const Set<T> & other)//merge new set with old set(map)
{
	internalStorage.merge(other.internalStorage);//other is the second map you're merging into internal storage?

}



template <class T>
bool Set<T>::deepS (const T &item)
{
bool success=false;
success=internalStorage.deepM(item);
return success;
}

