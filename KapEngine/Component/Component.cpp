/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

#include "Component.hpp"
#include "Errors.hpp"

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
        if (!getGameObject().isActive() || getGameObject().isDestroyed())
            return;
        __awake();
        if (!getGameObject().isActive() || getGameObject().isDestroyed())
            return;
        __start();
        if (!getGameObject().isActive() || getGameObject().isDestroyed())
            return;
        onUpdate();
        if (!getGameObject().isActive() || getGameObject().isDestroyed())
            return;
        __fixedUpdate();
        if (!getGameObject().isActive() || getGameObject().isDestroyed())
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
