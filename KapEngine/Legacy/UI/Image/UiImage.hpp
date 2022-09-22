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

#include "Component.hpp"

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

                void setColor(Tools::Color const& color) {
                    _color = color;
                }

                Tools::Vector2 getCalculatedPosition() const;

                Tools::Vector2 getCalculatedScale() const;

            protected:
            private:
                std::string _pathSprite = "";
                Tools::Color _color;
        };

    }

}

#endif /* !UIIMAGE_HPP_ */
