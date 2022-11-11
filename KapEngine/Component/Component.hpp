/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "GameObject.hpp"
#include "IComponent.hpp"
#include "Input.hpp"
#include "Mouse.hpp"
#include "Profiler/KapProfiler.hpp"

namespace KapEngine {
    class GameObject;
    class Transform;

    namespace Events {
        class Input;
        class Mouse;
    }
}

#include <memory>
#include <vector>
#include <string>

namespace KapEngine {

    class Component : public IComponent {
        public:
            Component(std::shared_ptr<GameObject> &go, std::string const& name);
            Component(GameObject &go, std::string const& name);
            ~Component();

            /**
             * @warning Do not call this function
             * @brief function call by KapEngine to update your component
             */
            void __update(bool runDisplay = true);

            /**
             * @warning Do not call this function
             * @brief function call by KapEngine to init your component
             */
            bool __setId(std::size_t i) {
                PROFILER_FUNC_START();
                if (_id != 0) {
                    PROFILER_FUNC_END();
                    return false;
                }
                _id = i;
                PROFILER_FUNC_END();
                return true;
            }

            /**
             * @fn GameObject &getGameObject()
             * @brief Get the Game Object object
             * @throw KapEngine::Errors::ComponentError if the object does not exist in scene
             * @return KapEngine::GameObject &
             */
            GameObject &getGameObject() const;
            std::size_t getGameObjectId() const { return _idGameObject; }

            //updates functions
            virtual void onInit() override {}
            virtual void onAwake() override {}
            virtual void onStart() override {}
            virtual void onUpdate() override {}
            virtual void onFixedUpdate() override {}

            virtual void onDisplay() override {}

            virtual void onTriggerEnter(std::shared_ptr<GameObject> go) override {}
            virtual void onTriggerStay(std::shared_ptr<GameObject> go) override {}
            virtual void onTriggerExit(std::shared_ptr<GameObject> go) override {}

            virtual void onMouseEnter() override {}
            virtual void onMouseStay() override {}
            virtual void onMouseExit() override {}

            virtual bool checkComponentValidity() override {
                return true;
            }

            virtual void onGameQuit() override {}
            virtual void onDestroy() override {}
            virtual void onDisable() override {}
            virtual void onEnable() override {}

            virtual void onSceneUpdated() override {}
            virtual void onSceneGonnaUpdated() override {}
            virtual void onSceneChanged() override {}

            /**
             * @fn std::size_t getLevel() const
             * the level gives call priority to the component. The higher the level, the sooner it will be updated
             * @brief Get the Level component
             *
             * @return std::size_t
             */
            std::size_t getLevel() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _level;
            }
            /**
             * @fn void setLevel(std::size_t lvl)
             * the level gives call priority to the component. The higher the level, the sooner it will be updated
             * @brief Set the Level object
             *
             * @param lvl
             */
            void setLevel(std::size_t lvl) {
                PROFILER_FUNC_START();
                _level = lvl;
                PROFILER_FUNC_END();
            }

            /**
             * @brief return if component is enable
             *
             * @return true
             * @return false
             */
            bool isEnable() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _enable;
            }

            /**
             * @brief return if component is disbale
             *
             * @return true
             * @return false
             */
            bool isDisable() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return !_enable;
            }

            /**
             * @brief Set the active status of component
             * if true : component is active else component is disable
             * @param b
             */
            void setActive(bool b) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                _enable = b;
            }

            /**
             * @brief Get the component name
             * @return std::string
             */
            std::string getName() const {
                return _name;
            }

            /**
             * @warning Do not call this fucntion. Engine will do
             */
            void __engineStop() {
                PROFILER_FUNC_START();
                _idGameObject = 0;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the Thread Running index
             * index of thread component
             * @return int
             */
            int getThreadRunning() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return threadRunning;
            }

            /**
             * @brief Get input events
             * @return KapEngine::Events::Input
             */
            Events::Input getInput();
            /**
             * @brief Get mouse events
             * @return KapEngine::Events::Mouse
             */
            Events::Mouse getMouse();

            /**
             * @brief Add require component
             * If your component need another component to work, you can add it's name with this function. Without the component require this component cannot run
             * @param componentName
             */
            void addRequireComponent(std::string const& componentName) {
                PROFILER_FUNC_START();
                _componentsNeeded.push_back(componentName);
                PROFILER_FUNC_END();
            }

            /**
             * @warning Do not touch or call this function. Your game can be destruct by modifications
             */
            void __fixedUpdate();

            /**
             * @brief check awake validity
             * @warning Do not call by your selves. KapEngine will call it itself
             */
            void __awake();

            /**
             * @brief Get the Transform component
             * 
             * @return KapEngine::Transform& 
             */
            Transform &getTransform();

            /**
             * @brief Get the Id of component
             * 
             * @return std::size_t 
             */
            std::size_t getId() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _id;
            }

            /**
             * @brief set if it is a physic component
             * if component is a physic component then it will be updated in physic thread if engine is threaded
             * 
             * @param b 
             */
            void __setPhysics(bool b) {
                PROFILER_FUNC_START();
                _physics = b;
                PROFILER_FUNC_END();
            }

            /**
             * @brief check if component is a physic component
             * 
             * @return true 
             * @return false 
             */
            bool __isPhysics() const {
                return _physics;
            }

            void __sceneChanged() {
                PROFILER_FUNC_START();
                onSceneChanged();
                _awakeDone = false;
                _startDone = false;
                PROFILER_FUNC_END();
            }

            SceneManagement::Scene &getScene() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _scene;
            }

            KEngine &getEngine() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _engine;
            }

        protected:
            /**
             * @brief Component name
             */
            std::string _name;
        private:
            bool _physics = false;
            int threadRunning = 2;
            std::size_t _id = 0;
            std::size_t _level = 0;
            std::size_t _idGameObject = 0;
            bool _enable = true;
            bool _awakeDone = false;
            bool _startDone = false;
            void __start();
            std::vector<std::string> _componentsNeeded;
            SceneManagement::Scene &_scene;
            KEngine &_engine;

            bool __checkValidity();
    };

}

#endif /* !COMPONENT_HPP_ */
