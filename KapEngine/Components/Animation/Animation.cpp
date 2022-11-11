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
    PROFILER_FUNC_START();
    if (!_startAnim) {
        if (_reseted) {
            PROFILER_FUNC_END();
            return;
        }
        _reseted = true;
        _currTime = 0;
        onResetAnim();
        PROFILER_FUNC_END();
        return;
    }
    _reseted = false;
    _currTime += getEngine().getElapsedTime().asMicroSecond();
    onUpdateAnim();
    if (_currTime >= _timing.asMicroSecond() && !_end && !_loop) {
        _end = true;
        _startAnim = false;
        _onEnd.invoke();
    } else if (_currTime >= _timing.asMicroSecond() && !_end && _loop) {
        _currTime = 0;
        _onRestart.invoke();
    }
    PROFILER_FUNC_END();
}

void KapEngine::Animation::onResetAnim() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Animation::onUpdateAnim() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}
