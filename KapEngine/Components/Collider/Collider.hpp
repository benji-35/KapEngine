/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#ifndef COLLIDER_HPP_
#define COLLIDER_HPP_

#include "KapEngine.hpp"
#include "KapEngineDebug.hpp"

namespace KapEngine {

    class Collider : public Component {
        public:
            Collider(std::shared_ptr<GameObject> go, bool isTrigger = false, bool isMovable = false, bool isCanvas = false);
            ~Collider();

            void onUpdate() override;
            void onDisplay() override;
            bool checkComponentValidity() override;
            void onSceneUpdated() override;

            void setInCanvas(bool isInCanvas);
            void setTrigger(bool isTrigger);
            void setMovability(bool isMovable);

            void setCollisionBox(Tools::Rectangle const& collisionBox);

            void __addCalculatedCollider(Collider &_collider) {
                _calculatedColliders.push_back(_collider);
            }

            Tools::Rectangle getCollisionBox() const;

            bool isTrigger() const {
                return _isTrigger;
            }

            void __callTrigger(Collider &collided);
            void __callEndTrigger(Collider &collided);

            void setOffset(Tools::Vector2 const& offset) {
                _offset = offset;
            }

        protected:
        private:
            bool _isTrigger = false;
            bool _isInCanvas = false;
            bool _isMovable = false;
            Tools::Rectangle _collisionBox;
            Tools::Vector2 _offset;
            std::vector<Collider &> _calculatedColliders;
            std::vector<Collider &> _alreadyCollided;

            void calculateCollisions(std::shared_ptr<GameObject> object);
            void calculateCollisions(Collider & collider);
            void checkNotCollided();

            Tools::Vector2 calculSizeCanvas(Tools::Vector2 const& size) const;

            bool isColliding(Tools::Rectangle const collisionBox);
            bool isSavedCollided(Collider &collider);
    };

}

#endif /* !COLLIDER_HPP_ */
