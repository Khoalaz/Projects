#pragma once
#include "menuAbstract.h"

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