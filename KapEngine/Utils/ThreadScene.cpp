/*
** EPITECH PROJECT, 2022
** engine
** File description:
** ThreadScene
*/

#include "ThreadScene.hpp"
#include "KapEngineDebug.hpp"

void KapEngine::ThreadScene::__threadRunning(ThreadScene *scene) {
    for (auto go : scene->_gos) {
        if (go.use_count() == 0) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("GameObject is not initialized");
            #endif
        } else {
            go->__update(false);
        }
    }
}

void KapEngine::ThreadScene::join() {
    _thread->join();
}

void KapEngine::ThreadScene::run() {
    _thread = std::make_shared<std::thread>(&ThreadScene::__threadRunning, this);
}

void KapEngine::ThreadScene::addGameObject(std::shared_ptr<GameObject> go) {
    _gos.push_back(go);
}
