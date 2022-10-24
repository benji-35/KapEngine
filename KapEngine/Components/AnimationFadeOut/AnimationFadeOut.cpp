/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeOut
*/

#include "AnimationFadeOut.hpp"

KapEngine::AnimationFadeOut::AnimationFadeOut(std::shared_ptr<GameObject> go) : Animation(go) {
    //besoin du composant Image pour fonctionner
    addRequireComponent("Image");
    _onEnd.registerAction([this](){
        this->getGameObject().setActive(false);
    });
}

KapEngine::AnimationFadeOut::~AnimationFadeOut() {}

void KapEngine::AnimationFadeOut::onPlay() {
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(255);
    img.setColor(cColor);
    img.setActive(true);
}

void KapEngine::AnimationFadeOut::onUpdateAnim() {
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    val = 1.0f - val;

    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)(val * 255));
    img.setColor(cColor);
}

void KapEngine::AnimationFadeOut::onResetAnim() {
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(255);
    img.setColor(cColor);
}
