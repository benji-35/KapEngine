/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "KapEngine.hpp"
#include "Debug.hpp"
#include "EventManager.hpp"

std::recursive_mutex KapEngine::KapEngine::debugMutex;

KapEngine::KapEngine::KapEngine(bool debug, std::string const& gameName, std::string const& version, std::string const& company) {
    _debug = debug;
    _gameName = gameName;
    _gameVersion = version;
    _gameCompany = company;

    __init();
    Time::ETime _baseTime;
    _baseTime.setMilliseconds(25);
    setFixedTime(_baseTime);
}

KapEngine::KapEngine::~KapEngine() {
    _sceneManager.reset();
    _libManager.reset();
}

void KapEngine::KapEngine::run() {
    _run = true;
    _splashsScreen->__init();
    _internalClock.restart();
    if (getSceneManager()->getCurrentSceneId() == 0)
        getSceneManager()->loadScene(1);
    while (_run) {
        _elapsed = _internalClock.getElapseTime();
        _runFixed = false;
        if (_elapsed >= _fixedTime) {
            _internalClock.restart();
            _runFixed = true;
        }
        __threadRun(this, 0);
    }
}

void KapEngine::KapEngine::stop() {
    _run = false;
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::KapEngine::getCurrentGraphicalLib() {
    return _libManager->getLib(_libManager->getCurrLib());
}

bool KapEngine::KapEngine::isGraphicalLibExists(std::size_t const& index) const {
    return _libManager->isLibExists(index);
}

bool KapEngine::KapEngine::isGraphicalLibExists(std::string const& name) const {
    return _libManager->isLibExists(name);
}

std::size_t KapEngine::KapEngine::getCurrentGraphicalLibIndex() const {
    return _libManager->getCurrLib();
}

void KapEngine::KapEngine::__init() {
    _sceneManager = std::make_shared<SceneManagement::SceneManager>(*this);
    _libManager = std::make_shared<Graphical::GraphicalLibManager>(*this);
    _eventManager = std::make_shared<Events::EventManager>(*this);
    _splashsScreen = std::make_shared<SceneManagement::SplashScreen>(*this);
}

/**
 * threadId : 0 = graphics  
 * threadId : 1 = component  
 * threadId : 2 = component  
 * threadId : 3 = component  
 * threadId : 4 = component
 */

void KapEngine::KapEngine::__threadRun(KapEngine *engine, int threadId) {
    if (threadId == 0) {
        try {
            if (engine->getCurrentGraphicalLib().use_count() != 0) {                
                engine->getCurrentGraphicalLib()->clear();
                engine->getCurrentGraphicalLib()->getEvents();
                engine->getEventManager().__update();

                std::thread t1(&KapEngine::__threadRun, engine, 1);
                std::thread t2(&KapEngine::__threadRun, engine, 2);
                std::thread t3(&KapEngine::__threadRun, engine, 3);
                std::thread t4(&KapEngine::__threadRun, engine, 4);

                t1.join();
                t2.join();
                t3.join();
                t4.join();

                engine->getCurrentGraphicalLib()->display();
            } else {
                if (engine->debugMode()) {
                    Debug::error("Scene not alloc");
                } else {
                    engine->stop();
                }
            }
        } catch(Errors::GraphicalSystemError e) {
            if (engine->debugMode()) {
                Debug::error(std::string(e.what()));
            } else {
                    engine->stop();
            }
        }
    }
    if (threadId > 0) {
        engine->getSceneManager()->__update(threadId);
    }
}

KapEngine::Events::EventManager &KapEngine::KapEngine::getEventManager() {
    return *_eventManager;
}

void KapEngine::KapEngine::setScreenSize(float width, float heigth) {
    screenSize.setX(width);
    screenSize.setY(heigth);
}

void KapEngine::KapEngine::setScreenSize(Tools::Vector2 size) {
    screenSize = size;
}
