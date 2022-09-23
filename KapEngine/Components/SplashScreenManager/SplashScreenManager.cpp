/*
** EPITECH PROJECT, 2022
** gameEngine
** File description:
** SplashScreenManager
*/

#include "SplashScreenManager.hpp"
#include "UiImage.hpp"
#include "Debug.hpp"
#include <string>

KapEngine::SceneManagement::SplashScreenManager::SplashScreenManager(std::shared_ptr<GameObject> go, bool b) : Component(go, "SplashScreenManager") {
    isFirst = b;
    _start = b;
    getGameObject().setActive(isFirst);
}

KapEngine::SceneManagement::SplashScreenManager::~SplashScreenManager()
{
}

void KapEngine::SceneManagement::SplashScreenManager::fixedUpdate() {
    if (!_start)
        return;
    currTime += getGameObject().getEngine().getElapsedTime();
    Debug::log("[Splash Screen Manager] currTime: " + std::to_string(currTime.asSecond()));
}

void KapEngine::SceneManagement::SplashScreenManager::update()
{
    if (!_start)
        return;
    float vMax = 1000000.0f;

    //alpha calcul
    if (currTime.asMicroSecond() <= vMax || lastAlpha < 1.0f) {
        try {
            UI::Image &imgC = (UI::Image &)getGameObject().getComponent("Image");
            Tools::Color col = imgC.getColorSprite();
            lastAlpha = col.getA();
            float alpha = (float)currTime.asMicroSecond() / vMax;
            col.setA(alpha);
            imgC.setColor(col);
        } catch(...) {}
    } else if (currTime.asMicroSecond() >= _time.asMicroSecond() - vMax) {
        try {
            UI::Image &imgC = (UI::Image &)getGameObject().getComponent("Image");
            Tools::Color col = imgC.getColorSprite();

            float alpha = 1.0f - (float)currTime.asMicroSecond() / (float)_time.asMicroSecond();
            col.setA(alpha);
            imgC.setColor(col);
        } catch(...) {}
    } else {
        try {
            UI::Image &imgC = (UI::Image &)getGameObject().getComponent("Image");
            Tools::Color col = imgC.getColorSprite();
            col.setA(1.0f);
            imgC.setColor(col);
        } catch(...) {}
    }

    if (currTime.asMicroSecond() >= _time.asMicroSecond()) {
        if (nextSplash.use_count() != 0) {
            nextSplash->getGameObject().setActive(true);
            nextSplash->setStart(true);
        } else if (getGameObject().getEngine().getSceneManager()->sceneExists(sceneName)) {
            getGameObject().getEngine().getSceneManager()->loadScene(sceneName);
        }
        if (getGameObject().getEngine().getSceneManager()->sceneExists(sceneName))
            getGameObject().setActive(false);
    }
}

void KapEngine::SceneManagement::SplashScreenManager::setStart(bool b) {
    _start = b;
    getGameObject().setActive(_start);
}
