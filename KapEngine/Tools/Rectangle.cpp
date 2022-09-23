/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

void KapEngine::Tools::Rectangle::setPos(Vector2 const& pos) {
    _pos = pos;
}

void KapEngine::Tools::Rectangle::setPos(float x, float y) {
    _pos.setX(x);
    _pos.setY(y);
}

void KapEngine::Tools::Rectangle::setSize(float w, float h) {
    _size.setX(w);
    _size.setY(h);
}

void KapEngine::Tools::Rectangle::setSize(Vector2 const& size) {
    _size = size;
}
