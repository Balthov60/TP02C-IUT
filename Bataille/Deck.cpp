#include <random>
#include <ctime>

#include "Deck.h"

using namespace std;

Deck::Deck(const Deck& deck) {
	this->size = deck.size;
	this->deckList = new Card*[size];

	for (int i = 0; i < size; i++)
		deckList[i] = new Card(*deck.deckList[i]);
}

void Deck::set32CardsSet() {
	for (int i = 0; i < 4; i++) {
		for (int j = 7; j < 15; j++) 
			resizeAndAddCard(Card(j, i));
	}
}
void Deck::set64CardsSet() {
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 15; j++)
			resizeAndAddCard(Card(j, i));
	}
}

Card ** Deck::resizeFor(int newSize) {
	return new Card*[newSize];
}

void Deck::resizeAndAddCard(const Card&  card) {
	Card ** temporaryPointer = resizeFor(size + 1);

	for (int i = 0; i < size; i++)
		temporaryPointer[i] = new Card(*deckList[i]);
	temporaryPointer[size] = new Card(card);

	freeDeckMemory();
	size++;
	deckList = temporaryPointer;
}
void Deck::resizeAndRemoveCard() {
	if (isEmpty()) {
		cout << "ERROR : SIZE can't be < 0";
		return;
	}

	Card ** temporaryPointer = resizeFor(size - 1);
	for (int i = 0; i < size - 1; i++)
		temporaryPointer[i] = new Card(*deckList[i + 1]);

	freeDeckMemory();
	size--;
	deckList = temporaryPointer;
}

void Deck::shuffle() {
	for (int i = 0; i < size; i++)
		swapTwoCardsByIndex(rand() % size, rand() % size);
}
void Deck::swapTwoCardsByIndex(const int firstIndex, const int secondIndex) {
	Card temp(*deckList[firstIndex]);
	*deckList[firstIndex] = *deckList[secondIndex];
	*deckList[secondIndex] = temp;
}

void Deck::emptyDeckInOtherDeck(Deck&  destinationDeck) {
	while (!isEmpty()) {
		destinationDeck.resizeAndAddCard(getTopCard());
		resizeAndRemoveCard();
	}
}

Deck& Deck::operator=(const Deck& deck) {
	this->size = deck.size;
	this->deckList = new Card*[size];

	for (int i = 0; i < size; i++)
		deckList[i] = new Card(*deck.deckList[i]);

	return *this;
}
ostream& operator<<(ostream& outStream, const Deck& deck) {
	for (int i = 0; i < deck.size; i++)
		outStream << *deck.deckList[i];

	return outStream;
}

void Deck::freeDeckMemory() {
	for (int i = 0; i < size; i++)
		delete deckList[i];
	delete[] deckList;
}