#include <iostream>
#include "Config.h"

int main()
{
	int InternalState = 999;

	std::cout << InternalState << std::endl;

	SystemVoltage = 12;

	void RunModule();

	RunModule();

	std::cin.get();
}