#include "Card.h"

using namespace std;

ostream& operator<<(ostream& outStream, const Card& card) {
	outStream << "Card : ";
	outStream << card.getAlphabeticalValue();
	outStream << " of " << card.getAlphabeticalSymbol() << endl;

	return outStream;
}

string Card::getAlphabeticalValue() const {
	if (value <= 10)
		return to_string(value);
	
	switch (value) {
	case JACK:
		return "Jack";

	case QUEEN:
		return "Queen";

	case KING:
		return "King";

	case AS:
		return "As";

	default:
		return "ERROR : UNDEFINED CARD value ";
	}
}
string Card::getAlphabeticalSymbol() const {
	switch (symbol) 
	{
	case PIKES:
		return "Pikes";

	case TILES:
		return "Tiles";

	case HEARTS:
		return "Hearts";

	case CLOVERS:
		return "Clovers";

	default:
		return "ERROR : UNDEFINED CARD SYMBOL";
	}
}

bool Card::operator==(const Card &card) const {
	if (value == card.value)
		return true;

	return false;
}
bool Card::operator>(const Card &card) const {
	if (value > card.value)
		return true;

	return false;
}