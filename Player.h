#ifndef PLAYER_H
#define PLAYER_H

class Board; //including class board

class Player
{
public:
	Player(); //empty
	Player(const Player& original); //empty
	virtual ~Player(); //empty
	Player& operator= (const Player& original); //empty

	virtual int getMove(const Board& board) = 0; 
	//^declaring a virtual function with no-body. this is gonna make our Player Class abstract-class

	//I wasnt sure what to do with this class because my path/logic was a little bit different from the Player Class Steps in the assignment
	//I have used Player Class mostly to demonstrate that i know how to use pure virtual function & its implementation
};

#endif

