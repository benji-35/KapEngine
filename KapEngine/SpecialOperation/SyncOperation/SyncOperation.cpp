/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** AsyncOperator
*/

#include "SyncOperation.hpp"

#ifdef ANY_SYNC

    KapEngine::Operation::SyncOperation::SyncOperation(std::any a) : _any(a) {}

    KapEngine::Operation::SyncOperation::~SyncOperation() {}

    void KapEngine::Operation::SyncOperation::setOperationFunction(std::function<void(std::any)> f) {
        _func = f;
    }

    void KapEngine::Operation::SyncOperation::startSync() {
        std::thread t(__threadRun, _func, _any);
        t.join();
    }

    void KapEngine::Operation::SyncOperation::__threadRun(std::function<void(std::any)> f, std::any any) {
        f(any);
    }

#else

    KapEngine::Operation::SyncOperation::SyncOperation(std::shared_ptr<void> a) : _any(a) {}

    KapEngine::Operation::SyncOperation::~SyncOperation() {}

    void KapEngine::Operation::SyncOperation::setOperationFunction(std::function<void(std::shared_ptr<void>)> f) {
        _func = f;
    }

    void KapEngine::Operation::SyncOperation::startSync() {
        std::thread t(__threadRun, _func, _any);
        t.join();
    }

    void KapEngine::Operation::SyncOperation::__threadRun(std::function<void(std::shared_ptr<void>)> f, std::shared_ptr<void> any) {
        f(any);
    }

#endif
