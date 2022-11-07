/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeOut
*/

#include "AnimationFadeOut.hpp"

KapEngine::AnimationFadeOut::AnimationFadeOut(std::shared_ptr<GameObject> go) : Animation(go) {
    PROFILER_FUNC_START();
    //besoin du composant Image pour fonctionner
    addRequireComponent("Image");
    _onEnd.registerAction([this](){
        this->getGameObject().setActive(false);
    });
    PROFILER_FUNC_END();
}

KapEngine::AnimationFadeOut::~AnimationFadeOut() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::AnimationFadeOut::onPlay() {
    PROFILER_FUNC_START();
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(255);
    img.setColor(cColor);
    img.setActive(true);
    PROFILER_FUNC_END();
}

void KapEngine::AnimationFadeOut::onUpdateAnim() {
    PROFILER_FUNC_START();
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    val = 1.0f - val;

    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)(val * 255));
    img.setColor(cColor);
    PROFILER_FUNC_END();
}

void KapEngine::AnimationFadeOut::onResetAnim() {
    PROFILER_FUNC_START();
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(255);
    img.setColor(cColor);
    PROFILER_FUNC_END();
}
