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

namespace KapEngine {
    class GameObject;

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
            Component(std::shared_ptr<GameObject> &go, std::string const& name, int threadRunning = 2);
            ~Component();

            /**
             * @warning Do not call this function
             * @brief function call by KapEngine to update your component
             */
            void __update();

            /**
             * @warning Do not call this function
             * @brief function call by KapEngine to init your component
             */
            bool __setId(std::size_t i) {
                if (_id != 0)
                    return false;
                _id = i;
                return true;
            }
            
            /**
             * @fn GameObject &getGameObject()
             * @brief Get the Game Object object
             * @throw KapEngine::Errors::ComponentError if the object does not exist in scene
             * @return GameObject& 
             */
            GameObject &getGameObject();

            /**
             * @brief 
             * 
             */
            GameObject &getGameObjectConst() const;

            //updates functions
            virtual void onInit() override {}
            virtual void onAwake() override {}
            virtual void onStart() override {}
            virtual void onUpdate() override {}
            virtual void onFixedUpdate() override {}

            virtual void onDisplay() override {}

            virtual void onTriggerEnter() override {}
            virtual void onTriggerStay() override {}
            virtual void onTriggerExit() override {}

            virtual void onMouseEnter() override {}
            virtual void onMouseStay() override {}
            virtual void onMouseExit() override {}

            /**
             * @fn std::size_t getLevel() const
             * the level gives call priority to the component. The higher the level, the sooner it will be updated
             * @brief Get the Level component
             * 
             * @return std::size_t 
             */
            std::size_t getLevel() const {
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
                _level = lvl;
            }

            bool isEnable() const {
                return _enable;
            }

            bool isDisable() const {
                return !_enable;
            }

            void setActive(bool b) {
                _enable = b;
            }

            std::string getName() const {
                return _name;
            }

            void __engineStop() {
                _go.reset();
            }

            int getThreadRunning() const {
                return threadRunning;
            }

            Events::Input getInput();
            Events::Mouse getMouse();

        protected:
            /**
             * @brief Component name
             */
            std::string _name;
        private:
            int threadRunning = 2;
            std::size_t _id = 0;
            std::size_t _level = 0;
            std::shared_ptr<GameObject> _go;
            bool _enable = true;
            bool _awakeDone = false;
            bool _startDone = false;
            void __fixedUpdate();
            void __awake();
            void __start();
    };

}

#endif /* !COMPONENT_HPP_ */
