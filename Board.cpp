#include<iostream>
#include<ctime>
#include<random>
#include <string>

#include "PlayerHuman.h"
#include "PlayerRandom.h"
#include "Player.h"
#include "Board.h"
using namespace std;

Board :: Board()
{
	screen = new char[9]; //creating an empty board dynamically
	for (int i = 0; i < 9; i++)
	{
		screen[i] = ' '; //allocating empty board 'space'
	}
}

Board :: Board(const Board& original)
{
	screen = new char[9]; //make a new size board array

	for (int i = 0; i < 9; i++)
	{
		screen[i] = original.screen[i]; //copy the passed board into the current board
	}
}

Board :: ~Board()
{
	delete[] screen; //delete the dynamically allocated memory which is our board array
}

Board &Board :: operator= (const Board& original)
{
	//if the passed board is not same as the current one
	if (this != &original)
	{
		delete screen; //delete the dynamically allocated memory which is our board array
		screen = new char[9]; //make a new size board array
		for (int i = 0; i < 9; i++)
		{
			screen[i] = original.screen[i]; //copy the passed board into the current board
		}
	}
	return *this; //return the current board pointer
}

char Board :: find(int slot)
{
	return screen[slot]; //returning the data on the board on a specific position
}

void Board :: insert (int slot, char symbol)
{
	screen[slot] = symbol; //inserting symbol 'O' or 'X' on the board on a specific position
} 

void Board :: print_screen()
{
	//simply printing my board using cout & making a nice representation of the board
	cout << "+---+---+---+" << endl;
	cout << "| " << screen[0] << " | " << screen[1] << " | " << screen[2] << " |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "| " << screen[3] << " | " << screen[4] << " | " << screen[5] << " |" << endl;
	cout << "+---+---+---+" << endl;
	cout << "| " << screen[6] << " | " << screen[7] << " | " << screen[8] << " |" << endl;
	cout << "+---+---+---+\n" << endl;
}

char Board :: check_winner()
{
	//checking the winning pattern in horizontal/row directions on the board
	//checking if the symbols are same and one of them is not empty
	if (screen[0] == screen[1] && screen[1] == screen[2] && screen[0] != ' ')
	{
		return screen[0];
	}
	if (screen[3] == screen[4] && screen[4] == screen[5] && screen[3] != ' ')
	{
		return screen[3];
	}
	if (screen[6] == screen[7] && screen[7] == screen[8] && screen[6] != ' ')
	{
		return screen[6];
	}

	//checking the winning pattern in vertical/column directions on the board
	//checking if the symbols are same and one of them is not empty
	if (screen[0] == screen[3] && screen[3] == screen[6] && screen[0] != ' ')
	{
		return screen[0];
	}
	if (screen[1] == screen[4] && screen[4] == screen[7] && screen[1] != ' ')
	{
		return screen[1];
	}
	if (screen[2] == screen[5] && screen[5] == screen[8] && screen[2] != ' ')
	{
		return screen[2];
	}

	//checking the winning pattern in diagonal directions on the board
	//checking if the symbols are same and one of them is not empty
	if (screen[0] == screen[4] && screen[4] == screen[8] && screen[0] != ' ')
	{
		return screen[0];
	}
	if (screen[2] == screen[4] && screen[4] == screen[6] && screen[2] != ' ')
	{
		return screen[2];
	}

	//checking if the board is full or not
	if (symbol_counter('X') + symbol_counter('O') < 9)
	{
		return 'C'; //if the board is empty/still space left we return one.
	}
	else
	{
		return 'D'; //if the board is full with symbols we return zero.
	}
}

int Board :: symbol_counter(char symbol)
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		if (screen[i] == symbol)
		{
			count += 1; //counting the number of 'X's or 'O's on the board at a given time
		}
	}

	return count; //then return the amount
}
