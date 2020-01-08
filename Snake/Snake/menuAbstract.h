#pragma once
#include <Windows.h>
#include <iostream>

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
	}
protected:
	const int KEY_UP_k = 72;
	const int KEY_DOWN_k = 80;
	const int KEY_ENTER_k = 13;
	const int WHITE_k = 15;
	const int HIGHLIGHT_k = 240;

	int selection = 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	

	int size;
};