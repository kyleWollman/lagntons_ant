/******************************************************************************************
** Program name: board.cpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the source file for the Board class object. Board creates a 
**		dynamically allocated 2D array of row and column size chosen by the user. 
**		The Board object can return the number of rows and columns chosen by the 
**		user to a calling function. It can fill a space in the array with a char, 
**		or return the char that occupies a space in the array. It can print the  
**		board to the user's screen and it can free the memory used to it. 
*******************************************************************************************/

#include "board.hpp"
#include<iostream>

/******************************************************************************************
** Description: This default constructor creates a Board object when called. It then uses
**		the private member user, which is an Input object, to ask the user to choose
**		the number of rows and columns that they want the array to have, and 
**		dynamically creates a 2d array of that size. Lastly,it fills the array with 
**		the ' ' char, which represents a white square.
*******************************************************************************************/

Board::Board()
{
	setRow();
	setCol();
	board = new char *[getRow()];
	
	for(int i = 0; i < getRow(); i++)
	{
		board[i] = new char[getCol()];
	}
	
	for(int i = 0; i < getRow(); i++) //filling the board with white space
	{
		for(int j = 0; j < getCol(); j++)
		{
			board[i][j] = ' ';
		}
	}
}

/******************************************************************************************
** Description: Board::getRow() returns to the calling function the number of rows that the 
**		user chose for the array. 
*******************************************************************************************/

int Board::getRow()
{ return row;}

/******************************************************************************************
** Description: Board::getCol() returns to the calling function the number of columns that  
**		the user chose for the array. 
*******************************************************************************************/

int Board::getCol()
{return col;}

/******************************************************************************************
** Description: Board::setRow() prompts the user to enter how many rows they want the array
**		to have. It uses the verify function to ensure that the user entered an int
**		larger than 1. 
*******************************************************************************************/

void Board::setRow()
{
	int r;
	std::cout << "How many rows do you want the board to have (min of 2)?" << std::endl; 
	std::cin >> r;
	row = verify(r);
}

/******************************************************************************************
** Description: Board::setCol() prompts the user to enter how many columns they want the 
**		array to have. It uses the verify function to ensure that the user entered 
**		an int larger than 1. 
*******************************************************************************************/

void Board::setCol()
{
	int c;
	std::cout << "How many columns do you want the board to have (min of 2)?" << std::endl; 
	std::cin >> c;
	col = verify(c);
}

/******************************************************************************************
** Description: Board::verify takes an int as an arguement. It then checks to make sure 
**		it is an int, and to make sure that it is 2 or larger. If the int meets
**		these requirements verify returns the number to the calling function.
*******************************************************************************************/

int Board::verify(int num)
{
	while(num < 2 || std::cin.fail()) 
	{
		if(std::cin.fail()) //verify that an int was entered
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a number 2 or larger:" << std::endl;
			std::cin >> num;
		}
		
		if(num < 2) 
		{
			std::cout << "Please enter a number 2 or larger:" << std::endl;
			std::cin >> num;
		}
	}
	return num;
}

/******************************************************************************************
** Description: Board::setSquare() takes two ints and a char as its parameters. It uses the
**		ints as coordinates in the array and places the char in that space.
*******************************************************************************************/

void Board::setSquare(int row, int col, char color)
{
	board[row][col] = color;
}

/******************************************************************************************
** Description: Board::getSquare() returns to the calling function the contents of the array
**		at the chosen coordinates.
*******************************************************************************************/

char Board::getSquare(int row, int col)
{
	return board[row][col];
}

/******************************************************************************************
** Description: Board::print() displays the array and its contents to the users screen when
**		called.
*******************************************************************************************/

void Board::print()
{
	
	for(int i = 0; i < getRow(); i++) //displaying the matrix
	{
		for(int j = 0; j < getCol(); j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/******************************************************************************************
** Description: Board::freeMem() deletes the Board object freeing the memory that it was
**		using. 
*******************************************************************************************/

void Board::freeMem()
{
	for(int i = 0; i < getRow(); i++) //deallocating memory
	{
		delete [] board[i];
	}
	
	delete [] board;
	
	board = NULL;
}
