#include "DesignPattern/Creational/Singleton.h"
#include "DesignPattern/Creational/Factory.h"
#include "DesignPattern/Creational/Builder.h"
#include "DesignPattern/Creational/Prototype.h"
#include "DesignPattern/Structural/Adapter.h"
#include "DesignPattern/Structural/Bridge.h"
#include "DesignPattern/Structural/Composite.h"
#include "DesignPattern/Structural/Decorator.h"
#include "DesignPattern/Structural/Facade.h"
#include "DesignPattern/Structural/Flyweight.h"
#include "DesignPattern/Structural/Proxy.h"
#include "DesignPattern/Behavioral/ResponsibilityChain.h"
#include "DesignPattern/Behavioral/Command.h"
#include "DesignPattern/Behavioral/Interpreter.h"
#include "DesignPattern/Behavioral/Iterator.h"
#include "DesignPattern/Behavioral/Mediator.h"
#include "DesignPattern/Behavioral/Memento.h"
#include "DesignPattern/Behavioral/NullObject.h"
#include "DesignPattern/Behavioral/Observer.h"
#include "DesignPattern/Behavioral/State.h"
#include "DesignPattern/Behavioral/Strategy.h"
#include "DesignPattern/Behavioral/TemplateMethod.h"
#include "DesignPattern/Behavioral/Visitor.h"

using namespace DP;

int main() {
    ///单例模式
    LazySingleton &lazySingleton = LazySingleton::getInstance();
    std::cout << "Lazy Singleton instance address: " << &lazySingleton << std::endl;
    LazySingleton &lazySingleton1 = LazySingleton::getInstance();
    std::cout << "Lazy Singleton instance address: " << &lazySingleton1 << std::endl;
    EagerSingleton &eagerSingleton = EagerSingleton::getInstance();
    std::cout << "Eager Singleton instance address: " << &eagerSingleton << std::endl;
    EagerSingleton &eagerSingleton1 = EagerSingleton::getInstance();
    std::cout << "Eager Singleton instance address: " << &eagerSingleton1 << std::endl;


    ///工厂模式
    Creator *creatorA = new ConcreteCreatorA();
    Product *productA = creatorA->factoryMethod();
    productA->operation(); // 输出: ConcreteProductA operation
    Creator *creatorB = new ConcreteCreatorB();
    Product *productB = creatorB->factoryMethod();
    productB->operation(); // 输出: ConcreteProductB operation
    delete productA;
    delete productB;
    delete creatorA;
    delete creatorB;


    ///抽象工厂模式
    GUIFactory *factory = new WindowsFactory;
    Button *button = factory->createButton();
    Checkbox *checkbox = factory->createCheckbox();
    button->paint();
    checkbox->check();
    delete button;
    delete checkbox;
    delete factory;


    ///构造器模式
    Director director;
    SportsCarBuilder builder;
    director.construct(&builder);
    Car *car = builder.getResult();
    car->show();
    delete car;


    ///原型模式
    ConcretePrototype prototype("Original");
    prototype.show();
    // 通过原型克隆新对象
    std::unique_ptr<Prototype> clone = prototype.clone();
    clone->show();


    ///适配器模式
    Adaptee adaptee;
    Adapter adapter(&adaptee);
    adapter.request();


    ///桥接模式
    std::unique_ptr<Implementor> implementorA = std::make_unique<ConcreteImplementorA>();
    RefinedAbstraction abstractionA(std::move(implementorA));
    abstractionA.operation();
    std::unique_ptr<Implementor> implementorB = std::make_unique<ConcreteImplementorB>();
    RefinedAbstraction abstractionB(std::move(implementorB));
    abstractionB.operation();


    ///组合模式
    std::unique_ptr<Component> leaf1 = std::make_unique<Leaf>();
    std::unique_ptr<Component> leaf2 = std::make_unique<Leaf>();
    leaf1->operation();
    Composite composite;
    composite.add(std::move(leaf1));
    composite.add(std::move(leaf2));
    composite.operation();


    ///装饰器模式
    std::unique_ptr<Coffee> coffee = std::make_unique<SimpleCoffee>();
    std::cout << coffee->description() << " costs: $" << coffee->cost() << std::endl;
    coffee = std::make_unique<MilkDecorator>(std::move(coffee));
    std::cout << coffee->description() << " costs: $" << coffee->cost() << std::endl;
    coffee = std::make_unique<SugarDecorator>(std::move(coffee));
    std::cout << coffee->description() << " costs: $" << coffee->cost() << std::endl;


    ///外观模式
    Facade facade;
    facade.simpleOperation(); // 通过外观类进行操作


    ///享元模式
    FlyweightFactory flyweightFactory;
    auto flyweight1 = flyweightFactory.getFlyweight("State1");
    flyweight1->operation("Context1");
    auto flyweight2 = flyweightFactory.getFlyweight("State1"); // 重用
    flyweight2->operation("Context2");
    auto flyweight3 = flyweightFactory.getFlyweight("State2");
    flyweight3->operation("Context3");


    ///代理模式
    Proxy *proxy = new Proxy();
    proxy->request(); // 通过代理对象进行请求
    delete proxy; // 清理资源


    ///职责链模式
    HandlerListFactory handlerListFactory;
    handlerListFactory.addHandler(new ConcreteHandlerA());
    handlerListFactory.addHandler(new ConcreteHandlerB());
    handlerListFactory.addHandler(new ConcreteHandlerC());
    handlerListFactory.handleRequest("B");
    handlerListFactory.handleRequest("C");
    handlerListFactory.handleRequest("A");
    handlerListFactory.handleRequest("D");


    ///命令模式
    Light light;
    TurnOnLightCommand turnOn(&light);
    TurnOffLightCommand turnOff(&light);
    RemoteControl remote;
    remote.setCommand(&turnOn);
    remote.pressButton();
    remote.setCommand(&turnOff);
    remote.pressButton();


    ///解释器模式
    Context context;
    context.assign("x", 10);
    context.assign("y", 5);
    // 表达式：x + y - 3
    std::shared_ptr<Expression> expression =
            std::make_shared<Subtract>(
                    std::make_shared<Add>(
                            std::make_shared<Variable>("x"),
                            std::make_shared<Variable>("y")
                    ),
                    std::make_shared<Number>(3)
            );
    int result = expression->interpret(context);
    std::cout << "Result: " << result << std::endl; // 输出：Result: 12


    ///迭代器模式
    ConcreteAggregate aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);
    std::unique_ptr<Iterator> iterator = aggregate.createIterator();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl; // 输出：1 2 3


    ///中介者模式
    ChatMediator mediator;
    User user1("Alice", &mediator);
    User user2("Bob", &mediator);
    User user3("Charlie", &mediator);
    mediator.addColleague(&user1);
    mediator.addColleague(&user2);
    mediator.addColleague(&user3);
    user1.send("Hello, everyone!");
    user2.send("Hi, Alice!");


    ///备忘录模式
    Originator originator;
    Caretaker caretaker;
    originator.setState("State 1");
    caretaker.addMemento(originator.saveToMemento());
    originator.setState("State 2");
    caretaker.addMemento(originator.saveToMemento());
    originator.setState("State 3");
    // 恢复到之前的状态
    originator.restoreFromMemento(*caretaker.getMemento(1)); // 恢复到 State 2
    originator.restoreFromMemento(*caretaker.getMemento(0)); // 恢复到 State 1


    ///空对象模式
    std::unique_ptr<Logger> logger1 = std::make_unique<ConsoleLogger>();
    clientCode(std::move(logger1)); // 使用具体日志
    std::unique_ptr<Logger> logger2 = std::make_unique<NullLogger>();
    clientCode(std::move(logger2)); // 使用空日志


    ///观察者模式
    WeatherData weatherData;
    auto currentDisplay = std::make_shared<CurrentConditionsDisplay>();
    weatherData.registerObserver(currentDisplay);
    weatherData.setMeasurements(25.0f, 65.0f); // 更新天气数据
    weatherData.setMeasurements(30.0f, 70.0f); // 再次更新天气数据


    ///状态模式
    auto offState = std::make_shared<OffState>();
    auto onState = std::make_shared<OnState>();
    LightState lightState(offState); // 初始状态为关
    lightState.pressSwitch(); // 输出: Light is now ON.
    lightState.setState(onState); // 切换到开状态
    lightState.pressSwitch(); // 输出: Light is now OFF.


    ///策略模式
    ShoppingCart cart;
    // 使用信用卡支付
    cart.setPaymentStrategy(std::make_shared<CreditCardPayment>());
    cart.checkout(100);
    // 使用PayPal支付
    cart.setPaymentStrategy(std::make_shared<PayPalPayment>());
    cart.checkout(200);


    ///模板方法
    CaffeineBeverage *tea = new makeTea();
    tea->prepareRecipe();
    CaffeineBeverage *coff = new makeCoffee();
    coff->prepareRecipe();
    delete tea;
    delete coff;


    ///访问者模式
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Circle>());
    shapes.push_back(std::make_shared<Square>());
    DrawVisitor drawVisitor;
    for (const auto &shape: shapes) {
        shape->accept(&drawVisitor);
    }

    return 0;
}