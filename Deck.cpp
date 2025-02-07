#include "Deck.h"
#include<iostream>
#include<time.h>
using namespace std;

Deck::Deck()
{
	refreshDeck();
}

void Deck::refreshDeck()
{
	currCard = 0;
	int value = 0;
	char suits[] = { 'S', 'H', 'D', 'C' };
	char rank[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	for (int s = 0; s < 4; s++)
	{
		for (int r = 0; r < 13; r++) 
		{
			Storage[value++].setCard(rank[r], suits[s]); 
		}
	}
}

Card Deck::deal()
{
	return Storage[currCard++]; 
}

void Deck::shuffle()
{
	srand(time(0));

	for (int i = 0; i <= 51; i++)
	{
		int value = rand() % 52;
		Card temp = Storage[value];
		Storage[value] = Storage[i];
		Storage[i] = temp;
	} 
}

int Deck::cardsLeft()
{
	int left;
	left = 52 - currCard;
	return left;
}

void Deck::showDeck()
{
	int suit;
	int value = 0;
	int rank;
	for (suit = 0; suit < 4; suit++)
	{
		for (rank = 0; rank < 13; rank++)
		{
			Storage[value++].showCard();		
		}
		cout << endl;
	}
}
