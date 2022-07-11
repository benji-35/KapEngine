/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include "Component.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

namespace KapEngine {

    class Component;
    class KapEngine;

    namespace SceneManagement {
        class Scene;
    }
}

#include <vector>
#include <memory>
#include <string>

namespace KapEngine {

    class GameObject {
        public:
            GameObject(SceneManagement::Scene &scene, std::string const& name);
            ~GameObject();

            //all function can be called by dev

            //actions with components
            void addComponent(std::shared_ptr<Component> comp);
            void removeComponent(std::shared_ptr<Component> comp);
            void removeComponent(std::size_t id);

            Component &getComponent(std::string const& name);

            KapEngine &getEngine();

            std::size_t getId() const {
                return _id;
            }

            //all functions call by engine
            void __update();

            void setActive(bool b) {
                _active = b;
            }

            bool isActive() const {
                return _active;
            }
            bool isDestroyed() const {
                return _destroyed;
            }

            bool allParentsActive() const;

            std::shared_ptr<GameObject> getParent() const;

            SceneManagement::Scene &getScene() {
                return _scene;
            }

        protected:
        private:
            std::string _name;
            bool _active = true;
            bool _destroyed = false;
            std::size_t _id = 0;
            std::size_t _parentId = 0;
            std::vector<std::shared_ptr<Component>> _components;
            SceneManagement::Scene &_scene;

    };

}

#endif /* !GAMEOBJECT_HPP_ */
