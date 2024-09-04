#ifndef CMAKE_CHECK_STATE_H
#define CMAKE_CHECK_STATE_H

#include <iostream>
#include <memory>

namespace DP {
    // 状态接口
    class State {
    public:
        virtual ~State() {}

        virtual void pressSwitch() = 0;
    };

    // 上下文
    class LightState {
    private:
        std::shared_ptr<State> state;

    public:
        LightState(std::shared_ptr<State> initialState) : state(initialState) {}

        void setState(std::shared_ptr<State> newState) {
            state = newState;
        }

        void pressSwitch() {
            state->pressSwitch();
        }
    };

    // 具体状态：开
    class OnState : public State {
    public:
        void pressSwitch() override {
            std::cout << "Light is now OFF." << std::endl;
        }
    };

    // 具体状态：关
    class OffState : public State {
    public:
        void pressSwitch() override {
            std::cout << "Light is now ON." << std::endl;
        }
    };

} // DP

#endif //CMAKE_CHECK_STATE_H
