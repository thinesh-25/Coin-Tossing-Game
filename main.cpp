//Preprocessor directives
#include<iostream>
#include<string>
#include <cstdlib>	// For rand and srand
#include <ctime>	// For the time function
#include <stdlib.h>
#include <unistd.h>
#include "Group.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

// Function prototypes
void players(string &, string &, string &);
void game(Group &, Group &, Stack &, Queue &);
void instructions();
int tossCoin();
void screen();

// Function main
int main()
{
	Group g1, g2;	// Greate g1 and g2 as objects.
	Stack s;		// Create a s object.
	Queue q;		// Create a q object.
	
	string p1, p2, p3;
	int x; 			// To hold value popped off the stack.
	int y; 			// To hold value enqueued in the queue.
	int total1 = 0, total2 = 0;
	int sml=1;
	char ch=sml;
	
	
	// Instructions
	cout << "\n\n\t\t" << "This is a Coin Tossing ~ Intuitive Game: \n";
	cout << "\t\t" << "There will be Group 1 versus Group 2, where each group consists of 3 players.\n\n\n";
	
	cout << "\t\t" << "Hello Group 1, please enter the details of the players!" << ch << endl;
	cout << "\n";
	
	// Function calls
	players(p1, p2, p3);
	g1.setNames(p1, p2, p3);
	
	cout << "\t\t" << "Hello Group 2, please enter the details of the players!" << ch << endl;
	cout << "\n";
	
	// Function calls
	players(p1, p2, p3);	
	g2.setNames(p1, p2, p3);
	
	cout << "\t\tGood Luck Group 1 and Group 2 !  ^-^"<< endl;
	cout << "\t\tPlease open the windows in fullscreen for better user experience." << ch << endl;
	sleep(5);
	
	// Function call
	screen();
	
	game(g1, g2, s, q);
	
	// Calculates the total points scored by each group
	for(int i = 0; i < 9; i++)
	{
		s.pop(x);		// Pop the values of the stack.
		q.dequeue(y);	// Dequeue the values in the queue.
		total1 = total1 + x;	// Pushed value is accumulated.
		total2 = total2 + y;	//Enqueued value is accumulated.
	}
	
	cout <<"\t\t\t\t\t THE FINAL RESULTS ARE HERE!\n\n" << endl;
	sleep(5);
	cout << "\t\t" << "The total points earned by Group 1 are " << total1 << "."<< endl;
	cout << "\t\t" << "The total points earned by Group 2 are " << total2 << "."<< endl;
	
	
	// Winner declaration
	if(total1 > total2)
	{
		cout << endl << endl << "\t\t" << "Wohooo Congratulations, Group 1 is the winner!\n";
	}
	else if(total2 > total1)
	{
		cout << endl << endl << "\t\t" << "Wohooo Congratulations, Group 2 is the winner!\n";
	}
	else
		cout << endl << endl << "\t\t" << "Wohooo Congratulations, both groups had a draw! Play another round to choose the winner!\n";
	
}

// Definition of function players.
// This function gets the name of the players.
void players(string &p1, string &p2, string &p3)
{
	cout << "\t\t" << "Name of Player 1 : ";
	getline(cin, p1);
	cout << "\t\t" << "Name of Player 2 : ";
	getline(cin, p2);
	cout << "\t\t" << "Name of Player 3 : ";
	getline(cin, p3);
	cout << "\n";
}

// Definition of function instructions.
// This function is used to display the instructions of the game throughout the play.
void instructions()
{
	cout <<"\n\n\t\t\t\t" << "Welcome to World of Matching Pennies Game , all it takes is good luck and great intuition!\n\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout <<"\t\t" << "Instructions of the game: \n";
	cout <<"\t\t" << "a. This is a one-on-one game between two groups.\n";
	cout <<"\t\t" << "b. The tossing of coin is simulated by random number generator.\n";

	cout <<"\t\t" << "c. If player 1's choice and player 2's choice are the same, the game will be a draw yet,\n";
	cout <<"\t\t" << "   the tossed coin by the system is used to determine whether the chosen choice is correct or not,\n"; 
	cout <<"\t\t" << "   if correct, both groups are awarded 25 points. If the answer is incorrect, neither group benefits.\n";
	cout <<"\t\t" << "d. If the system tosses a coin that is similar to the coin chosen by player from Group 1, then Group 1 earns 50 points.\n";
	cout <<"\t\t" << "e. If the system tosses a coin that is similar to the coin chosen by player from Group 2, then Group 2 earns 50 points.\n";
	cout <<"\t\t" << "f. According to the rules of the game, no groups will be penalised by losing points.\n";
	cout <<"\t\t" << "g. To determine the winning group, three rounds will be held and highest total points accumulated group will be the winner.\n\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout <<"\n\n\t\t" << "Choose Heads or Tails\n";	
	cout <<"\n\t\t" <<"[1]: Heads\n";
	cout <<"\t\t" << "[2]: Tails\n\n";
}

// Definition of tossCoin function.
// To generate random number between 1 and 2 and return the value.
int tossCoin()
{
	int randomCoin;
	randomCoin = (rand() % 2) + 1;     // The ranges is only between two numbers 1 and 0.
	return randomCoin;

}

// Definition of screen function.
// To clear screen and display instructions.
void screen()
{
	system("CLS");
	instructions();
}

// Definition of function game.
// This function is used to play the game.
void game(Group &g1, Group &g2, Stack &s, Queue &q)
{
	int choice1, choice2;
	int randomCoin= 0;
    srand((unsigned int) time(NULL));	// Initialize random number generator.
	
	for(int i = 0; i < 3; i++)			// Iterates the game for three rounds.
	{
		cout <<"\n\t\t" << "Round " << (i + 1) << endl;
		
		//Input and validification for player 1 from group 1.
		cout <<"\n\t\t" << g1.getName1() << "'s guess for the coin flip: ";
		cin >> choice1;					
		while(choice1 != 1 && choice1 != 2)	
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice1;
		}

		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		// Input and valdification for player 1 from group 2.
		cout <<"\t\t" << g2.getName1() << "'s guess for the coin flip: ";
		cin >> choice2;
		while(choice2 != 1 && choice2 != 2)
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice2;
		}
		
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		randomCoin = tossCoin();	// Calling the tossCoin function to return value.
		
		// To determine the correct guess.
		if (randomCoin == 2)
    	{
      		cout <<"\t\t" << "The tossed coin was TAILS!" << endl;
    	}
    	else if (randomCoin == 1)
    	{
     		cout <<"\t\t" << "The tossed coin was HEADS!" << endl;
    	}
		
		// To validate the correct guess and output results.
		if(choice1 == choice2)
		{
			if(choice1 == randomCoin){
				cout <<"\t\t" << g1.getName1() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName1() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "You both are pretty good guesser, huh!" << endl;
				cout <<"\t\t" << "The game is a draw. Both group wins 25 points each!" << endl;
				s.push(25);		// Pushing 25 into the stack.
				q.enqueue(25);	// Enqueuing 25 in the queue.
			}
			else
			{
				cout <<"\t\t" << g1.getName1() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName1() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "Uh-oh! You both guessed it wrongly." << endl;
				cout <<"\t\t" << "The game is a draw and both group earned 0 points.\n";
			}
		}
		
		else if (choice1 == randomCoin)
		{
			cout <<"\t\t" << g1.getName1() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName1() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g1.getName1() << " guessed it correctly!\n";
			s.push(50);		// Pushing 50 into the stack.
		}

		else 
		{
			cout <<"\t\t" << g1.getName1() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName1() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g2.getName1() << " guessed it correctly!\n";
			q.enqueue(50);	// Enqueuing 50 in the queue.
		}
		
		sleep(5);
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		//Input and validification for player 2 from group 1.
		cout <<"\t\t" << g1.getName2() << "'s guess for the coin flip: ";
		cin >> choice1;
		while(choice1 != 1 && choice1 != 2)
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice1;
		}
		
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		//Input and validification for player 2 from group 2.
		cout <<"\t\t" << g2.getName2() << "'s guess for the coin flip: ";
		cin >> choice2;
		while(choice2 != 1 && choice2 != 2)
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice2;
		}
		
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";

		randomCoin = tossCoin();	// Calling the tossCoin function to return value.
		
		// To determine the correct guess.	
		if (randomCoin == 2)
    	{
      		cout <<"\t\t" << "The tossed coin was TAILS!" << endl;
    	}
    	else if (randomCoin == 1)
    	{
     		cout <<"\t\t" << "The tossed coin was HEADS!" << endl;
    	}	

		// To validate the correct guess and output results.
		if(choice1 == choice2)
		{
			if(choice1 == randomCoin)
			{
				cout <<"\t\t" << g1.getName2() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName2() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "You both are pretty good guesser, huh!" << endl;
				cout <<"\t\t" << "The game is a draw. Both group wins 25 points each!"<<endl;
				s.push(25);		// Pushing 25 into the stack.
				q.enqueue(25);	// Enqueuing 25 in the queue.
			}
			else
			{
				cout <<"\t\t" << g1.getName2() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName2() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "Uh-oh! You both guessed it wrongly." << endl;
				cout <<"\t\t" << "The game is a draw and both group earned 0 points."<<endl;
			}
		}
		
		else if(choice1 == randomCoin)
		{
			cout <<"\t\t" << g1.getName2() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName2() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g1.getName2() << " guessed it correctly!\n";
			s.push(50);		// Pushing 50 into the stack.
		}	
		
		else
		{
			cout <<"\t\t" << g1.getName2() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName2() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g2.getName2() << " guessed it correctly!\n";
			q.enqueue(50);	// Enqueuing 50 in the queue.
		}
		
		sleep(5);
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		//Input and validification for player 3 from group 1.
		cout <<"\t\t" << g1.getName3() << "'s guess for the coin flip: ";
		cin >> choice1;
		while(choice1 != 1 && choice1 != 2)
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice1;
		}
		
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		//Input and validification for player 3 from group 2.		
		cout <<"\t\t" << g2.getName3() << "'s guess for the coin flip: ";
		cin >> choice2;
		while(choice2 != 1 && choice2 != 2)
		{
			cout <<"\t\t" << "Choose either 1 or 2. Please try again: ";
			cin >> choice2;
		}
		
		screen();
		cout <<"\n\t\t" << "Round " << (i + 1) << "\n";
		
		randomCoin = tossCoin();	// Calling the tossCoin function to return value.
		
		// To determine the correct guess.
		if (randomCoin == 2)
    	{
      		cout <<"\t\t" << "The tossed coin was TAILS!" << endl;
    	}
    	else if (randomCoin == 1)
    	{
     		cout <<"\t\t" << "The tossed coin was HEADS!" << endl;
    	}
        
        // To validate the correct guess and output results.
		if(choice1 == choice2) 
		{
			if(choice1 == randomCoin)
			{
				cout <<"\t\t" << g1.getName3() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName3() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "You both are pretty good guesser, huh!" << endl;
				cout <<"\t\t" << "The game is a draw. Both group wins 25 points each!\n"<<endl;
				s.push(25);		// Pushing 25 into the stack.
				q.enqueue(25);	// Enqueuing 25 in the queue.
			}
			else
			{
				cout <<"\t\t" << g1.getName3() << "'s choice: " << choice1 << endl;
				cout <<"\t\t" << g2.getName3() << "'s choice: " << choice2 << endl;
				cout <<"\t\t" << "Uh-oh! You both guessed it wrongly." << endl;		
				cout <<"\t\t" << "The game is a draw and both group earned 0 points!\n"<<endl;
			}
		}
		
		else if(choice1 == randomCoin)
		{
			cout <<"\t\t" << g1.getName3() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName3() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g1.getName3() << " guessed it correctly!\n";
			s.push(50);		// Pushing 50 into the stack
		}
		
		else
		{
			cout <<"\t\t" << g1.getName3() << "'s choice: " << choice1 << endl;
			cout <<"\t\t" << g2.getName3() << "'s choice: " << choice2 << endl;
			cout <<"\t\t" << g2.getName3() << " guessed it correctly!\n";
			q.enqueue(50);	// Enqueuing 50 in the queue.
		}
		
		sleep(5);
		screen();
	}
}


