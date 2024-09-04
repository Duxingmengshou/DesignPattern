#ifndef CMAKE_CHECK_NULLOBJECT_H
#define CMAKE_CHECK_NULLOBJECT_H

#include <iostream>
#include <memory>

namespace DP {
    // 抽象日志类
    class Logger {
    public:
        virtual ~Logger() {}

        virtual void log(const std::string &message) = 0;
    };

    // 具体日志类
    class ConsoleLogger : public Logger {
    public:
        void log(const std::string &message) override {
            std::cout << "Console: " << message << std::endl;
        }
    };

    // 空日志类
    class NullLogger : public Logger {
    public:
        void log(const std::string &message) override {
            // 不执行任何操作
        }
    };

    // 客户端代码
    void clientCode(std::unique_ptr<Logger> logger);
} // DP

#endif //CMAKE_CHECK_NULLOBJECT_H
