#pragma once
class Block
{
public:
	Block(int newValue = 0);
	~Block();
	void setValue(int newValue);
	int getValue();

private:
	int value;
};

