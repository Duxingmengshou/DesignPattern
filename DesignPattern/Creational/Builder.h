#ifndef CMAKE_CHECK_BUILDER_H
#define CMAKE_CHECK_BUILDER_H

#include <string>
#include <iostream>


namespace DP {

    // 产品
    class Car {
    public:
        void setEngine(const std::string &engine) { this->engine = engine; }

        void setWheels(int wheels) { this->wheels = wheels; }

        void setColor(const std::string &color) { this->color = color; }

        void show() {
            std::cout << engine << "-" << wheels << "-" << color << std::endl;
        }

    private:
        std::string engine;
        int wheels;
        std::string color;
    };

    // 抽象建造者
    class CarBuilder {
    public:
        virtual void buildEngine() = 0;

        virtual void buildWheels() = 0;

        virtual void buildColor() = 0;

        virtual Car *getResult() = 0;
    };

    // 具体建造者
    class SportsCarBuilder : public CarBuilder {
    public:
        SportsCarBuilder() { car = new Car(); }

        void buildEngine() override {
            car->setEngine("V8 Engine");
        }

        void buildWheels() override {
            car->setWheels(4);
        }

        void buildColor() override {
            car->setColor("Red");
        }

        Car *getResult() override {
            return car;
        }

    private:
        Car *car;
    };

    // 指挥者
    class Director {
    public:
        void construct(CarBuilder *builder) {
            builder->buildEngine();
            builder->buildWheels();
            builder->buildColor();
        }
    };


}

#endif //CMAKE_CHECK_BUILDER_H
