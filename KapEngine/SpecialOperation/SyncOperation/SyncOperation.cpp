/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** AsyncOperator
*/

#include "SyncOperation.hpp"

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
