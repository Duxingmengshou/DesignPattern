#ifndef CMAKE_CHECK_PROTOTYPE_H
#define CMAKE_CHECK_PROTOTYPE_H

#include <iostream>
#include <string>
#include <memory>

namespace DP {
    // 原型接口
    class Prototype {
    public:
        virtual std::unique_ptr<Prototype> clone() const = 0;

        virtual void show() const = 0;

        virtual ~Prototype() = default;
    };

    // 具体原型
    class ConcretePrototype : public Prototype {
    public:
        explicit ConcretePrototype(const std::string &name) : name(name) {}

        std::unique_ptr<Prototype> clone() const override {
            return std::make_unique<ConcretePrototype>(*this); // 浅拷贝
        }

        void show() const override {
            std::cout << "ConcretePrototype: " << name << std::endl;
        }

    private:
        std::string name;
    };

} // DP

#endif //CMAKE_CHECK_PROTOTYPE_H
