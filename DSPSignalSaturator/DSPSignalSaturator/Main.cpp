#include <iostream>

class Signal
{
private:
	int m_Value;
public:
	Signal(int value)
		:m_Value(value)
	{
		if (m_Value < 0)
		{
			m_Value = 0;
		}
		if (m_Value > 255)
		{
			m_Value = 255;
		}
	}

	Signal operator+(const Signal& other) const
	{
		int tempsum = this->m_Value + other.m_Value;
		if (tempsum > 255)
		{
			tempsum = 255;
		}
		return Signal(tempsum);
	}

	Signal& operator+=(const Signal& other)
	{
		this->m_Value += other.m_Value;
		if (this->m_Value > 255)
		{
			this->m_Value = 255;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Signal& s)
	{
		stream << "[SIG: " << s.m_Value << "]";
		return stream;
	}
};

int main()
{
	Signal s1(200);
	Signal s2(100);
	Signal sum = s1 + s2;
	std::cout << "Sum (200 + 100): " << sum << std::endl;

	s1 += s2;
	std::cout << "After s1 += s2: " << s1 << std::endl;

	Signal a(10), b(20), c(30);
	(a += b) += c;

	std::cout << "Chain result (10+20+30): " << a << std::endl;
}