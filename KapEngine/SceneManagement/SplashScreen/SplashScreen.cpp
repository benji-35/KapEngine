/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SplashScreen
*/

#include "SplashScreen.hpp"

KapEngine::SceneManagement::SplashScreen::SplashScreen(KapEngine &engine) : _engine(engine) {}

KapEngine::SceneManagement::SplashScreen::~SplashScreen() {}

void KapEngine::SceneManagement::SplashScreen::__init() {
    _sceneName = _engine.getSceneManager()->getCurrentScene().getName();

    //init KapEngine Splash Screen
    if (_displayKapEngineLogo) {
        std::shared_ptr<SplashScreenNode> kapEngineNode = std::make_shared<SplashScreenNode>("Documentation/Engine/images/KapEngineBannerNeg.png", 8);
        std::vector<std::shared_ptr<SplashScreenNode>> nNodes;

        kapEngineNode->rect.setX(0);
        kapEngineNode->rect.setY(0);
        kapEngineNode->rect.setWidth(1436);
        kapEngineNode->rect.setHeigth(1080);
        kapEngineNode->size.setX(450.0f);
        kapEngineNode->size.setY(400.0f);
        kapEngineNode->pos.setY((_engine.getScreenSize().getY() / 2.0f) - (400.f / 2.0f));
        kapEngineNode->pos.setX((_engine.getScreenSize().getX() / 2.f) - (450.f / 2.0f));

        nNodes.push_back(kapEngineNode);
        // nNodes.push_back(kapEngineNode2);
        for (std::size_t i = 0; i < _splahes.size(); i++) {
            nNodes.push_back(_splahes[i]);
        }
        _splahes.clear();
        _splahes = nNodes;
    }
    //check if there is splashes to display
    if (_splahes.size() == 0)
        return;

}
