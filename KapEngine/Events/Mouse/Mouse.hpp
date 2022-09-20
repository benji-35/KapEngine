/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include "Vectors.hpp"
#include "EventManager.hpp"

namespace KapEngine {

    namespace Events {
        class EventManager;
    }

    namespace Tools {
        class Vector2;
    }

}

namespace KapEngine {

    namespace Events {

        class Mouse {
            public:
                Mouse(EventManager &manager);
                ~Mouse();

                /**
                 * @fn void __update()
                 * @brief update intels
                 * @warning Do not use this function, it will be called by the engine
                 */
                void __update();

                /**
                 * @fn Tools::Vector2 getPosition() const
                 * @brief Get the Position of mouse
                 * @return KapEngine::Tools::Vector2 
                 */
                Tools::Vector2 getPosition() const {
                    return _mousePos;
                }

                /**
                 * @fn bool mouseMoved() const
                 * @brief get intel if mouse moved
                 * @retval true if mouse moved between now to last move
                 * @retval false if mouse does not move between now to last move
                 */
                bool mouseMoved() const {
                    return _mouseMoved;
                }

            protected:
            private:
                EventManager &manager;
                Tools::Vector2 _mousePos;
                bool _mouseMoved = false;;
        };

    }

}

#endif /* !MOUSE_HPP_ */
