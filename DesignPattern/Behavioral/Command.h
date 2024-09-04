#ifndef CMAKE_CHECK_COMMAND_H
#define CMAKE_CHECK_COMMAND_H

#include <iostream>
#include <vector>
#include <memory>

namespace DP {
    // 命令接口
    class Command {
    public:
        virtual ~Command() {}

        virtual void execute() = 0;
    };

    // 接收者
    class Light {
    public:
        void turnOn() {
            std::cout << "Light is ON" << std::endl;
        }

        void turnOff() {
            std::cout << "Light is OFF" << std::endl;
        }
    };

    // 具体命令：打开灯
    class TurnOnLightCommand : public Command {
    private:
        Light *light;

    public:
        explicit TurnOnLightCommand(Light *l) : light(l) {}

        void execute() override {
            light->turnOn();
        }
    };

    // 具体命令：关闭灯
    class TurnOffLightCommand : public Command {
    private:
        Light *light;

    public:
        explicit TurnOffLightCommand(Light *l) : light(l) {}

        void execute() override {
            light->turnOff();
        }
    };

    // 调用者
    class RemoteControl {
    private:
        Command *command;

    public:
        void setCommand(Command *cmd) {
            command = cmd;
        }

        void pressButton() {
            if (command) {
                command->execute();
            }
        }
    };
} // DP

#endif //CMAKE_CHECK_COMMAND_H
