/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Mouse
*/

#include "KapEngine.hpp"
#include "KapEngineEvents.hpp"

KapEngine::Events::Mouse::Mouse(EventManager &manager) : manager(manager)
{
}

KapEngine::Events::Mouse::~Mouse()
{
}

void KapEngine::Events::Mouse::__update() {
    if (!manager.getEngine().isGraphicalLibExists(manager.getEngine().getCurrentGraphicalLibIndex()))
        return;
    Tools::Vector2 nPos = manager.getEngine().getCurrentGraphicalLib()->getMousePosition();

    if (_mousePos != nPos) {
        _mouseMoved = true;
        _mousePos = nPos;
    }
}
