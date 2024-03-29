/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SplashScreen
*/

#include "KapEngine.hpp"
#include "KapEngineUi.hpp"

#include "AnimationSplashScreen.hpp"

KapEngine::SceneManagement::SplashScreen::SplashScreen(KEngine &engine) : _engine(engine) {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

KapEngine::SceneManagement::SplashScreen::~SplashScreen() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::SceneManagement::SplashScreen::__init() {
    PROFILER_FUNC_START();
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
        kapEngineNode->size.setX(450.f);
        kapEngineNode->size.setY(338.44f);
        kapEngineNode->pos.setY((_engine.getScreenSize().getY() / 2.0f) - (338.f / 2.0f));
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
    if (_splahes.size() == 0) {
        PROFILER_FUNC_END();
        return;
    }

    //create splash screen scene
    auto sceneSplash = Factory::createScene(_engine, "SplashScreen");
    
    auto canvas = UI::UiFactory::createCanvas(*sceneSplash);

    auto animator = std::make_shared<Animator>(canvas);
    canvas->addComponent(animator);

    try {
        auto &canvasC = canvas->getComponent<UI::Canvas>();
        canvasC.setResizeType(UI::Canvas::ResizyngType::RESIZE_WITH_SCREEN);
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Splashscreen failed to acces canvas component");
        #endif
    }

    //init all GameObjects in splashScreen scene
    for (std::size_t i = 0; i < _splahes.size(); i++) {
        std::string objName = "Image(" + std::to_string(i) + ")";
        std::shared_ptr<GameObject> img = UI::UiFactory::createImage(*sceneSplash, objName, _splahes[i]->pathImage);

        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("Create splash screen " + objName);
        #endif

        Tools::Vector3 startPos(_splahes[i]->pos.getX(), _splahes[i]->pos.getY(), 0);
        Tools::Vector3 startScale(_splahes[i]->size.getX(), _splahes[i]->size.getY(), 0);

        try {
            Transform &tr = (Transform &)img->getTransform();
            tr.setScale(startScale);
            tr.setPosition(startPos);

            auto &imgC = img->getComponent<UI::Image>();
            imgC.setRectangle(_splahes[i]->rect);
        } catch(...) {}
        
        std::shared_ptr<AnimationSplashScreen> anim = std::make_shared<AnimationSplashScreen>(img);

        Time::ETime timeAnim;
        timeAnim.setSeconds(_splahes[i]->timing);

        anim->setTiming(timeAnim);

        animator->addAnim(anim, "anim"+ std::to_string(i));

        try {
            auto &imgC = img->getComponent<UI::Image>();
            Tools::Color cCol = imgC.getColorSprite();
            cCol.setA(0.0f);
            imgC.setColor(cCol);
            if (i != 0) {
                imgC.setActive(false);
            }
        } catch(...) {}

        if (i == _splahes.size() - 1) {
            anim->getOnEnd().registerAction([this](){
                this->_engine.getSceneManager()->loadScene(this->_sceneId);
            });
        }

        img->addComponent(anim);

        try {
            Transform &tr = (Transform &)img->getTransform();
            tr.setParent(canvas->getId());
        } catch (...) {}
    }

    //add animations links
    for (std::size_t i = 0; i < _splahes.size(); i++) {
        if (i != _splahes.size() - 1) {
            animator->addLink("anim"+ std::to_string(i), "anim"+ std::to_string(i + 1));
        }
    }

    //change cam background color
    try {
        Camera &cam = (Camera&)sceneSplash->getActiveCamera();
        cam.setBackgroundColor(Tools::Color::black());
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_LOG("[Splash Screen]Active camera on object " + std::to_string(cam.getGameObjectId()));
        #endif
    } catch(...) {
        #if KAPENGINE_DEBUG_ACTIVE
            DEBUG_ERROR("Camera not found for splashscreen creation");
        #endif
    }
    //set splash screen scene as first scene
    _engine.getSceneManager()->loadScene(sceneSplash->getId());
    PROFILER_FUNC_END();
}
