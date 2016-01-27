#pragma once
class Player
{
public:
	Player(int pos = 0);
	~Player();
	int getPos();
	void setPos(int pos);
	void addMove();
	int getMoves();
	void Reset();

private:
	int position;
	int moves;
};

