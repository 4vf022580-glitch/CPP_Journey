#include <iostream>

class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance;  }

	void Hello() {}
};
Singleton* Singleton::s_Instance = nullptr;

int main()
{
	Singleton::Get().Hello();

	std::cin.get();
}