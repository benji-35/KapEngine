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

bool PrefabManager::instantiatePrefab(std::string const& name, std::size_t sceneId, std::shared_ptr<GameObject>& gameObject) {
    PROFILER_FUNC_START();
    auto scene = _engine.getSceneManager()->getScene(sceneId);
    if (scene == nullptr) {
        PROFILER_FUNC_END();
        return false;
    }
    PROFILER_FUNC_END();
    return instantiatePrefab(name, scene, gameObject);
}

void PrefabManager::removePrefab(std::string const& name) {
    PROFILER_FUNC_START();
    _prefabs.remove(name);
    PROFILER_FUNC_END();
}
