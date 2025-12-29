#include <iostream>
#include "log.h"


void Log(const char* message)
{
	std::cout << message << std::endl;
}

void ILog()
{
	Log("Initialized Log");
}
