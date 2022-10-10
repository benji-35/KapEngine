/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** PrefabManager
*/

#ifndef PREFABMANAGER_HPP_
#define PREFABMANAGER_HPP_

#include "Engine.hpp"
#include "Dictionary.hpp"
#include <functional>
#include <memory>
#include <string>

namespace KapEngine {
    class KEngine;
    class GameObject;
    class Component;

    namespace SceneManagement {
        class Scene;
    }
}

namespace KapEngine {
namespace Prefabs {
    class PrefabManager {
        private:
        KapEngine& _engine;

        using Prefab = std::function<std::shared_ptr<GameObject>(SceneManagement::Scene&)>;
        Dictionary<std::string, std::shared_ptr<Prefab>> _prefabs;

        public:
        PrefabManager(KapEngine& engine);
        ~PrefabManager() = default;

        void createPrefab(std::string const& name, Prefab hander);

        bool instantiatePrefab(std::string const& name, SceneManagement::Scene& scene, std::shared_ptr<GameObject>& gameObject);

        bool instantiatePrefab(std::string const& name, std::size_t sceneId, std::shared_ptr<GameObject>& gameObject);

        void removePrefab(std::string const& name);
    };
}
}

#endif
