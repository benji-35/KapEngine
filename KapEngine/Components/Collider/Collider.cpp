/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#include "Collider.hpp"
#include "KapEngineUi.hpp"

using namespace KapEngine;

Collider::Collider(std::shared_ptr<GameObject> go, bool isTrigger, bool isMovable, bool isCanvas) : Component(go, "Collider"),
    _isTrigger(isTrigger), _isMovable(isMovable), _isInCanvas(isCanvas) {

}

Collider::~Collider() {}

bool Collider::checkComponentValidity() {
    if (_isInCanvas) {
        try {
            auto &transform = getGameObject().getComponent<Transform>();
            return transform.getParentContainsComponent("Canvas");
        } catch (Errors::ComponentError &e) {
            throw Errors::ComponentError("Collider GameObject does not have a Transform component");
        }
    }
    return true;
}

void Collider::onUpdate() {
    if (!_isTrigger || !_isMovable)
        return;
    auto collision = getCollisionBox();
    auto gameObjects = getGameObject().getScene().getAllGameObjects();
    for (std::size_t i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->getId() != getGameObject().getId()) {
            calculateCollisions(gameObjects[i]);
        }
    }
    checkNotCollided();
}

KapEngine::Tools::Vector2 Collider::calculSizeCanvas(KapEngine::Tools::Vector2 const &size) const {

    Tools::Vector2 currentSize = getGameObjectConst().getEngine().getGraphicalLibManager()->getCurrentLib()->getScreenSize();
    Tools::Vector2 baseSize = getGameObjectConst().getEngine().getScreenSize();
    Tools::Vector2 result = size;

    try {
        auto idParent = getGameObjectConst().getComponent<Transform>().getParentContainsComponent("Canvas");
        auto parent = getGameObjectConst().getScene().getGameObjectConst(idParent);

        auto &canvas = parent->getComponent<UI::Canvas>();
        baseSize = canvas.getScreenSizeCompare();

    } catch(...) {}

    float xMultiplier = baseSize.getX() / currentSize.getX();
    float yMultiplier = baseSize.getY() / currentSize.getY();

    result.setX(result.getX() * xMultiplier);
    result.setY(result.getY() / yMultiplier);

    return result;
}

void Collider::calculateCollisions(std::shared_ptr<GameObject> object) {
    if (object->getId() == getGameObject().getId())
        return;

    auto colliders = findAllColliders(*object);
    for (std::size_t i = 0; i < colliders.size(); i++) {
        calculateCollisions(*colliders[i]);
    }
}

void Collider::calculateCollisions(KapEngine::Collider &collider) {
    //check already calculated
    for (std::size_t i = 0; i < _calculatedColliders.size(); i++) {
        if (_calculatedColliders[i]->getGameObject().getId() == collider.getGameObject().getId()) {
            if (_calculatedColliders[i]->getId() == collider.getId()) {
                return;
            }
        }
    }
    _calculatedColliders.push_back(&collider);
    collider.__addCalculatedCollider(this);
    //check collision
    if (isColliding(collider.getCollisionBox())) {
        if (_isTrigger) {
            __callTrigger(collider);
        }
        if (collider.isTrigger()) {
            collider.__callTrigger(*this);
        }
    }
}

bool Collider::isColliding(KapEngine::Tools::Rectangle const rect) {
    if (_collisionBox.getPos().getX() > rect.getPos().getX() + rect.getSize().getX())
        return false;
    if (rect.getPos().getX() > _collisionBox.getPos().getX() + _collisionBox.getSize().getX())
        return false;
    if (_collisionBox.getPos().getY() > rect.getPos().getY() + rect.getSize().getY())
        return false;
    if (rect.getPos().getY() > _collisionBox.getPos().getY() + _collisionBox.getSize().getY())
        return false;
    return true;
}

void Collider::__callTrigger(Collider &collided) {
    auto components = getGameObject().getAllComponents();
    auto goShared = collided.getGameObject().getScene().getGameObject(collided.getGameObject().getId());
    auto alreadyTriggered = isSavedCollided(collided);

    for (std::size_t i = 0; i < components.size(); i++) {
        if (alreadyTriggered) {
            components[i]->onTriggerStay(goShared);
        } else {
            components[i]->onTriggerEnter(goShared);
        }
    }
}

void Collider::onSceneUpdated() {
    checkNotCollided();
    _calculatedColliders.clear();
}

void Collider::checkNotCollided() {
    for (std::size_t i = 0; i < _alreadyCollided.size(); i++) {
        if (!isSavedCollided(*_alreadyCollided[i])) {
            __callEndTrigger(*_alreadyCollided[i]);
        }
    }
}

void Collider::__callEndTrigger(Collider &collided) {
    auto components = getGameObject().getAllComponents();
    auto goShared = collided.getGameObject().getScene().getGameObject(collided.getId());

    for (std::size_t i = 0; i < components.size(); i++) {
        components[i]->onTriggerExit(goShared);
    }
    for (std::size_t i = 0; i < _alreadyCollided.size(); i++) {
        if (_alreadyCollided[i]->getId() == collided.getId()) {
            _alreadyCollided.erase(_alreadyCollided.begin() + i);
            break;
        }
    }
}

bool Collider::isSavedCollided(Collider &collider) {
    for (std::size_t i = 0; i < _alreadyCollided.size(); i++) {
        if (_alreadyCollided[i]->getId() == collider.getId()) {
            return true;
        }
    }
    return false;
}

Tools::Rectangle Collider::getCollisionBox() const {
    Tools::Rectangle rect = _collisionBox;

    if (rect.getSize().getX() == 0 || rect.getSize().getY() == 0) {
        auto &transform = getGameObjectConst().getComponent<Transform>();
        Tools::Vector2 size;
        Tools::Vector2 pos;
        size = transform.getWorldScale();
        pos = transform.getWorldPosition();
        rect.setSize(size);
        rect.setPos(pos);
    }

    rect.setPos(rect.getPos() + _offset);
    if (_isInCanvas) {
        rect.setPos(calculSizeCanvas(rect.getPos()));
        rect.setSize(calculSizeCanvas(rect.getSize()));
    }
    return rect;
}

std::vector<Collider *> Collider::findAllColliders(GameObject &go) {
    auto allComponents = go.getAllComponents();
    std::vector<Collider *> colliders;

    for (std::size_t i = 0; i < allComponents.size(); i++) {
        if (allComponents[i]->getName() == "Collider") {
            colliders.push_back(dynamic_cast<Collider *>(allComponents[i].get()));
        }
    }
    return colliders;
}
