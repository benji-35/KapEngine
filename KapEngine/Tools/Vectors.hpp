/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Vectors
*/

#ifndef VECTORS_HPP_
#define VECTORS_HPP_

#include <string>

namespace KapEngine {
    namespace Tools {
        class Vector2;
        class Vector3;
    }
}

namespace KapEngine {

    namespace Tools {

        class Vector2 {

            public:
                Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                Vector2(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = vec;
                    PROFILER_FUNC_END();
                }
                ~Vector2() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                void setX(float _x) {
                    PROFILER_FUNC_START();
                    x = _x;
                    PROFILER_FUNC_END();
                }
                void setY(float _y) {
                    PROFILER_FUNC_START();
                    y = _y;
                    PROFILER_FUNC_END();
                }

                float getX() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return x;
                }
                float getY() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return y;
                }

                Vector2 operator+(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(getX() + vec.getX(), y + vec.getY());
                }

                Vector2 operator+(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x + f, y + f);
                }

                Vector2 operator+(Vector3 const& vec);


                Vector2 &operator+=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this + vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator+=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this + f;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator+=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this + vec;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector2 operator-(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x - vec.getX(), y - vec.getY());
                }

                Vector2 operator-(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x - f, y - f);
                }

                Vector2 operator-(Vector3 const& vec);


                Vector2 &operator-=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this - vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator-=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this - f;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator-=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this - vec;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector2 operator*(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x * vec.getX(), y * vec.getY());
                }

                Vector2 operator*(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x * f, y * f);
                }

                Vector2 operator*(Vector3 const& vec);


                Vector2 &operator*=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this * vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator*=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this * f;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator*=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this * vec;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector2 operator/(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x / vec.getX(), y / vec.getY());
                }

                Vector2 operator/(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(x / f, y / f);
                }

                Vector2 operator/(Vector3 const& vec);


                Vector2 &operator/=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this / vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator/=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this / f;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator/=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this / vec;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector2 &operator=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    x = vec.getX();
                    y = vec.getY();
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector2 &operator=(Vector3 const& vec);

                bool operator==(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    if (vec.getX() != x) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (vec.getY() != y) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    return true;
                }

                bool operator!=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return !(*this == vec);
                }

                static Vector2 zero() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(0.f, 0.f);
                }

                static Vector2 one() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector2(1.f, 1.f);
                }

                std::string to_string() const {
                    PROFILER_FUNC_START();
                    std::string res = "{";

                    res += std::to_string(x) + "; ";
                    res += std::to_string(y) + "}";

                    PROFILER_FUNC_END();
                    return res;
                }

            private:
                float x = 0.0f;
                float y = 0.0f;
        };

        class Vector3 {

            public:
                Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                Vector3(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = vec;
                    PROFILER_FUNC_END();
                }
                ~Vector3() {}

                void setX(float _x) {
                    PROFILER_FUNC_START();
                    x = _x;
                    PROFILER_FUNC_END();
                }
                void setY(float _y) {
                    PROFILER_FUNC_START();
                    y = _y;
                    PROFILER_FUNC_END();
                }
                void setZ(float _z) {
                    PROFILER_FUNC_START();
                    z = _z;
                    PROFILER_FUNC_END();
                }

                float getX() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return x;
                }
                float getY() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return y;
                }
                float getZ() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return z;
                }

                Vector3 operator+(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x + vec.getX(), y + vec.getY(), z + vec.getZ());
                }

                Vector3 operator+(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x + f, y + f, z + f);
                }

                Vector3 operator+(Vector2 const& vec);


                Vector3 &operator+=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this + vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator+=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this + vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator+=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this + f;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector3 operator-(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x - vec.getX(), y - vec.getY(), z - vec.getZ());
                }

                Vector3 operator-(Vector2 const& vec);

                Vector3 operator-(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x - f, y - f, z - f);
                }


                Vector3 &operator-=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this - vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator-=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this - vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator-=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this - f;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector3 operator*(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x * vec.getX(), y * vec.getY(), z * vec.getZ());
                }

                Vector3 operator*(Vector2 const& vec);

                Vector3 operator*(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x * f, y * f, z * f);
                }


                Vector3 &operator*=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this * vec;
                    PROFILER_FUNC_END();
                    return *this;
                }
                
                Vector3 &operator*=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this * vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator*=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this * f;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector3 operator/(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x / vec.getX(), y / vec.getY(), z / vec.getZ());
                }

                Vector3 operator/(Vector2 const& vec);

                Vector3 operator/(float const& f) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(x / f, y / f, z / f);
                }


                Vector3 &operator/=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this / vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator/=(Vector2 const& vec) {
                    PROFILER_FUNC_START();
                    *this = *this / vec;
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator/=(float const& f) {
                    PROFILER_FUNC_START();
                    *this = *this / f;
                    PROFILER_FUNC_END();
                    return *this;
                }


                Vector3 &operator=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    x = vec.getX();
                    y = vec.getY();
                    z = vec.getZ();
                    PROFILER_FUNC_END();
                    return *this;
                }

                Vector3 &operator=(Vector2 const& vec);


                bool operator==(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    if (vec.getX() != x) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (vec.getY() != y) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (vec.getZ() != z) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    return true;
                }

                bool operator!=(Vector3 const& vec) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return !(*this == vec);
                }

                static Vector3 zero() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(0.f, 0.f, 0.f);
                }

                static Vector3 one() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Vector3(1.f, 1.f, 1.f);
                }

                std::string to_string() const {
                    PROFILER_FUNC_START();
                    std::string res = "{";

                    res += std::to_string(x) + "; ";
                    res += std::to_string(y) + "; ";
                    res += std::to_string(z) + "}";

                    PROFILER_FUNC_END();
                    return res;
                }

            private:
                float x = 0.0f;
                float y = 0.0f;
                float z = 0.0f;
        };

    }

}

#endif /* !VECTORS_HPP_ */
