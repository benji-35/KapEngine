/*
** EPITECH PROJECT, 2022
** engine
** File description:
** MouseDetector
*/

#include "MouseDetector.hpp"

#include "KapEngineUi.hpp"

KapEngine::MouseDetector::MouseDetector(std::shared_ptr<GameObject> go) : Component(go, "Mouse Detector") {
    PROFILER_FUNC_START();
    __setPhysics(true);
    PROFILER_FUNC_END();
}

KapEngine::MouseDetector::~MouseDetector() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::MouseDetector::onUpdate() {
    PROFILER_FUNC_START();
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
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("[MOUSE DETECTOR] failed to get transform");
            #endif
        }

    }

    Tools::Vector2 pos = getMouse().getPosition();

    bool detected = false;

    if (_inCanvas) {
        detected = __checkCanvas(pos);
    } else {
        detected = __checkNoCanvas(pos);
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
    PROFILER_FUNC_END();
}

void KapEngine::MouseDetector::__callMouses(HoverType const& _type) {
    PROFILER_FUNC_START();
    auto _components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->isEnable()) {
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
    PROFILER_FUNC_END();
}

bool KapEngine::MouseDetector::__checkNoCanvas(Tools::Vector2 const& posMouse) {
    PROFILER_FUNC_START();
    float pX = _square.getX();
    float pMaxX = _square.getX() + _square.getWidth();

    float pY = _square.getY();
    float pMaxY = _square.getY() + _square.getHeigth();

    if (posMouse.getX() >= pX && posMouse.getX() <= pMaxX) {
        if (posMouse.getY() >= pY && posMouse.getY() <= pMaxY) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

bool KapEngine::MouseDetector::__checkCanvas(Tools::Vector2 const& posMouse) {
    PROFILER_FUNC_START();
    bool _resized = false;

    try {
        auto canvasId = getTransform().getParentContainsComponent("Canvas");

        if (canvasId == 0) {
            PROFILER_FUNC_END();
            return __checkNoCanvas(posMouse);
        }

        auto &canvas = getScene().getGameObject(canvasId)->getComponent<UI::Canvas>();
        if (canvas.getResizeType() == UI::Canvas::RESIZE_WITH_SCREEN)
            _resized = true;
    } catch(...) {}

    if (!_resized) {
        PROFILER_FUNC_END();
        return __checkNoCanvas(posMouse);
    }
    
    Tools::Vector2 pos = _square.getPos();
    Tools::Vector2 posMax = pos + _square.getSize();

    pos = crossProductScreen(pos);
    posMax = crossProductScreen(posMax);
    if (posMouse.getX() >= pos.getX() && posMouse.getX() <= posMax.getX()) {
        if (posMouse.getY() >= pos.getY() && posMouse.getY() <= posMax.getY()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

KapEngine::Tools::Vector2 KapEngine::MouseDetector::crossProductScreen(Tools::Vector2 value) {
    PROFILER_FUNC_START();
    Tools::Vector2 baseScreenSize = getEngine().getScreenSize();
    try {
        auto canvasId = getTransform().getParentContainsComponent("Canvas");
        if (canvasId == 0) {
            PROFILER_FUNC_END();
            return value;
        }

        auto &canvas = getScene().getGameObject(canvasId)->getComponent<UI::Canvas>();
        baseScreenSize = canvas.getScreenSizeCompare();
    } catch(...) { 
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to get canvas parent");
        #endif
    }
    Tools::Vector2 currentScreenSize = getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();

    Tools::Vector2 result = value;

    result.setX((currentScreenSize.getX() * result.getX()) / baseScreenSize.getX());
    result.setY((currentScreenSize.getY() * result.getY()) / baseScreenSize.getY());

    PROFILER_FUNC_END();
    return result;
}
