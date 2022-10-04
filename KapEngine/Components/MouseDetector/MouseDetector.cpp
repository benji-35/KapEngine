/*
** EPITECH PROJECT, 2022
** engine
** File description:
** MouseDetector
*/

#include "MouseDetector.hpp"

KapEngine::MouseDetector::MouseDetector(std::shared_ptr<GameObject> go) : Component(go, "Mouse Detector", 1) {}

KapEngine::MouseDetector::~MouseDetector() {}

void KapEngine::MouseDetector::onUpdate() {
    
    if (!_setted) {

        try {

            auto &tr = (Transform &)getGameObject().getTransform();

            Tools::Rectangle rect;
            Tools::Vector3 pos = tr.getWorldPosition();
            Tools::Vector3 scale = tr.getWorldScale();

            rect.setPos(Tools::Vector2(pos.getX(), pos.getY()));
            rect.setSize(Tools::Vector2(scale.getX(), scale.getY()));

            _square = rect;

        } catch(...) {
            DEBUG_ERROR("[MOUSE DETECTOR] failed to get transform");
        }

    }
    
    
    Tools::Vector2 pos = getMouse().getPosition();

    float pX = _square.getX();
    float pMaxX = _square.getX() + _square.getWidth();

    float pY = _square.getY();
    float pMaxY = _square.getY() + _square.getHeigth();

    bool detected = false;

    if (pos.getX() >= pX && pos.getX() <= pMaxX) {
        if (pos.getY() >= pY && pos.getY() <= pMaxY) {
            detected = true;
        }
    }

    HoverType type = HoverType::NONE;

    if (detected) {
        if (_inSquare) {
            type = HoverType::STAY_HOVER;
        } else {
            type = HoverType::JUSTE_HOVER;
        }
        _inSquare = true;
    } else {
        if (_inSquare)
            type = HoverType::LEAVE_HOVER;
        _inSquare = false;
    }
    __callMouses(type);
}

void KapEngine::MouseDetector::__callMouses(HoverType const& _type) {
    auto _components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < _components.size(); i++) {
        switch (_type) {
            case HoverType::JUSTE_HOVER :
                _components[i]->onMouseEnter();
                break;
            case HoverType::STAY_HOVER :
                _components[i]->onMouseStay();
                break;
            case HoverType::LEAVE_HOVER :
                _components[i]->onMouseExit();
                break;
            default:
                break;
        }
    }
}
