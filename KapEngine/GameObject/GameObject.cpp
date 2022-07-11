/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GameObject
*/

#include "GameObject.hpp"
#include "Errors.hpp"

KapEngine::GameObject::GameObject(SceneManagement::Scene &scene, std::string const& name) : _scene(scene) {
    _name = name;
}

KapEngine::GameObject::~GameObject() {

}

bool KapEngine::GameObject::allParentsActive() const {
    if (_parentId == 0)
        return _active;
    return getParent()->allParentsActive();
}

std::shared_ptr<KapEngine::GameObject> KapEngine::GameObject::getParent() const {
    if (_parentId == 0)
        throw Errors::GameObjectError("[GAMEOBJECT] No parent assigned to GameObject " + _name);
    try {
        return _scene.getObject(_parentId);
    } catch(Errors::SceneError e) {
        throw Errors::GameObjectError(std::string(e.what()));
    } catch(...) {
        throw Errors::GameObjectError("[GAMEOBJECT] unknown error to getParent");
    }
}

void KapEngine::GameObject::__update() {
    if (!_active || _destroyed)
        return;
    for (std::size_t i = 0; i < _components.size(); i++) {
        _components[i]->__update();
    }
}
