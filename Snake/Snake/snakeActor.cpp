#include "snakeActor.h"

snakeActor::snakeActor()
{
}

void snakeActor::setInitPos(const int gridX, const int gridY)
{
	snakeS = RIGHT;
	snake.clear();

	snakeFragment sFrag;
	sFrag.first = true;
	sFrag.last = false;
	sFrag.current.x = gridX / 2;
	sFrag.current.y = gridY / 2;
	snake.push_back(sFrag);

	sFrag.first = false;
	sFrag.next = &snake.back();
	sFrag.current.y = sFrag.current.y - 1;
	snake.push_back(sFrag);

	sFrag.last = true;
	sFrag.next = &snake.back();
	sFrag.current.y = sFrag.current.y - 1;
	snake.push_back(sFrag);
}

void snakeActor::nextPos()
{

}

void snakeActor::setSnakeDirection(std::queue<int>& key_q)
{

}

std::vector<snakeFragment>& snakeActor::getSnakeFrag()
{
	return snake;
}