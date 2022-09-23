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

void KapEngine::Tools::Rectangle::setH(float h) {
    _size.setY(h);
}


void KapEngine::Tools::Rectangle::setW(float w) {
    _size.setX(w);
}


void KapEngine::Tools::Rectangle::setX(float x) {
    _pos.setX(x);
}


void KapEngine::Tools::Rectangle::setY(float y) {
    _pos.setY(y);
}
