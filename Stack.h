//Specification file for Stack class
#ifndef STACK_H
#define STACK_H

// Stack class declaration
class Stack
{
	private:
		// Structure for stack nodes
		struct StackNode
		{
			int points;			// Value in the node
			StackNode *next;	// Pointer to the next node
		};
		StackNode *top;			// Pointer to the stack top
	
	public:
		// Constructor
		Stack();
		
		// Destructor
		~Stack();
		
		// Stack Operations
		void push(int);
		void pop(int &);
		bool isEmpty();
};
#endif


