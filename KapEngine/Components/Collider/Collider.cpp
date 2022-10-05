/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#include "Collider.hpp"

using namespace KapEngine;

Collider::Collider(std::shared_ptr<GameObject> go) : Component(go, "Collider") {}

Collider::~Collider() {}
