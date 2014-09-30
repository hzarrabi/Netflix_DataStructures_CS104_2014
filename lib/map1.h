#include "Map.h"
#include <iostream>
#include <stdlib.h>


using namespace std;


//CONSTRUCTOR
template <class keyType, class valueType>
Map<keyType, valueType>::Map()//constructor for map
{
	head=NULL;
	tail=NULL;
	numItems=0;
}



//COPY CONSTRUCTOR
template <class keyType, class valueType>
Map<keyType, valueType>::Map (const Map<keyType, valueType> & other)
{
	head = NULL;
	tail = NULL;
	numItems=0;
	
	
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
	MapItem <keyType, valueType> *current=this->head;//will set current to head
	MapItem <keyType, valueType> *tempP;//will be set to current in while loop then deleted
	while(current!=NULL)
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


//ADD
template <class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key, valueType value)//add function for end
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
	}

	else  //it has one or more items
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
		while(tempP->next!=NULL)
		{
			if(tempP->key==key)//if key trying to add exists exit
			{
				//cout<<"The item with this key already exists"<<endl;
				return;			
			}
			tempP=tempP->next;
	
			
			if(tempP->next==NULL)//when you reach end means you can add item to end
			{
				MapItem<keyType, valueType> *newItem=new MapItem <keyType, valueType>();//new instance map
				tail->next=newItem;
				newItem->prev=tail;
				tail=newItem;
				newItem->next=NULL;

				newItem->key=key;
				newItem->value=value;
				numItems++;
				break;
			}
		}		
			
	}
}


//REMOVE
template <class keyType, class valueType>
void Map<keyType, valueType>::remove (keyType key)
{
	MapItem <keyType, valueType> *tempP;//temp variable that is set equal to old tail(used for new items previous)
	tempP=head;//temp var that holds value that head points to
	if(head==NULL)
	{
		return;
	}
	else
	{
		if(head->prev==NULL && head->next==NULL)//if there is only one item in map
		{
			if(key==head->key)//key found
			{
			cout<<"The key has been found and the item has been deleted"<<endl;
			head=NULL;
			tail=NULL;
			numItems--;
			//DELETE THE ITEM			
			}
			else
			{
			cout<<"The item with the key was not found!"<<endl;
			}
		}	
		else//if there is more than one element
		{	
			while(tempP->next != NULL )
			{
				if(tempP->key==key)
				{
					if(tempP->prev==NULL && tempP->next != NULL)//if first one is key
					{
						head=tempP->next;
						head->prev=NULL;
						numItems--;
						return;						
					}
					else if(tempP->next==NULL && tempP->prev!=NULL)//if last one is key
					{
						tail=tempP->prev;
						tail->next=NULL;
						numItems--;
						return;						
					}
					else if (tempP->next==NULL && tempP->prev==NULL)//if there is one element
					{
						head=NULL;
						tail=NULL;
						numItems--;
						return;		
					}
					else
					{
						tempP->prev->next=tempP->next;
						tempP->next->prev=tempP->prev;	
						numItems--;
						return;			
					}
				}

				else
				{
					tempP=tempP->next;
				}
				
				
			}
			
		}
	}
}





//GET
template <class keyType, class valueType>
const valueType & Map<keyType, valueType>::get (const keyType & key, bool & success) const
{
	MapItem <keyType, valueType> *tempP;//temp variable 
	tempP = head;
	bool keer = true;
	//valueType result;
	if(head == NULL)//the case where map is empty 
	{
		cout<<"The map is empty"<<endl;

	}
	else  //it has one or more items
	{	
		while(tempP != NULL)//when there is one item
		{
			if(tempP->key == key)
			{
				success=keer;
				break;
			}
			else
			{
			tempP= tempP->next;
			}
		}

	}

	return tempP->value;
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
bool Map <keyType, valueType>::deepM(keyType key)
{

	if (head->key==key)
	{
		return true;
	}

	else
	{
		return false;
	}
}
