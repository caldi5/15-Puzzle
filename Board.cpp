#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(int newSize)
{
	size = newSize;
	Create();
}

void Board::Create()
{
	blocks = new Block[size*size];

	for (int i = 0; i < size*size; i++)
	{
		blocks[i].setValue(i);
	}
}

Board::~Board()
{
}

void Board::setSize(int newSize)
{
	size = newSize;
}

void Board::Print()
{
	int data;
	for (int i = 0; i < (size*size); i++)
	{
		data = blocks[i].getValue();
		if (data != 0)
			cout << blocks[i].getValue();
		if ((i + 1) % size == 0)
			cout << endl;
		else
			cout << "\t|\t";
	}
}

void Board::Scramble()
{
	do
	{
		for (int i = 0; i < size * 1000; i++)
		{
			int from = rand() % (size*size - 1) + 1;
			int to = rand() % (size*size - 1) + 1;
			Move(from, to);
		}
	} while (CheckIfSolved());
}

bool Board::CheckIfSolved()
{
	bool foundPlayer = false;
	for (int i = 0; i < size*size; i++)
	{
		if (blocks[i].getValue() != i)
			return false;
	}
	return true;
}

void Board::Move(int from, int to)
{
	temp = blocks[to];
	blocks[to] = blocks[from];
	blocks[from] = temp;
}

int Board::getSize()
{
	return size;
}

void Board::Reset()
{
	Create();
}
