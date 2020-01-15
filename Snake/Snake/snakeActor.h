#pragma once
#include <vector>

struct coordinates {
	short x;
	short y;
};

struct snakeFragment{
	coordinates current, next;
	bool first, last;
};

class snakeActor
{
public:
	snakeActor();
	void setInitPos(const int gridX, const int gridY);
	std::vector<snakeFragment>& getSnakeFrag();
private:
	short size;
	std::vector<snakeFragment> snake;
};