//Specification file for Queue class
#ifndef QUEUE_H
#define QUEUE_H

// Queue class declaration  
class Queue
{
	private:
		// Structure for the queue nodes
		struct QueueNode
		{
			int points;			// Value in a node
			QueueNode *next;	// Pointer to the next node
		};
		
		QueueNode *front;		// The front of the queue
		QueueNode *rear;		// The rear of the queue
		int numItems;			// Number of items in the queue
	
	public:
		//Constructor
		Queue();
		
		//Destructor
		~Queue();
		
		//Stack Operations
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty();
};
#endif


