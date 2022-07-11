/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Errors.hpp"

KapEngine::SceneManagement::Scene::Scene(std::string const& name) {
    _name = name;
}

KapEngine::SceneManagement::Scene::~Scene() {}

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

std::shared_ptr<KapEngine::GameObject> KapEngine::SceneManagement::Scene::getObject(std::size_t id)
{
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
