// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>
#include <conio.h>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "Menus.h"
#include "start.h"

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

void startSnake(start& startBoard)
{
	bool endSnake = false;
	int key;
	while (!endSnake)
	{
		if (key = _getch())
		{
			std::cout << key << std::endl;
		}
	}
}

void controls_t(bool&exitFlag, std::queue<int>& key_q, std::condition_variable& cv_Control)
{
	int key;
	while (!exitFlag)
	{
		key = 0;
		if (key = _getch()) 
		{ 
			key_q.push(key);
			cv_Control.notify_one();						//send semaphore to all
		}
	}
}

void menuState_t(bool& exitFlag, std::queue<int>& key_q, std::mutex& mtx_Control, std::condition_variable& cv_Control)
{
	start startBoard;

	mainMenu mMenu;
	settingsMenu sMenu;
	difficultyMenu dMenu;
	mMenu.menuPrint();

	int key;
	State currentState = mMenu_s;

	while (!exitFlag)
	{
		std::unique_lock<std::mutex> lock_state(mtx_Control);
		cv_Control.wait(lock_state);							//wait for semaphore from Control

		key = key_q.back();
		key_q = std::queue<int>();						//clear queue size of 2 if arrow keys are used

		switch (currentState)
		{
		case mMenu_s:
			switch (mMenu.menuControl(key))
			{
			case 1:
				currentState = start_s;
				break;
			case 2:
				currentState = history_s;
				break;
			case 3:
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 4:
				exitFlag = true;
				break;
			}
			break;
		case start_s:
			startSnake(startBoard);
			mMenu.menuPrint();
			break;
		case history_s:
			break;
		case sMenu_s:
			switch (sMenu.menuControl(key))
			{
			case 1:
				currentState = dMenu_s;
				dMenu.menuPrint();
				break;
			case 2:
				currentState = gMenu_s;
				break;
			case 3:
				currentState = mMenu_s;
				mMenu.menuPrint();
				break;
			}
			break;
		case dMenu_s:
			switch (dMenu.menuControl(key))
			{
			case 1:
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 2:
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 3:
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 4:
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			}
			break;
		case gMenu_s:
			break;
		}
	}
}

int main()
{
	bool exitFlag=false;

	std::mutex mtx_Control;
	std::condition_variable cv_Control;
	
	std::queue<int> key_q;
	std::thread th0(controls_t, std::ref(exitFlag), std::ref(key_q), std::ref(cv_Control));
	std::thread th1(menuState_t, std::ref(exitFlag), std::ref(key_q), std::ref(mtx_Control), std::ref(cv_Control));


	th0.join();
	th1.join();
	return 0;
}
