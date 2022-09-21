/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** AsyncOperator
*/

#ifndef ASYNCOPERATOR_HPP_
#define ASYNCOPERATOR_HPP_


#include <thread>
#include <mutex>
#include <functional>
#include <iostream>

#include "Component.hpp"

#if __cplusplus >= 201703L
    #define ANY_ASYNC
    #include <any>
#endif

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    namespace Operation {

        class AsyncOperation {
            #ifdef ANY_ASYNC
                public:
                    AsyncOperation(std::any a);
                    ~AsyncOperation();

                    void setOperationFunction(std::function<void(std::any)>);
                    void startAsync();
                    static void __threadRun(std::function<void(std::any)>, std::any any);
                protected:
                private:
                    std::any _any;
                    std::function<void(std::any)> _func;
            #else
                public:
                    AsyncOperation(std::shared_ptr<void> a);
                    ~AsyncOperation();

                    void setOperationFunction(std::function<void(std::shared_ptr<void>)>);
                    void startAsync();
                    static void __threadRun(std::function<void(std::shared_ptr<void>)>, std::shared_ptr<void> any);
                protected:
                private:
                    std::shared_ptr<void> _any;
                    std::function<void(std::shared_ptr<void>)> _func;
            #endif
        };

    }

}

#endif /* !ASYNCOPERATOR_HPP_ */
