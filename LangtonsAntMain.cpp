/******************************************************************************************
** Program name: LangtonsAntMain.cpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the client program for project 1. It introduces the conecpt of a 
**		Langton's Ant and briefly describes how it works. It then creates a Board
**		object, and Ant object, and passes them by reference to the menu function.
**		It finishes by freeing the memory used to create the Board object.
*******************************************************************************************/

#include<iostream>
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"


int main()
{
	std::cout << "\nThis program demonstrates Langton's Ant.\n"
		  << "You will choose the size of the board for the ant,\n"
		  << "and then choose the starting position and number of steps\n"
		  << "the ant will take. If the ant is on a white square it will\n"
		  << "turn 90 degrees right, change the square black and move forward\n"
		  << "one square. If the ant is on a black square it will turn 90 degrees\n"
		  << "left, change the square white and move forward one square.\n"
		  << std::endl;

	Board board;
	Ant ant;
	menu(&board, &ant);
	board.freeMem();
	
	return 0; 
}
