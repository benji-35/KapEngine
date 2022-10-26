/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

#include "Component.hpp"
#include "Errors.hpp"
#include "Transform.hpp"

#include "KapEngineDebug.hpp"

KapEngine::Component::Component(std::shared_ptr<GameObject> &go, std::string const& name, int threadId) {
    _go = go;
    _name = name;
    threadRunning = threadId;
}

KapEngine::Component::~Component() {
    _go.reset();
}

KapEngine::GameObject &KapEngine::Component::getGameObject() {
    try {
        if (_go.use_count() <= 1)
            throw Errors::SceneError("GameObject does not exist in scene");
        return *_go;
    } catch (Errors::SceneError e) {
        throw Errors::ComponentError(std::string(e.what()));
    }
}

void KapEngine::Component::__update(bool runDisplay) {
    try {
        __awake();
        if (!__checkValidity())
            return;
        __start();
        if (!__checkValidity())
            return;
        onUpdate();
        if (!__checkValidity())
            return;
        __fixedUpdate();
        if (!__checkValidity())
            return;
        if (runDisplay)
            onDisplay();
    } catch(...) {
        return;
    }
}

void KapEngine::Component::__awake() {
    if (_awakeDone || getGameObject().isDestroyed())
        return;
    _awakeDone = true;
    onAwake();
}

void KapEngine::Component::__start() {
    if (_startDone)
        return;
    _startDone = true;
    onStart();
}

void KapEngine::Component::__fixedUpdate() {
    if (getGameObjectConst().getEngine().__canRunFixed())
        onFixedUpdate();
}

KapEngine::Events::Input KapEngine::Component::getInput() {
    return getGameObject().getEngine().getEventManager().getInput();
}

KapEngine::Events::Mouse KapEngine::Component::getMouse() {
    return getGameObject().getEngine().getEventManager().getMouse();
}

KapEngine::GameObject &KapEngine::Component::getGameObjectConst() const {
    return *_go->getSceneConst().getGameObjectConst(_go->getId());
}

bool KapEngine::Component::__checkValidity() {
    if (!_enable)
        return false;
    if (!getGameObject().isActive() || getGameObject().isDestroyed()) {
        DEBUG_WARNING("Component " + getName() + " is disable or destroy");
        return false;
    }
    if (!getTransform().allParentsActive())
        return false;
    if (!checkComponentValidity()) {
        DEBUG_WARNING("Component " + getName() + " is disable by the creator");
        return false;
    }
    for (std::size_t i = 0; i < _componentsNeeded.size(); i++) {
        if (!getGameObject().hasComponent(_componentsNeeded[i]))
            return false;
    }

    return true;
}

KapEngine::Transform &KapEngine::Component::getTransform() {
    return getGameObject().getComponent<Transform>();
}
