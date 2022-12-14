// Implementation file for Group class
#include<iostream>
#include<string>
#include "Group.h"
using namespace std;

// Constructor
Group::Group()
{
	player1 = "";
	player2 = "";
	player3 = "";
}
// Overloading constructor
Group::Group(string name1, string name2, string name3)
{
	player1 = name1;
	player2 = name2;
	player3 = name3;
}

// Destructor
Group::~Group()
{
	player1 = "";
	player2 = "";
	player3 = "";
}

// The setNames member function sets the player's name.
void Group::setNames(string name1, string name2, string name3)
{
	player1 = name1;
	player2 = name2;
	player3 = name3;
}

// The getName1 member function returns the name of player 1.
string Group::getName1()
{
	return player1;
}

// The getName2 member function returns the name of player 2.
string Group::getName2()
{
	return player2;
}

// The getName3 member function returns the name of player 3.
string Group::getName3()
{
	return player3;
}







