#pragma once
#include <vector>
#include <queue>
#include "constSource.h"

#include <iostream>

struct coordinates {
	short x;
	short y;
};

enum snakeState {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class snakeActor
{
public:
	snakeActor();
	void setInitPos(const int gridX, const int gridY);
	void nextPos();
	void setSnakeDirection(int* key);
	std::vector<coordinates>& getSnakeFrag();

	void printCoord();			//debugger
private:
	snakeState snakeS;
	std::vector<coordinates> snake;
};