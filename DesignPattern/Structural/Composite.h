#ifndef CMAKE_CHECK_COMPOSITE_H
#define CMAKE_CHECK_COMPOSITE_H

#include <iostream>
#include <vector>

namespace DP {

    // 组件接口
    class Component {
    public:
        virtual void operation() const = 0;

        virtual ~Component() = default;
    };

    // 叶子节点
    class Leaf : public Component {
    public:
        void operation() const override {
            std::cout << "Leaf operation" << std::endl;
        }
    };

    // 组合节点
    class Composite : public Component {
    private:
        std::vector<std::unique_ptr<Component>> children;

    public:
        void add(std::unique_ptr<Component> component) {
            children.push_back(std::move(component));
        }

        void operation() const override {
            std::cout << "Composite operation" << std::endl;
            for (const auto &child: children) {
                child->operation(); // 递归调用子节点的操作
            }
        }
    };

}

#endif //CMAKE_CHECK_COMPOSITE_H
