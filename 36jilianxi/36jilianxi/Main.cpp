#include <iostream>
#include "MicroALU.h"

int main()
{
	MicroALU alu1("GPU_Core_0");
	MicroALU alu2("NPU_Core_1");

	int rest1 = alu1.Add(10, 20);
	int rest2 = alu2.Add(100, 200);
	rest1 = alu1.Add(1, 1);

	alu1.PrintStatus();
	alu2.PrintStatus();

	std::cin.get();
}