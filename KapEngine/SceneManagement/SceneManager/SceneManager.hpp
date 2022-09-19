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
    class KapEngine;

    namespace SceneManagement {
        class Scene;
    }
}

namespace KapEngine {

    namespace SceneManagement {

        class SceneManager {
            public:
                SceneManager(KapEngine &engine);
                ~SceneManager();

                void addScene(std::shared_ptr<Scene> scene);
                void addScene(std::string const& sceneName);

                void removeScene(std::string const& sceneName);
                void removeScene(std::size_t id);

                void loadScene(std::size_t index);
                void loadScene(std::string const& sceneName);

                void __update(int threadId = 0);

                KapEngine &getEngine() {
                    return _engine;
                }

                bool sceneExists(std::size_t index);
                bool sceneExists(std::string const& sceneName);

                Scene &getScene(std::string const& name);
                Scene &getCurrentScene();

            protected:
            private:
                std::size_t _indexScene = 0;
                std::vector<std::shared_ptr<Scene>> _scenes;
                KapEngine &_engine;

                std::size_t getSceneIndex(std::string const& sceneName);
                std::size_t getSceneIndexInList(std::size_t id);
                std::size_t getSceneIndexInList(std::string const& sceneName);

                std::string getSceneName(std::size_t index);

        };

    }

}

#endif /* !SCENEMANAGER_HPP_ */
