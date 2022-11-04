/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Errors.hpp"
#include "KapEngineDebug.hpp"
#include "Factory.hpp"
#include "Profiler/KapProfiler.hpp"

#include "ThreadScene.hpp"

#include <thread>

KapEngine::SceneManagement::Scene::Scene(SceneManager &manager, std::string const& name) : manager(manager) {
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Start init scene");
    #endif
    _name = name;
    __finit();
    
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Stop init scene");
    #endif
}

KapEngine::SceneManagement::Scene::~Scene() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i].reset();
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        _gameObjectsRun[i].reset();
    }
    PROFILER_FUNC_END();
}

KapEngine::Component &KapEngine::SceneManagement::Scene::getActiveCamera() const {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->isActive() && !_gameObjects[i]->isDestroyed()) {
            try {
                Component &comp = _gameObjects[i]->getComponent<Camera>();
                if (comp.isEnable()) {
                    PROFILER_FUNC_END();
                    return comp;
                }
            } catch(...) {}
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->isActive() && !_gameObjectsRun[i]->isDestroyed()) {
            try {
                Component &comp = _gameObjectsRun[i]->getComponent<Camera>();
                if (comp.isEnable()) {
                    PROFILER_FUNC_END();
                    return comp;
                }
            } catch(...) {}
        }
    }
    PROFILER_FUNC_START();
    throw Errors::SceneError("No active camera found in this scene");
}

std::shared_ptr<KapEngine::GameObject> &KapEngine::SceneManagement::Scene::getGameObject(std::size_t id) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == id) {
            PROFILER_FUNC_END();
            return _gameObjects[i];
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == id) {
            PROFILER_FUNC_END();
            return _gameObjectsRun[i];
        }
    }
    PROFILER_FUNC_END();
    throw Errors::SceneError("No object has id: " + std::to_string(id));
}

KapEngine::KEngine &KapEngine::SceneManagement::Scene::getEngine() {
    return manager.getEngine();
}

void KapEngine::SceneManagement::Scene::__update() {
    PROFILER_FUNC_START();
    __checkDestroy();
    try {
        Component camera = getActiveCamera();
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("No camera found in scene");
        #endif
        PROFILER_FUNC_END();
        return;
    }
    PROFILER_FUNC_START();
    #if KAPENGINE_THREAD_ACTIVE
        __checkThread();
    #else
        auto objs = __getGameObjectsNoParent();
        std::size_t indexFailed = 0;

        for (std::size_t i = 0; i < objs.size(); i++) {
            indexFailed = i;
            try {
                objs[i]->__onSceneGonnaUpdated();
            } catch(...) {
                indexFailed = i;
                break;
            }
        }

        __updateGameObjects(objs);

        for (std::size_t i = 0; i < objs.size(); i++) {
            indexFailed = i;
            try {
                objs[i]->__updateDisplay();
            } catch(std::exception &e) {
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Error in __updateDisplay for object " + objs[indexFailed]->getName() + " [" + std::to_string(objs[indexFailed]->getId()) + "]: " + e.what());
                #endif
            }
            try {
                objs[i]->__onSceneUpdated();
            } catch(std::exception& e) {
                
                #if KAPENGINE_DEBUG_ACTIVE
                    DEBUG_ERROR("Error in __onSceneUpdated for object " + objs[indexFailed]->getName() + " [" + std::to_string(objs[indexFailed]->getId()) + "]: " + e.what());
                #endif
            }
        }
        try {
            for (std::size_t i = 0; i < _tmpActionsAfterUpdate.size(); i++) {
                indexFailed = i;
                _tmpActionsAfterUpdate[i](*this);
            }
        } catch(...) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Error in scene update action " + std::to_string(indexFailed));
            #endif
        }
        _tmpActionsAfterUpdate.clear();
    #endif
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::addGameObject(std::shared_ptr<GameObject> go) {
    PROFILER_FUNC_START();
    if (go->getId() != 0) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_WARNING("Object " + go->getName() + " already added in scene: " + go->getScene().getName());
        #endif
        return;
    }
    _idObjectMax++;
    go->__setId(_idObjectMax);
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Add object " + go->getName() + " in scene " + getName());
    #endif
    if (!getEngine().isRunning() || manager.getCurrentSceneId() != getId()) {
        _gameObjects.push_back(go);
    } else {
        _gameObjectsRun.push_back(go);
    }
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::__changingScene() {
    PROFILER_FUNC_START();
    _changingScene = true;
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i]->__onSceneChanged();
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        _gameObjectsRun[i].reset();
    }
    _gameObjectsRun.clear();
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::__engineStop(bool currentScene) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (currentScene)
            _gameObjects[i]->__stoppingGame();
        _gameObjects[i]->__engineStop();
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (currentScene)
            _gameObjectsRun[i]->__stoppingGame();
        _gameObjectsRun[i]->__engineStop();
    }
    PROFILER_FUNC_END();
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getGameObjectConst(std::size_t id) const {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == id) {
            PROFILER_FUNC_END();
            return _gameObjects[i];
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == id) {
            PROFILER_FUNC_END();
            return _gameObjectsRun[i];
        }
    }
    PROFILER_FUNC_END();
    throw Errors::SceneError("No object has id: " + std::to_string(id));
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getAllGameObjects() {
    PROFILER_FUNC_START();
    std::vector<std::shared_ptr<GameObject>> result;

    result = _gameObjects;
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        result.push_back(_gameObjectsRun[i]);
    }
    PROFILER_FUNC_END();
    return result;
}

std::shared_ptr<KapEngine::GameObject> &KapEngine::SceneManagement::Scene::getGameObject(Entity const& en) {
    return getGameObject(en.getId());
}

void KapEngine::SceneManagement::Scene::destroyGameObject(std::shared_ptr<GameObject> const go) {
    if (go.use_count() == 0 || go->getScene().getId() != getId())
        return;
    destroyGameObject(go->getId());
}

void KapEngine::SceneManagement::Scene::destroyGameObject(GameObject const& go) {
    if (go.getSceneConst().getId() != getId())
        return;
    destroyGameObject(go.getId());
}

void KapEngine::SceneManagement::Scene::destroyGameObject(std::size_t index) {
    PROFILER_FUNC_START();
    _gameObjectsToDestroy.push_back(index);
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::__checkDestroy() {
    PROFILER_FUNC_START();
    for (std::size_t x = 0; x < _gameObjectsToDestroy.size(); x++) {
        for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
            if (_gameObjectsRun[i].use_count() != 0 && _gameObjectsRun[i]->getId() == _gameObjectsToDestroy[x]) {
                _gameObjectsRun[i]->__destroyIt();
                _gameObjectsRun[i]->__engineStop();
                _gameObjectsRun[i].reset();
                _gameObjectsRun.erase(_gameObjectsRun.begin() + i);
                break;
            }
        }
        for (std::size_t i = 0; i < _gameObjects.size(); i++) {
            if (_gameObjects[i].use_count() != 0 && _gameObjects[i]->getId() == _gameObjectsToDestroy[x]) {
                _gameObjectsRun[i]->__destroyIt();
                break;
            }
        }
    }
    _gameObjectsToDestroy.clear();
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::__init() {
    PROFILER_FUNC_START();
    _changingScene = false;
    _gameObjectsRun.clear();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i]->__init();
    }
    #if KAPENGINE_DEBUG_ACTIVE
        dump(true);
    #endif
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::__finit() {
    PROFILER_FUNC_START();
    auto mainCamera = createGameObject("Main Camera");
    auto cam = std::make_shared<Camera>(mainCamera);
    mainCamera->addComponent(cam);
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::Scene::dump(bool b) {
    PROFILER_FUNC_START();
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Scene: " + getName());
    #endif
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getComponent<Transform>().getParentId() == 0) {
            _gameObjects[i]->dump(b, "");
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getComponent<Transform>().getParentId() == 0) {
            _gameObjectsRun[i]->dump(b, "");
        }
    }
    PROFILER_FUNC_END();
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::createGameObject(std::string const& name) {
    PROFILER_FUNC_START();
    auto object = std::make_shared<GameObject>(*this, name);

    auto tr = std::make_shared<Transform>(object);
    object->addComponent(tr);

    addGameObject(object);
    PROFILER_FUNC_END();
    return object;
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getGameObjects(std::string const& name) {
    PROFILER_FUNC_START();
    std::vector<std::shared_ptr<GameObject>> result;

    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getName() == name)
            result.push_back(_gameObjects[i]);
    }

    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getName() == name)
            result.push_back(_gameObjectsRun[i]);
    }

    PROFILER_FUNC_END();
    return result;
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::findFirstGameObject(std::string const& name) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getName() == name) {
            PROFILER_FUNC_END();
            return _gameObjects[i];
        }
    }

    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getName() == name) {
            PROFILER_FUNC_END();
            return _gameObjectsRun[i];
        }
    }
    PROFILER_FUNC_END();
    throw Errors::SceneError("No object has name: " + name);
}

#if KAPENGINE_THREAD_ACTIVE

void KapEngine::SceneManagement::Scene::__threadSceneUpdate(std::vector<std::shared_ptr<GameObject>> gos, bool physics) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < gos.size(); i++) {
        if (gos[i]->getScene().__isChangingScene()) {
            PROFILER_FUNC_END();
            return;
        }
        gos[i]->__update(physics);
    }
    PROFILER_FUNC_END();
}


void KapEngine::SceneManagement::Scene::__checkThread() {
    PROFILER_FUNC_START();
    auto objs = __getGameObjectsNoParent();
    std::size_t indexFailed = 0;

    try {
        for (std::size_t i = 0; i < objs.size(); i++) {
            indexFailed = i;
            objs[i]->__onSceneGonnaUpdated();
        }
    } catch (...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Error in __onSceneGonnaUpdated for object " + objs[indexFailed]->getName());
        #endif
    }

    std::thread t1(__threadSceneUpdate, objs, true);

    for (std::size_t i = 0; i < objs.size(); i++) {
        objs[i]->__update(false, false);
    }

    t1.join();

    for (std::size_t i = 0; i < objs.size(); i++) {
        indexFailed = i;
        try {
            objs[i]->__updateDisplay();
        } catch(std::exception &e) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Error in __updateDisplay for object " + objs[indexFailed]->getName() + " [" + std::to_string(objs[indexFailed]->getId()) + "]: " + e.what());
            #endif
        }
        try {
            objs[i]->__onSceneUpdated();
        } catch(std::exception& e) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Error in __onSceneUpdated for object " + objs[indexFailed]->getName() + " [" + std::to_string(objs[indexFailed]->getId()) + "]: " + e.what());
            #endif
        }
    }
    try {
        for (std::size_t i = 0; i < _tmpActionsAfterUpdate.size(); i++) {
            indexFailed = i;
            _tmpActionsAfterUpdate[i](*this);
        }
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Error in scene update action " + std::to_string(indexFailed));
        #endif
    }
    _tmpActionsAfterUpdate.clear();
    PROFILER_FUNC_END();
}
#endif

std::size_t KapEngine::SceneManagement::Scene::__nbGameObjectNoParent() {
    PROFILER_FUNC_START();
    std::size_t result = 0;
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getComponent<Transform>().getParentId() == 0)
            result++;
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getComponent<Transform>().getParentId() == 0)
            result++;
    }
    PROFILER_FUNC_END();
    return result;
}

void KapEngine::SceneManagement::Scene::__updateGameObjects(std::vector<std::shared_ptr<GameObject>> objs) {
    PROFILER_FUNC_START();
    //updating scene
    for (std::size_t i = 0; i < objs.size(); i++) {
        objs[i]->__update(false, false);
        objs[i]->__update(true, false);
    }
    PROFILER_FUNC_END();
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::__getGameObjectsNoParent() {
    PROFILER_FUNC_START();
    std::vector<std::shared_ptr<GameObject>> result;
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getComponent<Transform>().getParentId() == 0 && _gameObjects[i].use_count() != 0 && _gameObjects[i]->isActive())
            result.push_back(_gameObjects[i]);
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getComponent<Transform>().getParentId() == 0 && _gameObjectsRun[i].use_count() != 0 && _gameObjectsRun[i]->isActive())
            result.push_back(_gameObjectsRun[i]);
    }
    PROFILER_FUNC_END();
    return result;
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getGameObjectByTag(std::string const& tag) {
    PROFILER_FUNC_START();

    std::vector<std::shared_ptr<GameObject>> result;

    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getTag() == tag)
            result.push_back(_gameObjects[i]);
    }

    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getTag() == tag)
            result.push_back(_gameObjectsRun[i]);
    }

    PROFILER_FUNC_END();
    return result;

}

bool KapEngine::SceneManagement::Scene::isGameObjectExists(std::size_t const& index) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == index) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == index) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

bool KapEngine::SceneManagement::Scene::isGameObjectExists(Entity const& en) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == en.getId()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == en.getId()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    return false;
}
