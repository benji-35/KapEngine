/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Image
*/

#include "Transform.hpp"
#include "UiImage.hpp"
#include "UiCanvas.hpp"
#include "KapEngineDebug.hpp"
#include "GraphicalLib.hpp"

KapEngine::UI::Image::Image(std::shared_ptr<GameObject> &go) : Component(go, "Image") {}

KapEngine::UI::Image::~Image() {}

void KapEngine::UI::Image::onAwake() {
    _lastScale = getTransform().getWorldScale();
    _lastPos = getTransform().getWorldPosition();
    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(getTransform().getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        _lastCompare = canvas.getScreenSizeCompare();
    } catch(...) {}
}

void KapEngine::UI::Image::onDisplay() {
    getGameObject().getEngine().getCurrentGraphicalLib()->drawImage(*this);
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedPosition() {
    auto &transform = getGameObjectConst().getComponent<Transform>();

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObject().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    if (_lastCompare == getCompare) {
        return _lastPos;
    }

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
        _lastPos = nPos;
        return nPos;
    }
    _lastPos = currPos;
    return Tools::Vector2(currPos.getX(), currPos.getY());
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedScale() {
    auto &transform = getGameObjectConst().getComponent<Transform>();

    Tools::Vector3 currSize = transform.getWorldScale();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObject().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    if (_lastCompare == getCompare) {
        return _lastScale;
    }

    try {

        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();

    } catch(...) {
        DEBUG_WARNING("Failed to get canvas intels for scale");
    }

    _lastCompare = getCompare;
    if (resizeType == Canvas::ResizyngType::RESIZE_WITH_SCREEN) {

        Tools::Vector2 nSize;
        nSize.setX(screenSize.getX() * currSize.getX() / getCompare.getX());
        nSize.setY(screenSize.getY() * currSize.getY() / getCompare.getY());
        _lastScale = nSize;
        return nSize;

    }
    _lastScale = currSize;
    return Tools::Vector2(currSize.getX(), currSize.getY());
}

bool KapEngine::UI::Image::checkComponentValidity() {
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        auto res = tr.parentContainsComponent("Canvas", true);
        
        if (res == false) {
            if (getGameObject().hasComponent<Canvas>())
                return true;
            DEBUG_WARNING("Cannot use Image because no canvas found!");
        }
        
        return res;
    } catch(...) {
        return false;
    }
}
