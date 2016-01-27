#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::Start()
{
	int size;
	do
	{
		cout << "What size do you want?" << endl;
		cin >> size;
	} while (size < 1 || size > 10);

	Player player;
	Board b(size);
	char input;

	b.Scramble();
	
	while (!b.CheckIfSolved())
	{
		system("cls");
		b.Print();
		cout << endl << "Moves: " << player.getMoves() << "  Player: " << player.getPos();
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
				b.Move(playerPos - size, playerPos);
				player.addMove();
			}
			break;
		case ('s') :
			if (playerPos + size < size*size)
			{
				player.setPos(playerPos + size);
				b.Move(playerPos + size, playerPos);
				player.addMove();
			}
			break;
		case ('a') :
			if (playerPos % size != 0)
			{
				player.setPos(playerPos - 1);
				b.Move(playerPos - 1, playerPos);
				player.addMove();
			}
			break;
		case ('d') :
			if ((playerPos + 1) % size != 0)
			{
				player.setPos(playerPos + 1);
				b.Move(playerPos + 1, playerPos);
				player.addMove();
			}
			break;
		default:
			break;
		}
	}

	cout << "Congratulations! You won in " << player.getMoves() << "!" << endl;

}