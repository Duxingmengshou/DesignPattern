#ifndef CMAKE_CHECK_ADAPTER_H
#define CMAKE_CHECK_ADAPTER_H

#include <iostream>

namespace DP {
    // 目标接口
    class Target {
    public:
        virtual void request() const {
            std::cout << "Target: Default request." << std::endl;
        }

        virtual ~Target() = default;
    };

    // 源接口
    class Adaptee {
    public:
        void specificRequest() const {
            std::cout << "Adaptee: Specific request." << std::endl;
        }
    };

    // 适配器
    class Adapter : public Target {
    public:
        Adapter(Adaptee *adaptee) : adaptee(adaptee) {}

        void request() const override {
            std::cout << "Adapter: Translating request to specific request." << std::endl;
            adaptee->specificRequest(); // 调用源接口的方法
        }

    private:
        Adaptee *adaptee; // 持有源接口的实例
    };

}

#endif //CMAKE_CHECK_ADAPTER_H
