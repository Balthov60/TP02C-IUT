#pragma once
#include <iostream>

#include "Card.h"

using namespace std;

class Deck 
{
private:
	int size = 0;
	Card ** deckList;

public:
	Deck() {/** Default Constructor **/}
	Deck(const Deck &deck);

	int getSize() {
		return size;
	}
	Card getTopCard() {
		if (size > 0)
			return *deckList[0];
		cout << "ERROR : Deck Empty return an Empty card";
	}

	void addCard(const Card & card);
	void remCard();

	void set32CardsSet();
	void shuffle();
	void swapTwoCardsByIndex(int firstIndex, int secondIndex);
	void emptyDeckInAnotherDeck(Deck & deck);

	Deck& operator=(const Deck &deck);
	friend ostream& operator<<(ostream& outStream, const Deck &deck);

	~Deck() {
		freeDeckMemory();
	}
	void Deck::freeDeckMemory();
};


