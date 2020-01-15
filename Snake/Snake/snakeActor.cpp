#include "snakeActor.h"

snakeActor::snakeActor()
{
	size = 3;
}

void snakeActor::setInitPos(const int gridX, const int gridY)
{
	size = 3;

	snakeFragment sFrag;
	sFrag.first = true;
	sFrag.last = false;
	sFrag.current.x = gridX / 2;
	sFrag.current.y = gridY / 2;
	sFrag.next.x = sFrag.current.x + 1;
	sFrag.next.y = sFrag.current.y;
	snake.push_back(sFrag);

	sFrag.first = false;
	sFrag.next.x = sFrag.current.x;
	sFrag.current.x = sFrag.current.x - 1;
	snake.push_back(sFrag);

	sFrag.last = true;
	sFrag.next.x = sFrag.current.x;
	sFrag.current.x = sFrag.current.x - 1;
	snake.push_back(sFrag);
}

std::vector<snakeFragment>& snakeActor::getSnakeFrag()
{
	return snake;
}