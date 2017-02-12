#pragma once
#include <string>

#include "Deck.h"

class WarGame
{
private:
	string title = "War Game";

	Deck stackDeck;
	Deck firstPlayerDeck;
	Deck secondPlayerDeck;

public:
	WarGame() { 
		stackDeck.set32CardsSet(); 
	}
	WarGame(string title) {
		this->title = title;
		stackDeck.set32CardsSet();
	}
	
	void setUp();
	void run();

private:
	void dispatchCards();

	void launchRound();
	void displayCurrentRoundCards(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard) const {
		cout << "*****************************" << endl;
		cout << firstPlayerTopCard << "VS\n" << secondPlayerTopCard;
	}
	void launchBattleRoundEnd(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard);
	void launchClassicRoundEnd(const Card& winnerTopCard, Deck& winnerDeck, const Card& looserTopCard, Deck& looserDeck);
	
	bool isGameFinished();
	void displayResults();
};