/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Vectors.hpp"

namespace KapEngine {
    namespace Tools {
        class Vector2;
    }
}

namespace KapEngine {

    namespace Tools {

        class Rectangle {
            public:
                Rectangle() {}
                Rectangle(float x, float y, float w, float h) {
                    setPos(x, y);
                    setSize(w, h);
                }
                Rectangle(Vector2 const& pos, Vector2 const& size) {
                    setPos(pos);
                    setSize(size);
                }
                ~Rectangle() {}

                void setPos(float x, float y);
                void setPos(Vector2 const& pos);

                void setSize(float width, float heigth);
                void setSize(Vector2 const& size);

                Vector2 getPos() const {
                    return _pos;
                }

                Vector2 getSize() const {
                    return _size;
                }

            protected:
            private:
                Vector2 _pos;
                Vector2 _size;
        };

    }

}

#endif /* !RECTANGLE_HPP_ */
