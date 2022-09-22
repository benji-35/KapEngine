/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventManager
*/

#include "EventManager.hpp"
#include "Debug.hpp"

KapEngine::Events::EventManager::EventManager(KapEngine &engine) : _engine(engine)
{
    _input = std::make_shared<Input>(*this);
    _mouse = std::make_shared<Mouse>(*this);
}

void KapEngine::Events::EventManager::__update() {
    if (_engine.debugMod()) {
        Debug::warning("Update inputs");
    }
    _input->__update();
    _mouse->__update();
}
