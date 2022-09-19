/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GameObject
*/

#include "GameObject.hpp"
#include "Errors.hpp"

KapEngine::GameObject::GameObject(SceneManagement::Scene &scene, std::string const& name) : _scene(scene) {
    _name = name;
}

KapEngine::GameObject::~GameObject() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i].reset();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i].reset();
    }
}

bool KapEngine::GameObject::allParentsActive() const {
    if (_parentId == 0)
        return _active;
    return getParent()->allParentsActive();
}

std::shared_ptr<KapEngine::GameObject> KapEngine::GameObject::getParent() const {
    if (_parentId == 0)
        throw Errors::GameObjectError("[GAMEOBJECT] No parent assigned to GameObject " + _name);
    try {
        return _scene.getObject(_parentId);
    } catch(Errors::SceneError e) {
        throw Errors::GameObjectError(std::string(e.what()));
    } catch(...) {
        throw Errors::GameObjectError("[GAMEOBJECT] unknown error to getParent");
    }
}

void KapEngine::GameObject::__update(int threadId) {
    if (!_active || _destroyed)
        return;
    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getThreadRunning() == threadId)
            _components[i]->__update();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        if (_componentsRun[i]->getThreadRunning() == threadId)
            _componentsRun[i]->__update();
    }
}

KapEngine::Component &KapEngine::GameObject::getComponent(std::string const& name) {
    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getName() == name)
            return *_components[i];
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        if (_componentsRun[i]->getName() == name)
            return *_componentsRun[i];
    }
    throw Errors::GameObjectError("No component named \"" + name + "\" found");
}

KapEngine::Component &KapEngine::GameObject::getTransform() {
    try {
        return getComponent("Transform");
    } catch(...) {
        throw Errors::GameObjectError("GameObject " + _name + " does not contain transform component");
    }
}

KapEngine::KapEngine &KapEngine::GameObject::getEngine() {
    return _scene.getEngine();
}

void KapEngine::GameObject::addComponent(std::shared_ptr<Component> comp) {
    _idComp++;
    comp->__setId(_idComp);
    if (getEngine().isRunning()) {
        _componentsRun.push_back(comp);
    } else {
        _components.push_back(comp);
    }
}

void KapEngine::GameObject::__engineStop() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__engineStop();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->__engineStop();
    }
}
