/******************************************************************************************
** Program name: board.hpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the header file for the Board class object. Board creates a 
**		dynamically allocated 2D array of row and column size chosen by the user. 
**		The Board object can return the number of rows and columns chosen by the 
**		user to the calling function. It can fill a space in the array with a char, 
**		or return the char that occupies a space in the array. It can print the  
**		board to the user's screen and it can free the memory used to it. 
*******************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
			int row;
			int col;
			char **board;
	public:
			Board();
			int getRow();
			int getCol();
			void setRow();
			void setCol();
			int verify(int);
			void setSquare(int row, int col, char color);
			char getSquare(int row, int col);
			void print(); 
			void freeMem();
};

#endif
