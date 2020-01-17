#pragma once
#include <vector>
#include <queue>
#include "constSource.h"

struct coordinates {
	short x;
	short y;
};

struct snakeFragment{
	snakeFragment* next;
	coordinates current;
	bool first, last;
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
	void setSnakeDirection(std::queue<int>& key_q);
	std::vector<snakeFragment>& getSnakeFrag();
private:
	snakeState snakeS;
	std::vector<snakeFragment> snake;
};