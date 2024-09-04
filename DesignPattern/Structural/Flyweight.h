#ifndef CMAKE_CHECK_FLYWEIGHT_H
#define CMAKE_CHECK_FLYWEIGHT_H

#include <iostream>
#include <unordered_map>
#include <memory>

namespace DP {
    // 享元接口
    class Flyweight {
    public:
        virtual void operation(const std::string &extrinsicState) = 0;

        virtual ~Flyweight() = default;
    };

    // 具体享元
    class ConcreteFlyweight : public Flyweight {
    private:
        std::string intrinsicState; // 共享状态

    public:
        ConcreteFlyweight(const std::string &state) : intrinsicState(state) {}

        void operation(const std::string &extrinsicState) override {
            std::cout << "Intrinsic State: " << intrinsicState
                      << ", Extrinsic State: " << extrinsicState << std::endl;
        }
    };

    // 享元工厂
    class FlyweightFactory {
    private:
        std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;

    public:
        std::shared_ptr<Flyweight> getFlyweight(const std::string &key) {
            if (flyweights.find(key) == flyweights.end()) {
                flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
            }
            return flyweights[key];
        }
    };
}

#endif //CMAKE_CHECK_FLYWEIGHT_H
