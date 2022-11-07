/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animator
*/

#include "Animator.hpp"

KapEngine::Animator::Animator(std::shared_ptr<GameObject> go) : Component(go, "Animator", 1) {}

KapEngine::Animator::~Animator() {
    PROFILER_FUNC_START();
    _anims.clear();
    PROFILER_FUNC_END();
}

void KapEngine::Animator::onStart()
{
    PROFILER_FUNC_START();
    _anim = _firstAnim;
    if (_anim.use_count() != 0) {
        _anim->_anim->play(true);
    }
    PROFILER_FUNC_END();
}

void KapEngine::Animator::onFixedUpdate() {
    PROFILER_FUNC_START();
    if (_anim.use_count() == 0) {
        PROFILER_FUNC_END();
        return;
    }
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
    PROFILER_FUNC_END();
}

void KapEngine::Animator::addAnim(std::shared_ptr<Animation> anim, std::string name) {
    PROFILER_FUNC_START();
    if (_anim.use_count() == 0) {
        _anim = std::make_shared<NodeAnim>(anim, name);
        _anims.push_back(_anim);
        _firstAnim = _anim;
    } else {
        _anims.push_back(std::make_shared<NodeAnim>(anim, name));
    }
    PROFILER_FUNC_END();
}

void KapEngine::Animator::setTrigger(std::string name) {
    PROFILER_FUNC_START();
    if (_anim.use_count() == 0) {
        PROFILER_FUNC_END();
        return;
    }
    for (size_t i = 0; i < _anim->links.size(); i++) {
        std::shared_ptr<LinkAnim> _link = _anim->links.at(i);
        std::vector<std::string> _triggers;
        _triggers = _link->triggers;
        for (std::size_t x = 0; x < _triggers.size(); x++) {
            if (_triggers.at(x) == name) {
                _anim->_anim->play(false);
                _anim = _link.get()->target;
                _anim->_anim->play(true);
                PROFILER_FUNC_END();
                return;
            }
        }
    }
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_ERROR("[Animator]: trigger " + name + " does not exists");
    #endif
    PROFILER_FUNC_END();
}

std::shared_ptr<KapEngine::Animator::NodeAnim> KapEngine::Animator::getAnimNode(std::string name) {
    PROFILER_FUNC_START();
    std::shared_ptr<NodeAnim> res;
    for (size_t i = 0; i < _anims.size(); i++) {
        if (_anims.at(i)->_name == name) {
            PROFILER_FUNC_END();
            return _anims.at(i);
        }
    }
    PROFILER_FUNC_END();
    return res;
}

void KapEngine::Animator::addLink(std::string animName, std::string outAnim, std::string trigger)
{
    PROFILER_FUNC_START();
    std::vector<std::string> triggers;

    if (trigger == "") {
        PROFILER_FUNC_END();
        return addLink(animName, outAnim, triggers);        
    }
    triggers.push_back(trigger);
    addLink(animName, outAnim, triggers);
    PROFILER_FUNC_END();
}

void KapEngine::Animator::addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers)
{
    PROFILER_FUNC_START();
    std::shared_ptr<NodeAnim> node = getAnimNode(animName);
    std::shared_ptr<NodeAnim> out = getAnimNode(outAnim);
    bool isMainExit = false;

    if (node.use_count() == 0) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("[Animator] addLink no animation found with name " + animName);
        #endif
        PROFILER_FUNC_END();
        return;
    }
    if (out.use_count() == 0) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("[Animator] addLink no animation found with name " + outAnim);
        #endif
        PROFILER_FUNC_END();
        return;
    }
    if (triggers.size() == 0 && node->hasMainExit()) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("[Animator] addLink animation " + animName + " already had a main exit");
        #endif
        PROFILER_FUNC_END();
        return;
    }

    if (triggers.size() == 0)
        isMainExit = true;
    std::shared_ptr<LinkAnim> nLink = std::make_shared<LinkAnim>();

    nLink->mainExit = isMainExit;
    nLink->target = out;
    nLink->triggers = triggers;

    node->links.push_back(nLink);
    PROFILER_FUNC_END();
}
