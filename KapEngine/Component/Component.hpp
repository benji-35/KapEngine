/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "GameObject.hpp"

namespace KapEngine {
    class GameObject;
}

#include <memory>
#include <vector>
#include <string>

namespace KapEngine {

    class Component {
        public:
            Component(std::shared_ptr<GameObject> &go, std::string const& name);
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

            //updates functions
            virtual void onInit() {}
            virtual void onAwake() {}
            virtual void onStart() {}
            virtual void onUpdate() {}
            virtual void onFixedUpdate() {}

            virtual void onDisplay() {}

            virtual void onTriggerEnter() {}
            virtual void onTriggerStay() {}
            virtual void onTriggerExit() {}

            virtual void onMouseEnter() {}
            virtual void onMouseStay() {}
            virtual void onMouseExit() {}

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

        protected:
            /**
             * @brief Component name
             */
            std::string _name;
        private:
            std::size_t _id = 0;
            std::size_t _level = 0;
            std::shared_ptr<GameObject> _go;
            bool _enable = true;
            void __fixedUpdate();
            void __awake();
            void __start();
    };

}

#endif /* !COMPONENT_HPP_ */
