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

std::string KapEngine::Tools::Rectangle::to_string() const {
    std::string res = "{";

    res += std::to_string(_pos.getX()) + "; ";
    res += std::to_string(_pos.getY()) + "; ";
    res += std::to_string(_size.getX()) + "; ";
    res += std::to_string(_size.getY()) + "}";

    return res;
}

float KapEngine::Tools::Rectangle::getX() const {
    return getPos().getX();
}

float KapEngine::Tools::Rectangle::getY() const {
    return getPos().getY();
}

float KapEngine::Tools::Rectangle::getWidth() const {
    return getSize().getX();
}

float KapEngine::Tools::Rectangle::getHeigth() const {
    return getSize().getY();
}
