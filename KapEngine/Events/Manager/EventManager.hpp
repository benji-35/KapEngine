/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "KapEngine.hpp"

namespace KapEngine {

    class KapEngine;

    namespace Events {
        class Input;
        class Mouse;
    }
}

namespace KapEngine {
    namespace Events {
        /**
         * @class EventManager
         * Gère et met à jours les évenements de l'engine
         * @brief gestionnaire des évenements
         */
        class EventManager {
            public:
                EventManager(KapEngine &engine);
                ~EventManager() {}

                /**
                 * @fn KapEngine &getEngine()
                 * @brief Avoir l'engine
                 * @return KapEngine&
                 */
                KapEngine &getEngine() {
                    return _engine;
                }
                /**
                 * @fn Input &getInput()
                 * @brief Avoir les informations de l'input
                 * @return Input&
                 */
                Input &getInput() {
                    return *_input;
                }
                /**
                 * @fn Mouse &getMouse()
                 * @brief Avoir les informations de la souris
                 * @return Mouse&
                 */
                Mouse &getMouse() {
                    return *_mouse;
                }

                /**
                 * @fn void __update()
                 * @brief mettre à jour
                 * @warning Ne pas utiliser cette fonction. Elle est appelé par l'engine
                 */
                void __update();

            protected:
            private:
                std::shared_ptr<Input> _input;
                std::shared_ptr<Mouse> _mouse;
                KapEngine &_engine;
        };
    }
}

#endif /* !EVENTMANAGER_HPP_ */
