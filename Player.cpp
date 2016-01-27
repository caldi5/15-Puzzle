#include "Player.h"



Player::Player(int pos)
{
	position = pos;
	moves = 0;
}


Player::~Player()
{
}

int Player::getPos()
{
	return position;
}

void Player::setPos(int pos)
{
	position = pos;
}

void Player::addMove()
{
	moves++;
}

int Player::getMoves()
{
	return moves;
}

void Player::Reset()
{
	position = 0;
	moves = 0;
}
