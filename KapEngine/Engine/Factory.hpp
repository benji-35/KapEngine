/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "GameObject.hpp"
#include "Vectors.hpp"
#include "Colors.hpp"
#include "Transform.hpp"
#include "Camera.hpp"

namespace KapEngine {

    class Factory {
        public:

            /*
                Create empty GameObject
            */

            static std::shared_ptr<GameObject> createEmptyGameObject(SceneManagement::Scene &scene, std::string const& name = "Empty", Tools::Vector3 pos = Tools::Vector3::zero(), Tools::Vector3 rot = Tools::Vector3::zero(), Tools::Vector3 scale = Tools::Vector3::one()) {
                PROFILER_FUNC_START();
                auto result = std::make_shared<GameObject>(scene, name);
                scene.addGameObject(result);

                auto transform = std::make_shared<Transform>(result);
                result->addComponent(transform);

                transform->setRotation(rot);
                transform->setPosition(pos);
                transform->setScale(scale);

                PROFILER_FUNC_END();
                return result;
            }

            static std::shared_ptr<GameObject> createEmptyGameObject(std::shared_ptr<SceneManagement::Scene>scene, std::string const& name = "Empty", Tools::Vector3 pos = Tools::Vector3::zero(), Tools::Vector3 rot = Tools::Vector3::zero()) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return createEmptyGameObject(*scene, name, pos, rot);
            }

            /*
                CREATE CAMERA
            */

            static std::shared_ptr<GameObject> createCamera(SceneManagement::Scene &scene, std::string const& name = "Camera", Tools::Vector3 pos = {0, 0, 0}, Tools::Vector3 rot = {0, 0, 0}, Tools::Color bgColor = Tools::Color::blue()) {
                PROFILER_FUNC_START();
                std::shared_ptr<GameObject> camera = createEmptyGameObject(scene, name);

                try {
                    auto &transform = camera->getComponent<Transform>();
                    transform.setPosition(pos);
                    transform.setRotation(rot);
                } catch(...) {}

                std::shared_ptr<Camera> camComp = std::make_shared<Camera>(camera);
                camComp->setBackgroundColor(bgColor);
                camera->addComponent(camComp);

                PROFILER_FUNC_END();
                return camera;
            }

            static std::shared_ptr<GameObject> createCamera(std::shared_ptr<SceneManagement::Scene> scene, std::string const& name, Tools::Vector3 pos = {0, 0, 0}, Tools::Vector3 rot = {0, 0, 0}, Tools::Color bgColor = Tools::Color::blue()) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return createCamera(*scene, name, pos, rot, bgColor);
            }

            /*
                 CREATE SCENE
            */

            static std::shared_ptr<SceneManagement::Scene> createScene(KEngine &engine, std::string const& name) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return createScene(engine.getSceneManager(), name);
            }

            static std::shared_ptr<SceneManagement::Scene> createScene(std::shared_ptr<SceneManagement::SceneManager> manager, std::string const& name) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return createScene(*manager, name);
            }

            static std::shared_ptr<SceneManagement::Scene> createScene(SceneManagement::SceneManager &manager, std::string const& name) {
                PROFILER_FUNC_START();
                auto nScene = std::make_shared<SceneManagement::Scene>(manager, name);
                manager.addScene(nScene);

                PROFILER_FUNC_END();
                return nScene;
            }

            /*
                  CREATE CUBE
            */

        protected:
        private:
    };

}

#endif /* !FACTORY_HPP_ */
