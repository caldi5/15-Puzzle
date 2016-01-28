#pragma once
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <conio.h>
#include <iostream>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void Play();
	void Input();
	void Reset();

private:
	Board b;
	Player player;
};

