	#include "WarGame.h"

void WarGame::setUp() {
	stackDeck.shuffle();
	dispatchCards();
}
void WarGame::dispatchCards() {
	while (!stackDeck.isEmpty()) {
		if (firstPlayerDeck.isBiggerThan(secondPlayerDeck))
			secondPlayerDeck.resizeAndAddCard(stackDeck.getTopCard());
		else
			firstPlayerDeck.resizeAndAddCard(stackDeck.getTopCard());
		stackDeck.resizeAndRemoveCard();
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
	stackDeck.resizeAndAddCard(firstPlayerTopCard);
	stackDeck.resizeAndAddCard(secondPlayerTopCard);

	firstPlayerDeck.resizeAndRemoveCard();
	secondPlayerDeck.resizeAndRemoveCard();
}
void WarGame::launchClassicRoundEnd(const Card& winnerTopCard, Deck& winnerDeck, const Card& looserTopCard, Deck& looserDeck) {
	stackDeck.emptyDeckInOtherDeck(winnerDeck);

	winnerDeck.resizeAndAddCard(looserTopCard);
	looserDeck.resizeAndRemoveCard();
	winnerDeck.resizeAndAddCard(winnerTopCard);
	winnerDeck.resizeAndRemoveCard();
}

bool WarGame::isGameFinished() {
	if (firstPlayerDeck.getSize() == 0 || secondPlayerDeck.getSize() == 0)
		return true;
	return false;
}
void WarGame::displayResults() {
	if (firstPlayerDeck.isBiggerThan(secondPlayerDeck))
		cout << "Le joueur 1 à gagné !" << endl;
	else
		cout << "Le joueur 2 à gagné !" << endl;
}