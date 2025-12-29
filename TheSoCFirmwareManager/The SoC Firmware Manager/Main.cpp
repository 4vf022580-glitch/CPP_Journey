#include <iostream>
#include <string>

enum Status
{
	STOPPED , RUNNING
};

class Hardware
{
protected:
	std::string m_Name;
	Status m_status;

public:
	static int s_Count;

public:
	Hardware(std::string name)
		:m_Name(name), m_status(STOPPED)
	{
		s_Count += 1;
	}

	virtual void Start() = 0;

	void PrintStatus() const
	{
		std::cout << m_Name << m_status << std::endl;
	}

	virtual ~Hardware()
	{
		std::cout << m_Name << "Destroyed" << std::endl;
		s_Count -= 1;
	}
};

int Hardware::s_Count = 0;

class CpuCore : public Hardware
{
public:
	CpuCore(std::string name) : Hardware(name){}

	void Start() override
	{
		std::cout << "CPU" << m_Name << "is fetching instructions..." << std::endl;
		m_status = RUNNING;
	}
};

class NttAccelerator : public Hardware
{
public:
	NttAccelerator(std::string name) : Hardware(name){}

	void Start() override
	{
		std::cout << "NTT" << m_Name << "is calculating fast..." << std::endl;
		m_status = RUNNING;
	}
};

class SoC
{
private://weishenmezhelishisiyou?
	Hardware* m_Devices[5] = { nullptr };
	int m_DeviceCount;

public:
	explicit SoC()
	{
		m_DeviceCount = 0;
	}

	~SoC()
	{
		for (int i = 0; i < m_DeviceCount; i++)
		{
			delete m_Devices[i];
		}
	}
	
	void AddDevice(Hardware* name)
	{
		if (m_DeviceCount < 5)
		{
			m_Devices[m_DeviceCount] = name;
			m_DeviceCount += 1;
		}
	}

	void BootAll()
	{
		for (int i = 0; i < m_DeviceCount; i++)
		{
			m_Devices[i]->Start();
		}
	}
};

int main()
{
	SoC myChip;

	Hardware* cpuPtr = new CpuCore("Cortex-A710");
	Hardware* npuPtr = new NttAccelerator("NPU-Zero");

	myChip.AddDevice(cpuPtr);
	myChip.AddDevice(npuPtr);

    myChip.BootAll();

    std::cout << Hardware::s_Count << std::endl;

    std::cin.get();
}