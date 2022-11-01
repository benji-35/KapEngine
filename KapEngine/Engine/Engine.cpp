/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "Engine.hpp"
#include "KapEngineDebug.hpp"
#include "EventManager.hpp"
#include "KapEngineSettings.hpp"

#if !KAPENGINE_BETA_ACTIVE
    KapEngine::KEngine::KEngine(bool debug, std::string const& gameName, std::string const& version, std::string const& company) {
        _debug = debug;
        _gameName = gameName;
        _gameVersion = version;
        _gameCompany = company;

        __init();
        Time::ETime _baseTime;
        _baseTime.setMilliseconds(25);
        setFixedTime(_baseTime);
    }
#else
    KapEngine::KEngine::KEngine(std::string const& gameName, std::string const& version, std::string const& company) {
        _gameName = gameName;
        _gameVersion = version;
        _gameCompany = company;

        __init();
        Time::ETime _baseTime;
        _baseTime.setMilliseconds(25);
        setFixedTime(_baseTime);
    }
#endif

KapEngine::KEngine::~KEngine() {
    _sceneManager.reset();
    _prefabManager.reset();
    _libManager.reset();
}

void KapEngine::KEngine::run() {
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_WARNING("[ RUNNING ] running game");
    #endif
    #if KAPENGINE_BETA_ACTIVE
        DEBUG_WARNING("[ RUNNING ] running game beta version");
        #if KAPENGINE_THREAD_ACTIVE
            DEBUG_ERROR("[ RUNNING ] running game beta version with thread -> this version is not available");
        #else
            DEBUG_ERROR("[ RUNNING ] running game beta version without thread -> this version is not available");
        #endif
    #else
        _splashsScreen->__init();
        _run = true;
        _internalClock.restart();
        if (getSceneManager()->getCurrentSceneId() == 0)
            getSceneManager()->loadScene(1);
        while (_run) {
            if (__canRunUpdate()) {
                getCurrentGraphicalLib()->clear();
                getCurrentGraphicalLib()->getEvents();
                getEventManager().__update();

                getSceneManager()->__update();

                getCurrentGraphicalLib()->display();
            }
        }
    #endif
}

void KapEngine::KEngine::stop() {
    _run = false;
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::KEngine::getCurrentGraphicalLib() {
    return _libManager->getLib(_libManager->getCurrLib());
}

bool KapEngine::KEngine::isGraphicalLibExists(std::size_t const& index) const {
    return _libManager->isLibExists(index);
}

bool KapEngine::KEngine::isGraphicalLibExists(std::string const& name) const {
    return _libManager->isLibExists(name);
}

std::size_t KapEngine::KEngine::getCurrentGraphicalLibIndex() const {
    return _libManager->getCurrLib();
}

void KapEngine::KEngine::__init() {
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("[INIT] KapEngine");
    #endif
    _sceneManager = std::make_shared<SceneManagement::SceneManager>(*this);
    _prefabManager = std::make_shared<Prefabs::PrefabManager>(*this);
    _libManager = std::make_shared<Graphical::GraphicalLibManager>(*this);
    _eventManager = std::make_shared<Events::EventManager>(*this);
    _splashsScreen = std::make_shared<SceneManagement::SplashScreen>(*this);
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_LOG("[INIT] end init KapEngine");
    #endif
}

KapEngine::Events::EventManager &KapEngine::KEngine::getEventManager() {
    return *_eventManager;
}

void KapEngine::KEngine::setScreenSize(float width, float heigth) {
    screenSize.setX(width);
    screenSize.setY(heigth);
}

void KapEngine::KEngine::setScreenSize(Tools::Vector2 size) {
    screenSize = size;
}

bool KapEngine::KEngine::__canRunUpdate() {
    _runFixed = false;
    bool runUpdate = false;

    Time::ETime etime = _internalClock.getElapseTime();
    
    //check if we can run update
    if (etime.asSecond() - _elapsed.asSecond() >= (1 / getMaxFps())) {
        runUpdate = true;
    }
    _elapsed = etime;
    //check if we can run fixed update
    if (_elapsed >= _fixedTime) {
        _internalClock.restart();
        _runFixed = true;
    }
    if (_runFixed)
        return true;
    return runUpdate;
}
