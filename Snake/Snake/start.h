#pragma once
#include "snakeActor.h"
#include <iostream>

class start 
{
public:
	start();
	~start();
	void printBoard();
	void setGridSize(short sizeInput);
	void setDifficulty();
private:
	int msTimer;
	void setBoardDebugger();
	short xSize,ySize;
	char** grid2D;
	bool food;
};