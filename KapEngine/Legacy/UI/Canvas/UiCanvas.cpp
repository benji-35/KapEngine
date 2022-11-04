/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Canvas
*/

#include "UiCanvas.hpp"
#include "KapEngine.hpp"

KapEngine::UI::Canvas::Canvas(std::shared_ptr<GameObject> &go) : Component(go, "Canvas") {
    _screenSizeCompare = go->getEngine().getScreenSize();
}

KapEngine::UI::Canvas::~Canvas() {}

bool KapEngine::UI::Canvas::checkComponentValidity() {
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        return !(tr.parentContainsComponent("Canvas", true));
    } catch(...) {
        return false;
    }
}
