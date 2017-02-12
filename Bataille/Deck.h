#pragma once
#include "Card.h"

class Deck 
{
private:
	int size = 0;
	Card ** deckList;

public:
	Deck() {/** Default Constructor **/}
	Deck(const Deck& deck);

	int getSize() const {
		return size;
	}
	Card getTopCard() const {
		if (size > 0)
			return *deckList[0];
		cout << "ERROR : Deck Empty return an Empty card";
	}

	void addCard(const Card& card);
	void removeCard();

	void set32CardsSet();
	void shuffle();
	void swapTwoCardsByIndex(const int firstIndex, const int secondIndex);
	void emptyDeckInOtherDeck(Deck& deck);

	bool isBiggerThan(const Deck& otherDeck) const {
		return (getSize() > otherDeck.getSize());
	}
	bool isEmpty() const {
		return !getSize();
	}

	Deck& operator=(const Deck& deck);
	friend ostream& operator<<(ostream& outStream, const Deck& deck);

	~Deck() {
		freeDeckMemory();
	}
	void Deck::freeDeckMemory();
};


