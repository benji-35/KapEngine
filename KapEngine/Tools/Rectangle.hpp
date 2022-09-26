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
                void setX(float x);
                void setPosX(float x) {
                    setX(x);
                }
                void setY(float y);
                void setPosY(float y) {
                    setY(y);
                }

                void setSize(float width, float heigth);
                void setSize(Vector2 const& size);
                void setW(float w);
                void setWidth(float w) {
                    setW(w);
                }
                void setH(float h);
                void setHeigth(float h) {
                    setH(h);
                }

                Vector2 getPos() const {
                    return _pos;
                }

                Vector2 getSize() const {
                    return _size;
                }

                std::string to_string() const;

            protected:
            private:
                Vector2 _pos;
                Vector2 _size;
        };

    }

}

#endif /* !RECTANGLE_HPP_ */
