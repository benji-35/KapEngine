/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLibManager
*/

#include "KapEngine.hpp"
#include "KapEngineGraphical.hpp"
#include "LegacyGraphicalLib.hpp"

KapEngine::Graphical::GraphicalLibManager::GraphicalLibManager(KEngine &engine) : _engine(engine) {
    PROFILER_FUNC_START();
    std::shared_ptr<LegacyGraphicalLib> legacy = std::make_shared<LegacyGraphicalLib>(*this);
    addLib(legacy);
    changeLib(1);
    PROFILER_FUNC_END();
}

KapEngine::Graphical::GraphicalLibManager::~GraphicalLibManager() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLibManager::__update() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

bool KapEngine::Graphical::GraphicalLibManager::isLibExists(std::size_t const& index) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() != 0 && _libs[i]->getId() == index) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

bool KapEngine::Graphical::GraphicalLibManager::isLibExists(std::string const& name) {
    PROFILER_FUNC_END();
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getName() == name) {
            PROFILER_FUNC_END();
            return true;
        }
    }
    PROFILER_FUNC_END();
    return false;
}

void KapEngine::Graphical::GraphicalLibManager::removeLib(std::size_t const& index) {
    PROFILER_FUNC_START();
    if (!isLibExists(index)) {
        PROFILER_FUNC_END();
        return;
    }
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() > 0 && _libs[i]->getId() == index) {
            _libs[index].reset();
            _libs.erase(_libs.begin() + index);
            break;
        }
    }
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLibManager::removeLib(std::string const& name) {
    PROFILER_FUNC_START();
    if (!isLibExists(name)) {
        PROFILER_FUNC_END();
        return;
    }
    removeLib(getLibIndexFromName(name));
    PROFILER_FUNC_END();
}

std::size_t KapEngine::Graphical::GraphicalLibManager::getLibIndexFromName(std::string const& name) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getName () == name) {
            PROFILER_FUNC_END();
            return _libs[i]->getId();
        }
    }
    PROFILER_FUNC_END();
    throw Errors::GraphicalSystemError("Lib " + name + " not found");
}

void KapEngine::Graphical::GraphicalLibManager::addLib(std::shared_ptr<GraphicalLib> lib) {
    PROFILER_FUNC_START();
    _libs.push_back(lib);
    _maxLib++;
    lib->__setId(_maxLib);
    PROFILER_FUNC_END();
}

std::string KapEngine::Graphical::GraphicalLibManager::getLibNameFromIndex(std::size_t const& index) {
    PROFILER_FUNC_START();
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getId() == index) {
            PROFILER_FUNC_END();
            return _libs[i]->getName();
        }
    }
    PROFILER_FUNC_END();
    return "";
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::Graphical::GraphicalLibManager::getLib(std::size_t index) {
    PROFILER_FUNC_START();
    if (!isLibExists(index)) {
        PROFILER_FUNC_END();
        throw Errors::GraphicalSystemError("Library not found");
    }
    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i].use_count() != 0 && _libs[i]->getId() == index) {
            PROFILER_FUNC_END();
            return _libs[i];
        }
    }
    PROFILER_FUNC_END();
    throw Errors::GraphicalSystemError("Library " + std::to_string(index) + " not found");
}

void KapEngine::Graphical::GraphicalLibManager::changeLib(std::size_t const& libId) {
    PROFILER_FUNC_START();
    if (!isLibExists(libId)) {
        PROFILER_FUNC_END();
        return;
    }
    if (currLib != 0) {
        std::shared_ptr<GraphicalLib> lLib = getLib(getCurrLib());
        lLib->clearCache();
        lLib->stopDisplay();
    }
    
    #if KAPENGINE_DEBUG_ACTIVE
        DEBUG_WARNING("[Graphic Manager] : changing to lib " + std::to_string(libId));
    #endif

    std::shared_ptr<GraphicalLib> nLib = getLib(libId);
    nLib->startDisplay();
    currLib = libId;
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLibManager::changeLib(std::string const& libName) {
    PROFILER_FUNC_START();
    if (!isLibExists(libName)) {
        PROFILER_FUNC_END();
        return;
    }
    changeLib(getLibIndexFromName(libName));
    PROFILER_FUNC_END();
}

std::shared_ptr<KapEngine::Graphical::GraphicalLib> KapEngine::Graphical::GraphicalLibManager::getCurrentLib() const {
    PROFILER_FUNC_START();
    std::size_t id = getCurrLib();

    for (std::size_t i = 0; i < _libs.size(); i++) {
        if (_libs[i]->getId() == id) {
            PROFILER_FUNC_END();
            return _libs[i];
        }
    }

    PROFILER_FUNC_END();
    throw Errors::GraphicalSystemError("No current graphical library found");
}
