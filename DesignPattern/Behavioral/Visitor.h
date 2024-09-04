#ifndef CMAKE_CHECK_VISITOR_H
#define CMAKE_CHECK_VISITOR_H

#include <iostream>
#include <vector>
#include <memory>

namespace DP {
    // 前向声明
    class Circle;

    class Square;

    // 访问者接口
    class ShapeVisitor {
    public:
        virtual ~ShapeVisitor() {}

        virtual void visit(Circle *circle) = 0;

        virtual void visit(Square *square) = 0;
    };

    // 元素接口
    class Shape {
    public:
        virtual ~Shape() {}

        virtual void accept(ShapeVisitor *visitor) = 0;
    };

    // 具体元素：圆形
    class Circle : public Shape {
    public:
        void accept(ShapeVisitor *visitor) override {
            visitor->visit(this);
        }

        void draw() {
            std::cout << "Drawing a Circle." << std::endl;
        }
    };

    // 具体元素：正方形
    class Square : public Shape {
    public:
        void accept(ShapeVisitor *visitor) override {
            visitor->visit(this);
        }

        void draw() {
            std::cout << "Drawing a Square." << std::endl;
        }
    };

    // 具体访问者：绘制访问者
    class DrawVisitor : public ShapeVisitor {
    public:
        void visit(Circle *circle) override {
            circle->draw();
        }

        void visit(Square *square) override {
            square->draw();
        }
    };
}

#endif //CMAKE_CHECK_VISITOR_H
