/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeIn
*/

#include "AnimationFadeIn.hpp"

KapEngine::AnimationFadeIn::AnimationFadeIn(std::shared_ptr<GameObject> go) : Animation(go) {
    //besoin du composant Image pour fonctionner
    addRequireComponent("Image");
}

KapEngine::AnimationFadeIn::~AnimationFadeIn() {}

void KapEngine::AnimationFadeIn::__onPlay() {
    //lors du début de l'animation, initialiser les valeurs souhaitées

    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0.0f);
    img.setColor(cColor);
    img.setActive(true);
}

void KapEngine::AnimationFadeIn::__updateAnim() {
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    if (val >= 1.0f)
        return;
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();
    cColor.setA(val);
    img.setColor(cColor);
}

void KapEngine::AnimationFadeIn::__resetAnim() {
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(0.0f);
    img.setColor(cColor);
}
