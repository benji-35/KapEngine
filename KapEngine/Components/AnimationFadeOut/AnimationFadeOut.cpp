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

void KapEngine::AnimationFadeOut::__onPlay() {
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(1.0f);
    img.setColor(cColor);
    img.setActive(true);
}

void KapEngine::AnimationFadeOut::__updateAnim() {
    float val = ((float)_currTime / (float)_timing.asMicroSecond());

    val = 1.0f - val;
    Debug::log("Fade out [" + std::to_string(val) + "/1]");

    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();
    cColor.setA(val);
    img.setColor(cColor);
}

void KapEngine::AnimationFadeOut::__resetAnim() {
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();

    cColor.setA(1.0f);
    img.setColor(cColor);
}
