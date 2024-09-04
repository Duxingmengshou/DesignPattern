#ifndef CMAKE_CHECK_FACADE_H
#define CMAKE_CHECK_FACADE_H

#include <iostream>

namespace DP {
    // 子系统类 A
    class SubsystemA {
    public:
        void operationA() {
            std::cout << "Subsystem A: Operation A" << std::endl;
        }
    };

    // 子系统类 B
    class SubsystemB {
    public:
        void operationB() {
            std::cout << "Subsystem B: Operation B" << std::endl;
        }
    };

    // 子系统类 C
    class SubsystemC {
    public:
        void operationC() {
            std::cout << "Subsystem C: Operation C" << std::endl;
        }
    };

    // 外观类
    class Facade {
    private:
        SubsystemA subsystemA;
        SubsystemB subsystemB;
        SubsystemC subsystemC;

    public:
        void simpleOperation() {
            std::cout << "Facade: Simple Operation" << std::endl;
            subsystemA.operationA();
            subsystemB.operationB();
            subsystemC.operationC();
        }
    };
}

#endif //CMAKE_CHECK_FACADE_H
