#pragma once
#include <string>

class MicroALU 
{
private:
	const std::string m_ModuleName;
	int m_LastResult;
public:
	static int s_GlobalCycleCount;
public:
	MicroALU(std::string Name);
	int Add(int a, int b);
	void PrintStatus() const;
};
	


