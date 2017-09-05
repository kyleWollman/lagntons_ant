/******************************************************************************************
** Program name: menu.cpp
**Author: Kyle Wollman
** Date: 01/18/2017
** Description: This is the source file for the menu function. Menu displays a menu to the 
**		user's screen giving them the option to choose an Ant objects starting 
**		row and column on a 2D array, choose a random position for the Ant, choose
**		the starting direction for the Ant, or quit the program. Once a starting 
**		position and direction have been chosen for the Ant, the user is prompted 
**		to choose how many steps the ant will take. This information is then passed
**		to an Ant object. To call menu() use menu(&BOARD_NAME, &ANT_NAME) 
*******************************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <ctype.h> //for toupper()
#include <cstdlib> //for random
#include <ctime> //for seed

void menu(Board *board, Ant *ant)
{
	int row, col, choice; 
	char dir;
	bool item1 = false;
	bool item3 = false;
	bool item4 = false;
	int steps;
	unsigned seed = time(0);
	srand(seed);
	
	do
	{
		std::cout << "\nPlease make a selection:" << std::endl;
		
		if(!item1)
		{
			std::cout << "1. Choose the starting position of the ant\n" 
				  << "2. Make the starting position of the ant random" << std::endl;
		}
		if(!item3)
		{
			std::cout << "3. Choose the starting direction of the ant" << std::endl;
		}
		if(!item4)
		{
			std::cout << "4. Choose how many steps the ant will take" << std::endl;
		}
	 
			std::cout << "5. Quit." << std::endl
				  << std:: endl;
					  
		std::cin >> choice;
	
		if (choice == 1)
		{
			std::cout << "Please enter the row that you would like the ant to start in: " << std::endl;
			std::cin >> row;

			while(std::cin.fail()) //verify user input
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Please enter a number between 0 and " << (board ->getRow() - 1) << std::endl;
				std::cin >> row;
			}
				
			while(row < 0 || row > (board ->getRow()) - 1) 
			{
				if(row > board ->getRow() - 1)
				{
					std::cout << "Please choose a number less than " << board ->getRow() << std::endl;
					std::cin >> row;
				}
				
				else if(row < 0)
				{
					std::cout << "Please enter a positive number: " << std::endl;
					std::cin >> row;
				}
			}
				
			ant ->setRow(row); //initialize ant member data row
			
			std::cout << "Please enter the column that you would like the ant to start in: " << std::endl;
			std::cin >> col;
			
			while(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Please enter a number between 0 and " << (board ->getCol() - 1) << std::endl;
				std::cin >> col;
			}
				
			while(col < 0 || col > (board ->getCol()) - 1) //verify user input
			{
				if(col > board ->getCol() - 1)
				{
					std::cout << "Please choose a number less than " << board ->getCol() << std::endl;
					std::cin >> col;
				}
	
				else if(col < 0)
				{
					std::cout << "Please enter a positive number: " << std::endl;
					std::cin >> col;
				}
			}
			
			ant ->setCol(col); //initialize ant member data col
			item1 = true;
		}
		
		else if (choice == 2)
		{
			row = rand() % board ->getRow() - 1;
			col = rand() % board ->getCol() - 1;
			ant -> setRow(row);
			ant -> setCol(col);
			item1 = true;
		}
			
			
		else if (choice == 3)
		{
			
			std::cout << "Please choose the starting direction that the ant will face (U, D, L, R):" << std::endl;
			std::cin >> dir;
			
			dir = toupper(dir);
			
			while(dir != 'U' && dir!= 'D' && dir != 'L' && dir!= 'R') //verify user input
			{
				std::cout << "Please choose the starting direction that the ant will face (U, D, L, R):" << std::endl;
				std::cin >> dir;
				dir = toupper(dir);
			}
			ant ->setDirection(dir);
			item3 = true;
		}
		
		else if(choice == 4)
		{
			std::cout << "Please enter the number of steps you would like the ant to take: " << std::endl;
			std::cin >> steps;
			
			while(std::cin.fail()) //verify user input
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Please enter the number of steps you want the ant to take:" << std::endl;
				std::cin >> steps;
			}
			
			while(steps < 0)
			{
				std::cout << "Please enter a positive number of steps: " << std::endl;
				std:: cin >> steps;
			}
			
			ant ->setNumSteps(steps);
			item4 = true;
		}
			
		else if(choice == 5)
		{	
			return;
		}
		
		else if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Not a valid selection. Please choose 1 - 5." << std::endl;
		}
		
		else if(choice > 5)
		{
			std::cout << "Not a valid selection. Please choose 1 - 5." << std::endl;
		}
		
	}while(!item1 || !item3 || !item4); //use bools to keep do/while loop going until menu items are filled
	
	
	ant ->moveAnt(board); //initialize ant movement

}
	
