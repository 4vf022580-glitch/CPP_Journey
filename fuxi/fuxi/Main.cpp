#include <iostream>

void swap(int &a, int &b)
{
	int c =a;
		 a = b;
		 b = c;
		std::cout << a << "  " <<  b << std::endl;
	std::cin.get();
}
int main()
{
	int a = 5;
	int b = 10;
	swap(a, b);
	std::cout << a << "  " << b << std::endl;
	std::cin.get();
	return 0;
}