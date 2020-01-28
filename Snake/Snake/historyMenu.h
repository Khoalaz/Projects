#pragma once
#include <ctime>

class historyMenu
{
public:
	constexpr historyMenu() {};



private:
	char timeBuffer[26] = {};
	time_t rawTime = 0;

	//ctime_s(TimeBuffer, 26 * sizeof(char), &RawTime);
	//std::cout << TimeBuffer << std::endl;
};