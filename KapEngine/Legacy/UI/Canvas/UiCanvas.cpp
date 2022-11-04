/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Canvas
*/

#include "UiCanvas.hpp"
#include "KapEngine.hpp"

KapEngine::UI::Canvas::Canvas(std::shared_ptr<GameObject> &go) : Component(go, "Canvas") {
    PROFILER_FUNC_START();
    _screenSizeCompare = go->getEngine().getScreenSize();
    PROFILER_FUNC_END();
}

KapEngine::UI::Canvas::~Canvas() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

bool KapEngine::UI::Canvas::checkComponentValidity() {
    PROFILER_FUNC_START();
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        PROFILER_FUNC_END();
        return !(tr.parentContainsComponent("Canvas", true));
    } catch(...) {
        PROFILER_FUNC_END();
        return false;
    }
}
