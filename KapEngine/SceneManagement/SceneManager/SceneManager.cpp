/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SceneManager
*/

#include "KapEngine.hpp"

KapEngine::SceneManagement::SceneManager::SceneManager(KEngine &engine) : _engine(engine) {
    PROFILER_FUNC_START();
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Create Default Scene");
    #endif
    createScene("Default Scene");
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("End init sceneManager");
    #endif
    PROFILER_FUNC_END();
}

KapEngine::SceneManagement::SceneManager::~SceneManager() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        bool current = false;
        if (_scenes[i]->getId() == _indexScene)
            current = true;
        _scenes[i]->__engineStop(current);
        _scenes[i].reset();
    }
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::addScene(std::shared_ptr<Scene> scene) {
    PROFILER_FUNC_END();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i].use_count() != 0 && _scenes[i]->getName() == scene->getName()) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("Scene called \"" + scene->getName() + "\" already exists");
            #endif
            PROFILER_FUNC_END();
            return;
        }
    }

    _maxIndex++;
    scene->setId(_maxIndex);
    _scenes.push_back(scene);
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("Scene " + scene->getName() + " added to scene manager");
    #endif
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::addScene(std::string const& name) {
    PROFILER_FUNC_START();
    std::shared_ptr<Scene> nScene = std::make_shared<Scene>(*this, name);

    addScene(nScene);
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::__update() {
    PROFILER_FUNC_START();
    try {
        if (_indexScene == 0)
            loadScene(1);
        getCurrentScene().__update();
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Cannot update scene " + getCurrentScene().getName());
        #endif
    }
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::removeScene(std::size_t index) {
    PROFILER_FUNC_START();
    if (!sceneExists(index)) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Cannot destroy scene id: " + std::to_string(index) + " because it does not exists.");
        #endif
        PROFILER_FUNC_END();
        return;
    }
    _scenes.erase(_scenes.begin() + getSceneIndexInList(index));
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::removeScene(std::string const& sceneName) {
    PROFILER_FUNC_START();
    if (!sceneExists(sceneName)) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Cannot destroy scene \"" + sceneName + "\" because it does not exists.");
        #endif
        PROFILER_FUNC_END();
        return;
    }
    _scenes.erase(_scenes.begin() + getSceneIndexInList(sceneName));
    PROFILER_FUNC_END();
}

bool KapEngine::SceneManagement::SceneManager::sceneExists(std::size_t index) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == index) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

bool KapEngine::SceneManagement::SceneManager::sceneExists(std::string const& sceneName) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndex(std::string const& sceneName) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName) {
            PROFILER_FUNC_END();
            return _scenes[i]->getId();
        }
    }
    PROFILER_FUNC_END();
    return 0;
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndexInList(std::size_t id) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == id) {
            PROFILER_FUNC_END();
            return i;
        }
    }
    PROFILER_FUNC_END();
    return _scenes.size();
}

std::size_t KapEngine::SceneManagement::SceneManager::getSceneIndexInList(std::string const& sceneName) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName) {
            PROFILER_FUNC_END();
            return i;
        }
    }
    PROFILER_FUNC_END();
    return _scenes.size();
}

void KapEngine::SceneManagement::SceneManager::loadScene(std::string const& sceneName) {
    PROFILER_FUNC_START();
    if (!sceneExists(sceneName)) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Cannot load scene \"" + sceneName + "\" because it does not exists");
        #endif
        PROFILER_FUNC_END();
        return;
    }
    loadScene(getSceneIndex(sceneName));
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SceneManager::loadScene(std::size_t index) {
    PROFILER_FUNC_START();
    #if KAPENGINE_BETA_ACTIVE
        #if KAPENGINE_THREAD_ACTIVE
            _mutex.lock();
        #endif
    #endif
    if (!sceneExists(index)) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Cannot load scene id: " + std::to_string(index) + " because it does not exists");
        #endif
        PROFILER_FUNC_END();
        return;
    }
    try {
        getCurrentScene().__changingScene();
    } catch(...) {}
    _indexScene = index;
    getCurrentScene().__init();
    #if KAPENGINE_BETA_ACTIVE
        #if KAPENGINE_THREAD_ACTIVE
            _mutex.unlock();
        #endif
    #endif
    #if KAPENGINE_DEBUG_ACTIVE
        getCurrentScene().dump(true);
        DEBUG_WARNING("Changing scene to scene " + getSceneName(index));
    #endif
    PROFILER_FUNC_END();
}

std::string KapEngine::SceneManagement::SceneManager::getSceneName(std::size_t index) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == index) {
            PROFILER_FUNC_END();
            return _scenes[i]->getName();
        }
    }
    PROFILER_FUNC_END();
    throw Errors::SceneError("Scene id: " + std::to_string(index) + " does not exists");
}

KapEngine::SceneManagement::Scene &KapEngine::SceneManagement::SceneManager::getScene(std::string const& sceneName) {
    PROFILER_FUNC_START();
    if (!sceneExists(sceneName)) {
        PROFILER_FUNC_END();
        throw Errors::SceneError("Scene " + sceneName + " does not exists");
    }
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getName() == sceneName) {
            PROFILER_FUNC_END();
            return *_scenes[i];
        }
    }
    throw Errors::SceneError("Unknown error while getting scene");
}

KapEngine::SceneManagement::Scene &KapEngine::SceneManagement::SceneManager::getScene(std::size_t const& index) {
    return getScene(getSceneName(index));
}

KapEngine::SceneManagement::Scene &KapEngine::SceneManagement::SceneManager::getCurrentScene() {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _scenes.size(); i++) {
        if (_scenes[i]->getId() == _indexScene) {
            PROFILER_FUNC_END();
            return *_scenes[i];
        }
    }
    PROFILER_FUNC_END();
    throw Errors::SceneError("Unknown error while getting current scene");
}

std::shared_ptr<KapEngine::SceneManagement::Scene> KapEngine::SceneManagement::SceneManager::createScene(std::string const& name) {
    PROFILER_FUNC_START();
    std::shared_ptr<Scene> nScene = std::make_shared<Scene>(*this, name);

    addScene(nScene);
    PROFILER_FUNC_END();
    return nScene;
}
