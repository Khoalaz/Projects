#pragma once
#include <Windows.h>
#include <iostream>
#include "constSource.h"

class menuAbstract {
public:
	virtual void menuPrint() = 0;
	int menuControl(int& key) 
	{
		if (key == KEY_DOWN_k)
		{
			if (selection < size) { selection++; }
			else { selection = 1; }
		}
		else if (key == KEY_UP_k)
		{
			if (selection <= 1) { selection = size; }
			else { selection--; }
		}
		else if (key == KEY_ENTER_k)
		{
			return selection;
		}
		menuPrint();
		std::cout << "";
	}
protected:
	int selection = 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int size;
};