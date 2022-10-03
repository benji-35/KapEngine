/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Vector
*/

#include "Vectors.hpp"

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator+(Vector3 const& vec) {
    return Vector2(x + vec.getX(), y + vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator-(Vector3 const& vec) {
    return Vector2(x - vec.getX(), y - vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator*(Vector3 const& vec) {
    return Vector2(x * vec.getX(), y * vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator/(Vector3 const& vec) {
    return Vector2(x / vec.getX(), y / vec.getY());
}

KapEngine::Tools::Vector2 &KapEngine::Tools::Vector2::operator=(Vector3 const& vec) {
    x = vec.getX();
    y = vec.getY();

    return *this;
}
