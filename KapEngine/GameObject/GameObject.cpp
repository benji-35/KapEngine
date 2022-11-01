/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GameObject
*/

// #include "GameObject.hpp"
// #include "Errors.hpp"
// #include "KapEngineDebug.hpp"
// #include "Transform.hpp"

#include "KapEngine.hpp"

KapEngine::GameObject::GameObject(SceneManagement::Scene &scene, std::string const& name) : _scene(scene) {
    _name = name;
    _prefabName = "";
}

KapEngine::GameObject::~GameObject() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i].reset();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i].reset();
    }
}

void KapEngine::GameObject::__update(bool physics, bool runDisplay) {
    if (!_active || _destroyed)
        return;
    std::vector<std::shared_ptr<GameObject>> _children;
    try {
        Transform &tr = (Transform &)getTransform();
        if (!tr.allParentIsActive())
            return;
        _children = tr.getChildren();
    } catch (...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("GameObject has no Transform component for GameObject" + _name);
        #endif
    }
    try {
        for (std::size_t i = 0; i < _components.size(); i++) {
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive())
                    return;
            } catch (...) {}
            if (physics && _components[i]->__isPhysics()) {
                _components[i]->__update(runDisplay);
            } else if (!physics && !_components[i]->__isPhysics()) {
                _components[i]->__update(runDisplay);
            }
        }
    } catch (...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update components for GameObject" + _name);
        #endif
    }
    try {
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive())
                return;
        } catch (...) {}
        if (physics && _componentsRun[i]->__isPhysics()) {
            _componentsRun[i]->__update(runDisplay);
        } else if (!physics && !_componentsRun[i]->__isPhysics()) {
            _componentsRun[i]->__update(runDisplay);
        }
    }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update components run for GameObject" + _name);
        #endif
    }
    if (_active == false || _destroyed)
        return;
    try {
        for (std::size_t i = 0; i < _children.size(); i++) {
            _children[i]->__update(physics, runDisplay);
        }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update children for GameObject" + _name);
        #endif
    }
}

void KapEngine::GameObject::__updateDisplay() {
    if (!_active || _destroyed)
        return;
    std::vector<std::shared_ptr<GameObject>> _children;
    try {
        Transform &tr = (Transform &)getTransform();
        if (!tr.allParentIsActive())
            return;
        _children = tr.getChildren();
    } catch (...) {}
    try {
        for (std::size_t i = 0; i < _components.size(); i++) {
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive())
                    return;
            } catch (...) {}
            _components[i]->onDisplay();
        }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update display components for GameObject" + _name);
        #endif
    }
    try {
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive())
                return;
        } catch (...) {}
        _componentsRun[i]->onDisplay();
    }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update display components run for GameObject" + _name);
        #endif
    }
    if (_active == false || _destroyed)
        return;
    try {
    for (std::size_t i = 0; i < _children.size(); i++) {
        _children[i]->__updateDisplay();
    }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failed to update display children for GameObject" + _name);
        #endif
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
        return getComponent<Transform>();
    } catch(...) {
        throw Errors::GameObjectError("GameObject " + _name + " does not contain transform component");
    }
}

KapEngine::KEngine &KapEngine::GameObject::getEngine() {
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

void KapEngine::GameObject::dump(bool displayComponent, std::string prefix) {

    std::string color = Debug::colorWhite();    
    if (!isActive() || !getComponent<Transform>().allParentsActive()) {
        color = Debug::colorCyan();
    }

    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG(color + prefix + "-GameObject: " + getName() + Debug::colorNone());
    #endif
    if (displayComponent) {
        for (std::size_t i = 0; i < _components.size(); i++) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG(color + prefix + ": " + _components[i]->getName() + Debug::colorNone());
            #endif
        }
        for (std::size_t i = 0; i < _componentsRun.size(); i++) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_LOG(color + prefix + ": " + _componentsRun[i]->getName() + Debug::colorNone());
            #endif
        }
    }
    auto children = getComponent<Transform>().getChildren();
    prefix = prefix + "   ";
    for (std::size_t i = 0; i < children.size(); i++) {
        children[i]->dump(displayComponent, prefix);
    }
}

std::vector<std::shared_ptr<KapEngine::Component>> KapEngine::GameObject::getAllComponents() const {
    std::vector<std::shared_ptr<Component>> result;

    for (std::size_t i = 0; i < _components.size(); i++)
        result.push_back(_components[i]);
    for (std::size_t i = 0; i < _componentsRun.size(); i++)
        result.push_back(_componentsRun[i]);

    return result;
}

void KapEngine::GameObject::destroy() {
    getScene().destroyGameObject(getId());
}

void KapEngine::GameObject::__setPrefab(std::string const& name) {
    _prefabName = name;
}

void KapEngine::GameObject::__onSceneUpdated() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onSceneUpdated();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onSceneUpdated();
    }
    auto children = getComponent<Transform>().getChildren();
    for (std::size_t i = 0; i < children.size(); i++) {
        children[i]->__onSceneUpdated();
    }
}


void KapEngine::GameObject::__onSceneGonnaUpdated() {
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onSceneGonnaUpdated();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onSceneGonnaUpdated();
    }
    auto children = getComponent<Transform>().getChildren();
    for (std::size_t i = 0; i < children.size(); i++) {
        children[i]->__onSceneGonnaUpdated();
    }
}
