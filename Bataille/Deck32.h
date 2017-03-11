#pragma once

#include "Deck.h"


class Deck32 :
	public Deck
{
public:
	Deck32() {
		for (int i = 0; i < 4; i++) {
			for (int j = 7; j < 15; j++)
				addCard(Card(j, i));
		}
	}
};

