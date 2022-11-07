/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** UiImage
*/

#ifndef UIIMAGE_HPP_
#define UIIMAGE_HPP_

#include "Vectors.hpp"
#include "Colors.hpp"
#include "Rectangle.hpp"

#include "Component.hpp"
#include <filesystem>

#include "KapEngineSettings.hpp"


namespace KapEngine {

    class Component;

    namespace Tools {
        class Color;
        class Vector2;
    }
}

namespace KapEngine {

    namespace UI {

        class Image : public Component {
            public:
                Image(std::shared_ptr<GameObject> &go);
                ~Image();

                void onAwake() override;
                void onDisplay() override;
                bool checkComponentValidity() override;

                bool isUsingSprite() const {
                    PROFILER_FUNC_START();
                    if (_pathSprite == "") {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    return true;
                }

                std::string getPathSprite() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _pathSprite;
                }

                Tools::Color getColorSprite() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _color;
                }

                void setPathSprite(std::string const& pathSprite) {
                    PROFILER_FUNC_START();
                    _pathSprite = pathSprite;
                    PROFILER_FUNC_END();
                }

                void setPathSpriteRoot(std::string const& pathSprite) {
                    PROFILER_FUNC_START();
                    _pathSprite = std::filesystem::current_path().generic_string() + "/" + pathSprite;
                    PROFILER_FUNC_END();
                }

                void setColor(Tools::Color const& color) {
                    PROFILER_FUNC_START();
                    _color = color;
                    PROFILER_FUNC_END();
                }

                void setRectangle(Tools::Rectangle rect) {
                    PROFILER_FUNC_START();
                    _rect = rect;
                    PROFILER_FUNC_END();
                }

                Tools::Vector2 getCalculatedPosition();

                Tools::Vector2 getCalculatedScale();

                Tools::Rectangle getRectangle() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _rect;
                }

            protected:
            private:
                std::string _pathSprite = "";
                Tools::Color _color;
                Tools::Rectangle _rect;
                Tools::Vector2 _lastScale;
                Tools::Vector2 _lastCompare;
                Tools::Vector2 _lastPos;
                Tools::Vector2 _lastScaleWant;
                Tools::Vector2 _lastPosWant;
        };

    }

}

#endif /* !UIIMAGE_HPP_ */
