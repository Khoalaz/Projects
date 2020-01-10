#include "start.h"

start::start()
{
	ySize = 50;
	xSize = ySize/2;
	food = false;
	msTimer = 500;
	grid2D = new char*[xSize];
	for (int i = 0; i < xSize; ++i) { grid2D[i] = new char[ySize]; }
	start::setBoardDebugger();
}

start::~start()
{
	for (int i = 0; i < xSize; ++i) { delete[] grid2D[i]; }
	delete[] grid2D;
}

void start::printBoard()
{
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
}

void start::setGridSize(short sizeInput)
{
	ySize = sizeInput;
	xSize = ySize / 2;
	grid2D = new char*[xSize];
	for (int i = 0; i < xSize; ++i) { grid2D[i] = new char[ySize]; }
	start::setBoardDebugger();
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