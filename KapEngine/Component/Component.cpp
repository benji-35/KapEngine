/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

#include "Component.hpp"
#include "Errors.hpp"
#include "Transform.hpp"
#include "Debug.hpp"

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
        return *_go->getScene().getObject(_go->getId());
    } catch (Errors::SceneError e) {
        throw Errors::ComponentError(std::string(e.what()));
    }
}

void KapEngine::Component::__update() {
    try {
        if (!__checkValidity())
            return;
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
        onDisplay();
    } catch(...) {
        return;
    }
}

void KapEngine::Component::__awake() {
    if (_awakeDone)
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
    return *_go->getSceneConst().getObjectConst(_go->getId());
}

bool KapEngine::Component::__checkValidity() {
    if (!getGameObject().isActive() || getGameObject().isDestroyed()) {
        Debug::warning("Component " + getName() + " is disable or destroy");
        return false;
    }
    if (!checkComponentValidity()) {
        Debug::warning("Component " + getName() + " is disable by the creator");
        return false;
    }
    for (std::size_t i = 0; i < _componentsNeeded.size(); i++) {
        if (!getGameObject().hasComponent(_componentsNeeded[i]))
            return false;
    }

    return true;
}
