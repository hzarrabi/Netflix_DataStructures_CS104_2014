#include "Queue.h"
#include <iostream> 
#include <stdlib.h>

using namespace std;

//constructor
template <class T>
Queue<T>::Queue()
{
	head=NULL;
  	tail=NULL;
  	qSize=0;
}

//deconstructor
template <class T>
Queue<T>::~Queue()
{
	qItem<T> *P;//this pointer points to whatever stack item we need to delete
	for(int i=0; i<qSize; i++)
	{
		P=tail;
		tail=P->next;
		delete P;
	}
}


//enqueue
template <class T>
void Queue<T>::enqueue (const T & item)
{
	qItem<T> *newItem = new qItem<T>;
	newItem->value=item;
	if(qSize==0)
	{
		newItem->prev=NULL;
		newItem->next=NULL;
		head=newItem;
		tail=newItem;
		qSize++;
	}

	else
	{
		tail->prev=newItem;
		newItem->next=tail;
		newItem->prev=NULL;
		tail=newItem;
		qSize++;
	}
}

//dequeue
template <class T>
void Queue<T>::dequeue ()
{
	if(qSize==0)
	{
		throw EmptyQueueException();
	}
	else
	{
		qItem<T> *tempItem=head;
		head=head->prev;
		head->next=NULL;
		delete tempItem;
		qSize--;
	}
}


//peekFront
template <class T>
const T & Queue<T>::peekFront ()
{
	if(qSize=0)
	{
		throw EmptyQueueException();
	}
	return head->value;
}


//isempty
template <class T>
bool Queue<T>::isEmpty ()
{
	if(qSize==0)
	{
		return true;
	}
	return false;
}
