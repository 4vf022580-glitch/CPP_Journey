#include <iostream>

class Log
{
public:
    // 定义日志级别常量
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    // 成员变量，通常设为 private 以实现封装
    int m_LogLevel = LogLevelInfo;

public:
    // 设置日志级别的方法
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    // 打印错误信息
    void Error(const char* message)
    {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    // 打印警告信息
    void Warn(const char* message)
    {
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    // 打印普通信息
    void Info(const char* message)
    {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main()
{
    Log log; // 实例化类
    log.SetLevel(log.LogLevelWarning); // 设置只显示警告及以上级别
    log.Warn("Hello!");
    log.Error("Something went wrong!");
    log.Info("This will not print."); // 因级别设置，此行不会输出

    std::cin.get();
}
