#pragma once

#include <iostream>
#include <string>

using namespace std;

enum SYMBOLS { PIKES, TILES, HEARTS, CLOVERS };
enum PICTURE_CARDS { JACK = 11, QUEEN = 12, KING = 13, AS = 14 };


class Card
{
private:
	int value;
	int symbol;

public:
	Card(int value, int symbol) {
		this->value = value;
		this->symbol = symbol;
	}
	Card(const Card& card) {
		this->value = card.value;
		this->symbol = card.symbol;
	}

	string getAlphabeticalSymbol() const;
	int getSymbol() const {
		return symbol;
	}

	string getAlphabeticalValue() const;
	int getValue() const {
		return value;
	}

	Card& operator=(const Card& card) {
		this->value = card.value;
		this->symbol = card.symbol;

		return *this;
	}
	bool operator==(const Card& card) const;
	bool operator>(const Card& card) const;
	friend ostream& operator<<(ostream& outStream, const Card& card);
};

