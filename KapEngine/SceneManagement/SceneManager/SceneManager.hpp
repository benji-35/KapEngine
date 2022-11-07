/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <vector>
#include <memory>
#include "Scene.hpp"

namespace KapEngine {
    class KEngine;

    namespace SceneManagement {
        class Scene;
    }
}

namespace KapEngine {
    /**
     * @namespace KapEngine::SceneManagement
     * This namespace regroup all things about scene management (Scenes, SceneManager, ...)
     * @brief All things about scene management
     */
    namespace SceneManagement {

        class SceneManager {
            public:
                SceneManager(KEngine &engine);
                ~SceneManager();

                void addScene(std::shared_ptr<Scene> scene);
                void addScene(std::string const& sceneName);

                void removeScene(std::string const& sceneName);
                void removeScene(std::size_t id);

                void loadScene(std::size_t index);
                void loadScene(std::string const& sceneName);

                void __update();

                KEngine &getEngine() {
                    return _engine;
                }

                bool sceneExists(std::size_t index);
                bool sceneExists(std::string const& sceneName);

                Scene &getScene(std::string const& name);
                Scene &getScene(std::size_t const& index);
                Scene &getCurrentScene();

                std::size_t getSceneIndex(std::string const& sceneName);
                std::size_t getSceneIndexInList(std::size_t id);
                std::size_t getSceneIndexInList(std::string const& sceneName);

                std::size_t getCurrentSceneId() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _indexScene;
                }

                std::shared_ptr<Scene> createScene(std::string const& name);

                std::vector<std::shared_ptr<Scene>> &getAllScenes() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _scenes;
                }

            protected:
            private:
                std::size_t _indexScene = 0;
                std::size_t _maxIndex = 0;
                std::vector<std::shared_ptr<Scene>> _scenes;
                KEngine &_engine;

                std::string getSceneName(std::size_t index);

                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        std::mutex _mutex;
                    #endif
                #endif

        };

    }

}

#endif /* !SCENEMANAGER_HPP_ */
