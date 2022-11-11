/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Transform
*/

#include "KapEngine.hpp"

KapEngine::Transform::Transform(std::shared_ptr<GameObject> go) : Component(go, "Transform") {
    PROFILER_FUNC_START();
    _startPos = Tools::Vector3(0.f, 0.f, 0.f);
    _startRot = Tools::Vector3(0.f, 0.f, 0.f);
    _startScale = Tools::Vector3(1.f, 1.f, 1.f);
    PROFILER_FUNC_END();
}

KapEngine::Transform::~Transform() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Transform::onAwake() {
    PROFILER_FUNC_START();
    _pos = _startPos;
    _rot = _startRot;
    _scale = _startScale;
    _awkaeTr = true;
    PROFILER_FUNC_END();
}
void KapEngine::Transform::onDisplay() {
    PROFILER_FUNC_START();
    _updatePos = _pos;
    _updateScale = _scale;
    _updateRot = _rot;
    PROFILER_FUNC_END();
}

void KapEngine::Transform::setPosition(Tools::Vector3 pos) {
    PROFILER_FUNC_START();
    if (_awkaeTr) {
        _pos = pos;
    } else {
        _startPos = pos;
    }
    PROFILER_FUNC_END();
}
void KapEngine::Transform::setRotation(Tools::Vector3 rot) {
    PROFILER_FUNC_START();
    if (_awkaeTr) {
        _rot = rot;
    } else {
        _startRot = rot;
    }
    PROFILER_FUNC_END();
}
void KapEngine::Transform::setScale(Tools::Vector3 scale) {
    PROFILER_FUNC_START();
    if (_awkaeTr) {
        _scale = scale;
    } else {
        _startScale = scale;
    }
    PROFILER_FUNC_END();
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalPosition() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    if (!_awkaeTr)
        return _startPos;
    return _pos;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalRotation() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    if (!_awkaeTr)
        return _startRot;
    return _rot;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getLocalScale() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    if (!_awkaeTr)
        return _startScale;
    return _scale;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldPosition() const {
    Tools::Vector3 res(_pos);
    res += getParentPos();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldRotation() const {
    PROFILER_FUNC_START();
    Tools::Vector3 res(_rot);
    res += getParentRot();
    PROFILER_FUNC_END();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getWorldScale() const {
    Tools::Vector3 res(_scale);
    res *= getParentScale();
    return res;
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentPos() const{
    PROFILER_FUNC_START();
    Tools::Vector3 res = Tools::Vector3::zero();

    if (_parentId == 0) {
        PROFILER_FUNC_END();
        return res;
    }
    try {
        Transform &t = (Transform &)getParent()->getTransform();
        PROFILER_FUNC_END();
        return t.getWorldPosition();
    } catch(...) {
        PROFILER_FUNC_END();
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentRot() const {
    PROFILER_FUNC_START();
    Tools::Vector3 res = Tools::Vector3::zero();

    if (_parentId == 0) {
        PROFILER_FUNC_END();
        return res;
    }
    try {
        auto &t = getParent()->getComponent<Transform>();
        PROFILER_FUNC_END();
        return t.getWorldRotation();
    } catch(...) {
        PROFILER_FUNC_END();
        return res;
    }
}

KapEngine::Tools::Vector3 KapEngine::Transform::getParentScale() const {
    PROFILER_FUNC_START();
    Tools::Vector3 res = Tools::Vector3::one();
    if (_parentId == 0) {
        PROFILER_FUNC_END();
        return res;
    }
    try {
        auto &t = getParent()->getComponent<Transform>();
        PROFILER_FUNC_END();
        return t.getWorldScale();
    } catch(...) {
        PROFILER_FUNC_END();
        return res;
    }
}

void KapEngine::Transform::setParent(std::size_t id) {
    PROFILER_FUNC_START();
    _parentId = id;
    if (_parentId == 0) {
        getScene().getGameObject(id)->getComponent<Transform>().__removeChild(getGameObjectId());
    } else {
        getScene().getGameObject(id)->getComponent<Transform>().__addChild(getGameObjectId());
    }
    PROFILER_FUNC_END();
}

void KapEngine::Transform::__addChild(std::size_t id) {
    PROFILER_FUNC_START();
    _children.push_back(id);
    PROFILER_FUNC_END();
}

void KapEngine::Transform::__removeChild(std::size_t id) {
    PROFILER_FUNC_START();
    for (auto it = _children.begin(); it != _children.end(); it++) {
        if (*it == id) {
            _children.erase(it);
            PROFILER_FUNC_END();
            return;
        }
    }
    PROFILER_FUNC_END();
}

void KapEngine::Transform::setParent(std::any val) {
    PROFILER_FUNC_START();
    if (!val.has_value()) {
        _parentId = 0;
        PROFILER_FUNC_END();
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
        PROFILER_FUNC_END();
        throw Errors::ComponentError("[TRANSFORM] error while try to set parent");
    }
    PROFILER_FUNC_END();
}

bool KapEngine::Transform::allParentIsActive() {
    if (_parentId == 0) {
        return getGameObject().isActive();
    }
    try {
        Transform &tr = (Transform &) getScene().getGameObject(_parentId)->getTransform();
        return tr.allParentIsActive();
    } catch(...) {
        return false;
    }
}

std::vector<std::shared_ptr<KapEngine::GameObject>> KapEngine::Transform::getChildren() {
    PROFILER_FUNC_START();
    std::vector<std::shared_ptr<GameObject>> gos = getScene().getAllGameObjects();
    std::vector<std::shared_ptr<GameObject>> result;

    for (std::size_t i = 0; i < gos.size(); i++) {
        for (std::size_t x = 0; x < _children.size(); x++) {
            if (gos[i]->getId() == _children[x]) {
                result.push_back(gos[i]);
            }
        }
    }
    PROFILER_FUNC_END();
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
    PROFILER_FUNC_START();
    if (_parentId == 0) {
        PROFILER_FUNC_END();
        return false;
    }
    std::shared_ptr<GameObject> parent = getParent();
    if (parent.use_count() == 0) {
        PROFILER_FUNC_END();
        return false;
    }

    if (parent->hasComponent(componentName)) {
        PROFILER_FUNC_END();
        return true;
    }
    if (recurcively) {
        Transform &tr = (Transform &)parent->getTransform();
        PROFILER_FUNC_END();
        return tr.parentContainsComponent(componentName, recurcively);
    }
    PROFILER_FUNC_END();
    return false;
}

bool KapEngine::Transform::parentContainsComponents(std::vector<std::string> componentsName, bool recurcively) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < componentsName.size(); i++) {
        if (!parentContainsComponent(componentsName[i], recurcively)) {
            PROFILER_FUNC_END();
            return false;
        }
    }
    PROFILER_FUNC_END();
    return true;
}

std::size_t KapEngine::Transform::getParentContainsComponent(std::string const& componentName) {
    PROFILER_FUNC_START();
    if (_parentId == 0) {
        if (getGameObject().hasComponent(componentName)) {
            PROFILER_FUNC_END();
            return getGameObjectId();
        }
        PROFILER_FUNC_END();
        return 0;
    }
    std::shared_ptr<GameObject> parent = getParent();
    if (parent.use_count() == 0) {
        PROFILER_FUNC_END();
        return 0;
    }
    if (parent->hasComponent(componentName)) {
        PROFILER_FUNC_END();
        return parent->getId();
    }
    try {
        Transform &tr = (Transform &)parent->getTransform();
        auto val = tr.getParentContainsComponent(componentName);
        if (val == 0) {
            if (getGameObject().hasComponent(componentName)) {
                val = getGameObjectId();
            }
        }
        PROFILER_FUNC_END();
        return val;
    } catch(...) {

        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Failled to get Transform of parent");
        #endif
        PROFILER_FUNC_END();
        return 0;
    }
}

bool KapEngine::Transform::allParentsActive() const {
    if (_parentId == 0 || getGameObjectConst().isActive() == false) {
        return getGameObjectConst().isActive();
    }
    try {
        auto parent = getParent();

        auto &tr = parent->getComponent<Transform>();
        return tr.allParentsActive();
    } catch(...) {
        return false;
    }
}

bool KapEngine::Transform::hasChanged() {
    PROFILER_FUNC_START();
    if (_updatePos != _pos) {
        PROFILER_FUNC_END();
        return true;
    }
    if (_updateRot != _rot) {
        PROFILER_FUNC_END();
        return true;
    }
    if (_updateScale != _scale) {
        PROFILER_FUNC_END();
        return true;
    }
    PROFILER_FUNC_END();
    return false;
}
