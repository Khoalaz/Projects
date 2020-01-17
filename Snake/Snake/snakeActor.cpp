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
	switch (snakeS)
	{
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	}
}

void snakeActor::setSnakeDirection(int* key)
{
	if (snakeS == UP || snakeS == DOWN)
	{
		switch (*key)
		{
		case KEY_LEFT_k:
			snakeS = LEFT;
			break;
		case KEY_RIGHT_k:
			snakeS = RIGHT;
			break;
		}
	}
	else if (snakeS == LEFT || snakeS == RIGHT)
	{
		switch (*key)
		{
		case KEY_UP_k:
			snakeS = UP;
			break;
		case KEY_DOWN_k:
			snakeS = DOWN;
			break;
		}
	}
}

std::vector<snakeFragment>& snakeActor::getSnakeFrag()
{
	return snake;
}