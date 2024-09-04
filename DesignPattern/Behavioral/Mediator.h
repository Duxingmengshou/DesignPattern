#ifndef CMAKE_CHECK_MEDIATOR_H
#define CMAKE_CHECK_MEDIATOR_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace DP {
    // 中介者接口
    class Mediator {
    public:
        virtual ~Mediator() = default;

        virtual void send(const std::string &message, class Colleague *colleague) = 0;
    };

    // 同事类
    class Colleague {
    protected:
        Mediator *mediator;

    public:
        Colleague(Mediator *mediator) : mediator(mediator) {}

        virtual ~Colleague() {}

        virtual void receive(const std::string &message) = 0;
    };

    // 具体同事类：用户
    class User : public Colleague {
    private:
        std::string name;

    public:
        User(const std::string &name, Mediator *mediator) : Colleague(mediator), name(name) {}

        void send(const std::string &message) {
            std::cout << name << " sends: " << message << std::endl;
            mediator->send(message, this);
        }

        void receive(const std::string &message) override {
            std::cout << name << " receives: " << message << std::endl;
        }
    };

    // 具体中介者
    class ChatMediator : public Mediator {
    private:
        std::vector<Colleague *> colleagues;

    public:
        void addColleague(Colleague *colleague) {
            colleagues.push_back(colleague);
        }

        void send(const std::string &message, Colleague *sender) override {
            for (Colleague *colleague: colleagues) {
                // 不发送给发送者自己
                if (colleague != sender) {
                    colleague->receive(message);
                }
            }
        }
    };
}

#endif //CMAKE_CHECK_MEDIATOR_H
