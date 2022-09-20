/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** AsyncOperator
*/

#include "AsyncOperation.hpp"

KapEngine::Operation::AsyncOperation::AsyncOperation(std::any a) : _any(a) {}

KapEngine::Operation::AsyncOperation::~AsyncOperation() {}

void KapEngine::Operation::AsyncOperation::setOperationFunction(std::function<void(std::any )> f) {
    _func = f;
}

void KapEngine::Operation::AsyncOperation::startAsync() {
    std::thread t(__threadRun, _func, _any);
    t.detach();
}

void KapEngine::Operation::AsyncOperation::__threadRun(std::function<void(std::any )> f, std::any any) {
    f(any);
}
