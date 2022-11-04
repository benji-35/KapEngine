/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Canvas
*/

#ifndef UICANVAS_HPP_
#define UICANVAS_HPP_

#include "Component.hpp"

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    namespace UI {

        class Canvas : public Component {
            public:
                enum ResizyngType {
                    PIXEL_CONSTANT,
                    RESIZE_WITH_SCREEN
                };

            public:
                Canvas(std::shared_ptr<GameObject> &go);
                ~Canvas();

                void setResizeType(ResizyngType r) {
                    PROFILER_FUNC_START();
                    _resize = r;
                    PROFILER_FUNC_END();
                }

                void setScreenCompare(Tools::Vector2 screenSizeCompare) {
                    PROFILER_FUNC_START();
                    _screenSizeCompare = screenSizeCompare;
                    PROFILER_FUNC_END();
                }

                ResizyngType getResizeType() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _resize;
                }

                Tools::Vector2 getScreenSizeCompare() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _screenSizeCompare;
                }

                bool checkComponentValidity() override;

            protected:
            private:
                ResizyngType _resize = ResizyngType::PIXEL_CONSTANT;
                Tools::Vector2 _screenSizeCompare;
        };

    }

}

#endif /* !UICANVAS_HPP_ */
