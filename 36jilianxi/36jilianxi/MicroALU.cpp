#include <iostream>
#include "MicroALU.h"

int MicroALU::s_GlobalCycleCount = 0;

MicroALU::MicroALU(std::string Name)
:m_ModuleName(Name), m_LastResult(0)
{
	std::cout << "Unit" << Name << "Powered On." <<std::endl;
}

int MicroALU::Add(int a, int b)
{
	m_LastResult = a + b;
	s_GlobalCycleCount += 1;
	return m_LastResult;
}

void MicroALU::PrintStatus() const
{
	std::cout << "Unit:" << m_ModuleName << " | Last Result : " << m_LastResult << " | System Global Cycles : " << s_GlobalCycleCount <<std::endl;
}