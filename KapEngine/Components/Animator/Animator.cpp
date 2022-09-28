/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animator
*/

#include "Animator.hpp"

KapEngine::Animator::Animator(std::shared_ptr<GameObject> go) : Component(go, "Animator", 1) {}

KapEngine::Animator::~Animator() {
    _anims.clear();
}

void KapEngine::Animator::onStart()
{
    _anim = _firstAnim;
    if (_anim.use_count() != 0) {
        _anim->_anim->play(true);
    }
}

void KapEngine::Animator::onFixedUpdate() {
    if (_anim.use_count() == 0)
        return;
    if (_anim->_anim->isEnded() && _anim->_goAfter) {
        if (_anim->hasMainExit()) {
            for (std::size_t i = 0; i < _anim->links.size(); i++) {
                if (_anim->links.at(i)->mainExit) {
                    _anim->_anim->play(false);
                    _anim = _anim->links.at(i)->target;
                    _anim->_anim->play(true);
                }
            }
        }
    }
}

void KapEngine::Animator::addAnim(std::shared_ptr<Animation> anim, std::string name) {
    if (_anim.use_count() == 0) {
        _anim = std::make_shared<NodeAnim>(anim, name);
        _anims.push_back(_anim);
        _firstAnim = _anim;
    } else {
        _anims.push_back(std::make_shared<NodeAnim>(anim, name));
    }
}

void KapEngine::Animator::setTrigger(std::string name) {
    if (_anim.use_count() == 0)
        return;
    for (size_t i = 0; i < _anim->links.size(); i++) {
        std::shared_ptr<LinkAnim> _link = _anim->links.at(i);
        std::vector<std::string> _triggers;
        _triggers = _link->triggers;
        for (std::size_t x = 0; x < _triggers.size(); x++) {
            if (_triggers.at(x) == name) {
                _anim->_anim->play(false);
                _anim = _link.get()->target;
                _anim->_anim->play(true);
                return;
            }
        }
    }
    if (getGameObject().getEngine().debugMode())
        Debug::error("[Animator]: trigger " + name + " does not exists");
}

std::shared_ptr<KapEngine::Animator::NodeAnim> KapEngine::Animator::getAnimNode(std::string name) {
    std::shared_ptr<NodeAnim> res;
    for (size_t i = 0; i < _anims.size(); i++) {
        if (_anims.at(i)->_name == name) {
            return _anims.at(i);
        }
    }
    return res;
}

void KapEngine::Animator::addLink(std::string animName, std::string outAnim, std::string trigger)
{
    std::vector<std::string> triggers;

    if (trigger == "") {
        return addLink(animName, outAnim, triggers);        
    }
    triggers.push_back(trigger);
    addLink(animName, outAnim, triggers);        
}

void KapEngine::Animator::addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers)
{
    std::shared_ptr<NodeAnim> node = getAnimNode(animName);
    std::shared_ptr<NodeAnim> out = getAnimNode(outAnim);
    bool isMainExit = false;

    if (node.use_count() == 0) {
        Debug::error("[Animator] addLink no animation found with name " + animName);
        return;
    }
    if (out.use_count() == 0) {
        Debug::error("[Animator] addLink no animation found with name " + outAnim);
        return;
    }
    if (triggers.size() == 0 && node->hasMainExit()) {
        Debug::error("[Animator] addLink animation " + animName + " already had a main exit");
        return;
    }

    if (triggers.size() == 0)
        isMainExit = true;
    std::shared_ptr<LinkAnim> nLink = std::make_shared<LinkAnim>();

    nLink->mainExit = isMainExit;
    nLink->target = out;
    nLink->triggers = triggers;

    node->links.push_back(nLink);
}
