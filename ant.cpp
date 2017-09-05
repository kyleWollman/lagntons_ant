/******************************************************************************************
** Program name: ant.cpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the source file for the Ant class object. Ant fills a Board object
**		with character by following 2 rules. 1. If the space on the board is white
**		represented by ' ', the ant turns 90 degrees to the right, changes the space
**		to black, represented by '#' and moves forward one space. If the space is 
**		black, the ant turns 90 degress to the left, turns the space white and moves
**		forward one space. If the ant goes beyond the boundry of the board it will
**		leave the board and reenter from the opposite side. 
*******************************************************************************************/

#include "ant.hpp"
#include<iostream>

/******************************************************************************************
** Description: Ant::setDirection() sets the value for the private member direction. Since the
**		ant will be turning left or right, which are relative directions, the Ant
**		object needs to know which way it is facing relative to the Board. Acceptable
**		values for direction are the chars 'U', 'D', 'L', and 'R' representing up,
**		down, left, and right respectively.   
*******************************************************************************************/

void Ant::setDirection(char d)
{
	direction = d;
}

/******************************************************************************************
** Description: Ant::setRow() allows a calling function to initialze Ant's member data row. 
**		This helps Ant keep track of the row that it currently occupies on the Board.
*******************************************************************************************/

void Ant::setRow(int r)
{
	row = r;
}

/******************************************************************************************
** Description: Ant::setCol() allows a calling function to initialze Ant's member data column 
**		This helps Ant keep track of the column that it currently occupies on the 
**		Board.
*******************************************************************************************/
void Ant::setCol(int c)
{
	col = c;
}

void Ant::setNumSteps(int s)
{
	steps = s;
}

/******************************************************************************************
** Description: Ant::moveAnt() takes a pointer to a Board object and an int as its parameters.
**		It uses the Board's member function getSquare() to determine the color of the
**		square that it is currently standing on, and uses Board's setSquare()
**		function to place the Ant '*' on the Board and to change the color of that 
**		square once the Ant has left it. It uses the int steps to determine how many
**		times to run the for loop. moveAnt will print the initial state of the Board
**		to the user's screen (step 0) and then print each subsequent step until the 
**		for loop terminates.  
*******************************************************************************************/

void Ant::moveAnt(Board* board)
{
	for(int i = 0; i <= steps; i++)
	{
		color = board ->getSquare(row, col);
		board -> setSquare(row,col, ant);
		std::cout << "Step: " << i << std::endl;
		board ->print();
		
		if(direction == 'R')
		{
			if(color == ' ')
			{
				direction = 'D';
				board ->setSquare(row, col, '#');
				row++;
			}
			
			else if(color == '#')
			{
				direction = 'U';
				board -> setSquare(row, col, ' ');
				row--;
			}
		}
		
		else if(direction == 'L')
		{
			if(color == ' ')
			{
				direction = 'U';
				board -> setSquare(row, col, '#');
				row--;
			}
			else if(color == '#')
			{
				direction = 'D';
				board -> setSquare(row, col, ' ');
				row++;
			}
		}
		
		else if(direction == 'U')
		{
			if(color == ' ')
			{
				direction = 'R';
				board -> setSquare(row, col, '#');
				col++;
			}
			
			else if(color == '#')
			{
				direction = 'L';
				board -> setSquare(row, col, ' ');
				col--;
			}
		}
		
		else if(direction == 'D')
		{
			if(color == ' ')
			{
				direction = 'L';
				board -> setSquare(row, col, '#');
				col--;
			}
			
			else if(color == '#')
			{
				direction = 'R';
				board -> setSquare(row, col, ' ');
				col++;
			}
		}
		
		//check for off grid and wrap around if necessary
		if(row < 0)
		{
			row = board -> getRow() - 1;
		}
		
		if (col < 0)
		{
			col = board -> getCol() - 1;
		}
		
		if(row == board ->getRow())
		{
			row = 0;
		}
		
		if(col == board ->getCol())
		{
			col = 0;
		}
	}  
}
