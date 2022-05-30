#include<iostream>
#include<ctime>
#include<random>
#include <string>

#include "PlayerHuman.h"
#include "PlayerRandom.h"
#include "Player.h"
#include "Board.h"
using namespace std;

PlayerRandom :: PlayerRandom() 
{
	randomPosition = new int;
}

PlayerRandom :: PlayerRandom(const PlayerRandom& original) 
{
	randomPosition = original.randomPosition;
}

PlayerRandom :: ~PlayerRandom() 
{
	delete randomPosition;
}

PlayerRandom & PlayerRandom :: operator = (const PlayerRandom& original)
{
	if (this != &original)
	{
		delete randomPosition;
		randomPosition = new int;
		randomPosition = original.randomPosition;
	}

	return *this;
}

int PlayerRandom :: getMove(const Board& board)
{
	srand((unsigned int)time(NULL)); //randomize using time
	
	//srand(time(0)); 

	do
	{
		*randomPosition = rand() % 10; //storing a random number between 0-9
	} 
	while (board.screen[*randomPosition] != ' '); //do this loop until we find an empty space to store our symbol

	return *randomPosition;
}