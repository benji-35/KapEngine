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
                Text(std::shared_ptr<GameObject> &go);
                ~Text();

            protected:
            private:
        };

    }

}

#endif /* !UITEXT_HPP_ */
