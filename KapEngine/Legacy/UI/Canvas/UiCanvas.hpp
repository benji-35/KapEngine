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
                enum resizyngType {
                    PIXEL_CONSTANT,
                    RESIZE_WITH_SCREEN
                };

            public:
                Canvas(std::shared_ptr<GameObject> &go);
                ~Canvas();

                void setResizeType(resizyngType r) {
                    _resize = r;
                }

                void setScreenCompare(Tools::Vector2 screenSizeCompare) {
                    _screenSizeCompare = screenSizeCompare;
                }

                resizyngType getResizeType() const {
                    return _resize;
                }

                Tools::Vector2 getScreenSizeCompare() const {
                    return _screenSizeCompare;
                }

                bool checkComponentValidity() override;

            protected:
            private:
                resizyngType _resize = resizyngType::PIXEL_CONSTANT;
                Tools::Vector2 _screenSizeCompare;
        };

    }

}

#endif /* !UICANVAS_HPP_ */
