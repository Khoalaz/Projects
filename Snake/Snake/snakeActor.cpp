#include "snakeActor.h"

snakeActor::snakeActor(){}

void snakeActor::setInitPos(const int gridX, const int gridY)
{
	eating = false;
	snakeS = RIGHT;
	snake.clear();

	coordinates current;
	current.x = gridX / 2;
	current.y = gridY / 2;
	snake.push_back(current);

	current.y -= 1;
	snake.push_back(current);

	current.y -= 1;
	snake.push_back(current);
}

void snakeActor::nextPos()
{
	if (eating == false)
	{
		for (std::vector<coordinates>::reverse_iterator rit = snake.rbegin(); rit != snake.rend() - 1; ++rit)
		{
			rit->x = (rit + 1)->x;
			rit->y = (rit + 1)->y;
		}
	}
	else
	{
		snake.emplace(snake.begin(), snake.front());
		eating = false;
	}


	switch (snakeS)
	{
	case UP:
		snake.front().x--;
		break;
	case DOWN:
		snake.front().x++;
		break;
	case LEFT:
		snake.front().y--;
		break;
	case RIGHT:
		snake.front().y++;
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

std::vector<coordinates>& snakeActor::getSnakeFrag()
{
	return snake;
}

void snakeActor::snakeEat()
{
	eating = true;
}

void snakeActor::printCoord()
{
	for (std::vector<coordinates>::iterator it = snake.begin(); it != snake.end(); ++it)
	{
		std::cout << it->x << " " << it->y << std::endl;
	}
}

snakeState snakeActor::getSnakeDirection()
{
	return snakeS;
}