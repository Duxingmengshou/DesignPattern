#ifndef CMAKE_CHECK_SINGLETON_H
#define CMAKE_CHECK_SINGLETON_H

#include <iostream>

namespace DP {
    class SingletonBase {
    public:
        // 禁止拷贝构造和赋值操作
        SingletonBase(const SingletonBase &) = delete;

        void operator=(const SingletonBase &) = delete;

    protected:
        // 私有构造函数
        SingletonBase() = default;

        ~SingletonBase() = default;
    };

    // 懒汉单例
    class LazySingleton : public SingletonBase {
    public:
        // 获取单例实例（懒汉式）
        static LazySingleton &getInstance() {
            static LazySingleton instance; // 懒汉式
            return instance;
        }
    };

    // 饿汉单例
    class EagerSingleton : public SingletonBase {
    private:
        static EagerSingleton instance;
    public:
        static EagerSingleton &getInstance() {
            return instance;
        }
    };
}

#endif //CMAKE_CHECK_SINGLETON_H
