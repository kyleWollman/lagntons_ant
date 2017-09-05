/******************************************************************************************
** Program name: ant.hpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the header file for the Ant class object. Ant fills a Board object
**		with character by following 2 rules. 1. If the space on the board is white
**		represented by ' ', the ant turns 90 degrees to the right, changes the space
**		to black, represented by '#' and moves forward one space. If the space is 
**		black, the ant turns 90 degress to the left, turns the space white and moves
**		forward one space. If the ant goes beyond the boundry of the board it will
**		leave the board and reenter from the opposite side. 
*******************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"

class Ant
{
	private:
			char direction;
			char color;
			char ant = '*';
			int row;
			int col;
			int steps;
	public: 

			void setDirection(char d);
			void setRow(int r);
			void setCol(int c);
			void setNumSteps(int s);
			void moveAnt(Board*);
};
#endif




