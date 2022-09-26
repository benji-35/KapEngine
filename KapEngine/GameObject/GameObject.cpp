/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GameObject
*/

#include "GameObject.hpp"
#include "Errors.hpp"
#include "Debug.hpp"
#include "Transform.hpp"

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

void KapEngine::GameObject::__update() {
    if (!_active || _destroyed)
        return;
    try {
        Transform &tr = (Transform &)getTransform();
        if (!tr.allParentIsActive())
            return;
    } catch (...) {}
    for (std::size_t i = 0; i < _components.size(); i++) {
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive())
                return;
        } catch (...) {}
        _components[i]->__update();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive())
                return;
        } catch (...) {}
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

bool KapEngine::GameObject::hasComponent(std::string const& componentName) const {
    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getName() == componentName)
            return true;
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        if (_componentsRun[i]->getName() == componentName)
            return true;
    }
    return false;
}

void KapEngine::GameObject::__destroyIt() {
    _destroyed = true;
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onDestroy();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onDestroy();
        _componentsRun[i].reset();
    }
    _componentsRun.clear();
}

void KapEngine::GameObject::__init() {
    _destroyed = false;
    _active = _startActive;
    _componentsRun.clear();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__awake();
    }
}

void KapEngine::GameObject::setActive(bool b) {
    if (getEngine().isRunning()) {
        if (!b && _active) {
            for (std::size_t i = 0; i < _components.size(); i++) {
                _components[i]->onDisable();
            }
            for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                _componentsRun[i]->onDisable();
            }
        } else if (b && !_active) {
            for (std::size_t i = 0; i < _components.size(); i++) {
                _components[i]->onEnable();
            }
            for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                _componentsRun[i]->onEnable();
            }
        }
        _active = b;
    } else {
        _startActive = b;
    }
}

void KapEngine::GameObject::__stoppingGame() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onGameQuit();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onGameQuit();
    }
}

void KapEngine::GameObject::dump(int tab) {
    Debug::log("-GameObject: " + getName());
    std::string prefix = "";
    for (std::size_t i = 0; i < tab; i++) {
        prefix += "  ";
    }
    for (std::size_t i = 0; i < _components.size(); i++) {
        Debug::log(prefix + ": " + _components[i]->getName());
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        Debug::log(prefix + ": " + _componentsRun[i]->getName());
    }
}
