#include <iostream>

class Log
{
public:
    enum Level
    {
        Error = 0,Warning, Info
};

private:
    // 成员变量，通常设为 private 以实现封装
    int m_LogLevel = Info;

public:
    // 设置日志级别的方法
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    // 打印错误信息
    void Error(const char* message)
    {
        if (m_LogLevel >= Error)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    // 打印警告信息
    void Warn(const char* message)
    {
        if (m_LogLevel >= Warning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    // 打印普通信息
    void Info(const char* message)
    {
        if (m_LogLevel >= Info)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main()
{
    Log log; // 实例化类
    log.SetLevel(Log::Error); // 设置只显示警告及以上级别
    log.Warn("Hello!");
    log.Error("Something went wrong!");
    log.Info("This will not print."); // 因级别设置，此行不会输出

    std::cin.get();
}
