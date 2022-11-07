/*
** EPITECH PROJECT, 2022
** engine
** File description:
** AnimationSplashScreen
*/

#include "AnimationSplashScreen.hpp"

KapEngine::AnimationSplashScreen::AnimationSplashScreen(std::shared_ptr<GameObject> go) : Animation(go) {
    PROFILER_FUNC_START();
    addRequireComponent("Image");
    PROFILER_FUNC_END();
}

KapEngine::AnimationSplashScreen::~AnimationSplashScreen() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::AnimationSplashScreen::onPlay() {
    PROFILER_FUNC_START();
    getGameObject().getComponent<UI::Image>().setActive(true);

    getOnEnd().registerAction([this](){
        getGameObject().getComponent<UI::Image>().setActive(false);
    });
    PROFILER_FUNC_END();
}

void KapEngine::AnimationSplashScreen::onUpdateAnim() {
    PROFILER_FUNC_START();
    float mainVal = ((float)_currTime / (float)_timing.asMicroSecond());

    if (mainVal > 0.5f) {
        __fadeOut(mainVal);
    } else {
        __fadeIn(mainVal);
    }
    PROFILER_FUNC_END();
}

void KapEngine::AnimationSplashScreen::onResetAnim() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::AnimationSplashScreen::__fadeIn(float val) {
    PROFILER_FUNC_START();
    if (val >= 0.5f) {
        PROFILER_FUNC_END();
        return;
    }
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)((val / 0.5f) * 255));
    img.setColor(cColor);
    PROFILER_FUNC_END();
}

void KapEngine::AnimationSplashScreen::__fadeOut(float val) {
    PROFILER_FUNC_START();
    val -= 0.5f;

    if (val >= 0.5f) {
        getGameObject().getComponent<UI::Image>().setActive(false);
        PROFILER_FUNC_END();
        return;
    }
    auto &img = getGameObject().getComponent<UI::Image>();
    Tools::Color cColor = img.getColorSprite();
    cColor.setA((char)((1.0f - (val / 0.5f)) * 255));
    img.setColor(cColor);
    PROFILER_FUNC_END();
}
