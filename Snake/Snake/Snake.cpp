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

void controls_t(bool&exitFlag, std::queue<int>& key_q, std::condition_variable& cv_State)
{
	int key;
	while (!exitFlag)
	{
		key = 0;
		if (key = _getch()) 
		{ 
			key_q.push(key);
			cv_State.notify_all();						//send semaphore to all
		}
	}
}

void menuState_t(bool& exitFlag, bool& snakeExitFlag, std::queue<int>& key_q, std::queue<short>& settingsData_q, std::mutex& mtx_state, std::mutex& mtx_startSnake, std::mutex& mtx_endSnake, std::condition_variable& cv_State, std::condition_variable& cv_startSnake, std::condition_variable& cv_endSnake)
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
		std::unique_lock<std::mutex> lock(mtx_state);
		std::unique_lock<std::mutex> lock(mtx_endSnake);	//wait for semaphore from Start
		cv_State.wait(lock);							//wait for semaphore from Control

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
				snakeExitFlag = true;
				cv_startSnake.notify_one();					//send semaphore to Start
				break;
			}
			break;
		case start_s:
			cv_startSnake.notify_one();					//send semaphore to Start
			cv_endSnake.wait(lock);
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

void startSnake_t(bool& exitFlag, bool& snakeExitFlag, std::queue<int>& key_q, std::queue<short>& settingsData_q, std::mutex& mtx_startSnake, std::mutex& mtx_endSnake, std::condition_variable& cv_startSnake, std::condition_variable& cv_endSnake)
{
	start startSnake;
	int key;

	while (!exitFlag)
	{
		std::unique_lock<std::mutex> lock(mtx_startSnake);	//wait for semaphore from Menu
		cv_startSnake.wait(lock);
		while (!snakeExitFlag)
		{
			/*key = key_q.back();
			key_q = std::queue<int>();						//clear queue size of 2 if arrow keys are used

			std::cout << key << std::endl;

			if (key == 27)
			{
				snakeExitFlag = true;
				cv_startSnake.notify_one();
			}*/
		}
		startSnake.printBoard();
	}
	//startSnake.~start();
}

int main()
{
	bool exitFlag=false;
	bool snakeExitFlag = false;

	std::mutex mtx_state;
	std::mutex mtx_startSnake;
	std::mutex mtx_endSnake;
	std::condition_variable cv_State;
	std::condition_variable cv_startSnake;
	std::condition_variable cv_endSnake;
	
	std::queue<int> key_q;
	std::queue<short> settingsData_q;
	std::thread th0(controls_t, std::ref(exitFlag), std::ref(key_q), std::ref(cv_State));
	std::thread th1(menuState_t, std::ref(exitFlag), std::ref(snakeExitFlag), std::ref(key_q), std::ref(settingsData_q), std::ref(mtx_state), std::ref(mtx_startSnake),std::ref(mtx_endSnake), std::ref(cv_State), std::ref(cv_startSnake), std::ref(cv_endSnake));
	std::thread th2(startSnake_t, std::ref(exitFlag), std::ref(snakeExitFlag), std::ref(key_q), std::ref(settingsData_q), std::ref(mtx_startSnake), std::ref(mtx_endSnake), std::ref(cv_startSnake), std::ref(cv_endSnake));

	th0.join();
	th1.join();
	th2.join();
	return 0;
}
