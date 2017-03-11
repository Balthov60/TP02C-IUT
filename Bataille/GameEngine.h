#pragma once

#include <string>

using namespace std;


class GameEngine
{
protected:
	string title = "War Game";

public:
	GameEngine() { /* Default constructor */ }
	GameEngine(string title) {
		this->title = title;
	}
	~GameEngine() { /* Default Destructor */ }
};

