#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "Player.h"

class PlayerHuman : public Player //inheriting Player class in this subclass
{
	

public:
	int inputPosition; //inputted player position
	char player_human_name; //name for the player 1 = 'X' & player 2 = 'O'

	PlayerHuman(); //empty
	PlayerHuman(char); 
	PlayerHuman(const PlayerHuman& original); //empty
	virtual ~PlayerHuman(); //empty
	//PlayerHuman& operator= (const PlayerHuman& original); //empty

	int getMove(const Board& board); 
	//making a body for my virtual function which was declared in its parent which is Player Class
	//in this PlayerHuman class we define getMove to get player 1 & 2 input which is gonna return the entered position
};

#endif

