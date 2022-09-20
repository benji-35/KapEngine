/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLib
*/

#ifndef GRAPHICALLIB_HPP_
#define GRAPHICALLIB_HPP_

#include "KapEngine.hpp"
#include "Input.hpp"
#include "Vectors.hpp"

namespace KapEngine {
    class KapEngine;

    namespace Events {
        class Key;
        class Input;
    }

    namespace Graphical {
        class GraphicalLibManager;
    }

    namespace Tools {
        class Vector2;
    }
}

namespace KapEngine {

    namespace Graphical {

        class GraphicalLib {
            public:
                GraphicalLib(std::string const& name, GraphicalLibManager &manager);
                ~GraphicalLib();

                //updates things
                virtual void clear();
                virtual void display();
                virtual void getEvents();

                //back system call
                std::string getName() const {
                    return _name;
                }

                //inputs
                virtual float getJoystikValue(int gamepadId, int joystickId) {
                    return 0.0f;
                }

                std::vector<Events::Key> getLatsKey() const {
                    return _newPressedInputs;
                }
                std::vector<Events::Key> getKeysPressed() const {
                    return _pressedInputs;
                }
                std::vector<Events::Key> getKeysReleased() const {
                    return _releasedInputs;
                }

                virtual Tools::Vector2 getMousePosition() const {
                    Tools::Vector2 res;

                    return res;
                }

                //graphical call

            protected:
                std::vector<Events::Key> _newPressedInputs;
                std::vector<Events::Key> _pressedInputs;
                std::vector<Events::Key> _releasedInputs;
                std::string _name;
                GraphicalLibManager &manager;

        };

    }
}

#endif /* !GRAPHICALLIB_HPP_ */
