#ifndef CMAKE_CHECK_MEMENTO_H
#define CMAKE_CHECK_MEMENTO_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace DP {
    // 备忘录
    class Memento {
    private:
        std::string state;

    public:
        Memento(const std::string &state) : state(state) {}

        std::string getState() const { return state; }
    };

    // 发起人
    class Originator {
    private:
        std::string state;

    public:
        void setState(const std::string &state) {
            this->state = state;
            std::cout << "State set to: " << state << std::endl;
        }

        std::string getState() const {
            return state;
        }

        std::unique_ptr<Memento> saveToMemento() {
            return std::make_unique<Memento>(state);
        }

        void restoreFromMemento(const Memento &memento) {
            state = memento.getState();
            std::cout << "State restored to: " << state << std::endl;
        }
    };

    // 管理者
    class Caretaker {
    private:
        std::vector<std::unique_ptr<Memento>> mementos;

    public:
        void addMemento(std::unique_ptr<Memento> memento) {
            mementos.push_back(std::move(memento));
        }

        Memento *getMemento(int index) {
            if (index < 0 || index >= mementos.size()) {
                return nullptr;
            }
            return mementos[index].get();
        }
    };
}

#endif //CMAKE_CHECK_MEMENTO_H
