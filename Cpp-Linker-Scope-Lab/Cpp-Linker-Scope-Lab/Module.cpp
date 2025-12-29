#include <iostream>
#include "Config.h"

static int InternalState = 100;

void RunModule()
{
	std::cout << "Module InternalState: " << InternalState << std::endl;
	std::cout << "Global SystemVoltage: " << SystemVoltage << std::endl;
}