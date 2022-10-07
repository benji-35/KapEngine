/*
** EPITECH PROJECT, 2022
** engine
** File description:
** AnimationSplashScreen
*/

#include "AnimationSplashScreen.hpp"

KapEngine::AnimationSplashScreen::AnimationSplashScreen(std::shared_ptr<GameObject> go) : Animation(go) {
    addRequireComponent("Image");
}

KapEngine::AnimationSplashScreen::~AnimationSplashScreen() {}

void KapEngine::AnimationSplashScreen::onPlay() {
    getGameObject().getComponent<UI::Image>().setActive(true);

    getOnEnd().registerAction([this](){
        getGameObject().getComponent<UI::Image>().setActive(false);
    });
}

void KapEngine::AnimationSplashScreen::onUpdateAnim() {
    float mainVal = ((float)_currTime / (float)_timing.asMicroSecond());

    if (mainVal > 0.5f) {
        __fadeOut(mainVal);
    } else {
        __fadeIn(mainVal);
    }
}

void KapEngine::AnimationSplashScreen::onResetAnim() {
    
}

void KapEngine::AnimationSplashScreen::__fadeIn(float val) {
    if (val >= 0.5f)
        return;
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)((val / 0.5f) * 255));
    img.setColor(cColor);
}

void KapEngine::AnimationSplashScreen::__fadeOut(float val) {
    val -= 0.5f;

    if (val >= 0.5f) {
        getGameObject().getComponent<UI::Image>().setActive(false);
        return;
    }
    UI::Image &img = (UI::Image &)getGameObject().getComponent("Image");
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)((1.0f - (val / 0.5f)) * 255));
    img.setColor(cColor);
}
