/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animation
*/

#include "Animation.hpp"

KapEngine::Animation::Animation(std::shared_ptr<GameObject> go) : Component(go, "Animation", 1) {}

KapEngine::Animation::~Animation() {}

void KapEngine::Animation::onFixedUpdate() {
    if (!_startAnim) {
        if (_reseted)
            return;
        _reseted = true;
        _currTime = 0;
        onResetAnim();
        return;
    }
    _reseted = false;
    _currTime += getGameObject().getEngine().getElapsedTime().asMicroSecond();
    onUpdateAnim();
    if (_currTime >= _timing.asMicroSecond() && !_end && !_loop) {
        _end = true;
        _startAnim = false;
        _onEnd.invoke();
    } else if (_currTime >= _timing.asMicroSecond() && !_end && _loop) {
        _currTime = 0;
        _onRestart.invoke();
    }
}

void KapEngine::Animation::onResetAnim() {
}

void KapEngine::Animation::onUpdateAnim() {

}
