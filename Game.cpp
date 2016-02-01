#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::Play()
{
	b.setSize();
	b.Scramble();

	char input;	
	
	do
	{
		system("cls");
		b.Print();
		cout << endl << "Moves: " << player.getMoves();
		Input();
	} while (!b.CheckIfSolved());

	cout << "Congratulations! You won in " << player.getMoves() << "!" << endl;

}

void Game::Input()
{
	char input;
	input = _getch();

	int playerPos = player.getPos();
	int size = b.getSize();

	// Move
	switch (input)
	{
	case ('w') :
		if (playerPos - size >= 0)
		{
			player.setPos(playerPos - size);
			b.Swap(playerPos - size, playerPos);
			player.addMove();
		}
		break;
	case ('s') :
		if (playerPos + size < size*size)
		{
			player.setPos(playerPos + size);
			b.Swap(playerPos + size, playerPos);
			player.addMove();
		}
		break;
	case ('a') :
		if (playerPos % size != 0)
		{
			player.setPos(playerPos - 1);
			b.Swap(playerPos - 1, playerPos);
			player.addMove();
		}
		break;
	case ('d') :
		if ((playerPos + 1) % size != 0)
		{
			player.setPos(playerPos + 1);
			b.Swap(playerPos + 1, playerPos);
			player.addMove();
		}
		break;
	case ('r') :
		Reset();
		break;
	case('q') :
		Quit();
		break;
	default:
		break;
	}
}

void Game::Reset()
{
	int input;
	system("cls");
	b.Reset();
	player.Reset();
}

void Game::Quit()
{
}
