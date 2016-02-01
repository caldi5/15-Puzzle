#include <iostream>
#include "Board.h"
#include <time.h>

using namespace std;

Board::Board(int newSize)
{
	size = newSize;
	Create();
}

Board::~Board()
{
	delete blocks;
}

void Board::Create()
{
	blocks = new Block[size*size];

	for (int i = 0; i < size*size; i++)
	{
		blocks[i].setValue(i);
	}
}

void Board::setSize()
{
	int newSize;
	do
	{
		cout << "What size do you want?" << endl;
		cin >> newSize;
	} while (newSize < 3 || newSize > 10);
	size = newSize;
}

void Board::Print()
{
	for (int i = 0; i < (size*size); i++)
	{
		blocks[i].Print();
		cout << "\t|\t";
		if ((i+1) % size == 0)
			cout << endl;
	}
}

void Board::Scramble()
{
	srand(time(NULL));
	do
	{
		for (int i = 0; i < size * 1000; i++)
		{
			int from = rand() % (size*size - 1) + 1;
			int to = rand() % (size*size - 1) + 1;
			Swap(from, to);
		}
	} while (CheckIfSolved());
}

bool Board::CheckIfSolved()
{
	for (int i = 0; i < size*size; i++)
	{
		//cout << i << " " << blocks[i].getValue() << endl << endl;
		if (blocks[i].getValue() != i)
			return false;
	}
	return true;
}

void Board::Swap(int from, int to)
{
	Block temp = blocks[to];
	blocks[to] = blocks[from];
	blocks[from] = temp;
}

int Board::getSize()
{
	return size;
}

void Board::Reset()
{
	delete[] blocks;
	setSize();
	Create();
	Scramble();
}
