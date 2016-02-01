#pragma once
#include "Block.h"

class Board
{
public:
	Board(int newSize = 4);
	~Board();
	
	void setSize();
	void Print();
	void Scramble();
	bool CheckIfSolved();
	void Swap(int from, int to);
	int getSize();
	void Reset();

private:
	void Create();
	int size;
	//Block temp;
	Block *blocks;
};

