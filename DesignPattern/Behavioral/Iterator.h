#ifndef CMAKE_CHECK_ITERATOR_H
#define CMAKE_CHECK_ITERATOR_H

#include <iostream>
#include <vector>
#include <memory>

namespace DP {
    // 迭代器接口
    class Iterator {
    public:
        virtual ~Iterator() {}

        virtual bool hasNext() = 0;

        virtual int next() = 0;
    };

// 聚合接口
    class Aggregate {
    public:
        virtual ~Aggregate() {}

        virtual std::unique_ptr<Iterator> createIterator() = 0;

        virtual size_t size() = 0; // 添加 size 方法
        virtual int get(int) = 0;
    };


    // 具体迭代器
    class ConcreteIterator : public Iterator {
    private:
        Aggregate *aggregate;
        int index;

    public:
        ConcreteIterator(Aggregate *agg) : aggregate(agg), index(0) {}

        bool hasNext() override {
            return index < aggregate->size();
        }

        int next() override {
            return aggregate->get(index++);
        }
    };

    // 具体聚合
    class ConcreteAggregate : public Aggregate {
    private:
        std::vector<int> items;

    public:
        void add(int item) {
            items.push_back(item);
        }

        int get(int index) override {
            return items[index];
        }

        size_t size() override {
            return items.size();
        }

        std::unique_ptr<Iterator> createIterator() override {
            return std::make_unique<ConcreteIterator>(this);
        }
    };
}
#endif //CMAKE_CHECK_ITERATOR_H