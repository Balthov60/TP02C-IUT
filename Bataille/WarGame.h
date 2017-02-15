#pragma once
#include <string>

#include "GameEngine.h"
#include "Deck32.h"

class WarGame :
	public GameEngine
{
private:
	Deck * stackDeck;
	Deck * firstPlayerDeck;
	Deck * secondPlayerDeck;

public:
	WarGame() { 
		stackDeck = new Deck32();
		firstPlayerDeck = new Deck32();
		secondPlayerDeck = new Deck32();
	}
	WarGame(string title) : GameEngine(title) {
		stackDeck = new Deck32();
		firstPlayerDeck = new Deck32();
		secondPlayerDeck = new Deck32();
	}
	
	void setUp();
	void run();

private:
	void dispatchCards();

	void playRound();
	void displayCurrentRoundCards(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard) const {
		cout << "*****************************" << endl;
		cout << firstPlayerTopCard << "VS\n" << secondPlayerTopCard;
	}

	void endRound(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard);
	void launchBattleRoundEnd(const Card& firstPlayerTopCard, const Card& secondPlayerTopCard);
	void launchClassicRoundEnd(const Card& winnerTopCard, Deck& winnerDeck, const Card& looserTopCard, Deck& looserDeck);
	
	bool isGameFinished() {
		return (firstPlayerDeck->getSize() == 0 || secondPlayerDeck->getSize() == 0);
	}
	void displayResults();

public:
	~WarGame() {
		delete stackDeck;
		delete firstPlayerDeck;
		delete secondPlayerDeck;
	}
};