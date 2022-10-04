/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "Engine.hpp"
#include "KapEngineDebug.hpp"
#include "EventManager.hpp"

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
    _prefabManager.reset();
    _libManager.reset();
}

void KapEngine::KapEngine::run() {
    DEBUG_WARNING("[ RUNNING ] running game");
    _splashsScreen->__init();
    _run = true;
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
        getCurrentGraphicalLib()->clear();
        getCurrentGraphicalLib()->getEvents();
        getEventManager().__update();

        getSceneManager()->__update();

        getCurrentGraphicalLib()->display();
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
    DEBUG_LOG("[INIT] KapEngine");
    _sceneManager = std::make_shared<SceneManagement::SceneManager>(*this);
    _prefabManager = std::make_shared<Prefabs::PrefabManager>(*this);
    _libManager = std::make_shared<Graphical::GraphicalLibManager>(*this);
    _eventManager = std::make_shared<Events::EventManager>(*this);
    _splashsScreen = std::make_shared<SceneManagement::SplashScreen>(*this);
    DEBUG_LOG("[INIT] end init KapEngine");
}

/**
 * threadId : 0 = graphics
 * threadId : 1 = component
 * threadId : 2 = component
 * threadId : 3 = component
 * threadId : 4 = component
 */

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
