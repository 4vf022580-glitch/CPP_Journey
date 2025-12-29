#include <iostream>
#include <string>

class Component
{
protected:
	std::string m_Name;

private:
	static int s_Count;

public:
	Component(std::string name)
		:m_Name(name)
	{
		s_Count += 1;
		std::cout << "Constructed: " << m_Name << std::endl;
	}

	virtual ~Component()
	{
		s_Count -= 1;
		std::cout << "Destroyed: " << m_Name << std::endl;
	}

	virtual void process() const = 0;

	std::string GetName () const
	{
		return m_Name;
	}

	static int GetActiveCount()
	{
		return s_Count;
	}
};

class CPU :public Component
{
public:
	CPU(std::string name)
		: Component(name)
	{}

	void process() const override
	{
			std::cout << "CPU " << m_Name << " is calculating data..." << std::endl;
	}
};

class GPU :public Component
{
	public:
		GPU(std::string name)
			: Component(name)
		{}

		void process () const override
		{
				std::cout << "GPU " << m_Name << " is rendering graphics..." << std::endl;
		}
};

void Analyze(const Component& comp)
{
	comp.process();
}

void FactoryReset(Component* comp)
{
	if (comp == nullptr)
	{
		std::cout << "WARINNING" << std::endl;
	}
	else
	{
		std::cout << "Resetting " << (*comp).GetName() << "..." << std::endl;
	}
}

int Component::s_Count = 0;

int main()
{
	std::cout << "Counts: " << Component::GetActiveCount() << std::endl;

	Component** components = new Component* [3];
	components[0] = new CPU("Intel");
	components[1] = new	GPU("Nvidia");
	components[2] = nullptr;

	std::cout << "Counts: " << Component::GetActiveCount() << std::endl;

	for (int i = 0; i < 3; i++)
	{
		if (components[i] != nullptr)
		{
			Analyze(*components[i]);
			FactoryReset(components[i]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete components[i];
	}

	delete[] components;

	std::cout << "Counts: " << Component::GetActiveCount() << std::endl;

	std::cin.get();
}