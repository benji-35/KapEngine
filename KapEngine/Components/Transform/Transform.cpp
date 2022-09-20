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

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldPosition() const {
    Tools::Vector3 res(_pos);
    res += getParentPos();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldRotation() const {
    Tools::Vector3 res(_rot);
    res += getParentRot();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldScale() const {
    Tools::Vector3 res(_scale);
    res *= getParentScale();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentPos() const{
    Tools::Vector3 res;
    try {
        Transform &t = (Transform &)getParent()->getComponent("Transform");
        return t.getWorldPosition();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentRot() const{
    Tools::Vector3 res;
    try {
        Transform &t = (Transform &)getParent()->getComponent("Transform");
        return t.getWorldRotation();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentScale() const{
    Tools::Vector3 res(1.0f, 1.0f, 1.0f);
    try {
        Transform &t = (Transform &)getParent()->getComponent("Transform");
        return t.getWorldScale();
    } catch(...) {
        return res;
    }
}

void KapEngine::Transform::setParent(std::size_t id) {
    _parentId = id;
}

void KapEngine::Transform::setParent(std::any val) {
    if (!val.has_value()) {
        _parentId = 0;
        return;
    }
    const std::type_info &inf = val.type();
    if (std::string(inf.name()) == "i") {
        int v = std::any_cast<int>(val);
        setParent((std::size_t)v);
    }
    if (std::string(inf.name()) == "d") {
        double v = std::any_cast<double>(val);
        setParent((std::size_t)v);
    }
    if (std::string(inf.name()) == "f") {
        float v = std::any_cast<float>(val);
        setParent((std::size_t)v);
    }

    try {
        std::shared_ptr<GameObject> go = std::any_cast<std::shared_ptr<GameObject>>(val);
        if (go.use_count() != 0)
            setParent(go->getId());
    } catch(...) {
        throw Errors::ComponentError("[TRANSFORM] error while try to set parent");
    }
}

bool KapEngine::Transform::allParentIsActive() {
    if (_parentId == 0)
        return getGameObject().isActive();
    try {
        Transform &tr = (Transform &)getGameObject().getScene().getObject(_parentId)->getTransform();
        return tr.allParentIsActive();
    } catch(...) {
        return false;
    }
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::Transform::getChildren() {
    std::vector<std::shared_ptr<GameObject>> gos = getGameObject().getScene().getAllObjects();
    std::vector<std::shared_ptr<GameObject>> result;
    
    for (std::size_t i = 0; i < gos.size(); i++) {
        if (((Transform &)gos[i]->getTransform()).getParentId() == getGameObject().getId())
            result.push_back(gos[i]);
    }
    return result;
}

std::size_t KapEngine::Transform::getParentId() const {
    return _parentId;
}

std::shared_ptr<KapEngine::GameObject> KapEngine::Transform::getParent() const {
    std::shared_ptr<GameObject> result;
    if (_parentId != 0) {
        try {
            result = getGameObjectConst().getScene().getObject(_parentId);
        } catch(...) {}
    }
    return result;
}
