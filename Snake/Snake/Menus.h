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
			std::cout << "1. Start game" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "2. History\n3. Settings\n4. Quit" << std::endl;
			break;
		case 2:
			std::cout << "1. Start game" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "2. History" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "3. Settings\n4. Quit" << std::endl;
			break;
		case 3:
			std::cout << "1. Start game\n2. History" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "3. Settings" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "4. Quit" << std::endl;
			break;
		case 4:
			std::cout << "1. Start game\n2. History\n3. Settings" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "4. Quit" << std::endl;
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
			std::cout << "1. Difficulty" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "2. Grid Size\n3. Back" << std::endl;
			break;
		case 2:
			std::cout << "1. Difficulty" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "2. Grid Size" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "3. Back" << std::endl;
			break;
		case 3:
			std::cout << "1. Difficulty\n2. Grid Size" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "3. Back" << std::endl;
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
			std::cout << "1. Easy" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "2. Medium\n3. Hard\n4. Impossible" << std::endl;
			break;
		case 2:
			std::cout << "1. Easy" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "2. Medium" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "3. Hard\n4. Impossible" << std::endl;
			break;
		case 3:
			std::cout << "1. Easy\n2. Medium" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "3. Hard" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			std::cout << "4. Impossible" << std::endl;
			break;
		case 4:
			std::cout << "1. Easy\n2. Medium\n3. Hard" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "4. Impossible" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			break;
		}
	}
};