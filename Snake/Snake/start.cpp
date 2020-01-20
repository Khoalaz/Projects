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
	flush();
}

void start::startSnake(start& startBoard, std::queue<int> &key_q)
{
	//snake.printCoord();
	//startBoard.printBoard();
	bool endSnake = false;
	int key = 0;
	while (!endSnake)
	{
		if (!key_q.empty())
		{
			std::cout << "";								//data race delay
			key = key_q.back();
			key_q = std::queue<int>();						//clear queue size of 2 if arrow keys are used
			
			snake.setSnakeDirection(&key);
			snake.nextPos();
			setSnakeDebugger();
			clearTail();
			//snake.printCoord();
			startBoard.printBoard();
		}
		if (key == KEY_EXIT_k)
		{
			std::cout << "exit" << std::endl;
			endSnake = true;
		}



	}
	flush();
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
	for (std::vector<coordinates>::iterator it = snakeFrag.begin(); it != snakeFrag.end(); ++it)
	{
		grid2D[it->x][it->y] = 'O';
	}
}

void start::clearTail()
{
	grid2D[snakeFrag.back().x][snakeFrag.back().y] = ' ';
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

void start::flush()
{
	snake.setInitPos(xSize, ySize);
	setBoardDebugger();
}
