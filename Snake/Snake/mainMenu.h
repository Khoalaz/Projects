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