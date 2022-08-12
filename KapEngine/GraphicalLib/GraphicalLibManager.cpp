/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLibManager
*/

#include "GraphicalLibManager.hpp"
#include "Debug.hpp"
#include "LegacyGraphicalLib.hpp"

KapEngine::Graphical::GraphicalLibManager::GraphicalLibManager(KapEngine &engine) : _engine(engine) {
    std::shared_ptr<LegacyGraphicalLib> legacy = std::make_shared<LegacyGraphicalLib>(*this);
    addLib(legacy);
}

KapEngine::Graphical::GraphicalLibManager::~GraphicalLibManager() {}

void KapEngine::Graphical::GraphicalLibManager::update() {
    if (_multiThread) {
        if (_threadRunning)
            return;
        // _thread = std::make_shared<std::thread>(__runThread);
        return;
    }
    Debug::log("update graphical normal");
}

void KapEngine::Graphical::GraphicalLibManager::__runThread() {
    while (_engine.isRunning() && _forceStopThread == false) {
        Debug::log("update graphical by thread");
    }
    Debug::warning("stopping graphical by thread");
    _forceStopThread = false;
    _multiThread = false;
    _threadRunning = false;
}

bool KapEngine::Graphical::GraphicalLibManager::isLibExists(std::size_t const& index) {
    if (index >= _libs.size())
        return false;
    return true;
}

bool KapEngine::Graphical::GraphicalLibManager::isLibExists(std::string const& name) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getName() == name)
            return true;
    }
    return false;
}

void KapEngine::Graphical::GraphicalLibManager::removeLib(std::size_t const& index) {
    if (!isLibExists(index))
        return;
    _libs[index].reset();
    _libs.erase(_libs.begin() + index);
}

void KapEngine::Graphical::GraphicalLibManager::removeLib(std::string const& name) {
    if (!isLibExists(name))
        return;
    removeLib(getLibIndexFromName(name));
}

std::size_t KapEngine::Graphical::GraphicalLibManager::getLibIndexFromName(std::string const& name) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getName() == name)
            return i;
    }
    return _libs.size();
}

void KapEngine::Graphical::GraphicalLibManager::addLib(std::shared_ptr<GraphicalLib> lib) {
    _libs.push_back(lib);
}

std::string KapEngine::Graphical::GraphicalLibManager::getLibNameFromIndex(std::size_t const& index) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (i == index)
            return _libs[i]->getName();
    }
    return "";
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::Graphical::GraphicalLibManager::getLib(std::size_t index) {
    if (!isLibExists(index))
        throw Errors::GraphicalSystemError("Library not found");
    return _libs[index];
}
