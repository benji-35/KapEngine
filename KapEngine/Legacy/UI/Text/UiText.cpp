/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Text
*/

#include "UiText.hpp"
#include "Transform.hpp"

KapEngine::UI::Text::Text(std::shared_ptr<GameObject> &go) : Component(go, "Text")
{
}

KapEngine::UI::Text::~Text()
{
}

void KapEngine::UI::Text::onDisplay() {
    getGameObject().getEngine().getCurrentGraphicalLib()->drawText(*this);
}

bool KapEngine::UI::Text::checkComponentValidity() {
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        return tr.parentContainsComponent("Canvas", true);
    } catch(...) {
        return false;
    }
}
