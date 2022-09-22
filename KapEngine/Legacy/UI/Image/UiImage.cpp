/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Image
*/

#include "Transform.hpp"
#include "UiImage.hpp"
#include "UiCanvas.hpp"
#include "Debug.hpp"

KapEngine::UI::Image::Image(std::shared_ptr<GameObject> &go) : Component(go, "Image") {}

KapEngine::UI::Image::~Image() {}

void KapEngine::UI::Image::onDisplay() {
    getGameObject().getEngine().getCurrentGraphicalLib()->drawImage(*this);
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedPosition() {
    Transform &transform = (Transform &)getGameObjectConst().getComponent("Transform");

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::resizyngType resizeType = Canvas::resizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObjectConst().getEngine().getScreenSize();
    Tools::Vector2 screenSize = getCompare;
    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getObject(transform.getParentContainsComponent("Canvas"));

        Canvas &canvas = (Canvas &)canvasObject->getComponent("Canvas");
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {}

    if (resizeType == Canvas::resizyngType::RESIZE_WITH_SCREEN) {
        Tools::Vector2 nPos;
        nPos.setX(screenSize.getX() * currPos.getX() / getCompare.getX());
        nPos.setY(screenSize.getY() * currPos.getY() / getCompare.getY());
        return nPos;
    }
    return Tools::Vector2(currPos.getX(), currPos.getY());;
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedScale() {
    Transform &transform = (Transform &)getGameObjectConst().getComponent("Transform");

    Tools::Vector3 currSize = transform.getWorldScale();
    Canvas::resizyngType resizeType = Canvas::resizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getGameObjectConst().getEngine().getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    try {

        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getObject(transform.getParentContainsComponent("Canvas"));

        Canvas &canvas = (Canvas &)canvasObject->getComponent("Canvas");
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();

    } catch(...) {}

    if (resizeType == Canvas::resizyngType::RESIZE_WITH_SCREEN) {

        Tools::Vector2 nSize;
        nSize.setX(screenSize.getX() * currSize.getX() / getCompare.getX());
        nSize.setY(screenSize.getY() * currSize.getY() / getCompare.getY());
        return nSize;

    }
    return Tools::Vector2(currSize.getX(), currSize.getY());
}

bool KapEngine::UI::Image::checkComponentValidity() {
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        auto res = tr.parentContainsComponent("Canvas", true);
        
        if (res == false) {
            Debug::warning("Cannot use Image because no canvas found!");
        } else {
            Debug::log("Canvas found");
        }
        
        return res;
    } catch(...) {
        return false;
    }
}
