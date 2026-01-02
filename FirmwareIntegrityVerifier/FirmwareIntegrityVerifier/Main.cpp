#include <iostream>
#include <cstring>

class SecureROM {
private:
    unsigned char* m_Data;
    int m_Size;

public:
    SecureROM(int size) {
        m_Size = size;
        m_Data = new unsigned char[size];

        std::memset(m_Data, 0, size);

        if (size > 0) {
            m_Data[0] = 0xAA;
            m_Data[size - 1] = 0xBB;
        }

        std::cout << "[构造] 申请了 " << size << " 字节，地址: " << (void*)m_Data << std::endl;
    }

    ~SecureROM() 
    {
        delete[] m_Data;

        std::cout << "[析构] 释放了内存，地址: " << (void*)m_Data << std::endl;
    }

    SecureROM(const SecureROM& other) {
        std::cout << "[拷贝] 正在克隆芯片..." << std::endl;

        m_Size = other.m_Size;

        m_Data = new unsigned char[m_Size];

        std::memcpy(m_Data, other.m_Data, m_Size);
    }

    unsigned char ReadByte(int index) const
    {
        return m_Data[index];
    }

    int CalculateChecksum() const {
        int sum = 0;

        for (int i = 0; i < m_Size; i++) 
        {
            sum += m_Data[i];
        }

        return sum;
    }
};

void VerifyFirmware(SecureROM rom) {
    std::cout << "   -> 正在校验副本... Checksum: " << rom.CalculateChecksum() << std::endl;
}

int main() {
    std::cout << "--- 步骤 1: 创建原版芯片 (Master) ---" << std::endl;
    SecureROM masterChip(1024);

    std::cout << "   -> 检查首字节: 0x" << std::hex << (int)masterChip.ReadByte(0) << std::dec << std::endl;

    std::cout << "\n--- 步骤 2: 发送芯片去校验 (触发克隆) ---" << std::endl;

    VerifyFirmware(masterChip);

    std::cout << "\n--- 步骤 3: 程序结束 ---" << std::endl;

    return 0;
}