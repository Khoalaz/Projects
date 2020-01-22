#include "start.h"

start::start()
{
	setGridSize(50);
	msTimer = 50;
}

void start::setGridSize(short sizeInput)
{
	ySize = sizeInput;
	xSize = ySize / 2;
	sFood.fSpawned = false;
	grid2D = new char*[xSize];
	for (int i = 0; i < xSize; ++i) { grid2D[i] = new char[ySize]; }
	flush();
}

void start::startSnake(start& startBoard, std::queue<int> &key_q)
{
	startBoard.printBoard();
	coordinates tempCoord;
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
		}
		if (key == KEY_EXIT_k)
		{
			endSnake = true;
		}

		//boardCheck();

		tempCoord = snakeFrag.back();
		snake.nextPos();
		snakePrintPos(&tempCoord);
		startBoard.printBoard();
		Sleep(msTimer);
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

void start::boardCheck()
{
	snakeNextCoord = snakeFrag.front();
	switch (snake.getSnakeDirection())
	{
	case UP:
		snakeNextCoord.x--;
		break;
	case DOWN:
		snakeNextCoord.x++;
		break;
	case LEFT:
		snakeNextCoord.y--;
		break;
	case RIGHT:
		snakeNextCoord.y++;
		break;
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
	foodGenerator();
}

void start::setSnakeDebugger()
{
	for (std::vector<coordinates>::iterator it = snakeFrag.begin(); it != snakeFrag.end(); ++it)
	{
		grid2D[it->x][it->y] = 'O';
	}
}

void start::snakePrintPos(coordinates* tempCoord)
{
	grid2D[snakeFrag.front().x][snakeFrag.front().y] = 'O';
	grid2D[tempCoord->x][tempCoord->y] = ' ';
}

void start::setDifficulty(short diffInput)
{
	switch (diffInput)
	{
	case 1:
		msTimer = 200;
		break;
	case 2:
		msTimer = 50;
		break;
	case 3:
		msTimer = 20;
		break;
	case 4:
		msTimer = 0;
		break;
	}
}

void start::foodGenerator()
{
	coordinates foodPos;
	while (sFood.fSpawned != true)
	{
		foodPos.x = rand() % (xSize - 2) + 1;
		foodPos.y = rand() % (ySize - 2) + 1;
		sFood.fSpawned = true;
	}
	foodPrintPos();
}

void start::foodPrintPos()
{
	grid2D[sFood.foodPos.x][sFood.foodPos.y] = '0';
}

void start::flush()
{
	snake.setInitPos(xSize, ySize);
	setBoardDebugger();
	//reset food
}
