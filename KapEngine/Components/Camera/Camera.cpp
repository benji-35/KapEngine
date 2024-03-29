/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Camera
*/

#include "Camera.hpp"

KapEngine::Camera::Camera(std::shared_ptr<GameObject> go) : Component(go, "Camera") {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

KapEngine::Camera::~Camera() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}
