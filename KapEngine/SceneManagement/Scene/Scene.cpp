/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Errors.hpp"
#include "Debug.hpp"

KapEngine::SceneManagement::Scene::Scene(SceneManager &manager, std::string const& name) : manager(manager) {
    _name = name;
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

void KapEngine::SceneManagement::Scene::__update(int threadId) {
    try {
        Component camera = getActiveCamera();
    } catch(...) {
        if (getEngine().debugMod()) {
            Debug::error("No camera found in scene");
        }
        return;
    }
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        if (_gameObjects[i]->isActive() && !_gameObjects[i]->isDestroyed())
            _gameObjects[i]->__update(threadId);
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
        if (_gameObjectsRun[i]->isActive() && !_gameObjectsRun[i]->isDestroyed())
            _gameObjectsRun[i]->__update(threadId);
    }
}

void KapEngine::SceneManagement::Scene::addGameObject(std::shared_ptr<GameObject> go) {
    _idObjectMax++;
    go->__setId(_idObjectMax);
    if (getEngine().isRunning()) {
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

void KapEngine::SceneManagement::Scene::__engineStop() {
    for (std::size_t i = 0; i < _gameObjects.size(); i++) {
        _gameObjects[i]->__engineStop();
    }
    for (std::size_t i = 0; i < _gameObjectsRun.size(); i++) {
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
