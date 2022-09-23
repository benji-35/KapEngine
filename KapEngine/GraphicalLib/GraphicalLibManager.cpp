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
    changeLib(1);
}

KapEngine::Graphical::GraphicalLibManager::~GraphicalLibManager() {}

void KapEngine::Graphical::GraphicalLibManager::__update() {
    
}

bool KapEngine::Graphical::GraphicalLibManager::isLibExists(std::size_t const& index) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() != 0 && _libs[i]->getId() == index)
            return true;
    }
    return false;
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
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() > 0 && _libs[i]->getId() == index) {
            _libs[index].reset();
            _libs.erase(_libs.begin() + index);
            break;
        }
    }
}

void KapEngine::Graphical::GraphicalLibManager::removeLib(std::string const& name) {
    if (!isLibExists(name))
        return;
    removeLib(getLibIndexFromName(name));
}

std::size_t KapEngine::Graphical::GraphicalLibManager::getLibIndexFromName(std::string const& name) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getName() == name)
            return _libs[i]->getId();
    }
    throw Errors::GraphicalSystemError("Lib " + name + " not found");
}

void KapEngine::Graphical::GraphicalLibManager::addLib(std::shared_ptr<GraphicalLib> lib) {
    _libs.push_back(lib);
    _maxLib++;
    lib->__setId(_maxLib);
}

std::string KapEngine::Graphical::GraphicalLibManager::getLibNameFromIndex(std::size_t const& index) {
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getId() == index)
            return _libs[i]->getName();
    }
    return "";
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::Graphical::GraphicalLibManager::getLib(std::size_t index) {
    if (!isLibExists(index))
        throw Errors::GraphicalSystemError("Library not found");
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() != 0 && _libs[i]->getId() == index)
            return _libs[i];
    }
    throw Errors::GraphicalSystemError("Library " + std::to_string(index) + " not found");
}

void KapEngine::Graphical::GraphicalLibManager::changeLib(std::size_t const& libId) {
    if (!isLibExists(libId))
        return;
    if (currLib != 0) {
        std::shared_ptr<GraphicalLib> lLib = getLib(getCurrLib());
        lLib->clearCache();
        lLib->stopDisplay();
    }

    if (getEngine().debugMode()) {
        Debug::warning("[Graphic Manager] : changing to lib " + std::to_string(libId));
    }

    std::shared_ptr<GraphicalLib> nLib = getLib(libId);
    nLib->startDisplay();
    currLib = libId;
}

void KapEngine::Graphical::GraphicalLibManager::changeLib(std::string const& libName) {
    if (!isLibExists(libName))
        return;
    changeLib(getLibIndexFromName(libName));
}
