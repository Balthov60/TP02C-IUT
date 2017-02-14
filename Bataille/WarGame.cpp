#include "WarGame.h"

void WarGame::setUp() {
	stackDeck.shuffle();
	dispatchCards();
}
void WarGame::dispatchCards() {
	while (!stackDeck.isEmpty()) {
		if (firstPlayerDeck.isBiggerThan(secondPlayerDeck))
			secondPlayerDeck.addCard(stackDeck.getTopCard());
		else
			firstPlayerDeck.addCard(stackDeck.getTopCard());
		stackDeck.removeCard();
	}
}

void WarGame::run() {
	while (!isGameFinished())
		playRound();

	displayResults();
}
void WarGame::playRound() {
	Card firstPlayerTopCard = firstPlayerDeck.getTopCard();
	Card secondPlayerTopCard = secondPlayerDeck.getTopCard();

	displayCurrentRoundCards(firstPlayerTopCard, secondPlayerTopCard);
	endRound(firstPlayerTopCard, secondPlayerTopCard);
}

void WarGame::endRound(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard) {
	if (firstPlayerTopCard == secondPlayerTopCard)
		launchBattleRoundEnd(firstPlayerTopCard, secondPlayerTopCard);
	else if (firstPlayerTopCard > secondPlayerTopCard)
		launchClassicRoundEnd(firstPlayerTopCard, firstPlayerDeck, secondPlayerTopCard, secondPlayerDeck);
	else
		launchClassicRoundEnd(secondPlayerTopCard, secondPlayerDeck, firstPlayerTopCard, firstPlayerDeck);
}
void WarGame::launchBattleRoundEnd(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard) {
	stackDeck.addCard(firstPlayerTopCard);
	stackDeck.addCard(secondPlayerTopCard);

	firstPlayerDeck.removeCard();
	secondPlayerDeck.removeCard();
}
void WarGame::launchClassicRoundEnd(const Card& winnerTopCard, Deck& winnerDeck, const Card& looserTopCard, Deck& looserDeck) {
	stackDeck.emptyDeckInOtherDeck(winnerDeck);

	winnerDeck.addCard(looserTopCard);
	looserDeck.removeCard();
	winnerDeck.addCard(winnerTopCard);
	winnerDeck.removeCard();
}

void WarGame::displayResults() {
	if (firstPlayerDeck.isBiggerThan(secondPlayerDeck))
		cout << "Le joueur 1 à gagné !" << endl;
	else
		cout << "Le joueur 2 à gagné !" << endl;
}