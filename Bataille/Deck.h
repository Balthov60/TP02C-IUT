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

	void Deck::createByCopyOf(const Deck& deck);

	// DeckList is resize each time we add or remove a card.
	void addCard(const Card& card);
	void removeCard();
	Card ** Deck::resizeFor(int newSize);

	void set32CardsSet();
	void set64CardsSet();
	void emptyDeckInOtherDeck(Deck& deck);

	void shuffle();
	void swapTwoCardsByIndex(const int firstIndex, const int secondIndex);

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


