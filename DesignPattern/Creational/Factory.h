#ifndef CMAKE_CHECK_FACTORY_H
#define CMAKE_CHECK_FACTORY_H

#include <iostream>

namespace DP {
    // 产品接口
    class Product {
    public:
        virtual void operation() = 0; // 纯虚函数
    };

    // 具体产品 A
    class ConcreteProductA : public Product {
    public:
        void operation() override {
            std::cout << "ConcreteProductA operation" << std::endl;
        }
    };

    // 具体产品 B
    class ConcreteProductB : public Product {
    public:
        void operation() override {
            std::cout << "ConcreteProductB operation" << std::endl;
        }
    };

    // 工厂接口
    class Creator {
    public:
        virtual Product *factoryMethod() = 0; // 工厂方法
    };

    // 具体工厂 A
    class ConcreteCreatorA : public Creator {
    public:
        Product *factoryMethod() override {
            return new ConcreteProductA(); // 创建具体产品 A
        }
    };

    // 具体工厂 B
    class ConcreteCreatorB : public Creator {
    public:
        Product *factoryMethod() override {
            return new ConcreteProductB(); // 创建具体产品 B
        }
    };

    // 抽象产品
    class Button {
    public:
        virtual void paint() = 0; // 纯虚函数
    };

    class Checkbox {
    public:
        virtual void check() = 0; // 纯虚函数
    };

    // 具体产品
    class WindowsButton : public Button {
    public:
        void paint() override {
            std::cout << "Windows 风格的按钮绘制\n";
        }
    };

    class WindowsCheckbox : public Checkbox {
    public:
        void check() override {
            std::cout << "Windows 风格的复选框检查\n";
        }
    };

    // 抽象工厂
    class GUIFactory {
    public:
        virtual Button *createButton() = 0;

        virtual Checkbox *createCheckbox() = 0;
    };

    // 具体工厂
    class WindowsFactory : public GUIFactory {
    public:
        Button *createButton() override {
            return new WindowsButton();
        }

        Checkbox *createCheckbox() override {
            return new WindowsCheckbox();
        }
    };


}
#endif //CMAKE_CHECK_FACTORY_H
