#include<iostream>
#include<ctime>
#include<random>
#include <string>
#include "PlayerHuman.h"
#include "PlayerRandom.h"
#include "Player.h"
#include "Board.h"
using namespace std;

int main()
{
	Board b; //making a board class
	Player *p1, *p2, *prp1; //pointers for player class
	PlayerHuman ph1('X'), ph2('O'); //making 2 players
	PlayerRandom pr1; //making 1 object to get random value when playing as computer

	//using Player Object-type pointers to reference our virtual function in each subclass of Player-Class to get player input
	p1 = &ph1;
	p2 = &ph2;

	//using Player Object-type pointers to reference our virtual function in each subclass of Player-Class to get random integer
	prp1 = &pr1;

	int mode; //user can choose which mode to choose
	
	bool continueGame = true; //if true continue the game. if false stop the game.
	int tempRandom = 0; //making temporary random variable to store

	cout << "Select any game mode from the following: " << endl;
	cout << "1. Player vs Player" << endl;
	cout << "2. Computer vs Player" << endl;
	cout << "3. Computer vs Computer" << endl;
	cout << "4. Quit" << endl;
	cout << "your choice: "; 
	cin >> mode; //user enters either of the play modes or exits

	while (continueGame) //if true run the game
	{
		if (mode==4) //quit the game entered 4
		{
			cout << "\nQuitting...\n";
			continueGame = false; //quit the case & main loop
		}
		else if(mode>4||mode<=0) //made user enter again if there is invliad mode intered at the first place
		{
			system("cls");
			cout << "Invalid Input Try again!\n"<<endl;
			cout << "Select any game mode from the following: " << endl;
			cout << "1. Player vs Player" << endl;
			cout << "2. Player vs Computer" << endl;
			cout << "3. Computer vs Computer" << endl;
			cout << "4. Quit" << endl;
			cout << "your choice: "; cin >> mode;
		}
		else
		{
			switch (mode) //switch case for 4 different states of the game.
			{
			//Player vs Player
			//Player 1 = 'X' & Player 2 = 'O' 
			case 1:
				while (continueGame)
				{
					system("cls"); //clear screen for much more cleaner approach
					b.print_screen();
					//Player 1 will make a move first
					if (b.symbol_counter('X') == b.symbol_counter('O')) //exchange the turns
					{
						b.insert(p1->getMove(b), ph1.player_human_name);  //insert value inside the our array
						char winnerReturn = b.check_winner();
						if (winnerReturn == 'X') //if return 'X' player 1 won the game
						{
							system("cls");
							b.print_screen(); //print the board before ending the game
							cout << "Player 1 Wins!" << endl;
							continueGame = false; //exit loop and end the game
						}
						else if (winnerReturn == 'O') //if return 'O' player 2 won the game
						{
							system("cls");
							b.print_screen();
							cout << "Player 2 Wins!" << endl;
							continueGame = false; //exit loop and end the game
						}
					}
					else
					{
						b.insert(p2->getMove(b), ph2.player_human_name); //insert value inside the our array
						char winnerReturn = b.check_winner();
						if (winnerReturn == 'X')
						{
							system("cls");
							b.print_screen();
							cout << "Player 1 Wins!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'O')
						{
							system("cls");
							b.print_screen();
							cout << "Player 2 Wins!" << endl;
							continueGame = false; //exit loop and end the game
						}
					}
					char winnerReturn = b.check_winner();
					if (winnerReturn == 'D') //if return 'D' player 2 won the game
					{
						system("cls");
						b.print_screen();
						cout << "Game was draw!" << endl;
						continueGame = false; //exit loop and end the game
					}
				}
				break;
			
			//Player vs Computer
			//Player = 'X' & Computer = 'O' 
			case 2:
				while (continueGame)
				{
					system("cls");
					b.print_screen();

					if (tempRandom < 9 && tempRandom < 0) //this makes us avoid computer move because its first players turn
					{
						//do nothing
					}
					else
					{
						cout << "\nComputer has played at position: " << tempRandom << endl; //everytime computer makes a move display the position
					}

					//Player will make move first
					if (b.symbol_counter('X') == b.symbol_counter('O'))
					{
						b.insert(p1->getMove(b), ph1.player_human_name);
						char winnerReturn = b.check_winner();
						if (winnerReturn == 'X')
						{
							system("cls");
							b.print_screen();
							cout << "Player 1 Wins!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'O')
						{
							system("cls");
							b.print_screen();
							cout << "Computer Wins!" << endl;
							continueGame = false;
						}
					}
					else
					{
						tempRandom = prp1->getMove(b); //store random move into temp
						b.insert(tempRandom, 'O'); //place symbol into random position
						char winnerReturn = b.check_winner();
						if (winnerReturn == 'X')
						{
							system("cls");
							b.print_screen();
							cout << "Player 1 Wins!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'O')
						{
							system("cls");
							b.print_screen();
							cout << "Computer Wins!" << endl;
							continueGame = false;
						}
					}
					char winnerReturn = b.check_winner();
					if (winnerReturn == 'D')
					{
						system("cls");
						b.print_screen();
						cout << "Game was draw between computer & player!" << endl;
						continueGame = false;
					}
				}
				break;
			
			//Computer vs Computer
			//Computer 1 = 'X' & Computer 2 = 'O' 
			case 3:
				while (continueGame)
				{
					system("cls");
					b.print_screen();
					//Computer 1 will make move first
					if (b.symbol_counter('X') == b.symbol_counter('O'))
					{
						b.insert(prp1->getMove(b), 'X');

						char winnerReturn = b.check_winner();
						if (winnerReturn == 'D')
						{
							system("cls");
							b.print_screen();
							cout << "Game was draw between computers!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'X')
						{
							system("cls");
							b.print_screen();
							cout << "Computer 1 Wins!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'O')
						{
							system("cls");
							b.print_screen();
							cout << "Computer 2 Wins!" << endl;
							continueGame = false;
						}
					}
					else
					{
						b.insert(prp1->getMove(b), 'O');

						char winnerReturn = b.check_winner();
						if (winnerReturn == 'D')
						{
							system("cls");
							b.print_screen();
							cout << "Game was draw between computers!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'X')
						{
							system("cls");
							b.print_screen();
							cout << "Computer 1 Wins!" << endl;
							continueGame = false;
						}
						else if (winnerReturn == 'O')
						{
							system("cls");
							b.print_screen();
							cout << "Computer 2 Wins!" << endl;
							continueGame = false;
						}
					}
				}
				break;
			
			//Invalid Choice Case
			default:
				cout << "Invalid Choice!";
				break;
			}
		}
	}
}