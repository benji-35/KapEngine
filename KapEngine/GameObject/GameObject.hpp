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

#if KAPENGINE_BETA_ACTIVE
    #if KAPENGINE_THREAD_ACTIVE
        #include <mutex>
    #endif
#endif

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

            /**
             * @brief add new component to GameObject
             * 
             * @param comp 
             */
            void addComponent(std::shared_ptr<Component> comp);
            /**
             * @brief remove component from its shared_ptr
             * 
             * @param comp 
             */
            void removeComponent(std::shared_ptr<Component> comp);
            /**
             * @brief remove component from its id
             * 
             * @param id 
             */
            void removeComponent(std::size_t id);

            /**
             * @brief Get the Component by its name
             * 
             * @param componentName 
             * @return Component& 
             * @deprecated
             */
            Component &getComponent(std::string const& componentName);

            /**
             * @brief Get the Component by its type
             * 
             * @tparam T 
             * @tparam typename 
             * @tparam T>::value> 
             * @param componentName 
             * @return T& 
             * @deprecated
             */
            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            T &getComponent(std::string const& componentName) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return dynamic_cast<T &>(getComponent(componentName));
            }
            /**
             * @brief Get the Component by its type
             * 
             * @tparam T 
             * @tparam typename 
             * @tparam T>::value>
             * @return T& 
             */
            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            T &getComponent() {
                std::size_t hash = Type::getHashCode<T>();
                for (std::size_t i = 0; i < _components.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_components[i]);
                    if (_components[i] && componentHash == hash) {
                        return dynamic_cast<T &>(*_components[i]);
                    }
                }
                for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_componentsRun[i]);
                    if (_componentsRun[i] && componentHash == hash) {
                        return dynamic_cast<T &>(*_componentsRun[i]);
                    }
                }
                throw Errors::GameObjectError("No component found");
            }
            /**
             * @brief Get the Components by there type
             * 
             * @tparam T 
             * @tparam typename 
             * @tparam T>::value>
             * @return std::vector<std::shared_ptr<T>> 
             */
            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            std::vector<std::shared_ptr<T>> getComponents() {
                PROFILER_FUNC_START();
                std::vector<std::shared_ptr<T>> components;
                std::size_t hash = Type::getHashCode<T>();
                for (std::size_t i = 0; i < _components.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_components[i]);
                    if (_components[i] && componentHash == hash)
                        components.push_back(std::dynamic_pointer_cast<T>(_components[i]));
                }
                for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_componentsRun[i]);
                    if (_componentsRun[i] && componentHash == hash)
                        components.push_back(std::dynamic_pointer_cast<T>(_componentsRun[i]));
                }
                PROFILER_FUNC_END();
                return components;
            }

            /**
             * @brief return if GameObject has component from its name
             * 
             * @param componentName 
             * @return true 
             * @return false 
             * @deprecated
             */
            bool hasComponent(std::string const& componentName) const;

            /**
             * @brief return if GameObject has component from its type
             * 
             * @tparam T 
             * @tparam typename 
             * @tparam T>::value> 
             * @return true 
             * @return false 
             */
            template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
            bool hasComponent() const {
                PROFILER_FUNC_START();
                std::size_t hash = Type::getHashCode<T>();
                for (std::size_t i = 0; i < _components.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_components[i]);
                    if (_components[i] && componentHash == hash) {
                        PROFILER_FUNC_END();
                        return true;
                    }
                }
                for (std::size_t i = 0; i < _componentsRun.size(); i++) {
                    std::size_t componentHash = Type::getHashCode(*_componentsRun[i]);
                    if (_componentsRun[i] && componentHash == hash) {
                        PROFILER_FUNC_END();
                        return true;
                    }
                }
                return false;
            }

            /**
             * @brief Get the Engine
             * 
             * @return KapEngine::KEngine& 
             */
            KEngine &getEngine();

            #if KAPENGINE_BETA_ACTIVE
                #if KAPENGINE_THREAD_ACTIVE
                    void __updatePhysics();
                    void __updateComponents();
                    void __updateDisplay();
                    void __updateFixed(Time::ETime fixed);
                #else
                    void __update();
                    /**
                     * @warning do not call this function
                     */
                    void __updateDisplay();
                #endif
            #else
                /**
                 * @warning do not call this function
                 */
                void __update(bool physics = false, bool runDisplay = true);
                /**
                 * @warning do not call this function
                 */
                void __updateDisplay();
            #endif

            /**
             * @brief Set the Active status of GameObject
             * 
             * @param b 
             */
            void setActive(bool b);
            /**
             * @brief return if GameObject is active
             * 
             * @return true 
             * @return false 
             */
            bool isActive() const {
                return _active;
            }
            /**
             * @brief return if GameObject is destroyed
             * 
             * @return true 
             * @return false 
             */
            bool isDestroyed() const {
                return _destroyed;
            }

            /**
             * @brief Get the Scene
             * 
             * @return SceneManagement::Scene &
             */
            SceneManagement::Scene &getScene() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _scene;
            }

            /**
             * @brief Get the Scene
             * 
             * @return SceneManagement::Scene & const
             */
            SceneManagement::Scene &getSceneConst() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _scene;
            }

            /**
             * @brief Get the Transform
             * @deprecated
             * @return Component& 
             */
            Component &getTransform();

            /**
             * @warning do not call this function
             */
            void __engineStop();

            /**
             * @brief Get GameObject Name
             * 
             * @return std::string 
             */
            std::string getName() const {
                return _name;
            }

            /**
             * @brief Get the Entity of GameObject
             * 
             * @return KapEngine::Entity& 
             */
            Entity &getEntity() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return (Entity &)*this;
            }

            /**
             * @warning do not call this function
             */
            void __destroyIt();
            /**
             * @warning do not call this function
             */
            void __init();
            /**
             * @warning do not call this function
             */
            void __stoppingGame();
            /**
             * @warning do not call this function
             */
            void __onSceneGonnaUpdated();
            /**
             * @warning do not call this function
             */
            void __onSceneUpdated();

            /**
             * @brief display GameObject in log
             * 
             * @param displayComponent 
             * @param prefix 
             */
            void dump(bool displayComponent = false, std::string prefix = "");

            /**
             * @brief Get the All Components of GameObject
             * 
             * @return std::vector<std::shared_ptr<KapEngine::Component>> 
             */
            std::vector<std::shared_ptr<Component>> getAllComponents() const;

            /**
             * @brief destroy the GameObject
             * 
             */
            void destroy();

            /**
             * @brief set prefab name
             * @warning do not use this function
             * @param name 
             */
            void __setPrefab(std::string const& name);

            /**
             * @brief Get the Prefab Name
             * 
             * @return std::string 
             */
            std::string getPrefabName() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _prefabName;
            }

            /**
             * @brief Set the Name of GameObject
             * 
             * @param name 
             */
            void setName(std::string const& name) {
                PROFILER_FUNC_START();
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.lock();
                    #endif
                #endif
                _name = name;
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.unlock();
                    #endif
                #endif
                PROFILER_FUNC_END();
            }

            /**
             * @brief Set the GameObject Tag
             * 
             * @param tag 
             */
            void setTag(std::string const& tag) {
                PROFILER_FUNC_START();
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.lock();
                    #endif
                #endif
                _tag = tag;
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.unlock();
                    #endif
                #endif
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the GameObject Tag
             * 
             * @return std::string 
             */
            std::string getTag() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _tag;
            }

            /**
             * @brief call when scene changed to another scene
             * @warning do not call this function
             */
            void __onSceneChanged();

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
            std::string _tag;
            #if KAPENGINE_BETA_ACTIVE
                #if KAPENGINE_THREAD_ACTIVE
                    std::mutex _mutex;
                #endif
            #endif
    };

}

#endif /* !GAMEOBJECT_HPP_ */
