#pragma once
#include "snakeActor.h"
#include <Windows.h>
#include <iostream>

class start 
{
public:
	start();
	~start();
	void printBoard();
	void setGridSize(short sizeInput);
	void setDifficulty(short diffInput);
private:
	int msTimer;
	void setBoardDebugger();
	short xSize,ySize;
	char** grid2D;
	bool food;
};