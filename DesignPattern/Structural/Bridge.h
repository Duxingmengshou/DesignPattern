#ifndef CMAKE_CHECK_BRIDGE_H
#define CMAKE_CHECK_BRIDGE_H

#include <iostream>
#include <memory>

namespace DP {
    // 实现接口
    class Implementor {
    public:
        virtual void operationImpl() const = 0;

        virtual ~Implementor() = default;
    };

    // 具体实现类 A
    class ConcreteImplementorA : public Implementor {
    public:
        void operationImpl() const override {
            std::cout << "ConcreteImplementorA operation" << std::endl;
        }
    };

    // 具体实现类 B
    class ConcreteImplementorB : public Implementor {
    public:
        void operationImpl() const override {
            std::cout << "ConcreteImplementorB operation" << std::endl;
        }
    };

    // 抽象类
    class Abstraction {
    protected:
        std::unique_ptr<Implementor> implementor;

    public:
        Abstraction(std::unique_ptr<Implementor> impl) : implementor(std::move(impl)) {}

        virtual void operation() const {
            implementor->operationImpl();
        }

        virtual ~Abstraction() = default;
    };

    // 扩展抽象类
    class RefinedAbstraction : public Abstraction {
    public:
        RefinedAbstraction(std::unique_ptr<Implementor> impl) : Abstraction(std::move(impl)) {}

        void operation() const override {
            std::cout << "RefinedAbstraction: ";
            Abstraction::operation();
        }
    };

}

#endif //CMAKE_CHECK_BRIDGE_H
