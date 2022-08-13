/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Debug.hpp"

KapEngine::SceneManagement::SceneManager::SceneManager(KapEngine &engine) : _engine(engine) {
}

KapEngine::SceneManagement::SceneManager::~SceneManager() {
}

void KapEngine::SceneManagement::SceneManager::addScene(std::shared_ptr<Scene> scene) {
    _scenes.push_back(scene);
}

void KapEngine::SceneManagement::SceneManager::addScene(std::string const& name) {
    std::shared_ptr<Scene> nScene = std::make_shared<Scene>(*this, name);

    _scenes.push_back(nScene);
}

void KapEngine::SceneManagement::SceneManager::__update() {
    if (_indexScene >= _scenes.size()) {
        if (_engine.debugMod()) {
            Debug::error("Current scene out of range of all scenes");
        } else {
            throw Errors::SceneError("Current scene out of range");
        }
        return;
    }
    _scenes[_indexScene]->__update();
}
