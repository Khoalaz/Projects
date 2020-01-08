// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>
#include <cstdint>
#include <conio.h>
#include "mainMenu.h"

/*constexpr int KEY_UP_k = 72;
constexpr int KEY_DOWN_k = 80;
constexpr int KEY_LEFT_k = 75;
constexpr int KEY_RIGHT_k = 77;*/
constexpr int KEY_ENTER_k = 13;

enum State
{
	mMenu_s,
	start_s,
	history_s,
	sMenu_s,
	dMenu_s,
	gMenu_s,
};

void controls(int& key)
{
	while (1)
	{
		key = 0;
		if (key = _getch()){}
		std::cout << key << std::endl;
	}
}

int main()
{
	mainMenu mMenu;
	mMenu.menuPrint();
	
	int key = 0;
	std::thread th0(controls, std::ref(key));

	State currentState = mMenu_s;

	th0.join();
	return 0;
}
