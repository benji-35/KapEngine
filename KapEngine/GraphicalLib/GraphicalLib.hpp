/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLib
*/

#ifndef GRAPHICALLIB_HPP_
#define GRAPHICALLIB_HPP_

#include "Engine.hpp"
#include "Input.hpp"
#include "Vectors.hpp"
#include "Entity.hpp"

#include <functional>

namespace KapEngine {
    class KapEngine;
    class Entity;

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

    namespace UI {
        class Image;
        class Text;
    }

}

namespace KapEngine {

    namespace Graphical {

        class GraphicalLib : public Entity {
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

                std::vector<Events::Key> getNewKeys() const {
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

                virtual void clearCache() {}

                virtual void stopDisplay() {}

                virtual void startDisplay() {}

                virtual Tools::Vector2 getScreenSize();

                virtual void playMusic(std::string const& musicPath, float volume = 1.0f) {}
                virtual void stopMusic() {}
                virtual void pauseMusic() {}
                virtual void resumMusic() {}
                virtual void restartMusic() {}

                virtual void playSound(std::string const& soundPath);

                //graphical call

                void setDrawText(std::function<void(UI::Text &)> f) {
                    _drawText = f;
                }
                void setDrawImage(std::function<void(UI::Image &)> f) {
                    _drawImage = f;
                }

                void drawText(UI::Text &txt) {
                    _drawText(txt);
                }
                void drawImage(UI::Image &img) {
                    _drawImage(img);
                }

            protected:
                std::vector<Events::Key> _newPressedInputs;
                std::vector<Events::Key> _pressedInputs;
                std::vector<Events::Key> _releasedInputs;
                std::string _name;
                GraphicalLibManager &manager;

                std::function<void(UI::Text &)> _drawText;
                std::function<void(UI::Image &)> _drawImage;

        };

    }
}

#endif /* !GRAPHICALLIB_HPP_ */
