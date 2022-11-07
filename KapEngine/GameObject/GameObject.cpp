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
    PROFILER_FUNC_START();
    _name = name;
    _prefabName = "";
    PROFILER_FUNC_END();
}

KapEngine::GameObject::~GameObject() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i].reset();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i].reset();
    }
    PROFILER_FUNC_END();
}


#if KAPENGINE_BETA_ACTIVE
    #if KAPENGINE_THREAD_ACTIVE

        void KapEngine::GameObject::__updatePhysics() {
            PROFILER_FUNC_START();
            //check if gameObject is destroy or disable
            if (!_active || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }

            //set all children
            std::vector<std::shared_ptr<GameObject>> _children;
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
                _children = tr.getChildren();
            } catch (...) {
                DEBUG_ERROR("Failed to get children of gameObject " + _name);
            }

            //update components
            for (std::size_t i = 0; i < _components.size(); i++) {
                if (_components[i]->isEnable() && _components[i]->__isPhysics()) {
                    _components[i]->__update();
                }
            }
            for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                if (_componentsRun[i]->isEnable() && _componentsRun[i]->__isPhysics()) {
                    _componentsRun[i]->__update();
                }
            }

            //call children updates
            for (std::size_t i = 0; i < _children.size(); i++) {
                _children[i]->__updatePhysics();
            }
            PROFILER_FUNC_END();
        }

        void KapEngine::GameObject::__updateComponents() {
            PROFILER_FUNC_START();
            //check if gameObject is destroy or disable
            if (!_active || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }

            //set all children
            std::vector<std::shared_ptr<GameObject>> _children;
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
                _children = tr.getChildren();
            } catch (...) {
                DEBUG_ERROR("Failed to get children of gameObject " + _name);
            }

            //update components
            for (std::size_t i = 0; i < _components.size(); i++) {
                if (_components[i]->isEnable() && !_components[i]->__isPhysics()) {
                    _components[i]->__update();
                }
            }
            for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                if (_componentsRun[i]->isEnable() && !_componentsRun[i]->__isPhysics()) {
                    _componentsRun[i]->__update();
                }
            }

            //call children updates
            for (std::size_t i = 0; i < _children.size(); i++) {
                _children[i]->__updateComponents();
            }
            PROFILER_FUNC_END();
        }

        void KapEngine::GameObject::__updateDisplay() {
            PROFILER_FUNC_START();
            //check if gameObject is destroy or disable
            if (!_active || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }

            //set all children
            std::vector<std::shared_ptr<GameObject>> _children;
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
                _children = tr.getChildren();
            } catch (...) {
                DEBUG_ERROR("Failed to get children of gameObject " + _name);
            }

            //update components
            for (std::size_t i = 0; i < _components.size(); i++) {
                if (_components[i]->isEnable() && !_components[i]->__isPhysics()) {
                    _components[i]->onDisplay();
                }
            }
            for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                _componentsRun[i]->onDisplay();
            }

            //call children updates
            for (std::size_t i = 0; i < _children.size(); i++) {
                _children[i]->__updateDisplay();
            }
            PROFILER_FUNC_END();
        }

    #else
        void KapEngine::GameObject::__update() {
            PROFILER_FUNC_START();
            if (!_active || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }
            std::vector<std::shared_ptr<GameObject>> _children;
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
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
                        if (!tr.allParentIsActive()) {
                            PROFILER_FUNC_END();
                            return;
                        }
                    } catch (...) {}
                    _components[i]->__update();
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
                    if (!tr.allParentIsActive()) {
                        PROFILER_FUNC_END();
                        return;
                    }
                } catch (...) {}
                _componentsRun[i]->__update();
            }
            } catch(...) {
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Failed to update components run for GameObject" + _name);
                #endif
            }
            if (_active == false || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }
            try {
                for (std::size_t i = 0; i < _children.size(); i++) {
                    _children[i]->__update();
                }
            } catch(...) {
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Failed to update children for GameObject" + _name);
                #endif
            }
            PROFILER_FUNC_END();
        }

        void KapEngine::GameObject::__updateDisplay() {
            PROFILER_FUNC_START();
            if (!_active || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }
            std::vector<std::shared_ptr<GameObject>> _children;
            try {
                Transform &tr = (Transform &)getTransform();
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
                _children = tr.getChildren();
            } catch (...) {}
            try {
                for (std::size_t i = 0; i < _components.size(); i++) {
                    try {
                        Transform &tr = (Transform &)getTransform();
                        if (!tr.allParentIsActive()) {
                            PROFILER_FUNC_END();
                            return;
                        }
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
                    if (!tr.allParentIsActive()) {
                        PROFILER_FUNC_END();
                        return;
                    }
                } catch (...) {}
                _componentsRun[i]->onDisplay();
            }
            } catch(...) {
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Failed to update display components run for GameObject" + _name);
                #endif
            }
            if (_active == false || _destroyed) {
                PROFILER_FUNC_END();
                return;
            }
            try {
            for (std::size_t i = 0; i < _children.size(); i++) {
                _children[i]->__updateDisplay();
            }
            } catch(...) {
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Failed to update display children for GameObject" + _name);
                #endif
            }
            PROFILER_FUNC_END();
        }
    #endif
#else

    void KapEngine::GameObject::__update(bool physics, bool runDisplay) {
        PROFILER_FUNC_START();
        if (!_active || _destroyed) {
            PROFILER_FUNC_END();
            return;
        }
        std::vector<std::shared_ptr<GameObject>> _children;
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive()) {
                PROFILER_FUNC_END();
                return;
            }
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
                    if (!tr.allParentIsActive()) {
                        PROFILER_FUNC_END();
                        return;
                    }
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
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
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
        if (_active == false || _destroyed) {
            PROFILER_FUNC_END();
            return;
        }
        try {
            for (std::size_t i = 0; i < _children.size(); i++) {
                _children[i]->__update(physics, runDisplay);
            }
        } catch(...) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Failed to update children for GameObject" + _name);
            #endif
        }
        PROFILER_FUNC_END();
    }

    void KapEngine::GameObject::__updateDisplay() {
        PROFILER_FUNC_START();
        if (!_active || _destroyed) {
            PROFILER_FUNC_END();
            return;
        }
        std::vector<std::shared_ptr<GameObject>> _children;
        try {
            Transform &tr = (Transform &)getTransform();
            if (!tr.allParentIsActive()) {
                PROFILER_FUNC_END();
                return;
            }
            _children = tr.getChildren();
        } catch (...) {}
        try {
            for (std::size_t i = 0; i < _components.size(); i++) {
                try {
                    Transform &tr = (Transform &)getTransform();
                    if (!tr.allParentIsActive()) {
                        PROFILER_FUNC_END();
                        return;
                    }
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
                if (!tr.allParentIsActive()) {
                    PROFILER_FUNC_END();
                    return;
                }
            } catch (...) {}
            _componentsRun[i]->onDisplay();
        }
        } catch(...) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Failed to update display components run for GameObject" + _name);
            #endif
        }
        if (_active == false || _destroyed) {
            PROFILER_FUNC_END();
            return;
        }
        try {
        for (std::size_t i = 0; i < _children.size(); i++) {
            _children[i]->__updateDisplay();
        }
        } catch(...) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Failed to update display children for GameObject" + _name);
            #endif
        }
        PROFILER_FUNC_END();
    }

#endif

KapEngine::Component &KapEngine::GameObject::getComponent(std::string const& name) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getName() == name) {
            PROFILER_FUNC_END();
            return *_components[i];
        }
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        if (_componentsRun[i]->getName() == name) {
            PROFILER_FUNC_END();
            return *_componentsRun[i];
        }
    }
    PROFILER_FUNC_END();
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
    PROFILER_FUNC_START();
    _idComp++;
    comp->__setId(_idComp);
    if (getEngine().isRunning()) {
        _componentsRun.push_back(comp);
    } else {
        _components.push_back(comp);
    }
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__engineStop() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__engineStop();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->__engineStop();
    }
    PROFILER_FUNC_END();
}

bool KapEngine::GameObject::hasComponent(std::string const& componentName) const {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        if (_components[i]->getName() == componentName) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        if (_componentsRun[i]->getName() == componentName) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

void KapEngine::GameObject::__destroyIt() {
    PROFILER_FUNC_START();
    _destroyed = true;
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onDestroy();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onDestroy();
    }
    _componentsRun.clear();
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__init() {
    PROFILER_FUNC_START();
    _destroyed = false;
    _active = _startActive;
    _componentsRun.clear();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__awake();
    }
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::setActive(bool b) {
    PROFILER_FUNC_START();
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
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__stoppingGame() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->onGameQuit();
    }
    for (std::size_t i = 0; i < _componentsRun.size(); i++) {
        _componentsRun[i]->onGameQuit();
    }
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::dump(bool displayComponent, std::string prefix) {
    PROFILER_FUNC_START();
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
    PROFILER_FUNC_END();
}

std::vector<std::shared_ptr<KapEngine::Component>> KapEngine::GameObject::getAllComponents() const {
    PROFILER_FUNC_START();
    std::vector<std::shared_ptr<Component>> result;

    for (std::size_t i = 0; i < _components.size(); i++)
        result.push_back(_components[i]);
    for (std::size_t i = 0; i < _componentsRun.size(); i++)
        result.push_back(_componentsRun[i]);

    PROFILER_FUNC_END();
    return result;
}

void KapEngine::GameObject::destroy() {
    PROFILER_FUNC_START();
    getScene().destroyGameObject(getId());
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__setPrefab(std::string const& name) {
    PROFILER_FUNC_START();
    _prefabName = name;
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__onSceneUpdated() {
    PROFILER_FUNC_START();
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
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__onSceneGonnaUpdated() {
    PROFILER_FUNC_START();
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
    PROFILER_FUNC_END();
}

void KapEngine::GameObject::__onSceneChanged() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__sceneChanged();
    }
    PROFILER_FUNC_END();
}
