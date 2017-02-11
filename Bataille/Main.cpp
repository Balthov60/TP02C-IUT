#include <iostream>
#include <random>
#include <ctime>

#include "WarGame.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

// Demander au prof pour le const après des méthodes
// Demander au prof pour le getTopCard sans return (Throw exception java)
// Demander au prof duplication de code du constructeur par copie et de l'operateur de copie

int main() {
	srand(time(NULL));

	War myGame("My Game");
	myGame.setUp();
	myGame.run();

	return 0;
}