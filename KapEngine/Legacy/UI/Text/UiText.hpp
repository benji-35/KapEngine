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
                    PROFILER_FUNC_START();
                    _pathFont = fontPath;
                    PROFILER_FUNC_END();
                }

                void setText(std::string const& text) {
                    PROFILER_FUNC_START();
                    _content = text;
                    PROFILER_FUNC_END();
                }

                void setTextColor(Tools::Color const& color) {
                    PROFILER_FUNC_START();
                    _color = color;
                    PROFILER_FUNC_END();
                }

                void setSpace(float space) {
                    PROFILER_FUNC_START();
                    _space = space;
                    PROFILER_FUNC_END();
                }

                void setPoliceSize(float police) {
                    PROFILER_FUNC_START();
                    _police = police;
                    PROFILER_FUNC_END();
                }

                std::string getFontPath() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _pathFont;
                }

                std::string getText() const {
                    return _content;
                }

                Tools::Color getColor() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _color;
                }

                float getSpace() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _space;
                }

                float getPoliceSize() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _police;
                }

                void onAwake() override;
                void onDisplay() override;
                bool checkComponentValidity() override;

                Tools::Vector2 getCalculatedPos();
                Tools::Vector2 getCalculatedScale();

            protected:
            private:
                float _space = 0.5f;
                float _police = 15.0f;
                Tools::Color _color;
                std::string _content = "";
                std::string _pathFont = "";
                Tools::Vector2 _lastScale;
                Tools::Vector2 _lastCompare;
                Tools::Vector2 _lastPos;
                Tools::Vector2 _lastScaleWant;
                Tools::Vector2 _lastPosWant;
        };

    }

}

#endif /* !UITEXT_HPP_ */
