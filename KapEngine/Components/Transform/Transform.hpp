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

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    class Transform : public Component {
        public:
            Transform(std::shared_ptr<GameObject> go);
            ~Transform();

            void onStart() override;

            void setPosition(Tools::Vector3 pos);
            void setRotation(Tools::Vector3 rot);
            void setScale(Tools::Vector3 scale);

            Tools::Vector3 getLocalPosition() const;
            Tools::Vector3 getLocalRotation() const;
            Tools::Vector3 getLocalScale() const;

            Tools::Vector3 getWorldPosition();
            Tools::Vector3 getWorldRotation();
            Tools::Vector3 getWorldScale();

            void moveTo(Tools::Vector3 dest, float time);

        protected:
        private:
            Tools::Vector3 _pos;
            Tools::Vector3 _rot;
            Tools::Vector3 _scale;

            Tools::Vector3 _startPos;
            Tools::Vector3 _startRot;
            Tools::Vector3 _startScale;

            Tools::Vector3 getParentPos();
            Tools::Vector3 getParentRot();
            Tools::Vector3 getParentScale();
    };

}

#endif /* !TRANSFORM_HPP_ */
