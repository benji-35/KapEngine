/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Transform
*/

#include "Transform.hpp"

KapEngine::Transform::Transform(std::shared_ptr<GameObject> go) : Component(go, "Transform") {}

KapEngine::Transform::~Transform() {}

void KapEngine::Transform::onStart() {
    _pos = _startPos;
    _rot = _startRot;
    _scale = _startScale;
}

void KapEngine::Transform::setPosition(Tools::Vector3 pos) {
    if (getGameObject().getEngine().isRunning()) {
        _pos = pos;
    } else {
        _startPos = pos;
    }
}
void KapEngine::Transform::setRotation(Tools::Vector3 rot) {
    if (getGameObject().getEngine().isRunning()) {
        _rot = rot;
    } else {
        _startRot = rot;
    }
}
void KapEngine::Transform::setScale(Tools::Vector3 scale) {
    if (getGameObject().getEngine().isRunning()) {
        _scale = scale;
    } else {
        _startScale = scale;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalPosition() const {
    return _pos;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalRotation() const {
    return _rot;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalScale() const {
    return _scale;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldPosition() {
    Tools::Vector3 res(_pos);
    res += getParentPos();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldRotation() {
    Tools::Vector3 res(_rot);
    res += getParentRot();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldScale() {
    Tools::Vector3 res(_scale);
    res *= getParentScale();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentPos() {
    Tools::Vector3 res;
    try {
        Transform &t = (Transform &) getGameObject().getParent()->getComponent("Transform");
        return t.getWorldPosition();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentRot() {
    Tools::Vector3 res;
    try {
        Transform &t = (Transform &) getGameObject().getParent()->getComponent("Transform");
        return t.getWorldRotation();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentScale() {
    Tools::Vector3 res(1.0f, 1.0f, 1.0f);
    try {
        Transform &t = (Transform &) getGameObject().getParent()->getComponent("Transform");
        return t.getWorldScale();
    } catch(...) {
        return res;
    }
}
