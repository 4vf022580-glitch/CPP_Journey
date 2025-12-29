#include <iostream>
enum class GateType
{
	AND ,OR
};

class Gate
{
protected:
	GateType m_Type;
public:
	static int s_InstanceCount;
	
	Gate (GateType Type)
		: m_Type(Type)
	{
			s_InstanceCount += 1;
			std::cout << "Gate Created" << std::endl;
	}

	virtual ~Gate()
	{
		s_InstanceCount -= 1;
		std::cout << "Gate Destroyed.Remaining:" << s_InstanceCount << std::endl;

	}

	virtual bool Compute(bool a, bool b) = 0;
};

int Gate::s_InstanceCount = 0;

class AndGate :public Gate
{
public:
	AndGate()
		:Gate(GateType::AND)
	{

	}
	bool Compute (bool a, bool b) override
	{
		return a&&b;
	}
};

class OrGate :public Gate
{
public:
	OrGate()
		:Gate(GateType::OR)
	{

	}
	bool Compute (bool a, bool b) override
	{
		return a || b;
	}
};

int main()
{
	Gate* g1= new AndGate();
	std::cout << g1->Compute(true, false) << std::endl;
	delete g1;

	Gate* g2 = new OrGate();
	std::cout << g2->Compute(true, false) << std::endl;
	delete g2

	Gate* gtest = new Gate(GateType::AND);
	delete gtest
}