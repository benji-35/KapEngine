/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

// #include "Component.hpp"
// #include "Errors.hpp"
// #include "Transform.hpp"

// #include "KapEngineDebug.hpp"
// #include "KapEngineSettings.hpp"

#include "Profiler/KapProfiler.hpp"
#include "KapEngine.hpp"

KapEngine::Component::Component(std::shared_ptr<GameObject> &go, std::string const& name): _scene(go->getScene()), _engine(go->getEngine()), obj(*go) {
    PROFILER_FUNC_START();
    _name = name;
    PROFILER_FUNC_END();
}

KapEngine::Component::Component(GameObject &go, std::string const& name): _scene(go.getScene()), _engine(go.getEngine()), obj(go) {
    PROFILER_FUNC_START();
    _name = name;
    PROFILER_FUNC_END();
}

KapEngine::Component::~Component() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

KapEngine::GameObject &KapEngine::Component::getGameObject() const {
    try {
        return obj;
    } catch (Errors::SceneError e) {
        throw Errors::ComponentError(std::string(e.what()));
    }
}

void KapEngine::Component::__update(bool runDisplay) {
    #if KAPENGINE_BETA_ACTIVE && KAPENGINE_THREAD_ACTIVE
        PROFILER_FUNC_START();
        try {
            __awake();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            __start();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            onUpdate();
        } catch(...) {
            PROFILER_FUNC_END();
            return;
        }
        PROFILER_FUNC_END();
    #else
        PROFILER_FUNC_START();
        try {
            __awake();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            __start();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            onUpdate();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            __fixedUpdate();
            if (!__checkValidity()) {
                PROFILER_FUNC_END();
                return;
            }
            if (runDisplay)
                onDisplay();
        } catch(...) {
            PROFILER_FUNC_END();
            return;
        }
        PROFILER_FUNC_END();
    #endif
}

void KapEngine::Component::__awake() {
    PROFILER_FUNC_START();
    if (obj.getId() == 0) {
        DEBUG_ERROR("Component " + _name + " is not attached to a GameObject or GameObject do not have a valid id");
        PROFILER_FUNC_END();
        return;
    }
    if (_awakeDone || getGameObject().isDestroyed()) {
        PROFILER_FUNC_END();
        return;
    }
    _awakeDone = true;
    onAwake();
    PROFILER_FUNC_END();
}

void KapEngine::Component::__start() {
    PROFILER_FUNC_START();
    if (_startDone) {
        PROFILER_FUNC_END();
        return;
    }
    _startDone = true;
    onStart();
    PROFILER_FUNC_END();
}

#if KAPENGINE_BETA_ACTIVE && KAPENGINE_THREAD_ACTIVE

    void KapEngine::Component::__fixedUpdate(Time::ETime fixed) {
        PROFILER_FUNC_START();
        _elapsedTime = fixed;
        if (threadRunning == 1) {
            PROFILER_FUNC_END();
            return;
        }
        onFixedUpdate();
        PROFILER_FUNC_END();
    }

#else

    void KapEngine::Component::__fixedUpdate() {
        PROFILER_FUNC_START();
        if (getEngine().__canRunFixed())
            onFixedUpdate();
        PROFILER_FUNC_END();
    }
#endif

KapEngine::Events::Input KapEngine::Component::getInput() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getEngine().getEventManager().getInput();
}

KapEngine::Events::Mouse KapEngine::Component::getMouse() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getEngine().getEventManager().getMouse();
}

bool KapEngine::Component::__checkValidity() {
    if (obj.getId() == 0) {
        DEBUG_ERROR("Component " + _name + " is not attached to a GameObject or GameObject do not have a valid id");
        return false;
    }
    if (!_enable) {
        return false;
    }
    if (!getGameObject().isActive() || getGameObject().isDestroyed()) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Component " + getName() + " is disable or destroy");
        #endif
        return false;
    }
    if (getScene().__isChangingScene()) {
        return false;
    }
    if (!getTransform().allParentsActive()) {
        return false;
    }
    if (!checkComponentValidity()) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Component " + getName() + " is disable by the creator");
        #endif
        return false;
    }
    for (std::size_t i = 0; i < _componentsNeeded.size(); i++) {
        if (!getGameObject().hasComponent(_componentsNeeded[i])) {
            return false;
        }
    }

    return true;
}

KapEngine::Transform &KapEngine::Component::getTransform() {
    return getGameObject().getComponent<Transform>();
}

std::size_t KapEngine::Component::getGameObjectId() const {
    return obj.getId();
}

#if KAPENGINE_BETA_ACTIVE

    KapEngine::Time::ETime KapEngine::Component::getElapsedTime() const {
        #if KAPENGINE_THREAD_ACTIVE
            return _elapsedTime;
        #else
            return getGameObject().getEngine().getElapsedTime();
        #endif
    }

#endif
