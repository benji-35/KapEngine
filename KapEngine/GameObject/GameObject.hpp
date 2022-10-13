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
#include "Type.hpp"

namespace KapEngine {

    class Component;
    class KEngine;
    class Entity;

    namespace SceneManagement {
        class Scene;
    }
}

#include <vector>
#include <memory>
#include <string>
#include <typeinfo>

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

            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            T &getComponent(std::string const& componentName) {
                return dynamic_cast<T &>(getComponent(componentName));
            }

            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            T &getComponent() {
                std::size_t hash = Type::getHashCode<T>();
                for (std::size_t i = 0; i < _components.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_components[i]);
                    if (_components[i] && componentHash == hash)
                        return dynamic_cast<T &>(*_components[i]);
                }
                for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_componentsRun[i]);
                    if (_componentsRun[i] && componentHash == hash)
                        return dynamic_cast<T &>(*_componentsRun[i]);
                }
                throw Errors::GameObjectError("No component found");
            }

            bool hasComponent(std::string const& componentName) const;

            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            bool hasComponent() const {
                std::size_t hash = Type::getHashCode<T>();
                for (std::size_t i = 0; i < _components.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_components[i]);
                    if (_components[i] && componentHash == hash)
                        return true;
                }
                for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_componentsRun[i]);
                    if (_componentsRun[i] && componentHash == hash)
                        return true;
                }
                return false;
            }

            KEngine &getEngine();

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
            void __onSceneUpdated();

            void dump(bool displayComponent = false, std::string prefix = "");

            std::vector<std::shared_ptr<Component>> getAllComponents() const;

            void destroy();

            void __setPrefab(std::string const& name);

            std::string getPrefabName() const {
                return _prefabName;
            }

            /**
             * @brief Set the Name of GameObject
             * 
             * @param name 
             */
            void setName(std::string const& name) {
                _name = name;
            }

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
            std::string _prefabName;
    };

}

#endif /* !GAMEOBJECT_HPP_ */
