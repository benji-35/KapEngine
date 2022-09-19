/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "Debug.hpp"
#include "Factory.hpp"

KapEngine::SceneManagement::SceneManager::SceneManager(KapEngine &engine) : _engine(engine) {
    std::shared_ptr<Scene> baseScene = std::make_shared<Scene>(*this, "Default Scene");
    Factory::createCamera(baseScene, "Main Camera");
    addScene(baseScene);
}

KapEngine::SceneManagement::SceneManager::~SceneManager() {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        _scenes[i]->__engineStop();
        _scenes[i].reset();
    }
}

void KapEngine::SceneManagement::SceneManager::addScene(std::shared_ptr<Scene> scene) {

    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i].use_count() != 0 && _scenes[i]->getName() == scene->getName()) {
            Debug::error("Scene called \"" + scene->getName() + "\" already exists");
            return;
        }
    }

    _scenes.push_back(scene);
}

void KapEngine::SceneManagement::SceneManager::addScene(std::string const& name) {
    std::shared_ptr<Scene> nScene = std::make_shared<Scene>(*this, name);

    _scenes.push_back(nScene);
}

void KapEngine::SceneManagement::SceneManager::__update(int threadId) {
    if (_indexScene >= _scenes.size()) {
        if (_engine.debugMod()) {
            Debug::error("Current scene out of range of all scenes");
        } else {
            throw Errors::SceneError("Current scene out of range");
        }
        return;
    }
    _scenes[_indexScene]->__update(threadId);
}

void KapEngine::SceneManagement::SceneManager::removeScene(std::size_t index) {
    if (!sceneExists(index)) {
        if (getEngine().debugMod()) {
            Debug::error("Cannot destroy scene id: " + std::to_string(index) + " because it does not exists.");
        }
        return;
    }
    _scenes.erase(_scenes.begin() + getSceneIndexInList(index));
}

void KapEngine::SceneManagement::SceneManager::removeScene(std::string const& sceneName) {
    if (!sceneExists(sceneName)) {
        if (getEngine().debugMod()) {
            Debug::error("Cannot destroy scene \"" + sceneName + "\" because it does not exists.");
        }
        return;
    }
    _scenes.erase(_scenes.begin() + getSceneIndexInList(sceneName));
}

bool KapEngine::SceneManagement::SceneManager::sceneExists(std::size_t index) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == index)
            return true;
    }
    return false;
}

bool KapEngine::SceneManagement::SceneManager::sceneExists(std::string const& sceneName) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName)
            return true;
    }
    return false;
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndex(std::string const& sceneName) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName)
            return _scenes[i]->getId();
    }
    return 0;
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndexInList(std::size_t id) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == id)
            return i;
    }
    return _scenes.size();
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndexInList(std::string const& sceneName) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName)
            return i;
    }
    return _scenes.size();
}

void KapEngine::SceneManagement::SceneManager::loadScene(std::string const& sceneName) {
    if (!sceneExists(sceneName)) {
        if (getEngine().debugMod()) {
            Debug::error("Cannot load scene \"" + sceneName + "\" because it does not exists");
        }
        return;
    }
    std::size_t gdIndex = getSceneIndexInList(_indexScene);
    _scenes[gdIndex]->__changingScene();
    gdIndex = getSceneIndex(sceneName);
    _indexScene = gdIndex;
}

void KapEngine::SceneManagement::SceneManager::loadScene(std::size_t index) {
    if (!sceneExists(index)) {
        if (getEngine().debugMod()) {
            Debug::error("Cannot load scene id: " + std::to_string(index) + " because it does not exists");
        }
        return;
    }
    loadScene(getSceneName(index));
}

std::string KapEngine::SceneManagement::SceneManager::getSceneName(std::size_t index) {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == index)
            return _scenes[i]->getName();
    }
    throw Errors::SceneError("Scene id: " + std::to_string(index) + " does not exists");
}

KapEngine::SceneManagement::Scene &KapEngine::SceneManagement::SceneManager::getScene(std::string const& sceneName) {
    if (!sceneExists(sceneName)) {
        throw Errors::SceneError("Scene " + sceneName + " does not exists");
    }
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName)
            return *_scenes[i];
    }
    throw Errors::SceneError("Unknown error while getting scene");
}

KapEngine::SceneManagement::Scene &KapEngine::SceneManagement::SceneManager::getCurrentScene() {
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == _indexScene)
            return *_scenes[i];
    }
    throw Errors::SceneError("Unknown error while getting current scene");
}
