#include <random>
#include <ctime>

#include "WarGame.h"

// Demander au prof pour le const après des méthodes.
// Demander au prof pour le getTopCard sans return (Throw exception java).
// Demander au prof duplication de code du constructeur par copie et de l'operateur de copie.
// Demander au prof en quel mesure il faut utiliser le passage par reference.

int main() {
	srand(time(NULL));

	WarGame myGame("My Game");
	myGame.setUp();
	myGame.run();

	return 0;
}