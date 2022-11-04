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
#include "Colors.hpp"
#include "Rectangle.hpp"

#include <functional>

namespace KapEngine {
    class KEngine;
    class Entity;

    namespace Events {
        class Key;
        class Input;
    }

    namespace Graphical {
        class GraphicalLibManager;
    }

    namespace Tools {
        class Color;
        class Vector2;
        class Rectangle;
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
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _name;
                }

                //inputs
                virtual float getJoystikValue(int gamepadId, int joystickId) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return 0.0f;
                }

                std::vector<Events::Key> getNewKeys() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _newPressedInputs;
                }
                std::vector<Events::Key> getKeysPressed() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _pressedInputs;
                }
                std::vector<Events::Key> getKeysReleased() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _releasedInputs;
                }

                virtual Tools::Vector2 getMousePosition() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
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
                virtual void setMusicVolume(float volume) {}

                virtual void playSound(std::string const& soundPath) {}
                void setSoundVolume(float volume) {
                    PROFILER_FUNC_START();
                    _soundVolume = volume;
                    PROFILER_FUNC_END();
                }

                virtual void drawRectangle(Tools::Vector2 const& position, Tools::Vector2 const& size, Tools::Color const& color) {}
                virtual void drawRectangle(Tools::Rectangle rectangle, Tools::Color const& color, float rotation) {}

                //graphical call

                void setDrawText(std::function<void(UI::Text &)> f) {
                    PROFILER_FUNC_START();
                    _drawText = f;
                    PROFILER_FUNC_END();
                }
                void setDrawImage(std::function<void(UI::Image &)> f) {
                    PROFILER_FUNC_START();
                    _drawImage = f;
                    PROFILER_FUNC_END();
                }

                void drawText(UI::Text &txt) {
                    PROFILER_FUNC_START();
                    _drawText(txt);
                    PROFILER_FUNC_END();
                }
                void drawImage(UI::Image &img) {
                    PROFILER_FUNC_START();
                    _drawImage(img);
                    PROFILER_FUNC_END();
                }

            protected:
                std::vector<Events::Key> _newPressedInputs;
                std::vector<Events::Key> _pressedInputs;
                std::vector<Events::Key> _releasedInputs;
                std::string _name;
                GraphicalLibManager &manager;

                std::function<void(UI::Text &)> _drawText;
                std::function<void(UI::Image &)> _drawImage;

                float _soundVolume = 1.f;

        };

    }
}

#endif /* !GRAPHICALLIB_HPP_ */
