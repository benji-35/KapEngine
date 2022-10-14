/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeIn
*/

#include <string>
#include "AnimationFadeIn.hpp"

KapEngine::AnimationFadeIn::AnimationFadeIn(std::shared_ptr<GameObject> go) : Animation(go) {
    //besoin du composant Image pour fonctionner
    addRequireComponent("Image");
}

KapEngine::AnimationFadeIn::~AnimationFadeIn() {}

void KapEngine::AnimationFadeIn::onPlay() {
    //lors du début de l'animation, initialiser les valeurs souhaitées

    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0);
    img.setColor(cColor);
    img.setActive(true);
}

void KapEngine::AnimationFadeIn::onUpdateAnim() {
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    if (val >= 1.0f)
        return;
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)(val * 255));
    img.setColor(cColor);
}

void KapEngine::AnimationFadeIn::onResetAnim() {
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0);
    img.setColor(cColor);
}
