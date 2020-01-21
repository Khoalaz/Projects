#pragma once
#include "snakeActor.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <vector>
#include <queue>
#include "constSource.h"

struct food{
	bool fSpawned;
	coordinates foodPos;
};

class start 
{
public:
	start();
	~start();
	void startSnake(start& startBoard, std::queue<int> &key_q);
	void printBoard();
	void setGridSize(short sizeInput);
	void setDifficulty(short diffInput);

private:
	void setBoardDebugger();
	inline void setSnakeDebugger();
	void foodGenerator();			//to be worked on
	inline void snakePrintPos(coordinates *tempCoord);
	inline void foodPrintPos();
	inline void flush();

	int msTimer;
	short xSize,ySize;
	char** grid2D;
	food sFood;
	

	snakeActor snake;
	std::vector<coordinates>& snakeFrag = snake.getSnakeFrag();
};