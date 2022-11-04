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
                Rectangle() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                Rectangle(float x, float y, float w, float h) {
                    PROFILER_FUNC_START();
                    setPos(x, y);
                    setSize(w, h);
                    PROFILER_FUNC_END();
                }
                Rectangle(Vector2 const& pos, Vector2 const& size) {
                    PROFILER_FUNC_START();
                    setPos(pos);
                    setSize(size);
                    PROFILER_FUNC_END();
                }
                ~Rectangle() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                void setPos(float x, float y);
                void setPos(Vector2 const& pos);
                void setX(float x);
                void setPosX(float x) {
                    PROFILER_FUNC_START();
                    setX(x);
                    PROFILER_FUNC_END();
                }
                void setY(float y);
                void setPosY(float y) {
                    PROFILER_FUNC_START();
                    setY(y);
                    PROFILER_FUNC_END();
                }

                void setSize(float width, float heigth);
                void setSize(Vector2 const& size);
                void setW(float w);
                void setWidth(float w) {
                    PROFILER_FUNC_START();
                    setW(w);
                    PROFILER_FUNC_END();
                }
                void setH(float h);
                void setHeigth(float h) {
                    PROFILER_FUNC_START();
                    setH(h);
                    PROFILER_FUNC_END();
                }

                Vector2 getPos() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _pos;
                }

                Vector2 getSize() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _size;
                }

                float getX() const;
                float getY() const;
                float getWidth() const;
                float getHeigth() const;

                std::string to_string() const;

            protected:
            private:
                Vector2 _pos;
                Vector2 _size;
        };

    }

}

#endif /* !RECTANGLE_HPP_ */
