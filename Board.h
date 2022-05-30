#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	char *screen; //dynamic memory pointer for board array

	Board();
	Board(const Board& original);
	~Board();
	Board & operator= (const Board& original);

	void print_screen(); 
	//this function is for printing the board on screen nicely

	char check_winner(); 
	//checking the winner. if its full it returns (0). if has empty space it has returns (1)

	char find(int slot);
	//this function returns the data at a specific position

	void insert(int, char);
	//this function simply inserts elements from user/computer to board

	int symbol_counter(char);
	//this function is used for counting the symbols inside our board. 
};

#endif



