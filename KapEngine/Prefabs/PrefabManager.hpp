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
    /**
     * @namespace KapEngine::Prefab
     * This namespace regroup all things about prefabs
     * @brief All things about prefabs
     */
    namespace Prefabs {
        class PrefabManager {
            private:
            KEngine &_engine;

            using Prefab = std::function<std::shared_ptr<GameObject>(SceneManagement::Scene&, const std::string&)>;
            Dictionary<std::string, std::shared_ptr<Prefab>> _prefabs;

            public:
            explicit PrefabManager(KEngine &engine);
            ~PrefabManager() = default;

            /**
             * @brief Create a prefab
             * @param name The name of the prefab
             * @param hander The handler of the prefab (the function that will be called when the prefab is instantiated)
             */
            void createPrefab(std::string const& name, const Prefab& hander);

            /**
             * @brief Instantiate a prefab
             * @param name The name of the prefab
             * @param scene The scene where the prefab will be instantiated
             * @param gameObject The game object that will be instantiated
             */
            bool instantiatePrefab(std::string const& name, SceneManagement::Scene& scene, std::shared_ptr<GameObject>& gameObject);

            /**
             * @brief Instantiate a prefab
             * @param name The name of the prefab
             * @param sceneId The id of the scene where the prefab will be instantiated
             * @param gameObject The game object that will be instantiated
             * @param components The components that will be added to the game object
             */
            bool instantiatePrefab(std::string const& name, std::size_t const& sceneId, std::shared_ptr<GameObject>& gameObject);

            /**
             * @brief Destroy a prefab
             * @param name The name of the prefab
             */
            void removePrefab(std::string const& name);
        };
    }
}

#endif
