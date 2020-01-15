#include "start.h"

start::start()
{
	setGridSize(50);
	msTimer = 500;
}

void start::setGridSize(short sizeInput)
{
	ySize = sizeInput;
	xSize = ySize / 2;
	food = false;
	grid2D = new char*[xSize];
	for (int i = 0; i < xSize; ++i) { grid2D[i] = new char[ySize]; }
	start::setBoardDebugger();
	snake.setInitPos(xSize, ySize);
}

start::~start()
{
	for (int i = 0; i < xSize; ++i) { delete[] grid2D[i]; }
	delete[] grid2D;
}

void start::printBoard()
{
	system("cls");
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			std::cout << grid2D[x][y];
		}
		std::cout << std::endl;
	}
}

void start::setBoardDebugger()
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			if (y == 0 || y == (ySize - 1) || x == 0 || x == (xSize-1))
			{
				grid2D[x][y] = 'X';
			}
			else
			{
				grid2D[x][y] = ' ';
			}
		}
	}
	setSnakeDebugger();
}

void start::setSnakeDebugger()
{
	for (std::vector<snakeFragment>::iterator it = snakeFrag.begin(); it != snakeFrag.end(); ++it)
	{
		grid2D[it->current.x][it->current.y] = 'O';
	}
}

void start::setDifficulty(short diffInput)
{
	switch (diffInput)
	{
	case 1:
		diffInput = 1000;
		break;
	case 2:
		diffInput = 500;
		break;
	case 3:
		diffInput = 250;
		break;
	case 4:
		diffInput = 50;
		break;
	}
}

void start::foodGenerator()
{
	int foodPosX = rand() % (xSize - 1) + 1;
	int foodPosY = rand() % (ySize - 1) + 1;
	while (food == false)
	{
		foodPosX = rand() % (xSize - 1) + 1;
		if (grid2D[foodPosX, foodPosY])
		{

		}
	}
}
