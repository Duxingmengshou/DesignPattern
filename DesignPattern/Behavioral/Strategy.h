#ifndef CMAKE_CHECK_STRATEGY_H
#define CMAKE_CHECK_STRATEGY_H

#include <iostream>
#include <memory>

namespace DP {
    // 策略接口
    class PaymentStrategy {
    public:
        virtual ~PaymentStrategy() {}

        virtual void pay(int amount) = 0;
    };

    // 具体策略：信用卡支付
    class CreditCardPayment : public PaymentStrategy {
    public:
        void pay(int amount) override {
            std::cout << "Paid " << amount << " using Credit Card." << std::endl;
        }
    };

    // 具体策略：PayPal支付
    class PayPalPayment : public PaymentStrategy {
    public:
        void pay(int amount) override {
            std::cout << "Paid " << amount << " using PayPal." << std::endl;
        }
    };

    // 上下文
    class ShoppingCart {
    private:
        std::shared_ptr<PaymentStrategy> paymentStrategy;

    public:
        void setPaymentStrategy(std::shared_ptr<PaymentStrategy> strategy) {
            paymentStrategy = strategy;
        }

        void checkout(int amount) {
            if (paymentStrategy) {
                paymentStrategy->pay(amount);
            } else {
                std::cout << "Payment strategy not set!" << std::endl;
            }
        }
    };
}

#endif //CMAKE_CHECK_STRATEGY_H
