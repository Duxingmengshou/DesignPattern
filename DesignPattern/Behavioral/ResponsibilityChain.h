#ifndef CMAKE_CHECK_RESPONSIBILITYCHAIN_H
#define CMAKE_CHECK_RESPONSIBILITYCHAIN_H

#include <iostream>
#include <string>

namespace DP {

    class HandlerListFactory;

    // 抽象处理者
    class Handler {
    protected:
        Handler *nextHandler;

    public:
        Handler() : nextHandler(nullptr) {}

        virtual ~Handler() {}

        void setNextHandler(Handler *handler) {
            nextHandler = handler;
        }

        virtual void handleRequest(const std::string &request) {
            if (nextHandler) {
                nextHandler->handleRequest(request);
            }
        }

        friend HandlerListFactory;
    };

    // 具体处理者 A
    class ConcreteHandlerA : public Handler {
    public:
        void handleRequest(const std::string &request) override {
            if (request == "A") {
                std::cout << "Handler A handling request A" << std::endl;
            } else {
                Handler::handleRequest(request);
            }
        }
    };

    // 具体处理者 B
    class ConcreteHandlerB : public Handler {
    public:
        void handleRequest(const std::string &request) override {
            if (request == "B") {
                std::cout << "Handler B handling request B" << std::endl;
            } else {
                Handler::handleRequest(request);
            }
        }
    };

    // 具体处理者 C
    class ConcreteHandlerC : public Handler {
    public:
        void handleRequest(const std::string &request) override {
            if (request == "C") {
                std::cout << "Handler C handling request C" << std::endl;
            } else {
                Handler::handleRequest(request);
            }
        }
    };

// 处理者链工厂类
    class HandlerListFactory {
    private:
        Handler *start;

    public:
        HandlerListFactory() : start(nullptr) {}

        // 添加处理者到链中
        void addHandler(Handler *handler) {
            if (!start) {
                start = handler;
            } else {
                Handler *current = start;
                while (current->nextHandler) {
                    current = current->nextHandler;
                }
                current->setNextHandler(handler);
            }
        }

        // 处理请求
        void handleRequest(const std::string &request) {
            if (start) {
                start->handleRequest(request);
            } else {
                std::cout << "No handlers in the chain." << std::endl;
            }
        }

        ~HandlerListFactory() {
            // 清理内存
            Handler *current = start;
            while (current) {
                Handler *next = current->nextHandler;
                delete current;
                current = next;
            }
        }
    };
}

#endif //CMAKE_CHECK_RESPONSIBILITYCHAIN_H
