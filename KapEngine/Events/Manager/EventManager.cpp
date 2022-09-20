/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventManager
*/

#include "EventManager.hpp"

KapEngine::Events::EventManager::EventManager(KapEngine &engine) : _engine(engine)
{
    _input = std::make_shared<Input>(*this);
    _mouse = std::make_shared<Mouse>(*this);
}
