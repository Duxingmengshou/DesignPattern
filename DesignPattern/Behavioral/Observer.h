#ifndef CMAKE_CHECK_OBSERVER_H
#define CMAKE_CHECK_OBSERVER_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace DP {
    // 观察者接口，依赖于主题的对象，定义一个更新接口，以便在主题状态变化时接收通知。
    class Observer {
    public:
        virtual ~Observer() = default;

        virtual void update(float temperature, float humidity) = 0;
    };

    // 主题接口，被观察的对象，维护观察者的列表，并提供添加、删除观察者的方法。
    class SubjectOberver {
    public:
        virtual ~SubjectOberver() = default;

        virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void notifyObservers() = 0;
    };

    // 具体主题
    class WeatherData : public SubjectOberver {
    private:
        std::vector<std::shared_ptr<Observer>> observers;
        float temperature;
        float humidity;

    public:
        void registerObserver(std::shared_ptr<Observer> observer) override {
            observers.push_back(observer);
        }

        void removeObserver(std::shared_ptr<Observer> observer) override {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers() override {
            for (const auto &observer: observers) {
                observer->update(temperature, humidity);
            }
        }

        void setMeasurements(float temp, float hum) {
            temperature = temp;
            humidity = hum;
            notifyObservers();
        }
    };

    // 具体观察者
    class CurrentConditionsDisplay : public Observer {
    private:
        float temperature;
        float humidity;

    public:
        void update(float temp, float hum) override {
            temperature = temp;
            humidity = hum;
            display();
        }

        void display() {
            std::cout << "Current conditions: " << temperature << "°C and " << humidity << "% humidity." << std::endl;
        }
    };
}

#endif //CMAKE_CHECK_OBSERVER_H
