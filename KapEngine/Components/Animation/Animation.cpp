/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animation
*/

#include "Animation.hpp"

KapEngine::Animation::Animation(std::shared_ptr<GameObject> go) : Component(go, "Animation") {}

KapEngine::Animation::~Animation() {}

void KapEngine::Animation::onFixedUpdate() {
    if (!_startAnim) {
        __resetAnim();
        return;
    }
    _currTime += getGameObject().getEngine().getElapsedTime().asMilliSecond();
    __updateAnim();
    if (_currTime >= _timing.asMicroSecond() && !_end && !_loop) {
        _end = true;
        _startAnim = false;
        _onEnd.invoke();
    } else if (_currTime >= _timing.asMicroSecond() && !_end && _loop) {
        _currTime = 0;
        _onRestart.invoke();
    }
}

void KapEngine::Animation::__resetAnim() {
    _currTime = 0;
}

void KapEngine::Animation::__updateAnim() {

    bool allEnded = true;

    for (std::size_t i = 0; i < _nodes.size(); i++) {
        AnimationLine al = _nodes[i];

        std::size_t great = al.curr;
        for (std::size_t x = al.curr; x < al.nodeTiming.size(); x++) {
            if (al.nodeTiming[x] <= _currTime) {
                great = x;
            } else {
                break;
            }
        }
        al.curr = great;
        al.nodes[al.curr](al.comp);
        if (al.curr < al.nodeTiming.size() - 1)
            allEnded = false;
    }
    if (allEnded) {
        _startAnim = false;
    }
}
