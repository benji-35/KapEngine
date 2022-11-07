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

KapEngine::Component::Component(std::shared_ptr<GameObject> &go, std::string const& name, int threadId) {
    PROFILER_FUNC_START();
    _go = go;
    _name = name;
    threadRunning = threadId;
    PROFILER_FUNC_END();
}

KapEngine::Component::~Component() {
    PROFILER_FUNC_START();
    _go.reset();
    PROFILER_FUNC_END();
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
}

void KapEngine::Component::__awake() {
    PROFILER_FUNC_START();
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

void KapEngine::Component::__fixedUpdate() {
    PROFILER_FUNC_START();
    if (getGameObjectConst().getEngine().__canRunFixed())
        onFixedUpdate();
    PROFILER_FUNC_END();
}

KapEngine::Events::Input KapEngine::Component::getInput() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getGameObject().getEngine().getEventManager().getInput();
}

KapEngine::Events::Mouse KapEngine::Component::getMouse() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getGameObject().getEngine().getEventManager().getMouse();
}

KapEngine::GameObject &KapEngine::Component::getGameObjectConst() const {
    try {
        if (_go.use_count() <= 1)
            throw Errors::SceneError("GameObject does not exist in scene");
        return *_go;
    } catch (Errors::SceneError e) {
        throw Errors::ComponentError(std::string(e.what()));
    }
}

bool KapEngine::Component::__checkValidity() {
    if (!_enable) {
        return false;
    }
    if (!getGameObject().isActive() || getGameObject().isDestroyed()) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Component " + getName() + " is disable or destroy");
        #endif
        return false;
    }
    if (getGameObject().getScene().__isChangingScene()) {
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
