#pragma once
#include "menuAbstract.h"

class mainMenu : public menuAbstract
{
public:
	mainMenu()
	{
		size = 4;
	}

	void menuPrint() 
	{
		system("cls"); 
		switch (selection)
		{
		case 1:
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Start game" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " History\n Settings\n Quit" << std::endl;
			break;
		case 2:
			std::cout << " Start game" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " History" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Settings\n Quit" << std::endl;
			break;
		case 3:
			std::cout << " Start game\n History" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Settings" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Quit" << std::endl;
			break;
		case 4:
			std::cout << " Start game\n History\n Settings" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Quit" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			break;
		}
	}
};

class settingsMenu : public menuAbstract
{
public:
	settingsMenu()
	{
		size = 3;
	}

	void menuPrint()
	{
		system("cls");
		switch (selection)
		{
		case 1:
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Difficulty" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Grid Size\n Back" << std::endl;
			break;
		case 2:
			std::cout << " Difficulty" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Grid Size" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Back" << std::endl;
			break;
		case 3:
			std::cout << " Difficulty\n Grid Size" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Back" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			break;
		}
	}
};

class difficultyMenu : public menuAbstract
{
public:
	difficultyMenu()
	{
		size = 4;
	}

	void menuPrint()
	{
		system("cls");
		switch (selection)
		{
		case 1:
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Easy" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Medium\n Hard\n Impossible" << std::endl;
			break;
		case 2:
			std::cout << " Easy" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Medium" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Hard\n Impossible" << std::endl;
			break;
		case 3:
			std::cout << " Easy\n Medium" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Hard" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << " Impossible" << std::endl;
			break;
		case 4:
			std::cout << " Easy\n Medium\n Hard" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << " Impossible" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			break;
		}
	}
};