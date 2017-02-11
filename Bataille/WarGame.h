#pragma once
#include <string>

#include "Deck.h"

using namespace std;

class War
{
private:
	string title = "War Game";
	bool isRunning = false;

	Deck stackDeck;
	Deck firstPlayerDeck;
	Deck secondPlayerDeck;

public:
	War() {
		stackDeck.set32CardsSet();
	}
	War(string title) {
		stackDeck.set32CardsSet();
		this->title = title;
	}
	
	void setUp();
	void run();

private:
	void dispatchCards();

	void launchRound();
	void displayCurrentRoundCards(Card firstPlayerTopCard, Card secondPlayerTopCard) {
		cout << "*****************************" << endl;
		cout << firstPlayerTopCard << "VS" << endl << secondPlayerTopCard;
	}
	void battleRoundEnd(Card firstPlayerTopCard, Card secondPlayerTopCard);
	void classicRoundEnd(Card & winnerTopCard, Deck & winnerDeck, Card & looserTopCard, Deck & looserDeck);
	bool isGameFinished();
	void displayResults();
};

