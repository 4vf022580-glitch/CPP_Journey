#include <iostream>

int UpdateSensor(int input)
{
	static int RunningTotal = 0;
	(input > -1) ? (RunningTotal += input) : (RunningTotal = 0);
	return RunningTotal;
}

int main()
{
	for (int i = 0; i < 11; i++)
	{
		if (i == 5) continue;
			int currentReading = UpdateSensor(i);
			std::cout << currentReading << std::endl;
			if (currentReading > 25)
			{
				break;
			}
	}
	std::cin.get();
}