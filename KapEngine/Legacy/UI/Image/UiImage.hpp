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

                void onDisplay() override;
                bool checkComponentValidity() override;

                bool isUsingSprite() const {
                    if (_pathSprite == "")
                        return false;
                    return true;
                }

                std::string getPathSprite() const {
                    return _pathSprite;
                }

                Tools::Color getColorSprite() const {
                    return _color;
                }

                void setPathSprite(std::string const& pathSprite) {
                    _pathSprite = pathSprite;
                }

                void setPathSpriteRoot(std::string const& pathSprite) {
                    std::string rt(std::filesystem::current_path().root_path().u8string());
                    _pathSprite = rt + pathSprite;
                }

                void setColor(Tools::Color const& color) {
                    _color = color;
                }

                void setRectangle(Tools::Rectangle rect) {
                    _rect = rect;
                }

                Tools::Vector2 getCalculatedPosition();

                Tools::Vector2 getCalculatedScale();

                Tools::Rectangle getRectangle() const {
                    return _rect;
                }

            protected:
            private:
                std::string _pathSprite = "";
                Tools::Color _color;
                Tools::Rectangle _rect;
        };

    }

}

#endif /* !UIIMAGE_HPP_ */
