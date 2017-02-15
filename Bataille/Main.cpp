#include <random>
#include <ctime>

#include "WarGame.h"

int main() {
	srand(time(NULL));

	WarGame myGame("My Game");
	myGame.setUp();
	myGame.run();

	return 0;
}