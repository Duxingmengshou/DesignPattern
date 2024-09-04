#ifndef CMAKE_CHECK_INTERPRETER_H
#define CMAKE_CHECK_INTERPRETER_H

#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace DP {
    // 上下文类
    class Context {
    public:
        std::map<std::string, int> variables;

        void assign(const std::string &var, int value) {
            variables[var] = value;
        }

        int getValue(const std::string &var) {
            return variables[var];
        }
    };

    // 抽象表达式
    class Expression {
    public:
        virtual ~Expression() {}

        virtual int interpret(Context &context) = 0;
    };

    // 终结符表达式：变量
    class Variable : public Expression {
    private:
        std::string name;

    public:
        Variable(const std::string &name) : name(name) {}

        int interpret(Context &context) override {
            return context.getValue(name);
        }
    };

    // 终结符表达式：常量
    class Number : public Expression {
    private:
        int number;

    public:
        Number(int number) : number(number) {}

        int interpret(Context &context) override {
            return number;
        }
    };

    // 非终结符表达式：加法
    class Add : public Expression {
    private:
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;

    public:
        Add(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
                : left(left), right(right) {}

        int interpret(Context &context) override {
            return left->interpret(context) + right->interpret(context);
        }
    };

    // 非终结符表达式：减法
    class Subtract : public Expression {
    private:
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;

    public:
        Subtract(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
                : left(left), right(right) {}

        int interpret(Context &context) override {
            return left->interpret(context) - right->interpret(context);
        }
    };
}

#endif //CMAKE_CHECK_INTERPRETER_H