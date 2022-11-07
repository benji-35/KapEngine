/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventManager
*/

#include "KapEngine.hpp"
#include "KapEngineEvents.hpp"

KapEngine::Events::EventManager::EventManager(KEngine &engine) : _engine(engine)
{
    PROFILER_FUNC_START();
    _input = std::make_shared<Input>(*this);
    _mouse = std::make_shared<Mouse>(*this);
    PROFILER_FUNC_END();
}

void KapEngine::Events::EventManager::__update() {
    PROFILER_FUNC_START();
    _input->__update();
    _mouse->__update();
    PROFILER_FUNC_END();
}
