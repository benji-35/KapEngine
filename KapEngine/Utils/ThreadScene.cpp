/*
** EPITECH PROJECT, 2022
** engine
** File description:
** ThreadScene
*/

#include "ThreadScene.hpp"
#include "KapEngineDebug.hpp"

void KapEngine::ThreadScene::__threadRunning(ThreadScene *scene) {
    PROFILER_FUNC_START();
    for (auto go : scene->_gos) {
        if (go.use_count() == 0) {
            #if KAPENGINE_DEBUG_ACTIVE
                DEBUG_ERROR("GameObject is not initialized");
            #endif
        } else {
            go->__update(false);
        }
    }
    PROFILER_FUNC_END();
}

void KapEngine::ThreadScene::join() {
    PROFILER_FUNC_START();
    _thread->join();
    PROFILER_FUNC_END();
}

void KapEngine::ThreadScene::run() {
    PROFILER_FUNC_START();
    _thread = std::make_shared<std::thread>(&ThreadScene::__threadRunning, this);
    PROFILER_FUNC_END();
}

void KapEngine::ThreadScene::addGameObject(std::shared_ptr<GameObject> go) {
    PROFILER_FUNC_START();
    _gos.push_back(go);
    PROFILER_FUNC_END();
}
