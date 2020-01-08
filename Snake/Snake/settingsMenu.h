#pragma once
#include "menuAbstract.h"


class settingsMenu : public menuAbstract
{
public:
	settingsMenu()
	{
		size = 2;
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
			std::cout << "2. Grid Size" << std::endl;
			break;
		case 2:
			std::cout << "1. Difficulty" << std::endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_k);
			std::cout << "2. Grid Size" << std::endl;
			SetConsoleTextAttribute(hConsole, WHITE_k);
			break;
		}
	}
};