/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Transform
*/

#include "Transform.hpp"
#include "KapEngineDebug.hpp"
#include "Vectors.hpp"

KapEngine::Transform::Transform(std::shared_ptr<GameObject> go) : Component(go, "Transform") {
    _startPos = Tools::Vector3(0.f, 0.f, 0.f);
    _startRot = Tools::Vector3(0.f, 0.f, 0.f);
    _startScale = Tools::Vector3(1.f, 1.f, 1.f);
}

KapEngine::Transform::~Transform() {}

void KapEngine::Transform::onAwake() {
    _pos = _startPos;
    _rot = _startRot;
    _scale = _startScale;
    _awkaeTr = true;
}
void KapEngine::Transform::onDisplay() {
    _updatePos = _pos;
    _updateScale = _scale;
    _updateRot = _rot;
}

void KapEngine::Transform::setPosition(Tools::Vector3 pos) {
    if (_awkaeTr) {
        _pos = pos;
    } else {
        _startPos = pos;
    }
}
void KapEngine::Transform::setRotation(Tools::Vector3 rot) {
    if (_awkaeTr) {
        _rot = rot;
    } else {
        _startRot = rot;
    }
}
void KapEngine::Transform::setScale(Tools::Vector3 scale) {
    if (_awkaeTr) {
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
    Tools::Vector3 res = Tools::Vector3::zero();

    if (_parentId == 0)
        return res;
    try {
        Transform &t = (Transform &)getParent()->getTransform();
        return t.getWorldPosition();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentRot() const{
    Tools::Vector3 res = Tools::Vector3::zero();

    if (_parentId == 0)
        return res;
    try {
        auto &t = getParent()->getComponent<Transform>();
        return t.getWorldRotation();
    } catch(...) {
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentScale() const{
    Tools::Vector3 res = Tools::Vector3::one();
    if (_parentId == 0)
        return res;
    try {
        auto &t = getParent()->getComponent<Transform>();
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
        Transform &tr = (Transform &)getGameObject().getScene().getGameObject(_parentId)->getTransform();
        return tr.allParentIsActive();
    } catch(...) {
        return false;
    }
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::Transform::getChildren() {
    std::vector<std::shared_ptr<GameObject>> gos = getGameObject().getScene().getAllGameObjects();
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
            result = getGameObjectConst().getScene().getGameObject(_parentId);
        } catch(...) {}
    }
    return result;
}

bool KapEngine::Transform::parentContainsComponent(std::string const& componentName, bool recurcively) {
    if (_parentId == 0) {
        return false;
    }
    std::shared_ptr<GameObject> parent = getParent();
    if (parent.use_count() == 0)
        return false;

    if (parent->hasComponent(componentName))
        return true;
    if (recurcively) {
        Transform &tr = (Transform &)parent->getTransform();
        return tr.parentContainsComponent(componentName, recurcively);
    }
    return false;
}

bool KapEngine::Transform::parentContainsComponents(std::vector<std::string> componentsName, bool recurcively) {
    for (std::size_t i = 0; i < componentsName.size(); i++) {
        if (!parentContainsComponent(componentsName[i], recurcively))
            return false;
    }
    return true;
}

std::size_t KapEngine::Transform::getParentContainsComponent(std::string const& componentName) {
    if (_parentId == 0) {
        if (getGameObject().hasComponent(componentName))
            return getGameObject().getId();
        return 0;
    }
    std::shared_ptr<GameObject> parent = getParent();
    if (parent.use_count() == 0)
        return 0;
    if (parent->hasComponent(componentName))
        return parent->getId();
    try {
        Transform &tr = (Transform &)parent->getTransform();
        auto val = tr.getParentContainsComponent(componentName);
        if (val == 0) {
            if (getGameObject().hasComponent(componentName))
                val = getGameObject().getId();
        }
        return val;
    } catch(...) {
        DEBUG_ERROR("Failled to get Transform of parent");
        return 0;
    }
}

bool KapEngine::Transform::allParentsActive() const {
    if (_parentId == 0 || getGameObjectConst().isActive() == false)
        return getGameObjectConst().isActive();
    try {
        auto parent = getParent();

        auto &tr = parent->getComponent<Transform>();
        return tr.allParentsActive();
    } catch(...) {
        return false;
    }
}

bool KapEngine::Transform::hasChanged() {
    if (_updatePos != _pos)
        return true;
    if (_updateRot != _rot)
        return true;
    if (_updateScale != _scale)
        return true;
    return false;
}
