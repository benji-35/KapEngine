/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Rectangle
*/

#include "Rectangle.hpp"
#include "Profiler/KapProfiler.hpp"

void KapEngine::Tools::Rectangle::setPos(Vector2 const& pos) {
    PROFILER_FUNC_START();
    _pos = pos;
    PROFILER_FUNC_END();
}

void KapEngine::Tools::Rectangle::setPos(float x, float y) {
    PROFILER_FUNC_START();
    _pos.setX(x);
    _pos.setY(y);
    PROFILER_FUNC_END();
}

void KapEngine::Tools::Rectangle::setSize(float w, float h) {
    PROFILER_FUNC_START();
    _size.setX(w);
    _size.setY(h);
    PROFILER_FUNC_END();
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
    PROFILER_FUNC_START();
    std::string res = "{";

    res += std::to_string(_pos.getX()) + "; ";
    res += std::to_string(_pos.getY()) + "; ";
    res += std::to_string(_size.getX()) + "; ";
    res += std::to_string(_size.getY()) + "}";

    PROFILER_FUNC_END();
    return res;
}

float KapEngine::Tools::Rectangle::getX() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getPos().getX();
}

float KapEngine::Tools::Rectangle::getY() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getPos().getY();
}

float KapEngine::Tools::Rectangle::getWidth() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getSize().getX();
}

float KapEngine::Tools::Rectangle::getHeigth() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return getSize().getY();
}
