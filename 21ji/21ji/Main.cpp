#include <iostream>

struct Entity
{
	static int x, y;

	static void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

static void Print()
{
	std::cout << x << "," << y << std::endl;
}
int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;
	e1.x = 5;
	e1.y = 8;

	e.Print();
	e1.Print(); 
	std::cin.get();
}