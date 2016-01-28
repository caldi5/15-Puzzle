#pragma once
#include <iostream>
using namespace std;

class Block
{
public:
	Block(int newValue = 0);
	~Block();
	void setValue(int newValue);
	int getValue();
	void Print();

private:
	int value;
};

