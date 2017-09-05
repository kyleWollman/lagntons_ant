/******************************************************************************************
** Program name: menu.hpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the header file for the menu function. Menu displays a menu to the 
**		user's screen giving them the option to choose an Ant objects starting 
**		row and column on a 2D array, choose a random position for the Ant, choose
**		the starting direction for the Ant, or quit the program. Once a starting 
**		position and direction have been chosen for the Ant, the user is prompted 
**		to choose how many steps the ant will take. This information is then passed
**		to an Ant object. To call menu() use menu(&BOARD_NAME, &ANT_NAME) 
*******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "board.hpp"
#include "ant.hpp"

void menu(Board*, Ant*);

#endif


			
