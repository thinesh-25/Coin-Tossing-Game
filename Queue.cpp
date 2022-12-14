// Implementation file for Queue class
#include<iostream>
#include "Queue.h"
using namespace std;

// The constructor creates an empty queue.
Queue::Queue()
{
	front = NULL;
	rear = NULL;
	numItems = 0;
}

// Destructor
Queue::~Queue()
{
	int value;
	
	while(!isEmpty())
		dequeue(value);
}

// Function enqueue inserts the value in num
void Queue::enqueue(int value)
{
	QueueNode *newNode = NULL;
	
	// Create a new node and store value there.
	newNode = new QueueNode;
	newNode -> points = value;
	newNode -> next = NULL;
	
	// Adjust front and rear as necessary.
	if(isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	
	else
	{
		rear -> next = newNode;
		rear = newNode;
	}
	
	// Update numItems
	numItems++;
}

// Function dequeue removes the value at the
// front of the queue, and copies it into num.
void Queue::dequeue(int &value)
{
	QueueNode *nodePtr = NULL;
	
	if(isEmpty())
	{
		value = 0;
	}
	
	else
	{
		// Value is set as the points pointed by front.
		value = front -> points;
		
		// Front is set to the next node and the previous front is deleted.
		nodePtr = front;
		front = front -> next;
		delete nodePtr;
		
		// Update numItems.
		numItems--;
	}
}

// Function isEmpty returns true if the queue
// is empty, and false otherwise.
bool Queue::isEmpty()
{
	bool status;
	
	if(numItems > 0)
		status = false;
	else 
		status = true;
	
	return status;
}


