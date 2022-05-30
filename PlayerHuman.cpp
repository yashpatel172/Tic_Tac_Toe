#include<iostream>
#include<ctime>
#include<random>
#include <string>

#include "PlayerHuman.h"
#include "PlayerRandom.h"
#include "Player.h"
#include "Board.h"
using namespace std;

PlayerHuman :: PlayerHuman(){} //empty

PlayerHuman :: PlayerHuman(char name)
{
	player_human_name = name; //when a object is created give 'X' or 'O' as a name to this specific object
}

PlayerHuman :: PlayerHuman(const PlayerHuman & original){} //empty

PlayerHuman :: ~PlayerHuman() {} //empty

//PlayerHuman & PlayerHuman :: operator = (const PlayerHuman& original){}

int PlayerHuman :: getMove(const Board& board)
{
	cout << endl << player_human_name << " Player's Turn: ";
	cin >> inputPosition; //getting a position from a player
	inputPosition--; //decrease the position by 1

	while (true)
	{
		if (inputPosition>=0 && inputPosition<=8 && board.screen[inputPosition] == ' ') //if the position is good to use break the infinite loop
		{
				break;
		}
		else if (inputPosition < 0 || inputPosition>8) //if the position entered is not between 0-8
		{
			cout << "You entered a invalid position!\n" << endl;
		}
		else if (board.screen[inputPosition] != ' ') //if the position entered by user is already occupied
		{
			cout << "You entered a occupied position!\n" << endl;
		}

		//if the input was not valid then just ask user again for input
		cout << player_human_name << " Player's Turn: "; 
		cin >> inputPosition;
		inputPosition--;
	}

	return inputPosition; //return the valid position
}

