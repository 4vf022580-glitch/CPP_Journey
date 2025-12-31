#include <iostream>
#include <iomanip>

// 1. 必须在 main 之前声明函数，或者把函数体搬到 main 上面
void ParsePacket(void* rawData);

int main()
{
	// --- 模拟硬件发送数据 ---
	char* buffer = new char[8];

	// 写入 Frequency (4字节)
	int* ptr = (int*)buffer;
	*ptr = 0x12345678;

	// 写入 Voltage (2字节)
	// 修正：一定要赋值！
	short* sit = (short*)(buffer + 4);
	*sit = 1200;

	// 写入 Status (2字节)
	// 修正：索引改为 6 和 7，防止越界
	buffer[6] = 0xAA;
	buffer[7] = 0xBB;

	// --- 模拟接收端解析 ---
	// 修正：调用函数
	ParsePacket(buffer);

	// 修正：一定要释放内存，虽然 main 结束系统会回收，但在嵌入式中这是大忌
	delete[] buffer;

	std::cin.get();
}

// 函数实现
void ParsePacket(void* rawData)
{
	// 修正：删除了里面那个多余的 void ParsePacket...

	// 解析 Frequency
	int* pFreq = (int*)rawData;
	int frequency = *pFreq;

	// 解析 Voltage
	// 你的逻辑是对的，用 char* 移动步长，再转 short*
	char* pBytes = (char*)rawData;
	char* pVoltAddress = pBytes + 4;
	short* pVolt = (short*)pVoltAddress;
	short voltage = *pVolt;

	std::cout << "Frequency (Dec): " << frequency << std::endl;
	std::cout << "Frequency (Hex): 0x" << std::hex << frequency << std::dec << std::endl;
	std::cout << "Voltage: " << voltage << std::endl;

	// 解析 Status
	char* pBase = (char*)rawData;
	char* pStatus1 = pBase + 6;
	char* pStatus2 = pBase + 7;

	// 修正：强转 (int) 防止乱码，强转 (unsigned char) 防止符号扩展成 FFFFFFAA
	std::cout << "Status 1: 0x" << std::hex << (int)(unsigned char)(*pStatus1) << std::endl;
	std::cout << "Status 2: 0x" << std::hex << (int)(unsigned char)(*pStatus2) << std::endl;

	std::cout << "\n--- Memory Dump ---" << std::endl;

	unsigned char* pByte = (unsigned char*)rawData;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Addr: " << (void*)(pByte + i) << " | ";
		std::cout << "Value: 0x"
			<< std::hex << std::setw(2) << std::setfill('0')
			<< (int)pByte[i] // 打印出的就是内存里的真实样子
			<< std::endl;
		std::cout << std::dec;
	}
}