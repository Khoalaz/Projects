#pragma once
#include "snakeActor.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>

class start 
{
public:
	start();
	~start();
	void printBoard();
	void setGridSize(short sizeInput);
	void setDifficulty(short diffInput);

private:
	void setBoardDebugger();
	void foodGenerator();			//to be worked on

	int msTimer;
	short xSize,ySize;
	char** grid2D;
	bool food;
	snakeActor snake;
};