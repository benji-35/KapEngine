/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "KapEngine.hpp"

#if !KAPENGINE_BETA_ACTIVE
    KapEngine::KEngine::KEngine(bool debug, std::string const& gameName, std::string const& version, std::string const& company) {
        PROFILER_FUNC_START();
        _debug = debug;
        _gameName = gameName;
        _gameVersion = version;
        _gameCompany = company;

        __init();
        Time::ETime _baseTime;
        _baseTime.setMilliseconds(25);
        setFixedTime(_baseTime);
        PROFILER_FUNC_END();
    }
#else
    KapEngine::KEngine::KEngine(std::string const& gameName, std::string const& version, std::string const& company) {
        PROFILER_FUNC_START();
        _gameName = gameName;
        _gameVersion = version;
        _gameCompany = company;

        __init();
        Time::ETime _baseTime;
        _baseTime.setMilliseconds(25);
        setFixedTime(_baseTime);
        PROFILER_FUNC_END();
    }
#endif

KapEngine::KEngine::~KEngine() {
    PROFILER_FUNC_START();
    _sceneManager.reset();
    _prefabManager.reset();
    _libManager.reset();
    PROFILER_FUNC_END();
}

void KapEngine::KEngine::run() {
    PROFILER_FUNC_START();
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_WARNING("[ RUNNING ] running game");
    #endif
    #if KAPENGINE_BETA_ACTIVE
        DEBUG_WARNING("[ RUNNING ] running game beta version");
        #if KAPENGINE_THREAD_ACTIVE
            DEBUG_ERROR("[ RUNNING ] running game beta version with thread -> this version is not available");
            //start update for physics
            //start update for components
            //start update for graphics
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
    PROFILER_FUNC_END();
}

void KapEngine::KEngine::stop() {
    PROFILER_FUNC_START();
    #if KAPENGINE_BETA_ACTIVE
        #if KAPENGINE_THREAD_ACTIVE
            _mutex.lock();
        #endif
    #endif
    if (!_run) {
        PROFILER_FUNC_END();
        return;
    }
    _run = false;
    #if KAPENGINE_BETA_ACTIVE
        #if KAPENGINE_THREAD_ACTIVE
            _mutex.unlock();
        #endif
    #endif
    PROFILER_FUNC_END();
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::KEngine::getCurrentGraphicalLib() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return _libManager->getLib(_libManager->getCurrLib());
}

bool KapEngine::KEngine::isGraphicalLibExists(std::size_t const& index) const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return _libManager->isLibExists(index);
}

bool KapEngine::KEngine::isGraphicalLibExists(std::string const& name) const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return _libManager->isLibExists(name);
}

std::size_t KapEngine::KEngine::getCurrentGraphicalLibIndex() const {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return _libManager->getCurrLib();
}

void KapEngine::KEngine::__init() {
    PROFILER_FUNC_START();
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
    PROFILER_FUNC_END();
}

KapEngine::Events::EventManager &KapEngine::KEngine::getEventManager() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return *_eventManager;
}

void KapEngine::KEngine::setScreenSize(float width, float heigth) {
    PROFILER_FUNC_START();
    screenSize.setX(width);
    screenSize.setY(heigth);
    PROFILER_FUNC_END();
}

void KapEngine::KEngine::setScreenSize(Tools::Vector2 size) {
    PROFILER_FUNC_START();
    screenSize = size;
    PROFILER_FUNC_END();
}

bool KapEngine::KEngine::__canRunUpdate() {
    PROFILER_FUNC_START();
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
    if (_runFixed) {
        PROFILER_FUNC_END();
        return true;
    }
    PROFILER_FUNC_END();
    return runUpdate;
}
