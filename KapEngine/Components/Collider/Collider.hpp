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
#include <vector>

namespace KapEngine {

    class Collider : public Component {
        public:
            Collider(std::shared_ptr<GameObject> go, bool isTrigger = false, bool isMovable = false, bool isCanvas = false);
            ~Collider();

            void onUpdate() override;
            bool checkComponentValidity() override;
            void onSceneUpdated() override;

            /**
             * @brief Set the Trigger
             * 
             * @param isTrigger 
             */
            void setTrigger(bool isTrigger) {
                _isTrigger = isTrigger;
            }

            /**
             * @brief Set collider is in canvas
             * 
             * @param isInCanvas
             */
            void setInCanvas(bool isInCanvas) {
                _isInCanvas = isInCanvas;
            }

            /**
             * @brief get if collider is in canvas
             */
            bool isInCanvas() {
                return _isInCanvas;
            }

            /**
             * @brief get if collider is trigger
             * 
             * @return true 
             * @return false 
             */
            bool isTrigger() const {
                return _isTrigger;
            }

            /**
             * @brief get calculated rectangle
             * 
             */
            Tools::Rectangle getCalculatedRectangle() const;

            /**
             * @brief Get the Collided Objects object
             * 
             * @return std::vector<std::shared_ptr<Collider>> 
             */
            std::vector<std::shared_ptr<Collider>> getCollidedObjects() const {
                std::vector<std::shared_ptr<Collider>> result;

                for (std::size_t i = 0; i < _justCollidedObjects.size(); i++) {
                    result.push_back(_justCollidedObjects[i]);
                }
                for (std::size_t i = 0; i < _notCollidedObjects.size(); i++) {
                    result.push_back(_notCollidedObjects[i]);
                }

                return result;
            }

            void __callEnter(GameObject &go);
            void __callStay(GameObject &go);
            void __callExit(GameObject &go);

        protected:
        private:
            bool _isTrigger = false;
            bool _isInCanvas = false;

            Tools::Rectangle _boxCollider;

            //object just collide with this object
            std::vector<std::shared_ptr<Collider>> _justCollidedObjects;
            //object not collided but calculated
            std::vector<std::shared_ptr<Collider>> _notCollidedObjects;
            //object already collide with this object
            std::vector<std::shared_ptr<Collider>> _collidedObjects;

            bool __checkCollision(Tools::Rectangle const& rect);
            void __checkCollision(std::shared_ptr<GameObject> &go);
            bool __colliderAlreadyCollide(std::shared_ptr<Collider> &collider);
            bool __currentlyCollided(std::shared_ptr<Collider> &collider);
            bool __alreayCalculated(std::shared_ptr<Collider> &collider);

            Tools::Vector2 __recalculCanvas(Tools::Vector2 const& vector) const;
    };

}

#endif /* !COLLIDER_HPP_ */
