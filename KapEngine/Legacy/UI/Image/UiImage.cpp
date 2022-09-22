/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Image
*/

#include "Transform.hpp"
#include "UiImage.hpp"
#include "UiCanvas.hpp"

KapEngine::UI::Image::Image(std::shared_ptr<GameObject> &go) : Component(go, "Image")
{
}

KapEngine::UI::Image::~Image()
{
}

void KapEngine::UI::Image::onDisplay() {
    getGameObject().getEngine().getCurrentGraphicalLib()->drawImage(*this);
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedPosition() const {
    Transform &transform = (Transform &)getGameObjectConst().getComponent("Transform");

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::resizyngType resizeType = Canvas::resizyngType::PIXEL_CONSTANT;
    Tools::Vector2 getCompare = getGameObjectConst().getEngine().getScreenSize();
    try {
        std::shared_ptr<GameObject> canvasObject = getGameObjectConst().getScene().getObject(transform.getParentContainsComponent("Canvas"));

        Canvas &canvas = (Canvas &)canvasObject->getComponent("Canvas");
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {}

    if (resizeType == Canvas::PIXEL_CONSTANT) {

    } else {
        return Tools::Vector2(currPos.getX(), currPos.getY());
    }
    Tools::Vector2 result(currPos.getX(), currPos.getY());
    return result;
}

KapEngine::Tools::Vector2 KapEngine::UI::Image::getCalculatedScale() const {
    Tools::Vector2 result;

    return result;
}

bool KapEngine::UI::Image::checkComponentValidity() {
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        return tr.parentContainsComponent("Canvas", true);
    } catch(...) {
        return false;
    }
}
