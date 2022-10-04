/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "Component.hpp"
#include "Vectors.hpp"
#include <any>

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    class Transform : public Component {
        public:
            Transform(std::shared_ptr<GameObject> go);
            ~Transform();

            void onAwake() override;
            void onDisplay() override;

            void setPosition(Tools::Vector3 pos);
            void setRotation(Tools::Vector3 rot);
            void setScale(Tools::Vector3 scale);

            Tools::Vector3 getLocalPosition() const;
            Tools::Vector3 getLocalRotation() const;
            Tools::Vector3 getLocalScale() const;

            Tools::Vector3 getWorldPosition() const;
            Tools::Vector3 getWorldRotation() const;
            Tools::Vector3 getWorldScale() const;

            void moveTo(Tools::Vector3 dest, float time);

            void setParent(std::size_t id);
            void setParent(std::any val);
            bool allParentIsActive();
            std::size_t getParentId() const;
            Entity getParentEntity() const;

            /**
             * @brief Get the Parent GameObject
             * @return std::shared_ptr<KapEngine::GameObject>
             */
            std::shared_ptr<GameObject> getParent() const;

            /**
             * @brief Get the Children of gameObject
             * @return std::vector<std::shared_ptr<KapEngine::GameObject>> 
             */
            std::vector<std::shared_ptr<GameObject>> getChildren();

            /**
             * @brief check parent contain a specific component
             * @param componentName name of component research
             * @param recurcively execute this action if component did not find on parent
             * @return true if parent contains component
             * @return false if object does not have parent or parent does not have component
             */
            bool parentContainsComponent(std::string const& componentName, bool recurcively = false);

            /**
             * @brief check parent contain specific components
             * 
             * @param componentsName list of components's name research
             * @param recurcively execute this action if components did not find on parent
             * @return true if parent contains components
             * @return false if object does not have parent or parent does not have components
             */
            bool parentContainsComponents(std::vector<std::string> componentsName, bool recurcively = false);

            /**
             * @brief Get the Parent Contains Component recurcively
             * 
             * @param componentName name of component to find
             * @return std::size_t 
             */
            std::size_t getParentContainsComponent(std::string const& componentName);

            /**
             * @brief check if all parents are active
             * 
             * @return true if all parents are active
             * @return false if one of parents is not active
             */
            bool allParentsActive() const;

            /**
             * @brief check if transform changed since last update
             * @return true 
             * @return false 
             */
            bool hasChanged() const;

        protected:
        //variables
        private:
            Tools::Vector3 _pos;
            Tools::Vector3 _rot;
            Tools::Vector3 _scale;

            //start values
            Tools::Vector3 _startPos;
            Tools::Vector3 _startRot;
            Tools::Vector3 _startScale;

            //update values
            Tools::Vector3 _updatePos;
            Tools::Vector3 _updateRot;
            Tools::Vector3 _updateScale;

            Tools::Vector3 getParentPos() const;
            Tools::Vector3 getParentRot() const;
            Tools::Vector3 getParentScale() const;

            std::size_t _parentId = 0;
            bool _awkaeTr = false;

    };

}

#endif /* !TRANSFORM_HPP_ */
