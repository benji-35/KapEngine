/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Engine.hpp"

namespace KapEngine {

    class KEngine;

    namespace Events {
        class Input;
        class Mouse;
    }

}

namespace KapEngine {
    /**
     * @namespace KapEngine::Events
     * This namespace regroup all events system that can be called by the engine and components
     * @brief All events from engine
     */
    namespace Events {
        /**
         * @class EventManager
         * Manage all events from engine
         * @brief Event manager
         */
        class EventManager {
            public:
                EventManager(KEngine &engine);
                ~EventManager() {}

                /**
                 * @fn KEngine &getEngine()
                 * @brief Get the engine
                 * @return KapEngine::KEngine &
                 */
                KEngine &getEngine() {
                    return _engine;
                }

                /**
                 * @fn Input &getInput()
                 * @brief Get input intels
                 * @return KapEngine::Events::Input &
                 */
                Input &getInput() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return *_input;
                }

                /**
                 * @fn Mouse &getMouse()
                 * @brief Get mouse intels
                 * @return KapEngine::Events::Mouse &
                 */
                Mouse &getMouse() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return *_mouse;
                }

                /**
                 * @fn void __update()
                 * @brief update event manager
                 * @warning Do not use this function, it will be called by the engine
                 */
                void __update();

            protected:
            private:
                std::shared_ptr<Input> _input;
                std::shared_ptr<Mouse> _mouse;
                KEngine &_engine;
        };
    }
}

#endif /* !EVENTMANAGER_HPP_ */
