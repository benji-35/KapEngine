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

            protected:
            private:
        };

    }

}

#endif /* !UIIMAGE_HPP_ */
