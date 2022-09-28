/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Text
*/

#ifndef UITEXT_HPP_
#define UITEXT_HPP_

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

        class Text : public Component {
            public:
                Text(std::shared_ptr<GameObject> &go, std::string const& textContent = "");
                ~Text();

                void setFont(std::string const& fontPath) {
                    _pathFont = fontPath;
                }

                void setText(std::string const& text) {
                    _content = text;
                }

                void setTextColor(Tools::Color const& color) {
                    _color = color;
                }

                void setSpace(float space) {
                    _space = space;
                }

                void setPoliceSize(float police) {
                    _police = police;
                }

                std::string getFontPath() const {
                    return _pathFont;
                }

                std::string getText() const {
                    return _content;
                }

                Tools::Color getColor() const {
                    return _color;
                }

                float getSpace() const {
                    return _space;
                }

                float getPoliceSize() const {
                    return _police;
                }

                void onDisplay() override;
                bool checkComponentValidity() override;

            protected:
            private:
                float _space = 0.5f;
                float _police = 15.0f;
                Tools::Color _color;
                std::string _content = "";
                std::string _pathFont = "";
        };

    }

}

#endif /* !UITEXT_HPP_ */
