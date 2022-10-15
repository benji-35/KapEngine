/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Text
*/

#include "UiText.hpp"
#include "Transform.hpp"
#include "UiCanvas.hpp"
#include "KapEngineDebug.hpp"

KapEngine::UI::Text::Text(std::shared_ptr<GameObject> &go, std::string const& textContent) : Component(go, "Text")
{
    setText(textContent);
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
        auto val = tr.parentContainsComponent("Canvas", true);
        if (!val) {
            if (getGameObject().hasComponent<Canvas>())
                val = true;
        }
        return val;
    } catch(...) {
        return false;
    }
}

KapEngine::Tools::Vector2 KapEngine::UI::Text::getCalculatedScale() {
    auto &transform = getGameObjectConst().getComponent<Transform>();

    Tools::Vector3 currScale = transform.getWorldScale();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObject().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;
    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {
        DEBUG_WARNING("Failed to get canvas intels for positions");
    }

    if (resizeType == Canvas::ResizyngType::RESIZE_WITH_SCREEN) {
        Tools::Vector2 nPos;
        nPos.setX(screenSize.getX() * currScale.getX() / getCompare.getX());
        nPos.setY(screenSize.getY() * currScale.getY() / getCompare.getY());
        return nPos;
    }
    return Tools::Vector2(currScale.getX(), currScale.getY());
}

KapEngine::Tools::Vector2 KapEngine::UI::Text::getCalculatedPos() {
    auto &transform = getGameObjectConst().getComponent<Transform>();

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObject().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;
    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {
        DEBUG_WARNING("Failed to get canvas intels for positions");
    }

    if (resizeType == Canvas::ResizyngType::RESIZE_WITH_SCREEN) {
        Tools::Vector2 nPos;
        nPos.setX(screenSize.getX() * currPos.getX() / getCompare.getX());
        nPos.setY(screenSize.getY() * currPos.getY() / getCompare.getY());
        return nPos;
    }
    return Tools::Vector2(currPos.getX(), currPos.getY());
}
