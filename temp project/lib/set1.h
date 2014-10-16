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

//overload operator
template <class T>
Set<T>& Set<T>::operator=(const Set<T> &other)
{
	internalStorage=other.internalStorage;//use the overload constructor for map

	return *this;

}




//add
template <class T>
void Set<T>::add (const T & item)
{
	internalStorage.add(item, "");//adding item to set, second thing in parameter is empty quotes for useless string :)
}

//size
template <class T>
int Set<T>::size () const
{
	return internalStorage.size ();//returns size of set
}

//remove
template <class T>
void Set<T>::remove (const T & item)
{
	internalStorage.remove(item);//removes item if key found
}

//contains
template <class T>
bool Set<T>::contains (const T &item) const
{
	bool success = true; 
	try
	{
		internalStorage.get(item);//if item found then change success to true, and returns success
	}
	catch(NoSuchElementException)
	{
		success = false;//if the exception has been caught (key hasn't been found) then you set success to false
	}
	return success;
}

//merge
template <class T>
void Set<T>::merge (const Set<T> & other)//merge new set with old set(map)
{
	internalStorage.merge(other.internalStorage);//other is the second map you're merging into internal storage?
}




//first
template <class T>
void Set<T>::first()//makes curEl pointer point to the first element so head?
{
	try
	{
		internalStorage.first();
	}

	catch(NoSuchElementException)
	{
		cout<<"Your set set is empty. No first element."<<endl;
	}
}


//next
template <class T>
void Set<T>::next()//makes curEl point to the next element
{
	try
	{
		internalStorage.next();
	}

	catch(NoSuchElementException)
	{
		cout<<"Cannot get next element."<<endl;
	}
}

//getCurrent (key)
template <class T>
const T & Set<T>::getCurrent () 
{
	return internalStorage.getCurrentKey ();
}


//set Union
template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const
{
	Set<T> tempSet(*this);//copy constructing a tempSet that take in all the values of this

	tempSet.merge(other);//merging the tempSet an the set passed in

	return tempSet;
}



//set Intersection
template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const
{
	Set<T> tempSet;//making a new tempSet that takes in all the keys that are the same

	for(int i =0; i < other.size(); i++)
	{

		if(this->contains(other.getCurrent()))//if other's item is in this then put that item in the new set
		{
			tempSet.add(other.getCurrent());
		}
		other.next();//then iterate curEl to the next item
	}

	return tempSet;
}


//set Intersection
template <class T>
void Set<T>::printSet()
{
	internalStorage.printKeys();//prints the keys of the set
}