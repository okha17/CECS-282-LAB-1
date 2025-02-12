#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck
{
private:
	Card Storage[52];
	int currCard;
public: 
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();
};

#endif
