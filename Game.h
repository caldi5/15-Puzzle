#pragma once
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void Play();
	void Input();
	void Reset();
	void Quit();

private:
	Board b;
	Player player;
};

