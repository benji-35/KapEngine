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
#include "Entity.hpp"

namespace KapEngine {

    class Component;
    class KapEngine;
    class Entity;

    namespace SceneManagement {
        class Scene;
    }
}

#include <vector>
#include <memory>
#include <string>

namespace KapEngine {

    class GameObject : public Entity {
        public:
            GameObject(SceneManagement::Scene &scene, std::string const& name);
            ~GameObject();

            //all function can be called by dev

            //actions with components
            void addComponent(std::shared_ptr<Component> comp);
            void removeComponent(std::shared_ptr<Component> comp);
            void removeComponent(std::size_t id);

            Component &getComponent(std::string const& componentName);

            template<typename T>
            T &getComponent(std::string const& componentName) {
                return dynamic_cast<T &>(getComponent(componentName));
            }

            bool hasComponent(std::string const& componentName) const;

            KapEngine &getEngine();

            //all functions call by engine
            void __update();

            void setActive(bool b);

            bool isActive() const {
                return _active;
            }
            bool isDestroyed() const {
                return _destroyed;
            }

            SceneManagement::Scene &getScene() {
                return _scene;
            }

            SceneManagement::Scene &getSceneConst() const {
                return _scene;
            }

            Component &getTransform();

            void __engineStop();

            std::string getName() const {
                return _name;
            }

            Entity &getEntity() const {
                return (Entity &)*this;
            }

            void __destroyIt();
            void __init();
            void __stoppingGame();

            void dump(int tab = 0);

            std::vector<std::shared_ptr<Component>> getAllComponents() const;

        protected:
        private:
            std::string _name;
            bool _active = true;
            bool _startActive = true;
            bool _destroyed = false;
            bool _firstUpdateDone = false;
            std::vector<std::shared_ptr<Component>> _components;
            std::vector<std::shared_ptr<Component>> _componentsRun;
            SceneManagement::Scene &_scene;
            std::size_t _idComp = 0;
    };

}

#endif /* !GAMEOBJECT_HPP_ */
