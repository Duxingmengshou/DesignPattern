#ifndef CMAKE_CHECK_PROXY_H
#define CMAKE_CHECK_PROXY_H

#include <iostream>

namespace DP {
    // 主题接口
    class Subject {
    public:
        virtual void request() = 0; // 纯虚函数
    };

    // 真实主题
    class RealSubject : public Subject {
    public:
        void request() override {
            std::cout << "RealSubject: Handling request." << std::endl;
        }
    };

    // 代理
    class Proxy : public Subject {
    private:
        RealSubject *realSubject;

    public:
        Proxy() {
            realSubject = new RealSubject(); // 创建真实主题
        }

        ~Proxy() {
            delete realSubject; // 清理资源
        }

        void request() override {
            std::cout << "Proxy: Pre-processing before request." << std::endl;
            realSubject->request(); // 调用真实主题的方法
            std::cout << "Proxy: Post-processing after request." << std::endl;
        }
    };
}

#endif //CMAKE_CHECK_PROXY_H
