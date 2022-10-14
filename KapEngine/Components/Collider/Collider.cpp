/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#include "Collider.hpp"
#include "Transform.hpp"
#include "KapEngineUi.hpp"

using namespace KapEngine;

Collider::Collider(std::shared_ptr<GameObject> go, bool isTrigger, bool isMovable, bool isCanvas) : Component(go, "Collider"),
    _isTrigger(isTrigger), _isInCanvas(isCanvas) {
    __setPhysics(true);
}

Collider::~Collider() {}

void Collider::onUpdate() {
    if (!_isTrigger)
        return;
    
    auto gameObjects = getGameObject().getScene().getGameObjectByTag("Collider");

    for (std::size_t i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->getId() != getGameObject().getId()) {
            __checkCollision(gameObjects[i]);
        }
    }
}

void Collider::onSceneUpdated() {
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
}

bool Collider::__checkCollision(Tools::Rectangle const& rect) {
    auto ownRect = getCalculatedRectangle();

    if (ownRect.getX() < rect.getX() + rect.getWidth() &&
        ownRect.getX() + ownRect.getWidth() > rect.getX() &&
        ownRect.getY() < rect.getY() + rect.getHeigth() &&
        ownRect.getY() + ownRect.getHeigth() > rect.getY()) {
        return true;
    }

    return false;
}

void Collider::__checkCollision(std::shared_ptr<GameObject> &go) {
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
}

bool Collider::__colliderAlreadyCollide(std::shared_ptr<Collider> &collider) {
    for (std::size_t i = 0; i < _collidedObjects.size(); i++) {
        if (_collidedObjects[i]->getId() == collider->getGameObject().getId() && collider->getGameObject().getId() != _collidedObjects[i]->getGameObject().getId()) {
            return true;
        }
    }
    return false;
}

void Collider::__callEnter(GameObject &go) {
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerEnter(go.getScene().getGameObject(go.getId()));
    }
}

void Collider::__callStay(GameObject &go) {
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerStay(go.getScene().getGameObject(go.getId()));
    }
}

void Collider::__callExit(GameObject &go) {
    auto components = getGameObject().getAllComponents();

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerExit(go.getScene().getGameObject(go.getId()));
    }
}

bool Collider::__currentlyCollided(std::shared_ptr<Collider> &collider) {
    for (std::size_t i = 0; i < _justCollidedObjects.size(); i++) {
        if (_justCollidedObjects[i]->getId() == collider->getId() && collider->getGameObject().getId() == _collidedObjects[i]->getGameObject().getId()) {
            return true;
        }
    }
    return false;
}

Tools::Rectangle Collider::getCalculatedRectangle() const {
    Tools::Rectangle rect = _boxCollider;
    if (rect.getSize().getX() == 0 || rect.getSize().getY() == 0) {
        Tools::Vector2 pos;
        pos = getGameObjectConst().getComponent<Transform>().getWorldPosition();
        Tools::Vector2 size;
        size = getGameObjectConst().getComponent<Transform>().getWorldScale();

        rect.setPos(pos);
        rect.setSize(size);
    }

    if (_isInCanvas) {
        rect.setPos(__recalculCanvas(rect.getPos()));
        rect.setSize(__recalculCanvas(rect.getSize()));
    }
    return rect;
}

Tools::Vector2 Collider::__recalculCanvas(Tools::Vector2 const& vector) const {
    try {
        Tools::Vector2 currentScreenSize = getGameObjectConst().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
        auto parent = getGameObjectConst().getComponent<Transform>().getParentContainsComponent("Canvas");
        auto canvas = getGameObjectConst().getScene().getGameObject(parent)->getComponent<UI::Canvas>();
        Tools::Vector2 canvasSize = canvas.getScreenSizeCompare();

        float x = vector.getX() * (currentScreenSize.getX() / canvasSize.getX());
        float y = vector.getY() * (currentScreenSize.getY() / canvasSize.getY());

        return Tools::Vector2(x, y);

    } catch (Errors::Error e) {
        DEBUG_ERROR(e.what());
        return vector;
    }
}

bool Collider::checkComponentValidity() {
    if (_isInCanvas) {
        try {
            if (getTransform().parentContainsComponent("Canvas")) {
                return true;
            } else {
                if (getGameObject().hasComponent<UI::Canvas>())
                    return true;
                DEBUG_ERROR("Collider must be in a GameObject with a Canvas component (GameObject: " + getGameObject().getName() + ")");
                return false;
            }
        } catch (Errors::Error e) {
            DEBUG_ERROR(e.what());
            return false;
        }
    }
    return true;
}

bool Collider::__alreayCalculated(std::shared_ptr<Collider> &collider) {
    auto colliders = collider->getCollidedObjects();

    for (std::size_t i = 0; i < colliders.size(); i++) {
        if (colliders[i]->getId() == getId() && colliders[i]->getGameObject().getId() == getGameObject().getId()) {
            return true;
        }
    }
    return false;
}
