/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Text
*/

#include "KapEngine.hpp"
#include "KapEngineUi.hpp"

KapEngine::UI::Text::Text(std::shared_ptr<GameObject> &go, std::string const& textContent) : Component(go, "Text")
{
    PROFILER_FUNC_START();
    setText(textContent);
    PROFILER_FUNC_END();
}

KapEngine::UI::Text::~Text()
{
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::UI::Text::onAwake()
{
    PROFILER_FUNC_START();
    _lastScale = getTransform().getWorldScale();
    _lastPos = getTransform().getWorldPosition();
    _lastScaleWant = getTransform().getWorldScale();
    _lastPosWant = getTransform().getWorldPosition();
    try {
        std::shared_ptr<GameObject> canvasObject = getScene().getGameObject(getTransform().getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        _lastCompare = canvas.getScreenSizeCompare();
    } catch(...) {}
    PROFILER_FUNC_END();
}

void KapEngine::UI::Text::onDisplay() {
    PROFILER_FUNC_START();
    try {
        getEngine().getCurrentGraphicalLib()->drawText(*this);
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to draw text");
        #endif
    }
    PROFILER_FUNC_END();
}

bool KapEngine::UI::Text::checkComponentValidity() {
    PROFILER_FUNC_START();
    try {
        Transform &tr = (Transform &)getGameObject().getTransform();
        auto val = tr.parentContainsComponent("Canvas", true);
        if (!val) {
            if (getGameObject().hasComponent<Canvas>())
                val = true;
        }
        PROFILER_FUNC_END();
        return val;
    } catch(...) {
        PROFILER_FUNC_END();
        return false;
    }
}

KapEngine::Tools::Vector2 KapEngine::UI::Text::getCalculatedScale() {
    PROFILER_FUNC_START();
    auto &transform = getGameObject().getComponent<Transform>();

    Tools::Vector3 currScale = transform.getWorldScale();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    if (_lastCompare == getCompare && _lastScaleWant == Tools::Vector2(currScale.getX(), currScale.getY())) {
        PROFILER_FUNC_START();
        return _lastScale;
    }

    _lastScaleWant = Tools::Vector2(currScale.getX(), currScale.getY());

    try {
        std::shared_ptr<GameObject> canvasObject = getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

        auto &canvas = canvasObject->getComponent<Canvas>();
        resizeType = canvas.getResizeType();
        getCompare = canvas.getScreenSizeCompare();
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Failed to get canvas intels for positions");
        #endif
    }

    _lastCompare = getCompare;
    if (resizeType == Canvas::ResizyngType::RESIZE_WITH_SCREEN) {
        Tools::Vector2 nSize;
        nSize.setX(screenSize.getX() * currScale.getX() / getCompare.getX());
        nSize.setY(screenSize.getY() * currScale.getY() / getCompare.getY());
        _lastScale = nSize;
        PROFILER_FUNC_END();
        return nSize;
    }
    _lastScale = currScale;
    PROFILER_FUNC_END();
    return Tools::Vector2(currScale.getX(), currScale.getY());
}

KapEngine::Tools::Vector2 KapEngine::UI::Text::getCalculatedPos() {
    PROFILER_FUNC_START();
    auto &transform = getGameObject().getComponent<Transform>();

    Tools::Vector3 currPos = transform.getWorldPosition();
    Canvas::ResizyngType resizeType = Canvas::ResizyngType::RESIZE_WITH_SCREEN;
    Tools::Vector2 getCompare = getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 screenSize = getCompare;

    if (_lastCompare == getCompare && _lastPosWant == Tools::Vector2(currPos.getX(), currPos.getY())) {
        PROFILER_FUNC_END();
        return _lastPos;
    }

    _lastPosWant = Tools::Vector2(currPos.getX(), currPos.getY());

    try {
        std::shared_ptr<GameObject> canvasObject = getScene().getGameObject(transform.getParentContainsComponent("Canvas"));

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
        PROFILER_FUNC_END();
        return nPos;
    }
    _lastPos = currPos;
    PROFILER_FUNC_END();
    return Tools::Vector2(currPos.getX(), currPos.getY());
}
