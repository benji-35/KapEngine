/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Image
*/

#include "KapEngine.hpp"
#include "KapEngineUi.hpp"
#include "KapEngineGraphical.hpp"

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
    try {
        getGameObject().getEngine().getCurrentGraphicalLib()->drawImage(*this);
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to draw image");
        #endif
    }
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedPosition() {
    auto &transform = getGameObjectConst().getComponent<Transform>();

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObject().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    if (_lastCompare == getCompare && _lastPosWant == Tools::Vector2(currPos.getX(), currPos.getY())) {
        return _lastPos;
    }

    _lastPosWant = Tools::Vector2(currPos.getX(), currPos.getY());

    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Failed to get canvas intels for positions");
        #endif
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

    if (_lastCompare == getCompare && _lastScaleWant == Tools::Vector2(currSize.getX(), currSize.getY())) {
        return _lastScale;
    }

    _lastScaleWant = Tools::Vector2(currSize.getX(), currSize.getY());

    try {

        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();

    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Failed to get canvas intels for scale");
        #endif
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
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_WARNING("Cannot use Image because no canvas found!");
            #endif
        }
        
        return res;
    } catch(...) {
        return false;
    }
}
