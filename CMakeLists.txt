cmake_minimum_required(VERSION 3.26)
set(ProjectName DesignPattern)
project(${ProjectName})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        main.cpp
        DesignPattern/Creational/Singleton.cpp
        DesignPattern/Creational/Singleton.h
        DesignPattern/Creational/Factory.cpp
        DesignPattern/Creational/Factory.h
        DesignPattern/Creational/Builder.cpp
        DesignPattern/Creational/Builder.h
        DesignPattern/Creational/Prototype.cpp
        DesignPattern/Creational/Prototype.h
        DesignPattern/Structural/Adapter.cpp
        DesignPattern/Structural/Adapter.h
        DesignPattern/Structural/Bridge.cpp
        DesignPattern/Structural/Bridge.h
        DesignPattern/Structural/Composite.cpp
        DesignPattern/Structural/Composite.h
        DesignPattern/Structural/Decorator.cpp
        DesignPattern/Structural/Decorator.h
        DesignPattern/Structural/Facade.cpp
        DesignPattern/Structural/Facade.h
        DesignPattern/Structural/Flyweight.cpp
        DesignPattern/Structural/Flyweight.h
        DesignPattern/Structural/Proxy.cpp
        DesignPattern/Structural/Proxy.h
        DesignPattern/Behavioral/ResponsibilityChain.cpp
        DesignPattern/Behavioral/ResponsibilityChain.h
        DesignPattern/Behavioral/Command.cpp
        DesignPattern/Behavioral/Command.h
        DesignPattern/Behavioral/Interpreter.cpp
        DesignPattern/Behavioral/Interpreter.h
        DesignPattern/Behavioral/Iterator.cpp
        DesignPattern/Behavioral/Iterator.h
        DesignPattern/Behavioral/Mediator.cpp
        DesignPattern/Behavioral/Mediator.h
        DesignPattern/Behavioral/Memento.cpp
        DesignPattern/Behavioral/Memento.h
        DesignPattern/Behavioral/NullObject.cpp
        DesignPattern/Behavioral/NullObject.h
        DesignPattern/Behavioral/Observer.cpp
        DesignPattern/Behavioral/Observer.h
        DesignPattern/Behavioral/State.cpp
        DesignPattern/Behavioral/State.h
        DesignPattern/Behavioral/Strategy.cpp
        DesignPattern/Behavioral/Strategy.h
        DesignPattern/Behavioral/TemplateMethod.cpp
        DesignPattern/Behavioral/TemplateMethod.h
        DesignPattern/Behavioral/Visitor.cpp
        DesignPattern/Behavioral/Visitor.h
)