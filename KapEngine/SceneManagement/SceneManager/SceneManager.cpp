/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

KapEngine::SceneManagement::SceneManager::SceneManager(KapEngine &engine) : _engine(engine) {
}

KapEngine::SceneManagement::SceneManager::~SceneManager() {
}

void KapEngine::SceneManagement::SceneManager::addScene(std::shared_ptr<Scene> scene) {
    _scenes.push_back(scene);
}

void KapEngine::SceneManagement::SceneManager::addScene(std::string const& name) {
    std::shared_ptr<Scene> nScene = std::make_shared<Scene>(name);
}
