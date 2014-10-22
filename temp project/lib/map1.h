#include "Map.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>


using namespace std;


//CONSTRUCTOR
template <class keyType, class valueType>
Map<keyType, valueType>::Map()//constructor for map
{
	head=NULL;
	tail=NULL;
	numItems=0;
	curEl=NULL;
}



//COPY CONSTRUCTOR
template <class keyType, class valueType>
Map<keyType, valueType>::Map (const Map<keyType, valueType> & other)
{
	head = NULL;
	tail = NULL;
	numItems=0;
	curEl=NULL;
	
	
	MapItem <keyType, valueType> *tempP;
	tempP=other.head;
	
	while (tempP!= NULL)
	{
		this->add(tempP->key,tempP->value);
		tempP=tempP->next;		
	}
}





//DECONSTRUCTOR
template <class keyType, class valueType>
Map<keyType, valueType>::~Map()//constructor for map
{

}




//operator overloading
template <class keyType, class valueType>
Map<keyType, valueType>& Map<keyType, valueType>::operator=(const Map<keyType, valueType> &other) //you return Map<keyType, valueType>& becaue you want to be able to do a=b=c and you don't want to return void on b
{
	//if the two maps are the same
	if(this==&other)
	{
		return *this;
	}


	MapItem <keyType, valueType> *current=this->head;//will set current to head
	MapItem <keyType, valueType> *tempP;//will be set to current in while loop then deleted
	
	while(current!=NULL)//deletes all items in map so other maps items can be copied over later
	{
		tempP=current;
		current=current->next;
		delete tempP;
	}
	this->head=NULL;//will set the head and tail of the map to null because it's empty now
	this->tail=NULL;   


	//adding everything from one map to other
	tempP=other.head;
	while (tempP!= NULL)
	{
		this->add(tempP->key,tempP->value);
		tempP=tempP->next;		
	}

	return *this;
}




//SIZE
template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
	return numItems;
}



//KEY EXIST
template<class keyType, class valueType> 
bool Map<keyType, valueType>::keyExist(keyType key) const
{
	if(head==NULL)//if map is empty
	{
		return false;
	}	

	MapItem<keyType, valueType>* tempP;
	tempP=head;

	while(tempP!=NULL)
	{
		if(tempP->key==key)//if key exists
		{
			return true;
		}

		else//key hasn't been found yet
		{
			tempP=tempP->next;
		}
	}
	return false;//if key not found in map returns false
}


//ADD
template <class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key, valueType value)//add function for end
{
	if(this->keyExist(key)==false)//checks to see if key exists before adding key
	{
		MapItem <keyType, valueType> *tempP;//temp variable 
		tempP=head;
		if(head==NULL && tail==NULL)//the case where map is empty 
		{
			MapItem<keyType, valueType> *newItem=new MapItem <keyType, valueType>();//making new instance of map item
			head = newItem;
			tail = newItem;


			newItem->key=key;
			newItem->value=value;
			newItem->prev=NULL;
			newItem->next=NULL;
			numItems++;

			curEl=head;//make curEl point to head
		}

		else //it has one or more items
		{	
			if(tempP->next==NULL)//when there is one item
			{
			MapItem<keyType, valueType> *newItem=new MapItem <keyType, valueType>();//new instance map
			newItem->prev=tail;
			tail->next=newItem;//sets previous to next
			tail=newItem;
			newItem->next=NULL;

			newItem->key=key;
			newItem->value=value;
			//numItems++;

			}
			/*while(tempP->next!=NULL)
			{
				if(tempP->key==key)//if key trying to add exists exit
				{
					//cout<<"The item with this key already exists"<<endl;
					return;			
				}
				tempP=tempP->next;*/
		
				
			//more than one item add to the end
			else
			{
			MapItem<keyType, valueType> *newItem=new MapItem <keyType, valueType>();//new instance map
			tail->next=newItem;
			newItem->prev=tail;
			tail=newItem;
			newItem->next=NULL;

			newItem->key=key;
			newItem->value=value;
			numItems++;
			//break;
			}
				
		}
	}
}


//REMOVE
template <class keyType, class valueType>
void Map<keyType, valueType>::remove (keyType key)
{
	if(keyExist(key)==false)//if key we're trying to find isn't there throw exception
	{
		throw NoSuchElementException();
	}

	

	//key does exists
	else
	{
		MapItem <keyType, valueType> *tempP;//temp variable that is set equal to old tail(used for new items previous)
		tempP=head;//temp var that holds value that head points to
		
		if(head->prev==NULL && head->next==NULL)//if there is only one item in map
		{
			if(key==head->key)//key found
			{
			cout<<"The key has been found and the item has been deleted"<<endl;
			delete head;
			head=NULL;
			tail=NULL;
			curEl=head;//makes curEl = to head which is null if you remove the only element
			numItems--;
			//DELETE THE ITEM			
			}
		}	
		else//if there is more than one element
		{	
			while(tempP!= NULL )
			{
				if(tempP->key==key)
				{
					if(tempP->prev==NULL && tempP->next != NULL)//if first one is key
					{
						if(curEl==head)//makes curEl = to the second element that is now beoming the first 
						{
							curEl=tempP->next;
						}

						head=tempP->next;
						head->prev=NULL;
						numItems--;
						delete tempP;//deletes that first item
						return;						
					}
					else if(tempP->next==NULL && tempP->prev!=NULL)//if last one is key
					{
						if(curEl==tail)//if curEl is point to the thing at the end and it get removed point it to head
						{
							curEl=head;
						}
						tail=tempP->prev;
						tail->next=NULL;
						numItems--;
						delete tempP;
						return;						
					}
					else//the key is in the middle
					{
						tempP->prev->next=tempP->next;//previous points to next
						tempP->next->prev=tempP->prev;//next points to previous	
						numItems--;
						delete tempP;
						return;			
					}
				}
				else//the hasn't been found go to the next item
				{
					tempP=tempP->next;
				}
			}	
		}
	}
}





//GET
template <class keyType, class valueType>
const valueType & Map<keyType, valueType>::get (const keyType & key) const
{
	MapItem <keyType, valueType> *tempP;//temp variable 
	tempP = head;
	//valueType result;
	if(head == NULL)//the case where map is empty 
	{
		//cout<<"The map is empty"<<endl;
		//NoSuchElementException e;if map empty throw an exception
		throw NoSuchElementException();

	}
	else  //it has one or more items
	{	
		while(tempP != NULL)//when there is one item
		{
			if(tempP->key == key)
			{
				//break;
				return tempP->value;//if key found return its' value
			}
			else
			{
			tempP= tempP->next;
			}
		}
		
		//in the case that you reach the end and the item has not been found you don't break so you have to throw this exception
		//NoSuchElementException e;//if you reach end of map and haven't found key exception thrown
		throw NoSuchElementException();//the key does not exist
	}

	//return tempP->value;
}



//MERGE
template <class keyType, class valueType>
void Map <keyType, valueType>::merge (const Map<keyType, valueType> & other)
{
	MapItem <keyType, valueType> *tempP;//temp variable 
	tempP = other.head;
	
	while (tempP!= NULL)
	{
			
		add(tempP->key, tempP->value);
		tempP = tempP->next;
	}
	
	//other->head

}



template <class keyType, class valueType>
void Map <keyType, valueType>::first()
{
	if(head==NULL)
	{
		//NoSuchElementException e;
		throw NoSuchElementException();
	}
	
	curEl=head;

}





template <class keyType, class valueType>
void Map <keyType, valueType>::next()
{
	if(curEl->next==NULL || head==NULL)
	{
		//NoSuchElementException e;
		throw NoSuchElementException();
	}
	curEl=curEl->next;

}

template <class keyType, class valueType>
const keyType & Map <keyType, valueType>::getCurrentKey ()
{
	if(head==NULL)//if map is empty throw NoSuchElementException
	{
		throw NoSuchElementException();
	}
	return curEl->key;
}


template <class keyType, class valueType>
const valueType & Map <keyType, valueType>::getCurrentValue()
{
	if(head==NULL)//if map is empty throw NoSuchElementException
	{
		throw NoSuchElementException();
	}
	return curEl->value;
}


template <class keyType, class valueType>
void Map <keyType, valueType>::printKeys()
{
	MapItem <keyType, valueType> *tempP;
	tempP=head;
	while(tempP!=NULL)
	{
		cout<<tempP->key<<endl;
		tempP=tempP->next;
	}
	cout<<"\n"<<endl;
}


//DELETE MAP
template <class keyType, class valueType>
void Map <keyType, valueType>::deleteMap()
{
	if(this->size()==0)
	{
		return;
	}
	MapItem<keyType, valueType> *temp=head;
	MapItem<keyType, valueType> *temp1;
	while(temp!=NULL)
	{	
		temp1=temp->next;
		if(temp1==NULL)
		{
			delete temp1;
			delete temp;
			break;
		}
		delete temp;
		temp=temp1;
	}
}