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

#if __cplusplus >= 201703L
    #define ANY_SYNC
    #include <any>
#endif

#include "Component.hpp"

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    namespace Operation {

        class SyncOperation {

            #ifdef ANY_SYNC

                public:
                    SyncOperation(std::any a);
                    ~SyncOperation();

                    void setOperationFunction(std::function<void(std::any)>);
                    void startSync();
                    static void __threadRun(std::function<void(std::any)>, std::any any);
                protected:
                private:
                    std::any _any;
                    std::function<void(std::any)> _func;
        
            #else

                public:
                    SyncOperation(std::shared_ptr<void> a);
                    ~SyncOperation();

                    void setOperationFunction(std::function<void(std::shared_ptr<void>)>);
                    void startSync();
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
