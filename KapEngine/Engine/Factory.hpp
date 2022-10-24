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
                auto result = std::make_shared<GameObject>(scene, name);
                scene.addGameObject(result);

                auto transform = std::make_shared<Transform>(result);
                result->addComponent(transform);

                transform->setRotation(rot);
                transform->setPosition(pos);
                transform->setScale(scale);

                return result;
            }

            static std::shared_ptr<GameObject> createEmptyGameObject(std::shared_ptr<SceneManagement::Scene>scene, std::string const& name = "Empty", Tools::Vector3 pos = Tools::Vector3::zero(), Tools::Vector3 rot = Tools::Vector3::zero()) {
                return createEmptyGameObject(*scene, name, pos, rot);
            }

            /*
                CREATE CAMERA
            */

            static std::shared_ptr<GameObject> createCamera(SceneManagement::Scene &scene, std::string const& name = "Camera", Tools::Vector3 pos = {0, 0, 0}, Tools::Vector3 rot = {0, 0, 0}, Tools::Color bgColor = Tools::Color::blue()) {
                std::shared_ptr<GameObject> camera = createEmptyGameObject(scene, name);

                try {
                    auto &transform = camera->getComponent<Transform>();
                    transform.setPosition(pos);
                    transform.setRotation(rot);
                } catch(...) {}

                std::shared_ptr<Camera> camComp = std::make_shared<Camera>(camera);
                camComp->setBackgroundColor(bgColor);
                camera->addComponent(camComp);

                return camera;
            }

            static std::shared_ptr<GameObject> createCamera(std::shared_ptr<SceneManagement::Scene> scene, std::string const& name, Tools::Vector3 pos = {0, 0, 0}, Tools::Vector3 rot = {0, 0, 0}, Tools::Color bgColor = Tools::Color::blue()) {
                return createCamera(*scene, name, pos, rot, bgColor);
            }

            /*
                 CREATE SCENE
            */

            static std::shared_ptr<SceneManagement::Scene> createScene(KEngine &engine, std::string const& name) {
                return createScene(engine.getSceneManager(), name);
            }

            static std::shared_ptr<SceneManagement::Scene> createScene(std::shared_ptr<SceneManagement::SceneManager> manager, std::string const& name) {
                return createScene(*manager, name);
            }

            static std::shared_ptr<SceneManagement::Scene> createScene(SceneManagement::SceneManager &manager, std::string const& name) {
                auto nScene = std::make_shared<SceneManagement::Scene>(manager, name);
                manager.addScene(nScene);

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
