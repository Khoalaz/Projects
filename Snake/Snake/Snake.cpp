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
constexpr int KEY_EXIT_k = 27;

enum State
{
	mMenu_s,
	start_s,
	history_s,
	sMenu_s,
	dMenu_s,
	gMenu_s,
};

void startSnake(start& startBoard, std::queue<int> &key_q)
{
	startBoard.printBoard();
	bool endSnake = false;
	int key = 0;
	while (!endSnake)
	{
		if (!key_q.empty())
		{
			std::cout << "";
			key = key_q.back();
			key_q = std::queue<int>();						//clear queue size of 2 if arrow keys are used
			//std::cout << key << std::endl;
			startBoard.printBoard();
		}
		if (key == KEY_EXIT_k)
		{
			std::cout << "exit" << std::endl;
			endSnake = true;
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

void menuState_t(start& startBoard, bool& exitFlag, std::queue<int>& key_q, std::mutex& mtx_Control, std::condition_variable& cv_Control)
{
	mainMenu mMenu;
	settingsMenu sMenu;
	difficultyMenu dMenu;
	gridMenu gMenu;
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
				startSnake(startBoard, key_q);
				mMenu.menuPrint();
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
			currentState = mMenu_s;
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
				gMenu.menuPrint();
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
				startBoard.setDifficulty(1);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 2:
				startBoard.setDifficulty(2);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 3:
				startBoard.setDifficulty(3);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 4:
				startBoard.setDifficulty(4);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			}
			break;
		case gMenu_s:
			switch (gMenu.menuControl(key))
			{
			case 1:
				startBoard.setGridSize(25);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 2:
				startBoard.setGridSize(50);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			case 3:
				startBoard.setGridSize(100);
				currentState = sMenu_s;
				sMenu.menuPrint();
				break;
			}
			break;
		}
	}
}

int main()
{
	bool exitFlag=false;
	srand(static_cast<unsigned int>(time(0)));
	start startBoard;

	std::mutex mtx_Control;
	std::condition_variable cv_Control;
	
	std::queue<int> key_q;
	std::thread th0(controls_t, std::ref(exitFlag), std::ref(key_q), std::ref(cv_Control));
	std::thread th1(menuState_t, std::ref(startBoard), std::ref(exitFlag), std::ref(key_q), std::ref(mtx_Control), std::ref(cv_Control));


	th0.join();
	th1.join();
	return 0;
}
