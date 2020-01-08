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

void controls_t(std::queue<int>& key_q, std::condition_variable& cv_State)
{
	int key;
	while (1)
	{
		key = 0;
		if (key = _getch()) 
		{ 
			key_q.push(key);
			cv_State.notify_one();						//send semaphore
		}
	}
}

void menuState_t(std::queue<int>& key_q, std::mutex& mtx_state, std::condition_variable& cv_State, mainMenu& mMenu, settingsMenu& sMenu, difficultyMenu& dMenu)
{
	int key;
	State currentState = mMenu_s;
	while (1)
	{
		std::unique_lock<std::mutex> lock(mtx_state);
		cv_State.wait(lock);							//wait for semaphore

		key = key_q.back();
		key_q = std::queue<int>();						//clear queue size of 2 if arrow keys are used

		switch (currentState)
		{
		case mMenu_s:
			mMenu.menuControl(key);
			break;
		case start_s:
			break;
		case history_s:
			break;
		case sMenu_s:
			break;
		case dMenu_s:
			break;
		case gMenu_s:
			break;
		}
	}
}

/*void clearQueue(std::queue<int>& old_q)
{
	std::queue<int
}*/

int main()
{
	mainMenu mMenu;
	settingsMenu sMenu;
	difficultyMenu dMenu;
	mMenu.menuPrint();

	std::mutex mtx_state;
	std::condition_variable cv_State;
	
	std::queue<int> key_q;
	std::thread th0(controls_t, std::ref(key_q), std::ref(cv_State));
	std::thread th1(menuState_t, std::ref(key_q), std::ref(mtx_state), std::ref(cv_State), std::ref(mMenu), std::ref(sMenu), std::ref(dMenu));


	th0.join();
	th1.join();
	return 0;
}
