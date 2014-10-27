#include <exception>

#ifndef QUEUE_H
#define QUEUE_H




template <class T>
struct qItem
{
  T value;
  qItem<T> *next;
  qItem<T> *prev;
};


class EmptyQueueException:public std::exception//for exception when queue is empty 
{
public:
  virtual const char* what() const throw()
  {
   return "Empty Queue!";
  }

};



template <class T>
class Queue {
  public:
  	Queue();

  	~Queue();

    void enqueue (const T & item);
      /* adds the item to the end of the queue.
         The same item may be added many times. */

    void dequeue (); 
      /* removes the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    const T & peekFront ();
      /* returns the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */

    bool isEmpty ();
      /* returns whether the queue is empty. */

  private: 
  	qItem<T> *head;
  	qItem<T> *tail;
  	int qSize;



};



#include "queueImp.h"
#endif