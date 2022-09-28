/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SplashScreen
*/

#include "SplashScreen.hpp"
#include "Factory.hpp"
#include "UiFactory.hpp"

#include "Animator.hpp"
#include "AnimationFadeIn.hpp"
#include "AnimationFadeOut.hpp"

KapEngine::SceneManagement::SplashScreen::SplashScreen(KapEngine &engine) : _engine(engine) {}

KapEngine::SceneManagement::SplashScreen::~SplashScreen() {}

void KapEngine::SceneManagement::SplashScreen::__init() {
    _sceneId = _engine.getSceneManager()->getCurrentSceneId();
    if (_sceneId == 0)
        _sceneId = 1;

    //init KapEngine Splash Screen
    if (_displayKapEngineLogo) {
        std::shared_ptr<SplashScreenNode> kapEngineNode = std::make_shared<SplashScreenNode>("./Library/KapEngine/Documentation/images/KapEngineBannerNeg.png", 4);
        std::vector<std::shared_ptr<SplashScreenNode>> nNodes;

        kapEngineNode->rect.setX(0);
        kapEngineNode->rect.setY(0);
        kapEngineNode->rect.setWidth(1436);
        kapEngineNode->rect.setHeigth(1080);
        kapEngineNode->size.setX(0.3f);
        kapEngineNode->size.setY(1.0f);
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

    //create splash screen scene
    auto sceneSplash = Factory::createScene(_engine, "SplashScreen");
    
    auto canvas = UI::UiFactory::createCanvas(*sceneSplash);

    auto animator = std::make_shared<Animator>(canvas);
    canvas->addComponent(animator);

    //init all GameObjects in splashScreen scene
    for (std::size_t i = 0; i < _splahes.size(); i++) {
        std::string objName = "Image(" + std::to_string(i) + ")";
        std::shared_ptr<GameObject> img = UI::UiFactory::createImage(*sceneSplash, objName, _splahes[i]->pathImage);

        Debug::log("Create splash screen " + objName);

        Tools::Vector3 startPos(_splahes[i]->pos.getX(), _splahes[i]->pos.getY(), 0);
        Tools::Vector3 startScale(_splahes[i]->size.getX(), _splahes[i]->size.getY(), 0);

        try {
            Transform &tr = (Transform &)img->getTransform();
            tr.setScale(startScale);
            tr.setPosition(startPos);

            UI::Image &imgC = (UI::Image &)img->getComponent("Image");
            imgC.setRectangle(_splahes[i]->rect);
        } catch(...) {}
        
        std::shared_ptr<AnimationFadeIn> animIn = std::make_shared<AnimationFadeIn>(img);
        std::shared_ptr<AnimationFadeOut> animOut = std::make_shared<AnimationFadeOut>(img);

        Time::ETime timeAnim;
        timeAnim.setSeconds(_splahes[i]->timing);

        animIn->setTiming(timeAnim);
        animOut->setTiming(timeAnim);

        animator->addAnim(animIn, "animIn "+ std::to_string(i));
        animator->addAnim(animOut, "animOut "+ std::to_string(i));

        animator->addLink("animIn "+ std::to_string(i), "animOut "+ std::to_string(i));

        try {
            UI::Image &imgC = (UI::Image &)img->getComponent("Image");
            Tools::Color cCol = imgC.getColorSprite();
            cCol.setA(0.0f);
            imgC.setColor(cCol);
            if (i != 0) {
                imgC.setActive(false);
            }
        } catch(...) {}

        if (i == _splahes.size() - 1) {
            animOut->getOnEnd().registerAction([this](){
                this->_engine.getSceneManager()->loadScene(this->_sceneId);
            });
        }

        img->addComponent(animIn);
        img->addComponent(animOut);

        try {
            Transform &tr = (Transform &)img->getTransform();
            tr.setParent(canvas->getId());
        } catch (...) {}
    }

    //add animations links
    for (std::size_t i = 0; i < _splahes.size(); i++) {
        if (i != _splahes.size() - 1) {
            animator->addLink("animOut "+ std::to_string(i), "animIn "+ std::to_string(i + 1));
        }
    }

    //change cam background color
    try {
        Camera &cam = (Camera&)sceneSplash->getActiveCamera();
        cam.setBackgroundColor(Tools::Color::black());
        Debug::log("[Splash Screen]Active camera on object " + std::to_string(cam.getGameObject().getId()));
    } catch(...) {
        Debug::error("Camera not found for splashscreen creation");
    }
    //set splash screen scene as first scene
    _engine.getSceneManager()->loadScene(sceneSplash->getId());
}
