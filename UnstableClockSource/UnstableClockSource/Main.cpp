#include <iostream>

class ClockGenerator
{
protected:
    int m_Multiplier;
    const int m_BaseFreq;
    int m_OutputFreq;

public:
    int GetOutput() const
    {
        return m_OutputFreq;
    }

    ClockGenerator(int base, int mult)
        : m_Multiplier(mult), m_BaseFreq(base), m_OutputFreq(m_BaseFreq* m_Multiplier)
    {

    }
};

int main()
{
    ClockGenerator clk(100, 5);
    std::cout << clk.GetOutput() << std::endl;
    std::cin.get();
}