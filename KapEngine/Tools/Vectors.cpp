/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Vector
*/

#include "Vectors.hpp"
#include "Profiler/KapProfiler.hpp"

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator+(Vector3 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector2(x + vec.getX(), y + vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator-(Vector3 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector2(x - vec.getX(), y - vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator*(Vector3 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector2(x * vec.getX(), y * vec.getY());
}

KapEngine::Tools::Vector2 KapEngine::Tools::Vector2::operator/(Vector3 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector2(x / vec.getX(), y / vec.getY());
}

KapEngine::Tools::Vector2 &KapEngine::Tools::Vector2::operator=(Vector3 const& vec) {
    PROFILER_FUNC_START();
    x = vec.getX();
    y = vec.getY();

    PROFILER_FUNC_END();
    return *this;
}


KapEngine::Tools::Vector3 KapEngine::Tools::Vector3::operator+(Vector2 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector3(x + vec.getX(), y + vec.getY(), z);
}

KapEngine::Tools::Vector3 KapEngine::Tools::Vector3::operator-(Vector2 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector3(x - vec.getX(), y - vec.getY(), z);
}

KapEngine::Tools::Vector3 KapEngine::Tools::Vector3::operator*(Vector2 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector3(x * vec.getX(), y * vec.getY(), z);
}

KapEngine::Tools::Vector3 KapEngine::Tools::Vector3::operator/(Vector2 const& vec) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return Vector3(x / vec.getX(), y / vec.getY(), z);
}

KapEngine::Tools::Vector3 &KapEngine::Tools::Vector3::operator=(Vector2 const& vec) {
    PROFILER_FUNC_START();
    x = vec.getX();
    y = vec.getY();

    PROFILER_FUNC_END();
    return *this;
}

