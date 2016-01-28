#include "Block.h"

Block::Block(int newValue)
{
	value = newValue;
}

Block::~Block()
{
}

void Block::setValue(int newValue)
{
	value = newValue;
}

int Block::getValue()
{
	return value;
}

void Block::Print()
{
	if (value == 0)
		cout << " ";
	else
		cout << value;
}
