// Specification file for Group class
#ifndef GROUP_H
#define GROUP_H
#include<iostream>
#include<string>
using namespace std;

// Group class declaration
class Group
{
	private:
		string player1, player2, player3; 	// Name of the players
	public:
		// Constructor
		Group();
		
		// Overloading consructors
		Group(string, string, string);
		
		// Destructor
		~Group();
		
		void setNames(string, string, string);	// Sets the name of the players
		string getName1();		// Returns the name of player1.
		string getName2();		// Returns the name of player2.
		string getName3();		// Returns the name of player3.
};
#endif



