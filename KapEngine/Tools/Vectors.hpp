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
                Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
                Vector2(Vector2 const& vec) {
                    *this = vec;
                }
                ~Vector2() {}

                void setX(float _x) {
                    x = _x;
                }
                void setY(float _y) {
                    y = _y;
                }

                float getX() const {
                    return x;
                }
                float getY() const {
                    return y;
                }

                Vector2 operator+(Vector2 const& vec) {
                    return Vector2(getX() + vec.getX(), y + vec.getY());
                }

                Vector2 operator+(float const& f) {
                    return Vector2(x + f, y + f);
                }

                Vector2 operator+(Vector3 const& vec);


                Vector2 &operator+=(Vector2 const& vec) {
                    *this = *this + vec;
                    return *this;
                }

                Vector2 &operator+=(float const& f) {
                    *this = *this + f;
                    return *this;
                }

                Vector2 &operator+=(Vector3 const& vec) {
                    *this = *this + vec;
                    return *this;
                }


                Vector2 operator-(Vector2 const& vec) {
                    return Vector2(x - vec.getX(), y - vec.getY());
                }

                Vector2 operator-(float const& f) {
                    return Vector2(x - f, y - f);
                }

                Vector2 operator-(Vector3 const& vec);


                Vector2 &operator-=(Vector2 const& vec) {
                    *this = *this - vec;
                    return *this;
                }

                Vector2 &operator-=(float const& f) {
                    *this = *this - f;
                    return *this;
                }

                Vector2 &operator-=(Vector3 const& vec) {
                    *this = *this - vec;
                    return *this;
                }


                Vector2 operator*(Vector2 const& vec) {
                    return Vector2(x * vec.getX(), y * vec.getY());
                }

                Vector2 operator*(float const& f) {
                    return Vector2(x * f, y * f);
                }

                Vector2 operator*(Vector3 const& vec);


                Vector2 &operator*=(Vector2 const& vec) {
                    *this = *this * vec;
                    return *this;
                }

                Vector2 &operator*=(float const& f) {
                    *this = *this * f;
                    return *this;
                }

                Vector2 &operator*=(Vector3 const& vec) {
                    *this = *this * vec;
                    return *this;
                }


                Vector2 operator/(Vector2 const& vec) {
                    return Vector2(x / vec.getX(), y / vec.getY());
                }

                Vector2 operator/(float const& f) {
                    return Vector2(x / f, y / f);
                }

                Vector2 operator/(Vector3 const& vec);


                Vector2 &operator/=(Vector2 const& vec) {
                    *this = *this / vec;
                    return *this;
                }

                Vector2 &operator/=(float const& f) {
                    *this = *this / f;
                    return *this;
                }

                Vector2 &operator/=(Vector3 const& vec) {
                    *this = *this / vec;
                    return *this;
                }


                Vector2 &operator=(Vector2 const& vec) {
                    x = vec.getX();
                    y = vec.getY();
                    return *this;
                }

                Vector2 &operator=(Vector3 const& vec);

                bool operator==(Vector2 const& vec) {
                    if (vec.getX() != x)
                        return false;
                    if (vec.getY() != y)
                        return false;
                    return true;
                }

                bool operator!=(Vector2 const& vec) {
                    return !(*this == vec);
                }

                static Vector2 zero() {
                    return Vector2(0.f, 0.f);
                }

                static Vector2 one() {
                    return Vector2(1.f, 1.f);
                }

                std::string to_string() const {
                    std::string res = "{";

                    res += std::to_string(x) + "; ";
                    res += std::to_string(y) + "}";

                    return res;
                }

            private:
                float x = 0.0f;
                float y = 0.0f;
        };

        class Vector3 {

            public:
                Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}
                Vector3(Vector3 const& vec) {
                    *this = vec;
                }
                ~Vector3() {}

                void setX(float _x) {
                    x = _x;
                }
                void setY(float _y) {
                    y = _y;
                }
                void setZ(float _z) {
                    z = _z;
                }

                float getX() const {
                    return x;
                }
                float getY() const {
                    return y;
                }
                float getZ() const {
                    return z;
                }

                Vector3 operator+(Vector3 const& vec) {
                    return Vector3(x + vec.getX(), y + vec.getY(), z + vec.getZ());
                }

                Vector3 &operator+=(Vector3 const& vec) {
                    *this = *this + vec;
                    return *this;
                }

                Vector3 operator-(Vector3 const& vec) {
                    return Vector3(x - vec.getX(), y - vec.getY(), z - vec.getZ());
                }

                Vector3 &operator-=(Vector3 const& vec) {
                    *this = *this - vec;
                    return *this;
                }

                Vector3 operator*(Vector3 const& vec) {
                    return Vector3(x * vec.getX(), y * vec.getY(), z * vec.getZ());
                }

                Vector3 &operator*=(Vector3 const& vec) {
                    *this = *this * vec;
                    return *this;
                }

                Vector3 operator/(Vector3 const& vec) {
                    return Vector3(x / vec.getX(), y / vec.getY(), z / vec.getZ());
                }

                Vector3 &operator/=(Vector3 const& vec) {
                    *this = *this / vec;
                    return *this;
                }

                Vector3 &operator=(Vector3 const& vec) {
                    x = vec.getX();
                    y = vec.getY();
                    z = vec.getZ();
                    return *this;
                }

                bool operator==(Vector3 const& vec) {
                    if (vec.getX() != x)
                        return false;
                    if (vec.getY() != y)
                        return false;
                    if (vec.getZ() != z)
                        return false;
                    return true;
                }

                bool operator!=(Vector3 const& vec) {
                    return !(*this == vec);
                }

                static Vector3 zero() {
                    return Vector3(0.f, 0.f, 0.f);
                }

                static Vector3 one() {
                    return Vector3(1.f, 1.f, 1.f);
                }

                std::string to_string() const {
                    std::string res = "{";

                    res += std::to_string(x) + "; ";
                    res += std::to_string(y) + "; ";
                    res += std::to_string(z) + "}";

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
