#include "WarGame.h"

using namespace std;

void War::setUp() {
	stackDeck.shuffle();
	dispatchCards();
}
void War::dispatchCards() {
	while (stackDeck.getSize() > 0) {
		if (firstPlayerDeck.getSize() <= secondPlayerDeck.getSize())
			firstPlayerDeck.addCard(stackDeck.getTopCard());
		else
			secondPlayerDeck.addCard(stackDeck.getTopCard());
		stackDeck.remCard();
	}
}

void War::run() {
	isRunning = true;
	while (isRunning) {
		launchRound();
		isRunning = !isGameFinished();
	}
	displayResults();
}
void War::launchRound() {
	Card firstPlayerTopCard = firstPlayerDeck.getTopCard();
	Card secondPlayerTopCard = secondPlayerDeck.getTopCard();
	displayCurrentRoundCards(firstPlayerTopCard, secondPlayerTopCard);

	if (firstPlayerTopCard == secondPlayerTopCard)
		battleRoundEnd(firstPlayerTopCard, secondPlayerTopCard);
	else if (firstPlayerTopCard > secondPlayerTopCard)
		classicRoundEnd(firstPlayerTopCard, firstPlayerDeck, secondPlayerTopCard, secondPlayerDeck);
	else
		classicRoundEnd(secondPlayerTopCard, secondPlayerDeck, firstPlayerTopCard, firstPlayerDeck);
}

void War::battleRoundEnd(Card firstPlayerTopCard, Card secondPlayerTopCard) {
	stackDeck.addCard(firstPlayerTopCard);
	stackDeck.addCard(secondPlayerTopCard);

	firstPlayerDeck.remCard();
	secondPlayerDeck.remCard();
}
void War::classicRoundEnd(Card & winnerTopCard, Deck & winnerDeck, Card & looserTopCard, Deck & looserDeck) {
	stackDeck.emptyDeckInAnotherDeck(winnerDeck);

	winnerDeck.addCard(looserTopCard);
	looserDeck.remCard();
	winnerDeck.addCard(winnerTopCard);
	winnerDeck.remCard();
}

bool War::isGameFinished() {
	if (firstPlayerDeck.getSize() == 0 || secondPlayerDeck.getSize() == 0)
		return true;
	return false;
}
void War::displayResults() {
	if (firstPlayerDeck.getSize() == 0)
		cout << "Le joueur 2 à gagné !" << endl;
	else
		cout << "Le joueur 1 à gagné !" << endl;
}