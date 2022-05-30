#ifndef PLAYERRANDOM_H
#define PLAYERRANDOM_H

#include "Player.h"

class PlayerRandom : public Player //inheriting Player class in this subclass
{
public:
	PlayerRandom(); 
	PlayerRandom(const PlayerRandom& original);
	virtual ~PlayerRandom();
	PlayerRandom& operator= (const PlayerRandom& original);

	int getMove(const Board& board);
	//making another body for my virtual function which was declared in its parent which is Player Class
	//in this PlayerRandom class we define getMove to return random number (which is gonna be the location on board)

private:
	int *randomPosition; //variable to store random integer
};

#endif
