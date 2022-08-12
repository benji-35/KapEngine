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

namespace KapEngine {

    class Factory {
        public:

            /*
                Create empty GameObject
            */

            static std::shared_ptr<GameObject> createEmptyGameObject(SceneManagement::Scene &scene, std::string const& name) {
                std::shared_ptr<GameObject> result = std::make_shared<GameObject>(scene, name);

                result->addComponent(std::make_shared<Transform>(result));

                scene.addGameObject(result);
                return result;
            }

            static std::shared_ptr<GameObject> createEmptyGameObject(SceneManagement::Scene &scene, std::string const& name, Tools::Vector3 pos, Tools::Vector3 rot) {
                std::shared_ptr<GameObject> result;
                try {
                    result = createEmptyGameObject(scene, name, pos);

                    Transform &transform = (Transform &)result->getComponent("Transform");
                    transform.setRotation(rot);
                } catch (...) {
                    throw Errors::EngineError("GameObject created cannot set position");
                }
                return result;
            }
            
            static std::shared_ptr<GameObject> createEmptyGameObject(SceneManagement::Scene &scene, std::string const& name, Tools::Vector3 pos) {
                std::shared_ptr<GameObject> result = createEmptyGameObject(scene, name);

                try {
                    Transform &transform = (Transform &)result->getComponent("Transform");

                    transform.setPosition(pos);

                } catch (...) {
                    throw Errors::EngineError("GameObject created cannot set position");
                }

                return result;
            }


            static std::shared_ptr<GameObject> createEmptyGameObject(std::shared_ptr<SceneManagement::Scene> scene, std::string const& name) {
                return createEmptyGameObject(*scene, name);
            }

            static std::shared_ptr<GameObject> createEmptyGameObject(std::shared_ptr<SceneManagement::Scene>scene, std::string const& name, Tools::Vector3 pos, Tools::Vector3 rot) {
                return createEmptyGameObject(*scene, name, pos, rot);
            }
            
            static std::shared_ptr<GameObject> createEmptyGameObject(std::shared_ptr<SceneManagement::Scene>scene, std::string const& name, Tools::Vector3 pos) {
                return createEmptyGameObject(*scene, name, pos);
            }

            /*
                CREATE CAMERA
            */

            static std::shared_ptr<GameObject> createCamera(SceneManagement::Scene &scene, std::string const& name, Tools::Vector3 pos, Tools::Vector3 rot, Tools::Color bgColor) {

            }

            /*
                 CREATE SCENE
            */

            /*
                  CREATE CUBE
            */

        protected:
        private:
    };

}

#endif /* !FACTORY_HPP_ */
