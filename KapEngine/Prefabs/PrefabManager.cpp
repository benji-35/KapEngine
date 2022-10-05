#include "PrefabManager.hpp"

using namespace KapEngine::Prefabs;

PrefabManager::PrefabManager(KapEngine& engine) : _engine(engine) {};

void PrefabManager::createPrefab(std::string const& name, Prefab hander) {
    _prefabs[name] = std::make_shared<Prefab>(hander);
}

bool PrefabManager::instantiatePrefab(std::string const& name, SceneManagement::Scene& scene, std::shared_ptr<GameObject>& gameObject) {
    std::shared_ptr<Prefab> handler;
    if (_prefabs.tryGetValue(name, handler)) {
        gameObject = (*handler)(scene);
        gameObject->__setPrefab(name);
        return true;
    }
    return false;
}

bool PrefabManager::instantiatePrefab(std::string const& name, std::size_t sceneId, std::shared_ptr<GameObject>& gameObject) {
    auto scene = _engine.getSceneManager()->getScene(sceneId);
    if (scene == nullptr) {
        return false;
    }
    return instantiatePrefab(name, scene, gameObject);
}

void PrefabManager::removePrefab(std::string const& name) {
    _prefabs.remove(name);
}
