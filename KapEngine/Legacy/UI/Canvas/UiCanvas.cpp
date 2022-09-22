/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Canvas
*/

#include "UiCanvas.hpp"
#include "Transform.hpp"

KapEngine::UI::Canvas::Canvas(std::shared_ptr<GameObject> &go) : Component(go, "Canvas") {
    _screenSizeCompare = Tools::Vector2(720, 480);
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
