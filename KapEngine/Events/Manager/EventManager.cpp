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
    _input = std::make_shared<Input>(*this);
    _mouse = std::make_shared<Mouse>(*this);
}

void KapEngine::Events::EventManager::__update() {
    _input->__update();
    _mouse->__update();
}
