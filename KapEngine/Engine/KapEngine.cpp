/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "KapEngine.hpp"
#include "Debug.hpp"

KapEngine::KapEngine::KapEngine(bool debug, std::string const& gameName, std::string const& version, std::string const& company) {
    _debug = debug;
    _gameName = gameName;
    _gameVersion = version;
    _gameCompany = company;

    __init();
}

KapEngine::KapEngine::~KapEngine()
{
}

void KapEngine::KapEngine::run() {
    _run = true;

    while (_run) {
        try {
            if (getCurrentGraphicalLib().use_count() != 0) {
                getCurrentGraphicalLib()->clear();
                getCurrentGraphicalLib()->getEvents();
                _sceneManager->__update();
                getCurrentGraphicalLib()->display();
            } else {
                if (debugMod()) {
                    Debug::error("Scene not alloc");
                } else {
                    _run = false;
                }
            }
        } catch(Errors::GraphicalSystemError e) {
            if (debugMod()) {
                Debug::error(std::string(e.what()));
            } else {
                _run = false;
            }
        }
    }
}

void KapEngine::KapEngine::stop() {
    _run = false;
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::KapEngine::getCurrentGraphicalLib() {
    return _libManager->getLib(_libManager->getCurrLib());
}

bool KapEngine::KapEngine::isGraphicalLibExists(std::size_t const& index) const {
    return false;
}

bool KapEngine::KapEngine::isGraphicalLibExists(std::string const& name) const {
    return false;
}

std::size_t KapEngine::KapEngine::getCurrentGraphicalLibIndex() const {
    return _libManager->getCurrLib();
}

void KapEngine::KapEngine::__init() {
    _sceneManager = std::make_shared<SceneManagement::SceneManager>(*this);
    _libManager = std::make_shared<Graphical::GraphicalLibManager>(*this);
}
