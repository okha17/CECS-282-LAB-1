// Osman Khan
// CECS 282-07
// Proj 1 -Solitare Prime 
// 09/18/19

#include<iostream>
using namespace std;
#include "Card.h"
#include "Deck.h"

bool isPrime(int n); // Function protoype for the isPrime function
int main()
{
	int choice = 0; // choice variable for the menu options
	Deck myDeck; // object of type Deck used in the game
	
	while (choice != 5) // while the choice is not 5 the program and menu keep running
	{
		cout << "\n";
		cout << "Welcome to Solitare Prime!\n";
		cout << " 1) New Deck\n";
		cout << " 2) Display Deck\n";
		cout << " 3) Shuffle Deck\n";
		cout << " 4) Play Solitare Prime\n";
		cout << " 5) Exit\n";
		cout << " Enter your choice and press return: ";
		int total = 0; // total value that stores the sum of the cards to check if prime
		int count = 0; // variable used to count each pile when found prime
		Card dealt; // object of type card used to store the dealt card from the deal function
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			myDeck.refreshDeck(); // creates a new Deck 
			cout << "New Deck has been created!" << endl;
			break;
		case 2:
			cout << "Here is your deck!\n" << endl;
			myDeck.showDeck(); // displays the deck as 4 rows and 13 columns
			break;
		case 3:
			cout << "Deck has now been shuffled!\n" << endl;
			myDeck.shuffle(); // shuffles the deck using srand
			break;
		case 4:
			cout << "Playing Solitare Prime!!!" << endl;
			while (myDeck.cardsLeft()) // plays game until cards run out
			{
				dealt = myDeck.deal(); // dealt card stored in card object
				total = total + dealt.getValue(); // sum of cards
				dealt.showCard(); //displays the dealt card
				if (isPrime(total)) // checks if card value is prime
				{
					cout << "Prime: " << total << endl;
					++count; // increment pile counter
					total = 0; //reset total for new pile
				}
			}
			if (myDeck.cardsLeft() == 0 && total == 0) 
			{
				// The deck is empty and total is 0 so last line is prime
				cout << "Winner in " << count << " piles!" << endl;
			}
			else 
			{
				// last line is not prime so you lose
				cout << "Loser" << endl;
			}
			// refresh and shuffle deck after to play again
			myDeck.refreshDeck();
			myDeck.shuffle();
			break;
		case 5:
			cout << "Thanks for playing!" << endl; 
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
		}
	}
	return 0;
}
// Check if integer is prime
bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	for (int i = 2; i < n; i++) 
	{
		if (n % i == 0) 
		{
			return false;
		}
	}
	return true;
}
