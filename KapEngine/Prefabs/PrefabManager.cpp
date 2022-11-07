#include "PrefabManager.hpp"

using namespace KapEngine::Prefabs;

PrefabManager::PrefabManager(KEngine &engine) : _engine(engine) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
};

void PrefabManager::createPrefab(std::string const& name, Prefab hander) {
    PROFILER_FUNC_START();
    _prefabs[name] = std::make_shared<Prefab>(hander);
    PROFILER_FUNC_END();
}

bool PrefabManager::instantiatePrefab(std::string const& name, SceneManagement::Scene& scene, std::shared_ptr<GameObject>& gameObject) {
    PROFILER_FUNC_START();
    std::shared_ptr<Prefab> handler;
    if (_prefabs.tryGetValue(name, handler)) {
        gameObject = (*handler)(scene);
        gameObject->__setPrefab(name);
        PROFILER_FUNC_END();
        return true;
    }
    PROFILER_FUNC_END();
    return false;
}

bool PrefabManager::instantiatePrefab(std::string const& name, std::size_t const& sceneId, std::shared_ptr<GameObject>& gameObject) {
    std::size_t idToCheck = sceneId;
    PROFILER_FUNC_START();
    try {
        auto &scene = _engine.getSceneManager()->getScene(idToCheck);
        PROFILER_FUNC_END();
        return instantiatePrefab(name, scene, gameObject);
    } catch(...) {
        PROFILER_FUNC_END();
        return false;
    }
}

void PrefabManager::removePrefab(std::string const& name) {
    PROFILER_FUNC_START();
    _prefabs.remove(name);
    PROFILER_FUNC_END();
}
