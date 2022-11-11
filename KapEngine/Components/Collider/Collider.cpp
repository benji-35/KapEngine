/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#include "Collider.hpp"
#include "KapEngine.hpp"
#include "KapEngineUi.hpp"

using namespace KapEngine;

Collider::Collider(std::shared_ptr<GameObject> go, bool isTrigger) : Component(go, "Collider"),
    _isTrigger(isTrigger) {
    PROFILER_FUNC_START();
    __setPhysics(true);
    PROFILER_FUNC_END();
}

Collider::~Collider() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void Collider::onUpdate() {
    PROFILER_FUNC_START();
    if (!_isTrigger) {
        PROFILER_FUNC_END();
        return;
    }
    
    auto gameObjects = getScene().getGameObjectByTag("Collider");

    for (std::size_t i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->getId() != getGameObjectId()) {
            __checkCollision(gameObjects[i]);
        }
    }
    PROFILER_FUNC_END();
}

void Collider::onSceneUpdated() {
    PROFILER_FUNC_START();
    if (!_isTrigger) {
        PROFILER_FUNC_END();
        return;
    }
    __checkCollidersExists();
    //check all collided
    for (std::size_t i = 0; i < _justCollidedObjects.size(); i++) {
        if (__colliderAlreadyCollide(_justCollidedObjects[i])) {
            if (_justCollidedObjects[i]->isTrigger()) {
                _justCollidedObjects[i]->__callStay(getGameObject());
            }
            __callStay(_justCollidedObjects[i]->getGameObject());
        } else {
            if (_justCollidedObjects[i]->isTrigger()) {
                _justCollidedObjects[i]->__callEnter(getGameObject());
            }
            __callEnter(_justCollidedObjects[i]->getGameObject());
        }
    }
    //check not collided
    std::vector<std::shared_ptr<Collider>> _newColliders;
    for (std::size_t i = 0; i < _collidedObjects.size(); i++) {
        if (!__currentlyCollided(_collidedObjects[i])) {
            __callExit(_collidedObjects[i]->getGameObject());
        } else {
            _newColliders.push_back(_collidedObjects[i]);
        }
    }
    _collidedObjects = _newColliders;
    for (std::size_t i= 0; i <_justCollidedObjects.size(); i++) {
        _collidedObjects.push_back(_justCollidedObjects[i]);
    }
    _justCollidedObjects.clear();
    _notCollidedObjects.clear();
    PROFILER_FUNC_END();
}

bool Collider::__checkCollision(Tools::Rectangle const& rect) {
    PROFILER_FUNC_START();
    auto ownRect = getCalculatedRectangle();

    if (ownRect.getX() < rect.getX() + rect.getWidth() &&
        ownRect.getX() + ownRect.getWidth() > rect.getX() &&
        ownRect.getY() < rect.getY() + rect.getHeigth() &&
        ownRect.getY() + ownRect.getHeigth() > rect.getY()) {
        PROFILER_FUNC_END();
        return true;
    }

    PROFILER_FUNC_END();
    return false;
}

void Collider::__checkCollision(std::shared_ptr<GameObject> &go) {
    PROFILER_FUNC_START();
    auto collider = go->getComponents<Collider>();

    for (std::size_t i = 0; i < collider.size(); i++) {
        if (collider[i]->isTrigger() && !__alreayCalculated(collider[i])) {
            auto rect = collider[i]->getCalculatedRectangle();
            if (__checkCollision(rect)) {
                _justCollidedObjects.push_back(collider[i]);
            } else {
                _notCollidedObjects.push_back(collider[i]);
            }
        }
    }
    PROFILER_FUNC_END();
}

bool Collider::__colliderAlreadyCollide(std::shared_ptr<Collider> &collider) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _collidedObjects.size(); i++) {
        if (_collidedObjects[i]->getId() == collider->getGameObjectId() && collider->getGameObjectId() != _collidedObjects[i]->getGameObjectId()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

void Collider::__callEnter(GameObject &go) {
    PROFILER_FUNC_START();
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerEnter(go.getScene().getGameObject(go.getId()));
    }
    PROFILER_FUNC_END();
}

void Collider::__callStay(GameObject &go) {
    PROFILER_FUNC_START();
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerStay(go.getScene().getGameObject(go.getId()));
    }
    PROFILER_FUNC_END();
}

void Collider::__callExit(GameObject &go) {
    PROFILER_FUNC_START();
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerExit(go.getScene().getGameObject(go.getId()));
    }
    PROFILER_FUNC_END();
}

bool Collider::__currentlyCollided(std::shared_ptr<Collider> &collider) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _justCollidedObjects.size(); i++) {
        if (_justCollidedObjects[i]->getId() == collider->getId() && collider->getGameObjectId() == _collidedObjects[i]->getGameObjectId()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

Tools::Rectangle Collider::getCalculatedRectangle() const {
    PROFILER_FUNC_START();
    Tools::Rectangle rect = _boxCollider;
    if (rect.getSize().getX() == 0 || rect.getSize().getY() == 0) {
        Tools::Vector2 pos;
        pos = getGameObject().getComponent<Transform>().getWorldPosition();
        Tools::Vector2 size;
        size = getGameObject().getComponent<Transform>().getWorldScale();

        rect.setPos(pos);
        rect.setSize(size);
    }
    PROFILER_FUNC_END();
    return rect;
}

bool Collider::__alreayCalculated(std::shared_ptr<Collider> &collider) {
    PROFILER_FUNC_START();
    auto colliders = collider->getCollidedObjects();

    for (std::size_t i = 0; i < colliders.size(); i++) {
        if (colliders[i]->getId() == getId() && colliders[i]->getGameObjectId() == getGameObjectId()) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

void Collider::__checkCollidersExists() {
    PROFILER_FUNC_START();
    auto &scene = getScene();
    for (std::size_t i = 0; i < _collidedObjects.size(); i++) {
        if (!scene.isGameObjectExists(_collidedObjects[i]->getGameObjectId())) {
            _collidedObjects.erase(_collidedObjects.begin() + i);
            i--;
        }
    }
    for (std::size_t i = 0; i < _justCollidedObjects.size(); i++) {
        if (!scene.isGameObjectExists(_justCollidedObjects[i]->getGameObjectId())) {
            _justCollidedObjects.erase(_justCollidedObjects.begin() + i);
            i--;
        }
    }
    PROFILER_FUNC_END();
}
