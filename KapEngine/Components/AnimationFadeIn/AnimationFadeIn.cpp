/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeIn
*/

#include <string>
#include "AnimationFadeIn.hpp"

KapEngine::AnimationFadeIn::AnimationFadeIn(std::shared_ptr<GameObject> go) : Animation(go) {
    PROFILER_FUNC_START();
    //besoin du composant Image pour fonctionner
    addRequireComponent("Image");
    PROFILER_FUNC_END();
}

KapEngine::AnimationFadeIn::~AnimationFadeIn() {}

void KapEngine::AnimationFadeIn::onPlay() {
    PROFILER_FUNC_START();
    //lors du début de l'animation, initialiser les valeurs souhaitées

    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0);
    img.setColor(cColor);
    img.setActive(true);
    PROFILER_FUNC_END();
}

void KapEngine::AnimationFadeIn::onUpdateAnim() {
    PROFILER_FUNC_START();
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    if (val >= 1.0f) {
        PROFILER_FUNC_END();
        return;
    }
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)(val * 255));
    img.setColor(cColor);
    PROFILER_FUNC_END();
}

void KapEngine::AnimationFadeIn::onResetAnim() {
    PROFILER_FUNC_START();
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0);
    img.setColor(cColor);
    PROFILER_FUNC_END();
}
