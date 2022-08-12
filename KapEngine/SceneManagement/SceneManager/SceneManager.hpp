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
                void loadScene(std::string sceneName);

            protected:
            private:
                std::size_t indexScene = 0;
                std::vector<std::shared_ptr<Scene>> _scenes;
                KapEngine &_engine;
        };

    }

}

#endif /* !SCENEMANAGER_HPP_ */
