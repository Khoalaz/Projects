#pragma once
#include <vector>

struct coordinates {
	short x;
	short y;
};

struct snakeFragment{
	coordinates* next, previous;
	coordinates current;
};

class snakeActor
{
public:
	snakeActor();
private:
	short size;
	std::vector<snakeFragment> snake;
};