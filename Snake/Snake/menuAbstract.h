#pragma once
#include <Windows.h>
#include <iostream>

class menuAbstract {
public:
	virtual void menuPrint() = 0;
	void menuControl(int& key) 
	{
		if (key == KEY_DOWN_k) //DOWN
		{
			if (selection < size)
				selection++;
			else
				selection = 1;
			
		}
		else if (key == KEY_UP_k) //UP
		{
			if (selection <= 1)
				selection = size;
			else
				selection--;
		}
		menuPrint();
	}
protected:
	int selection = 1;
	int WHITE_k = 15;
	int HIGHLIGHT_k = 240;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int KEY_UP_k = 72;
	int KEY_DOWN_k = 80;

	int size;
};