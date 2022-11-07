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
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

KapEngine::Events::Mouse::~Mouse()
{
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Events::Mouse::__update() {
    PROFILER_FUNC_START();
    if (!manager.getEngine().isGraphicalLibExists(manager.getEngine().getCurrentGraphicalLibIndex())) {
        PROFILER_FUNC_END();
        return;
    }
    Tools::Vector2 nPos = manager.getEngine().getCurrentGraphicalLib()->getMousePosition();

    if (_mousePos != nPos) {
        _mouseMoved = true;
        _mousePos = nPos;
    }
    PROFILER_FUNC_END();
}
