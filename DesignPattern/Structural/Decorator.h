#ifndef CMAKE_CHECK_DECORATOR_H
#define CMAKE_CHECK_DECORATOR_H

#include <iostream>
#include <memory>

namespace DP {
    // 组件接口
    class Coffee {
    public:
        virtual double cost() const = 0;

        virtual std::string description() const = 0;

        virtual ~Coffee() = default;
    };

    // 具体组件
    class SimpleCoffee : public Coffee {
    public:
        double cost() const override {
            return 2.0; // 基础咖啡价格
        }

        std::string description() const override {
            return "Simple Coffee";
        }
    };

    // 装饰器
    class CoffeeDecorator : public Coffee {
    protected:
        std::unique_ptr<Coffee> coffee;

    public:
        CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}

        double cost() const override {
            return coffee->cost(); // 默认返回基础咖啡的价格
        }

        std::string description() const override {
            return coffee->description(); // 默认返回基础咖啡的描述
        }
    };

    // 具体装饰器：牛奶
    class MilkDecorator : public CoffeeDecorator {
    public:
        MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

        double cost() const override {
            return CoffeeDecorator::cost() + 0.5; // 加牛奶的额外费用
        }

        std::string description() const override {
            return CoffeeDecorator::description() + ", Milk"; // 添加牛奶描述
        }
    };

    // 具体装饰器：糖
    class SugarDecorator : public CoffeeDecorator {
    public:
        SugarDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

        double cost() const override {
            return CoffeeDecorator::cost() + 0.2; // 加糖的额外费用
        }

        std::string description() const override {
            return CoffeeDecorator::description() + ", Sugar"; // 添加糖描述
        }
    };
}

#endif //CMAKE_CHECK_DECORATOR_H
