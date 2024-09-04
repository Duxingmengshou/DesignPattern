#ifndef CMAKE_CHECK_TEMPLATEMETHOD_H
#define CMAKE_CHECK_TEMPLATEMETHOD_H

#include <iostream>

namespace DP {
    // 抽象类
    class CaffeineBeverage {
    public:
        // 模板方法
        void prepareRecipe() {
            boilWater();
            brew();
            pourInCup();
            addCondiments();
        }

    protected:
        virtual void brew() = 0; // 抽象方法，子类实现
        virtual void addCondiments() = 0; // 抽象方法，子类实现

    private:
        void boilWater() {
            std::cout << "Boiling water..." << std::endl;
        }

        void pourInCup() {
            std::cout << "Pouring into cup..." << std::endl;
        }
    };

    // 具体类：茶
    class makeTea : public CaffeineBeverage {
    protected:
        void brew() override {
            std::cout << "Steeping the tea..." << std::endl;
        }

        void addCondiments() override {
            std::cout << "Adding lemon..." << std::endl;
        }
    };

    // 具体类：咖啡
    class makeCoffee : public CaffeineBeverage {
    protected:
        void brew() override {
            std::cout << "Dripping coffee through filter..." << std::endl;
        }

        void addCondiments() override {
            std::cout << "Adding sugar and milk..." << std::endl;
        }
    };
}

#endif //CMAKE_CHECK_TEMPLATEMETHOD_H
