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

#include <thread>

KapEngine::SceneManagement::Scene::Scene(SceneManager &manager, std::string const& name) : manager(manager) {
    DEBUG_LOG("Start init scene");
    _name = name;
    __finit();
    DEBUG_LOG("Stop init scene");
}

KapEngine::SceneManagement::Scene::~Scene() {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i].reset();
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        _gameObjectsRun[i].reset();
    }
}

KapEngine::Component &KapEngine::SceneManagement::Scene::getActiveCamera() const {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->isActive() && !_gameObjects[i]->isDestroyed()) {
            try {
                Component &comp = _gameObjects[i]->getComponent("Camera");
                if (comp.isEnable()) {
                    return comp;
                }
            } catch(...) {}
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->isActive() && !_gameObjectsRun[i]->isDestroyed()) {
            try {
                Component &comp = _gameObjectsRun[i]->getComponent("Camera");
                if (comp.isEnable()) {
                    return comp;
                }
            } catch(...) {}
        }
    }
    throw Errors::SceneError("No active camera found in this scene");
}

std::shared_ptr<KapEngine::GameObject> &KapEngine::SceneManagement::Scene::getGameObject(std::size_t id) {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == id)
            return _gameObjects[i];
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == id)
            return _gameObjectsRun[i];
    }
    throw Errors::SceneError("No object has id: " + std::to_string(id));
}

KapEngine::KEngine &KapEngine::SceneManagement::Scene::getEngine() {
    return manager.getEngine();
}

void KapEngine::SceneManagement::Scene::__update() {
    __checkDestroy();
    try {
        Component camera = getActiveCamera();
    } catch(...) {
        if (getEngine().debugMode()) {
            DEBUG_ERROR("No camera found in scene");
        }
        return;
    }
    __updateGameObjects();
}

void KapEngine::SceneManagement::Scene::addGameObject(std::shared_ptr<GameObject> go) {
    if (go->getId() != 0) {
        DEBUG_WARNING("Object " + go->getName() + " already added in scene: " + go->getScene().getName());
        return;
    }
    _idObjectMax++;
    go->__setId(_idObjectMax);
    if (getEngine().debugMode()) {
        DEBUG_LOG("Add object " + go->getName() + " in scene " + getName());
    }
    if (!getEngine().isRunning() || manager.getCurrentSceneId() != getId()) {
        _gameObjects.push_back(go);
    } else {
        _gameObjectsRun.push_back(go);
    }
}

void KapEngine::SceneManagement::Scene::__changingScene() {
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        _gameObjectsRun[i].reset();
    }
    _gameObjectsRun.clear();
}

void KapEngine::SceneManagement::Scene::__engineStop(bool currentScene) {
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
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getGameObjectConst(std::size_t id) const {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getId() == id)
            return _gameObjects[i];
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getId() == id)
            return _gameObjectsRun[i];
    }
    throw Errors::SceneError("No object has id: " + std::to_string(id));
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getAllGameObjects() {
    std::vector<std::shared_ptr<GameObject>> result;

    result = _gameObjects;
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        result.push_back(_gameObjectsRun[i]);
    }
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
    _gameObjectsToDestroy.push_back(index);
}

void KapEngine::SceneManagement::Scene::__checkDestroy() {
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
}

void KapEngine::SceneManagement::Scene::__init() {
    _gameObjectsRun.clear();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i]->__init();
    }
    dump(true);
}

void KapEngine::SceneManagement::Scene::__finit() {
    auto mainCamera = createGameObject("Main Camera");
    auto cam = std::make_shared<Camera>(mainCamera);
    mainCamera->addComponent(cam);
}

void KapEngine::SceneManagement::Scene::dump(bool b) {
    DEBUG_LOG("Scene: " + getName());
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
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::createGameObject(std::string const& name) {
    auto object = std::make_shared<GameObject>(*this, name);

    auto tr = std::make_shared<Transform>(object);
    object->addComponent(tr);

    addGameObject(object);
    return object;
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getGameObjects(std::string const& name) {
    std::vector<std::shared_ptr<GameObject>> result;

    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getName() == name)
            result.push_back(_gameObjects[i]);
    }

    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getName() == name)
            result.push_back(_gameObjectsRun[i]);
    }

    return result;
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::findFirstGameObject(std::string const& name) {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getName() == name)
            return _gameObjects[i];
    }

    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getName() == name)
            return _gameObjectsRun[i];
    }
    throw Errors::SceneError("No object has name: " + name);
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::__getGameObjectsNoParent() {
    std::vector<std::shared_ptr<GameObject>> result;

    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->getComponent<Transform>().getParentId() == 0)
            result.push_back(_gameObjects[i]);
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->getComponent<Transform>().getParentId() == 0)
            result.push_back(_gameObjectsRun[i]);
    }
    return result;
}

void KapEngine::SceneManagement::Scene::__updateGameObjects() {
    std::thread t1(&Scene::__threadSceneUpdate, *this, 1);
    std::thread t2(&Scene::__threadSceneUpdate, *this, 2);
    std::thread t3(&Scene::__threadSceneUpdate, *this, 3);
    std::thread t4(&Scene::__threadSceneUpdate, *this, 4);

    __threadSceneUpdate(*this, 0);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto gameObjects = __getGameObjectsNoParent();
    for (std::size_t i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->__updateDisplay();
    }
}

void KapEngine::SceneManagement::Scene::__threadSceneUpdate(Scene &scene, std::size_t id) {
    auto objs = scene.__getGameObjectsNoParent();
    for (std::size_t i = 0; i < objs.size(); i++) {
        objs[i]->__update(id, false);
    }
}
