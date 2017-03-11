#pragma once

#include "Deck.h"


class Deck52 :
	public Deck
{
public:
	Deck52() {
		for (int i = 0; i < 4; i++) {
			for (int j = 2; j < 15; j++)
				addCard(Card(j, i));
		}
	}
};

