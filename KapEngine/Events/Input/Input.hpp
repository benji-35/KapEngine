/*
** EPITECH PROJECT, 2022
** cpp_sfmlV2
** File description:
** Input
*/

/**
* @file Input.hpp
* fichier contenant les fonctions permettant la prise d'information sur les inputs
* @author Benjamin Delvert
* @date 2022
* @version 1.0
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <vector>
#include "Key.hpp"
#include "EventManager.hpp"

namespace KapEngine {
    namespace Events {
        class Key;
        class EventManager;
    }
}

namespace KapEngine {
    namespace Events
    {
        /**
         * @class Input
         * Input is made to know action of input while game is running
         * @brief Input actions
         */
        class Input {
            public:

                /**
                 * @brief axis mode detection
                 * 
                 */
                enum AxisDetectMode {
                    UNKNOWN,
                    GET,
                    DOWN,
                    UP
                };

                /**
                 * @struct Axis
                 * Axis allow you to have several inputs for a specific action like vertical move with W ans S.
                 * @brief 
                 * @param name axis name
                 * @param positiveButton input giving value 1
                 * @param altPositiveButton alternative input giving value 1
                 * @param negativeButton input giving value -1
                 * @param altNegativeButton alternative input giving value -1
                 * @param joystickId joystick index of gamepad (if joystick set to -1 then no joystick is assigned)
                 * @param gamepadId gamepad index. If 1 joystoick is defined but gamepad is set to -1, then all gamepad gonna be checked (2 gamepads)
                 * @param invert invert result
                 */
                struct Axis {
                    std::string name;
                    Key positiveButton;
                    Key negativeButton;
                    Key altPositiveButton;
                    Key altNegativeButton;

                    AxisDetectMode detectMode;

                    int joystickId;
                    int gamepadId;

                    bool invert;

                    Axis(std::string _name) {
                        PROFILER_FUNC_START();
                        gamepadId = -1;
                        joystickId = -1;
                        positiveButton = Key::UNKNOWN;
                        negativeButton = Key::UNKNOWN;
                        altPositiveButton = Key::UNKNOWN;
                        altNegativeButton = Key::UNKNOWN;
                        invert = false;
                        name = _name;
                        detectMode = AxisDetectMode::GET;
                        PROFILER_FUNC_END();
                    }
                };

                Input(EventManager &manager);
                ~Input() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                /**
                 * @fn void __update()
                 * @brief update inputs
                 * @warning Do not call this function
                 */
                void __update();

                /**
                 * @fn bool getKey(Key::EKey key)
                 * Knows if an action occured on a specifics input
                 * @brief input action
                 * @param key KapEngine::Events::Key::Ekey (enum) key
                 * @retval true if an action occured
                 * @retval false if no action occured
                 */
                bool getKey(Key::EKey key);
                /**
                 * @fn bool getKeyDown(Key::EKey key)
                 * knows if key is just pressed
                 * @brief key pressed
                 * @param key KapEngine::Events::Key::Ekey (enum) key
                 * @retval true if action occured
                 * @retval false if no action occured
                 */
                bool getKeyDown(Key::EKey key);
                /**
                 * @fn bool getKeyUp(Key::EKey key)
                 * knows if key is just released
                 * @brief key released
                 * @param key KapEngine::Events::Key::Ekey (enum) key
                 * @retval true if an action occured
                 * @retval false if no action occured
                 */
                bool getKeyUp(Key::EKey key);

                /**
                 * @fn bool getKey(Key key)
                 * Knows if an action occured on a specifics input
                 * @brief input action
                 * @param key KapEngine::Events::Key
                 * @retval true if an action occured
                 * @retval false if no action occured
                 */
                bool getKey(Key key);
                /**
                 * @fn bool getKeyDown(Key key)
                 * knows if key is just pressed
                 * @brief key pressed
                 * @param key KapEngine::Events::Key key
                 * @retval true if action occured
                 * @retval false if no action occured
                 */
                bool getKeyDown(Key key);
                /**
                 * @fn bool getKeyUp(Key key)
                 * knows if key is just released
                 * @brief key released
                 * @param key KapEngine::Events::Key
                 * @retval true if an action occured
                 * @retval false if no action occured
                 */
                bool getKeyUp(Key key);
                /**
                 * @fn float getAxis(std::string name)
                 * get axis value. If axis not found then value is 0
                 * @brief get axis value
                 * 
                 * @param name axis name
                 * @return float (betwenn 1 and -1)
                 */
                float getAxis(std::string name);

                /**
                 * @fn void addAxis(std::string name)
                 * add empty axis
                 * @brief add new axis
                 * @param name axis name
                 */
                void addAxis(std::string name) {
                    PROFILER_FUNC_START();
                    _axises.push_back(Axis(name));
                    PROFILER_FUNC_END();
                }

                /**
                 * @fn void addAxis(Axis const& axis)
                 * add axis you defined
                 * @brief add new axis
                 * @param axis axis
                 */
                void addAxis(Axis const& axis) {
                    PROFILER_FUNC_START();
                    _axises.push_back(axis);
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief Get the Axis
                 * 
                 * @param name axis name
                 * @return KapEngine::Events::Input::Axis Axis& 
                 */
                Axis &getAxisSettings(std::string const& name) {
                    PROFILER_FUNC_START();
                    for (std::size_t i = 0; i < _axises.size(); i++) {
                        if (_axises[i].name == name) {
                            PROFILER_FUNC_END();
                            return _axises[i];
                        }
                    }
                    PROFILER_FUNC_END();
                    throw Errors::EngineError("Axis \"" + name + "\" not found");
                }

            protected:
            private:
                bool _pressed = false;
                bool _realesed = false;
                EventManager &_manager;

                std::vector<Key> _justInputs;
                std::vector<Key> _inputs;
                std::vector<Key> _outInputs;

                std::vector<Axis> _axises;
        };
    }
}

#endif /* !INPUT_HPP_ */
