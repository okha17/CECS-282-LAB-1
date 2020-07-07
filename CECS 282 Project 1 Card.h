#ifndef CARD_H
#define CARD_H

class Card
{
private:
	char suit;
	char rank;
public:
	Card(); 
	Card(char, char);
	int getValue(); 
	char getSuit();
	void setCard(char, char);
	void showCard();
};

#endif
