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
#include <any>
#include <iostream>

#include "Component.hpp"

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    namespace Operation {

        class AsyncOperation {
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
        };

    }

}

#endif /* !ASYNCOPERATOR_HPP_ */
