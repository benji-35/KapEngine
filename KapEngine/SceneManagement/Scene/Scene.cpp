/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Errors.hpp"
#include "Debug.hpp"
#include "Factory.hpp"

KapEngine::SceneManagement::Scene::Scene(SceneManager &manager, std::string const& name) : manager(manager) {
    Debug::log("Start init scene");
    _name = name;
    __finit();
    Debug::log("Stop init scene");
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

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getObject(std::size_t id) {
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

KapEngine::KapEngine &KapEngine::SceneManagement::Scene::getEngine() {
    return manager.getEngine();
}

void KapEngine::SceneManagement::Scene::__update() {
    try {
        Component camera = getActiveCamera();
    } catch(...) {
        if (getEngine().debugMode()) {
            Debug::error("No camera found in scene");
        }
        return;
    }
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->isActive() && !_gameObjects[i]->isDestroyed()) {
            try {
                Transform &tr = (Transform &)_gameObjects[i]->getTransform();
                if (tr.getParentId() == 0)
                    _gameObjects[i]->__update();
            } catch(...) {}
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->isActive() && !_gameObjectsRun[i]->isDestroyed()) {
            try {
                Transform &tr = (Transform &)_gameObjectsRun[i]->getTransform();
                if (tr.getParentId() == 0)
                    _gameObjectsRun[i]->__update();
            } catch(...) {}
        }
    }
}

void KapEngine::SceneManagement::Scene::addGameObject(std::shared_ptr<GameObject> go) {
    if (go->getId() != 0) {
        Debug::warning("Object " + go->getName() + " already added in scene: " + go->getScene().getName());
        return;
    }
    _idObjectMax++;
    go->__setId(_idObjectMax);
    if (getEngine().debugMode()) {
        Debug::log("Add object " + go->getName() + " in scene " + getName());
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

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getObjectConst(std::size_t id) const {
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

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::SceneManagement::Scene::getAllObjects() {
    std::vector<std::shared_ptr<GameObject>> result;

    result = _gameObjects;
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        result.push_back(_gameObjectsRun[i]);
    }
    return result;    
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getObject(Entity const& en) {
    return getObject(en.getId());
}

void KapEngine::SceneManagement::Scene::removeGameObject(std::shared_ptr<GameObject> go) {
    if (go.use_count() == 0)
        return;
    removeGameObject(go->getId());
}

void KapEngine::SceneManagement::Scene::removeGameObject(std::size_t index) {
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i].use_count() != 0 && _gameObjectsRun[i]->getId() == index) {
            _gameObjectsRun[i]->__destroyIt();
            _gameObjectsRun[i]->__engineStop();
            _gameObjectsRun[i].reset();
            _gameObjectsRun.erase(_gameObjectsRun.begin() + i);
            break;
        }
    }
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjectsRun[i].use_count() != 0 && _gameObjectsRun[i]->getId() == index) {
            _gameObjectsRun[i]->__destroyIt();
            break;
        }
    }
}

void KapEngine::SceneManagement::Scene::__init() {
    _gameObjectsRun.clear();
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i]->__init();
    }
    dump(true);
}

void KapEngine::SceneManagement::Scene::__finit() {
    auto mainCamera = Factory::createEmptyGameObject(*this, "Main Camera");
    auto cam = std::make_shared<Camera>(mainCamera);
    mainCamera->addComponent(cam);
}

void KapEngine::SceneManagement::Scene::dump(bool b) {
    Debug::log("Scene: " + getName());
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (b) {
            _gameObjects[i]->dump();
        } else {
            Debug::log("-GameObject: " + _gameObjects[i]->getName());
        }
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (b) {
            _gameObjectsRun[i]->dump();
        } else {
            Debug::log("-GameObject: " + _gameObjectsRun[i]->getName());
        }
    }
}

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::createGameObject(std::string const& name) {
    auto object = std::make_shared<GameObject>(*this, name);

    addGameObject(object);
    return object;
}
