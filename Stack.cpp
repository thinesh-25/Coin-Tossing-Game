// Implementation file for Stack class
#include<iostream>
#include "Stack.h"
using namespace std;

// Constructor
Stack::Stack()
{
	top = NULL;
}

// Destructor
// This function deletes every nodes in the list.
Stack::~Stack()
{
	StackNode *temp;
	
	// Traverse the list deleting each node.
	while(top != NULL)
	{
		temp = top;			// Position temp at the top of the stack.
		top = top -> next;
		delete temp;
	}
}

// Member function push pushes the argument onto the stack.
void Stack::push(int value)
{
	StackNode *newNode = NULL;		// Pointer to a new node
	
	
	// Allocate a new node and store value there.
	newNode = new StackNode;
	newNode -> points = value;
	
	
	// If there are no nodes in the list
	// make newNode the first node.
	if(isEmpty())
	{
		top = newNode;
		top -> next = NULL;
	}
	
	else	// Otherwise, insert new node before top.
	{
		newNode -> next = top;
		top = newNode;
	}
}


// Member function pop pops the value at the top
// of the stack off, and copies it into the variable
// passed as an argument.
void Stack::pop(int &value)
{
	StackNode *nodePtr = NULL;		// Temporary pointer
	
	// Making sure the stack is empty
	if(isEmpty())
	{
		value = 0;
	}
	
	else	// Pop value from the top of stack
	{
		value = top -> points;
		nodePtr = top -> next;
		delete top;
		top = nodePtr;
	}
}

// Member function isEmpty returns true if the stack
// is empty, or false otherwise.
bool Stack::isEmpty()
{
	if(top == NULL)
		return true;
	else 
		return false;
}
