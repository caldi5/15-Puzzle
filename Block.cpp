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
